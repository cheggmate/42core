*This project has been created as part of the 42 curriculum by jotong.*

# Inception

## Description

The Inception project is a system administration exercise designed to introduce containerization and multi-container infrastructure orchestration using Docker. The goal of this project is to set up a fully-functional, secure, and isolated web server environment composed of core services: NGINX (serving as the secure entry point via TLS), WordPress (driven by PHP-FPM), and MariaDB (storing all persistent WordPress database information), alongside bonus services: an FTP server (VSFTPD) pointing to the WordPress volume, Redis cache, Adminer (database management web interface), Portainer (visual container management dashboard), and a Static Showcase Website (built without PHP).

Each service runs in a dedicated container, built using customized Dockerfiles from the penultimate stable version of Debian (Debian 12 Bookworm). The services communicate securely over a custom bridge network, and persist data using Docker named volumes mapped to specific directories on the host machine.

### Design Choices & Infrastructure Comparisons

#### Virtual Machines vs Docker
*   **Virtual Machines (VMs)**: Virtualize physical hardware. Each VM includes a complete guest operating system, virtual drivers, and virtual hardware. This introduces high resource overhead (CPU, RAM, disk space) and slower start times, but provides strong kernel-level isolation.
*   **Docker (Containers)**: Virtualize the operating system kernel. Multiple containers share the host operating system's kernel while remaining isolated in user space (using Linux namespaces and cgroups). Containers are extremely lightweight, start in seconds, and have minimal resource overhead.
*   *Design Choice*: Docker was chosen because it allows rapid deployment, microservice scaling, and precise control over the filesystem and networking using minimal system resources.

#### Secrets vs Environment Variables
*   **Environment Variables**: Stored in process environments. They are easy to set up but are often visible in command outputs (e.g., `docker inspect`), container logs, and process listings. Committing environment files containing passwords to version control exposes them publicly.
*   **Docker Secrets**: Stored outside of the container's image or run-time environment. Secrets are mounted dynamically in-memory (`tmpfs`) at `/run/secrets/<secret_name>` only to the containers that explicitly require them. They are never written to disk within the container.
*   *Design Choice*: Sensitive credentials (MariaDB root password, database user password, WordPress administrative credentials, FTP password) are managed using Docker Secrets to comply with security best practices and prevent accidental repository leaks. Non-sensitive configurations (database name, domain name, website title, FTP username) are stored in the `.env` file.

#### Docker Network vs Host Network
*   **Host Network**: The container shares the host network namespace directly. The container does not get its own IP address, and ports are bound directly to the host's interfaces. This offers high performance but lacks isolation and can lead to port conflicts.
*   **Docker Network (Bridge)**: A private, isolated network created on the host. Containers connected to this network can communicate with each other using container names as hostnames (via Docker's internal DNS), while remaining unreachable from the external host unless ports are explicitly forwarded.
*   *Design Choice*: A custom bridge network (`inception_network`) is defined. NGINX exposes port 443 for web traffic, FTP exposes port 21 (control) and 21100-21110 (passive data), Adminer exposes port 8080, Portainer exposes port 9000, and Static-Site exposes port 8081 to the host. MariaDB (3306), WordPress (9000), and Redis (6379) are kept inside the isolated bridge network.

#### Docker Volumes vs Bind Mounts
*   **Bind Mounts**: Reference a specific absolute path on the host machine directly. This creates tight coupling between the container and the host file structure, and can cause permission mismatches between the host user and the container user.
*   **Docker Volumes**: Managed directly by Docker. The storage is decoupled from the specific host filesystem configuration, and Docker manages directory creation, ownership, and performance optimization.
*   *Design Choice*: Docker named volumes are used with local driver options pointing to `/home/jotong/data/` on the host (`wordpress_data`, `mariadb_data`, `portainer_data`). This achieves the persistence requirements of storing data at a specific path while maintaining the container portability of named volumes.

---

## Instructions

### Prerequisites
*   A Linux host machine (tested on Debian/Ubuntu).
*   Docker and Docker Compose installed.
*   `sudo` privileges (to create and write data to `/home/jotong/data/`).

### Setup & Execution
1.  Clone this repository to your host machine.
2.  Navigate to the root of the project directory.
3.  Add the domain name redirect to your host's `/etc/hosts` file:
    ```bash
    echo "127.0.0.1 jotong.42.fr" | sudo tee -a /etc/hosts
    ```
4.  Run the Makefile to build and start the infrastructure:
    ```bash
    make
    ```
    *Note: The Makefile will automatically create the required directories `/home/jotong/data/wordpress`, `/home/jotong/data/mariadb`, and `/home/jotong/data/portainer`, and generate default credentials in the `secrets/` directory and `srcs/.env` if they do not already exist.*

### Managing the Stack
*   **Check Status of Running Containers**:
    ```bash
    make ps
    ```
*   **Follow Live Logs Across All Containers**:
    ```bash
    make logs
    ```
*   **Stop the infrastructure** (without deleting data):
    ```bash
    make down
    ```
*   **Clean the infrastructure** (stops containers, removes volumes and networks):
    ```bash
    make clean
    ```
*   **Full Clean** (performs `clean` and deletes the data directories `/home/jotong/data/` and credentials):
    ```bash
    make fclean
    ```
*   **Rebuild and Restart**:
    ```bash
    make re
    ```

## Project Description

This section breaks down the foundational concepts and technical design choices implemented throughout the **Inception** infrastructure.

---

### 📦 Virtual Machines vs. Docker Containers

| Feature | Virtual Machines (VMs) | Docker Containers |
| :--- | :--- | :--- |
| **Architecture** | Runs a complete Guest OS on top of a Hypervisor. | Shares the Host OS kernel; isolated via namespaces/cgroups. |
| **Overhead** | High (GBs of storage, dedicated RAM/CPU allocation). | Extremely low (MBs of storage, dynamic resource usage). |
| **Boot Time** | Minutes (requires full OS boot sequence). | Milliseconds (starts instantly as a native process). |

> **Inception Implementation:**
> Instead of wasting cluster resources running separate heavy operating systems, this project utilizes native Linux containers. This isolates our microservices (NGINX, WordPress, MariaDB, Redis, FTP, Adminer, Portainer) while keeping the host footprint lightweight and efficient.

---

### 🔑 Secrets vs. Environment Variables

* **Environment Variables (`.env`)**
    * **Characteristics:** Injected into the container environment as plain text. 
    * **Risk:** Highly visible via commands like `docker inspect` or `env` inside the terminal logs, making them unsafe for cryptographic keys.
    * **Use Case:** Ideal for non-sensitive structural configuration parameters (e.g., `SQL_DATABASE_NAME`, `DOMAIN_NAME`).

* **Docker Secrets (`/run/secrets/`)**
    * **Characteristics:** Mounted strictly at runtime as read-only, in-memory files. The application reads strings directly from a file path rather than the environment matrix.
    * **Risk:** Safe from environment inspection leaks and image history exposure.
    * **Use Case:** Mandated for all high-risk credentials (e.g., `db_root_password`, `db_password`).

---

### 🌐 Docker Network (Bridge) vs. Host Network

* **Host Networking:** The container bypasses Docker's network isolation entirely, binding its ports directly to the host machine's interfaces. This exposes internal service ports to the outside world, creating a significant security vulnerability.
* **Docker Custom Bridge Network:** Creates an isolated virtual network local to the Docker daemon. Containers communicate safely using their service names as hostnames via Docker’s internal automatic DNS resolver.

---

### 🛠️ Service of Choice Justification: Portainer

As permitted in the bonus part of the subject, **Portainer** was selected as the custom bonus service of choice. Here is the rationale and justification for its inclusion in this multi-container web stack:

1. **Centralized Infrastructure Monitoring & Management**:
   In a multi-service container environment consisting of 7 distinct microservices (NGINX, WordPress, MariaDB, Redis, VSFTPD, Adminer, and Portainer), monitoring system health, CPU/RAM resource usage, container statuses, and runtime logs across individual CLI commands (`docker ps`, `docker logs`) can be tedious. Portainer provides a real-time, web-based graphical user interface (GUI) dashboard that centralizes the monitoring and status of all containers in one place.

2. **DevOps Lifecycle & Resource Inspection**:
   Portainer connects directly to the host's Docker daemon via `/var/run/docker.sock`. This allows developers and peer evaluators to visually inspect active Docker networks (`inception_network`), verify persistent volume bindings (`wordpress_data`, `mariadb_data`, `portainer_data`), inspect container environment variables, and review real-time process logs without needing root terminal access.

3. **Built from Base OS (Subject Compliance)**:
   In strict compliance with the subject rules forbidding pre-built DockerHub images, Portainer is compiled inside a custom Dockerfile built from `debian:bookworm` (penultimate stable Debian), downloading and running the standalone Portainer Community Edition binary.

---

## Resources

### Reference Documentation
*   [Docker Documentation](https://docs.docker.com/)
*   [Docker Compose File Reference](https://docs.docker.com/compose/compose-file/compose-file-v3/)
*   [NGINX SSL/TLS Configuration Guide](https://nginx.org/en/docs/http/configuring_https_servers.html)
*   [WordPress Command Line Interface (WP-CLI)](https://wp-cli.org/)
*   [MariaDB Server Documentation](https://mariadb.com/kb/en/documentation/)
*   [Adminer Documentation](https://www.adminer.org/)
*   [Portainer Documentation](https://docs.portainer.io/)

### AI Usage Disclosure
Generative AI was used to learn about containerization and the configuration parameters of Docker.
