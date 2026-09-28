*This project has been created as part of the 42 curriculum by jotong.*

# Inception

## Description

The Inception project is a system administration exercise designed to introduce containerization and multi-container infrastructure orchestration using Docker. The goal of this project is to set up a fully-functional, secure, and isolated web server environment composed of three distinct services: NGINX (serving as the secure entry point via TLS), WordPress (driven by PHP-FPM), and MariaDB (storing all persistent WordPress database information).

Each service runs in a dedicated container, built using customized Dockerfiles from the penultimate stable version of Debian (Debian 12 Bookworm). The services communicate securely over a custom bridge network, and persist data using Docker named volumes mapped to specific directories on the host machine.

### Design Choices & Infrastructure Comparisons

#### Virtual Machines vs Docker
*   **Virtual Machines (VMs)**: Virtualize physical hardware. Each VM includes a complete guest operating system, virtual drivers, and virtual hardware. This introduces high resource overhead (CPU, RAM, disk space) and slower start times, but provides strong kernel-level isolation.
*   **Docker (Containers)**: Virtualize the operating system kernel. Multiple containers share the host operating system's kernel while remaining isolated in user space (using Linux namespaces and cgroups). Containers are extremely lightweight, start in seconds, and have minimal resource overhead.
*   *Design Choice*: Docker was chosen because it allows rapid deployment, microservice scaling, and precise control over the filesystem and networking using minimal system resources.

#### Secrets vs Environment Variables
*   **Environment Variables**: Stored in process environments. They are easy to set up but are often visible in command outputs (e.g., `docker inspect`), container logs, and process listings. Committing environment files containing passwords to version control exposes them publicly.
*   **Docker Secrets**: Stored outside of the container's image or run-time environment. Secrets are mounted dynamically in-memory (`tmpfs`) at `/run/secrets/<secret_name>` only to the containers that explicitly require them. They are never written to disk within the container.
*   *Design Choice*: Sensitive credentials (MariaDB root password, database user password, WordPress administrative credentials) are managed using Docker Secrets to comply with security best practices and prevent accidental repository leaks. Non-sensitive configurations (database name, domain name, website title) are stored in the `.env` file.

#### Docker Network vs Host Network
*   **Host Network**: The container shares the host network namespace directly. The container does not get its own IP address, and ports are bound directly to the host's interfaces. This offers high performance but lacks isolation and can lead to port conflicts.
*   **Docker Network (Bridge)**: A private, isolated network created on the host. Containers connected to this network can communicate with each other using container names as hostnames (via Docker's internal DNS), while remaining unreachable from the external host unless ports are explicitly forwarded.
*   *Design Choice*: A custom bridge network (`inception_network`) is defined. Only the NGINX container exposes its port (443) to the host. MariaDB (3306) and WordPress (9000) are kept entirely inside the isolated bridge network, preventing direct external access.

#### Docker Volumes vs Bind Mounts
*   **Bind Mounts**: Reference a specific absolute path on the host machine directly. This creates tight coupling between the container and the host file structure, and can cause permission mismatches between the host user and the container user.
*   **Docker Volumes**: Managed directly by Docker. The storage is decoupled from the specific host filesystem configuration, and Docker manages directory creation, ownership, and performance optimization.
*   *Design Choice*: Docker named volumes are used with local driver options pointing to `/home/jotong/data/` on the host. This achieves the persistence requirements of storing data at a specific path while maintaining the container portability of named volumes.

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
    *Note: The Makefile will automatically create the required directories `/home/jotong/data/wordpress` and `/home/jotong/data/mariadb`, and generate default credentials in the `secrets/` directory and `srcs/.env` if they do not already exist.*

### Managing the Stack
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

> **Inception Implementation:** > Instead of wasting cluster resources running three heavy, separate operating systems, this project utilizes native Linux containers. This isolates our microservices (NGINX, WordPress, MariaDB) while keeping the host footprint lightweight and efficient.

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
## Resources

### Reference Documentation
*   [Docker Documentation](https://docs.docker.com/)
*   [Docker Compose File Reference](https://docs.docker.com/compose/compose-file/compose-file-v3/)
*   [NGINX SSL/TLS Configuration Guide](https://nginx.org/en/docs/http/configuring_https_servers.html)
*   [WordPress Command Line Interface (WP-CLI)](https://wp-cli.org/)
*   [MariaDB Server Documentation](https://mariadb.com/kb/en/documentation/)

### AI Usage Disclosure
Generative AI was used to learn about containerization and the configuration parameters of Docker.
