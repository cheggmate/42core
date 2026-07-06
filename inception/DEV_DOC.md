# Developer Documentation

This document explains the technical architecture, development workflows, container details, and data lifecycle management for the Inception stack.

---

## 1. Setting Up the Environment from Scratch

### Prerequisites
Before developing, make sure the host operating system meets the following requirements:
*   **Operating System**: Linux (Debian Bullseye/Bookworm or Ubuntu 20.04+ recommended).
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

*Note: Any additions to configuration variables must be mirrored in `srcs/.env.example`.*

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
*   **Dockerfiles**: Built from `debian:bullseye`. Avoid using the `latest` tag in any Dockerfile.
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
    ```

### Troubleshooting Database Connection
To verify that WordPress can query MariaDB directly from its container:
```bash
docker exec -it wordpress mysql -h mariadb -u wp_db_user -p$(cat /run/secrets/db_password) -e "SHOW DATABASES;"
```

---

## 4. Data Storage & Persistence Architecture

The project guarantees data persistence through Docker named volumes configured with a local bind mount.

### Physical Host Paths
All database records and file uploads are saved directly on the host machine under the home directory of the user `jotong`:
*   **MariaDB Database Files**: `/home/jotong/data/mariadb/` (corresponds to `/var/lib/mysql` inside the container)
*   **WordPress Website Files**: `/home/jotong/data/wordpress/` (corresponds to `/var/www/html` inside the container)

### Lifecycle of the Storage Directories
1.  **Creation**: The directory paths on the host are created during `make setup` via `mkdir -p`.
2.  **Mounting**: When the containers boot, Docker mounts these host paths directly into the container filesystems.
3.  **Permissions**:
    *   WordPress runs as `www-data` (UID 33). The entrypoint script `wordpress_start.sh` automatically forces ownership of `/var/www/html` to `www-data:www-data` to prevent permissions errors.
    *   MariaDB runs as the `mysql` user (UID 106). Ownership of `/var/lib/mysql` is set to `mysql:mysql` on startup.
4.  **Destruction**: Running `make clean` does **not** delete the host data directories. To completely remove the persistent data and start with a clean slate, run:
    ```bash
    make fclean
    ```
