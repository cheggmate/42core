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

### Troubleshooting Database, FTP, Adminer, Portainer, & Static-Site
*   **Verify Database connection from WordPress**:
    ```bash
    docker exec -it wordpress mysql -h mariadb -u wp_db_user -p$(cat /run/secrets/db_password) -e "SHOW DATABASES;"
    ```

*   **Test FTP Server File Retrieval**:
    ```bash
    curl -v -u jotong_ftp:ftp_pass_12345 ftp://127.0.0.1:21/
    ```

*   **Test FTP Server File Upload**:
    ```bash
    echo "FTP Upload Test" > test.txt
    curl -u jotong_ftp:ftp_pass_12345 -T test.txt ftp://127.0.0.1:21/
    ```

*   **Test Adminer Web Interface Availability**:
    ```bash
    curl -I http://127.0.0.1:8080
    ```

*   **Test Portainer Dashboard Availability**:
    ```bash
    curl -I http://127.0.0.1:9000
    ```

*   **Test Static Showcase Website Availability**:
    ```bash
    curl -I http://127.0.0.1:8081
    ```

---

## 4. Data Storage & Persistence Architecture

The project guarantees data persistence through Docker named volumes configured with a local bind mount.

### Physical Host Paths
All database records, website files, and container configurations are saved directly on the host machine under the home directory of the user `jotong`:
*   **MariaDB Database Files**: `/home/jotong/data/mariadb/` (corresponds to `/var/lib/mysql` inside the container)
*   **WordPress Website Files**: `/home/jotong/data/wordpress/` (corresponds to `/var/www/html` shared across `wordpress`, `nginx`, and `ftp` containers)
*   **Portainer Data**: `/home/jotong/data/portainer/` (corresponds to `/data` inside the container)

### Special Volume & Socket Mounts
*   **Portainer Socket Mount**: Mounts `/var/run/docker.sock:/var/run/docker.sock` to enable Portainer to communicate directly with the host's Docker daemon for real-time container monitoring and management.
*   **Shared Volume Access & Permissions (`wordpress_data`)**:
    *   Mounted simultaneously in `wordpress`, `nginx`, and `ftp`.
    *   WordPress & NGINX execute as `www-data` (UID 33).
    *   The FTP container creates `FTP_USER` with home directory `/var/www/html` and adds it to the `www-data` group (`umask 002` / `775` permissions).

### Lifecycle of the Storage Directories
1.  **Creation**: The directory paths on the host are created during `make setup` via `mkdir -p`.
2.  **Mounting**: When the containers boot, Docker mounts these host paths directly into the container filesystems.
3.  **Destruction**: Running `make clean` does **not** delete the host data directories. To completely remove the persistent data and start with a clean slate, run:
    ```bash
    make fclean
    ```
