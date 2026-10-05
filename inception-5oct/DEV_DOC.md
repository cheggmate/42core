# Developer Documentation

This document explains the technical architecture, development workflows, container details, and data lifecycle management for the Inception stack.

---

## 1. Setting Up the Environment from Scratch

### Prerequisites
Before developing, make sure the host operating system meets the following requirements:
*   **Operating System**: Linux (Debian Bookworm recommended).
*   **Packages**: `make`, `docker.io`, `docker-compose-v2` (or `docker-compose`).
*   **Permissions**: The active developer user must be added to the `docker` group to run commands without `sudo` (except for direct `/home` root data directory edits):
    ```bash
    sudo usermod -aG docker $USER
    newgrp docker
    ```

### Initial Configuration & Secrets Layout
When building the project from scratch, the root directory must be structured as follows:
*   `srcs/docker-compose.yml`: Coordinates the multi-container configuration.
*   `srcs/.env`: Contains non-sensitive system environment variables.
*   `secrets/`: A folder containing plaintext credential files.

If these configuration files are missing, running `make setup` (or simply `make`) will auto-populate them with default, gitignored template values.

Example for `.env`:
```bash
DOMAIN_NAME=login.42.fr
SQL_DATABASE=wordpress
SQL_USER=wp_db_user
WP_TITLE=Inception_login
LOGIN=login
WP_ADMIN_USER=login_manager
WP_ADMIN_EMAIL=login@student.42.fr
WP_USER=login_user
WP_USER_EMAIL=login+user@student.42.fr
FTP_USER=login_ftp
```

Example for `credentials.txt`:
```bash
WP_ADMIN_USER=login_manager
WP_ADMIN_PASSWORD=manager_pass_12345
WP_ADMIN_EMAIL=login@student.42.fr
WP_USER=login_user
WP_USER_PASSWORD=user_pass_12345
WP_USER_EMAIL=login+user@student.42.fr
FTP_USER=login_ftp
FTP_PASSWORD=ftp_pass_12345
```

Example for `db_password.txt`:
```bash
wp_db_pass_12345
```

Example for `db_root_password.txt`:
```bash
db_root_pass_12345
```

---

## 2. Building and Launching the Stack

The build pipeline is managed with the `Makefile`:

```bash
# Prepare directories, write default secrets, build images, and run containers
make

# Equivalent step-by-step commands:
make setup
make build
make up
```

### Build Process details
*   **Docker Compose Build**: Docker Compose reads `./srcs/docker-compose.yml` and triggers the respective build contexts inside `./srcs/requirements/`.
*   **Dockerfiles**: Built from `debian:bookworm`. Avoid using the `latest` tag in any Dockerfile.
*   **Layer Caching**: Filesystem changes inside `conf/` or `tools/` will bust the cache for the COPY layer during subsequent builds, ensuring configurations update properly.

---

## 3. Container Management & Useful Commands

Developers can interact directly with the containers using the following CLI commands:

### Accessing Container Shells
To enter the terminal of any service and execute commands interactively:
```bash
# NGINX Container
docker exec -it nginx /bin/bash

# WordPress Container (e.g. running manual wp-cli commands)
docker exec -it wordpress /bin/bash

# MariaDB Container (e.g. debugging databases)
docker exec -it mariadb /bin/bash

# FTP Container (e.g. checking vsftpd daemon and permissions)
docker exec -it ftp /bin/bash

# Redis Container
docker exec -it redis /bin/bash

# Adminer Container
docker exec -it adminer /bin/bash

# Portainer Container
docker exec -it portainer /bin/bash

# Static-Site Container
docker exec -it static-site /bin/bash
```

### Inspecting Container Configurations
*   **View active network specifications**:
    ```bash
    docker network inspect inception_network
    ```
*   **Check mounted volumes configuration**:
    ```bash
    docker volume inspect wordpress_data
    docker volume inspect mariadb_data
    docker volume inspect portainer_data
    ```

---

## 4. Data Storage & Persistence Architecture

The project guarantees data persistence through Docker named volumes configured with a local bind mount.

### Physical Host Paths
All database records, website files, and container configurations are saved directly on the host machine under the home directory of the user `jotong`:
*   **MariaDB Database Files**: `/home/jotong/data/mariadb/` (corresponds to `/var/lib/mysql` inside the container)
*   **WordPress Website Files**: `/home/jotong/data/wordpress/` (corresponds to `/var/www/html` shared across `wordpress`, `nginx`, and `ftp` containers)
*   **Portainer Data**: `/home/jotong/data/portainer/` (corresponds to `/data` inside the container)

### Persistence Behavior
*   **Container Restarts / Stops (`make down`, `docker stop`, `docker restart`)**:
    All database records, uploaded WordPress media, and user accounts stored in host directories (`/home/jotong/data/...`) remain **100% preserved**. Stopping or restarting containers does not delete volume contents.
*   **Host Virtual Machine Reboot**:
    Because containers are configured with `restart: always` and named volumes are backed by persistent host paths (`/home/jotong/data/...`), all services automatically resume operation with their data intact when the VM boots up.
*   **Destruction Scenarios (`make clean` vs `make fclean`)**:
    *   `make clean`: Runs `docker compose down --volumes --rmi all` to remove containers, networks, and images. It does **NOT** delete the host data directories under `/home/jotong/data/`.
    *   `make fclean`: Performs `clean` and explicitly deletes `/home/jotong/data/` (via `sudo rm -rf`), permanently destroying database files and uploads to allow a fresh start.

### Restoration (WordPress Files & MariaDB)

#### 1. Restoring WordPress Files (`/home/jotong/data/wordpress`)
1.  Stop the stack:
    ```bash
    make down
    ```
2.  Copy your backup files into the host volume directory:
    ```bash
    sudo cp -r /path/to/wordpress_backup/* /home/jotong/data/wordpress/
    ```
3.  Restore correct ownership permissions for `www-data` (UID 33):
    ```bash
    sudo chown -R 33:33 /home/jotong/data/wordpress
    sudo chmod -R 775 /home/jotong/data/wordpress
    ```
4.  Restart the infrastructure:
    ```bash
    make up
    ```

#### 2. Restoring MariaDB Database
*   **Method A: Restoring from SQL Dump (Recommended)**:
    While the stack is running, import a `.sql` backup file directly into MariaDB:
    ```bash
    docker exec -i mariadb mysql -u wp_db_user -p$(cat secrets/db_password.txt) wordpress < backup.sql
    ```
*   **Method B: Physical Data Directory Restore**:
    1. Stop the stack: `make down`
    2. Replace contents of `/home/jotong/data/mariadb/` with your database backup.
    3. Ensure ownership belongs to MySQL user inside the container:
       ```bash
       sudo chown -R 999:999 /home/jotong/data/mariadb
       ```
    4. Restart the stack: `make up`

---

## 5. Changing Ports & Adding New Services

### How to Change a Port (Example: Changing Adminer Port from 8080 to 8088)
1. Open `srcs/docker-compose.yml`.
2. Locate the `adminer` service definition and update the `ports` mapping:
   ```yaml
   adminer:
     image: adminer
     container_name: adminer
     build:
       context: ./requirements/bonus/adminer
       dockerfile: Dockerfile
     ports:
       - "8088:8080"  # Forward host port 8088 to container port 8080
     networks:
       - inception_network
     depends_on:
       - mariadb
     restart: always
   ```
3. Apply the updated port configuration:
   ```bash
   make up
   ```
4. Access Adminer at the new URL: `http://localhost:8088`.

### How to Add a New Service (and Run It)
1. **Create Service Directory Structure**:
   Create a subfolder under `srcs/requirements/bonus/<new_service>/` containing a `Dockerfile` and any required configuration files or scripts.
2. **Write the Dockerfile**:
   Base the Dockerfile on `debian:bookworm` (penultimate stable Debian), install required packages, expose ports, and set the `ENTRYPOINT`.
3. **Define Service in `srcs/docker-compose.yml`**:
   Add the new service entry under `services:` in `srcs/docker-compose.yml`:
   ```yaml
   my-new-service:
     image: my-new-service
     container_name: my-new-service
     build:
       context: ./requirements/bonus/my-new-service
       dockerfile: Dockerfile
     ports:
       - "7000:7000"
     networks:
       - inception_network
     restart: always
   ```
4. **Build and Launch**:
   Run `make` or `make up` to build the new Docker image and start the container.

---

## 6. Debugging & Useful Commands

### Useful Debugging Commands
*   **Check status of all running containers**:
    ```bash
    make ps
    # or: docker compose -f srcs/docker-compose.yml -p inception ps
    ```
*   **Follow live logs across all services**:
    ```bash
    make logs
    # or: docker compose -f srcs/docker-compose.yml -p inception logs -f
    ```
*   **Check logs for a single container**:
    ```bash
    docker logs wordpress
    docker logs mariadb
    docker logs nginx
    ```
*   **Enter an interactive shell in any container**:
    ```bash
    docker exec -it wordpress /bin/bash
    docker exec -it mariadb /bin/bash
    ```
*   **Inspect bridge network & container IP addresses**:
    ```bash
    docker network inspect inception_network
    ```
*   **Inspect volume configuration & host paths**:
    ```bash
    docker volume inspect wordpress_data
    docker volume inspect mariadb_data
    ```
