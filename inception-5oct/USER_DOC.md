# User Documentation

This guide provides simple, step-by-step instructions for end users and administrators to manage and interact with the Inception web infrastructure stack.

---

## 1. Services Provided by the Stack

The stack is composed of interconnected services working together to serve a secure WordPress website:

1.  **NGINX (Web Server)**: The gateway to the infrastructure. It listens on port 443 (HTTPS) only, encrypting all communication using TLSv1.2 or TLSv1.3. It forwards dynamic PHP requests to WordPress and serves static files directly.
2.  **WordPress (Content Management System)**: Runs the website logic using PHP-FPM. It handles content rendering, user posts, and administrative dashboards.
3.  **MariaDB (Database)**: Stores all persistent data for the WordPress site, including user accounts, post content, comments, and configuration settings.
4.  **FTP Server (VSFTPD - Bonus Service)**: Provides direct FTP file upload and management capabilities pointing directly to the WordPress website volume (`/var/www/html`) on port 21 (control) and ports 21100-21110 (passive data).
5.  **Redis (Cache - Bonus Service)**: In-memory object caching system that speeds up WordPress query responses and page loads.
6.  **Adminer (Database Manager - Bonus Service)**: Lightweight, full-featured web-based database administration dashboard running on port 8080.
7.  **Portainer (Container Management Dashboard - Bonus Service)**: Web-based graphical interface running on port 9000 that allows administrators to monitor container health, inspect live process logs, view network graphs, and manage the Docker stack.
8.  **Static Showcase Website (Bonus Service)**: Non-PHP static HTML5/CSS3 developer portfolio website served via Python HTTP server on port 8081.

---

## 2. Starting and Stopping the Project

All container lifecycle tasks are controlled using the `Makefile` in the project root:

*   **To Start the Stack**:
    ```bash
    make
    ```
    This initializes the persistent directories on the host, configures credentials, builds the container images, and starts the services in the background.

*   **To Stop the Stack** (without deleting content):
    ```bash
    make down
    ```
    This pauses the services and stops the containers. Your data is kept safe in the volumes.

*   **To Stop and Destroy Everything** (including database volumes):
    ```bash
    make fclean
    ```
    *Warning: This will delete your website's database, uploaded files, and reset all credentials.*

---

## 3. Accessing Services (Website, Admin Panel, FTP, Adminer, Portainer, & Static Site)

### Accessing the Frontend (Public Site)
Open your web browser and navigate to:
*   [https://jotong.42.fr](https://jotong.42.fr)

*Note: Because the site uses a self-signed TLS certificate, your browser will display a certificate warning (e.g., "Your connection is not private"). This is normal for development. You can bypass this warning (click "Advanced" -> "Proceed to jotong.42.fr").*

### Accessing the Admin Dashboard (WordPress Backoffice)
To log in and manage the website:
1.  Navigate to [https://jotong.42.fr/wp-admin](https://jotong.42.fr/wp-admin).
2.  Enter the administrator credentials from `secrets/credentials.txt`.

### Accessing Adminer (Database Management Interface)
To manage the MariaDB database visually from your browser:
1.  Navigate to `http://jotong.42.fr:8080`.
2.  Fill in the login form with the following details:
    *   **System**: `MySQL`
    *   **Server**: `mariadb` *(use the internal container hostname)*
    *   **Username**: `wp_db_user` *(or `root` for administrative access)*
    *   **Password**: password from `secrets/db_password.txt` *(or `secrets/db_root_password.txt`)*
    *   **Database**: `wordpress`

### Accessing Portainer (Visual Container Management Dashboard)
To visually monitor container health, view live process logs, and inspect volumes/networks:
1.  Navigate to `http://jotong.42.fr:9000`.
2.  Upon first connection, create your administrator username and password (12+ characters).
3.  Select the **Get Started** option to connect to the local Docker environment (`/var/run/docker.sock`).
4.  You can now view live dashboards of all running containers.

### Accessing the Static Showcase Website
To view the developer portfolio and infrastructure showcase (built without PHP):
1. Open your web browser and navigate to `http://jotong.42.fr:8081`.

### Accessing the FTP Server (File Management)
To upload, download, or edit files inside your WordPress website volume via FTP:
*   **Host**: `127.0.0.1` (or `jotong.42.fr`)
*   **Port**: `21`
*   **Passive Ports**: `21100-21110`
*   **Username**: `defined in `srcs/.env` / `secrets/credentials.txt`
*   **Password**: `defined in `secrets/credentials.txt`

#### Connecting via Command Line (FTP Client or Curl):
```bash
# Using standard FTP client (Passive Mode):
ftp -p 127.0.0.1 21

# Listing directory contents using Curl:
curl -u jotong_ftp:ftp_pass_12345 ftp://127.0.0.1:21/

# Uploading a file using Curl:
curl -u jotong_ftp:ftp_pass_12345 -T myfile.txt ftp://127.0.0.1:21/
```

---

## 4. Locating and Managing Credentials

To maintain security, credentials are not hardcoded. They are stored in two locations at the root of the project:

1.  **Database Credentials**:
    *   `secrets/db_password.txt`: Holds the password for the database user `wp_db_user`.
    *   `secrets/db_root_password.txt`: Holds the administrator (root) password for the MariaDB database.
2.  **WordPress & Service Credentials**:
    *   `secrets/credentials.txt`: Contains variables defining the site administrator, regular user, and FTP credentials. 
        *   `WP_ADMIN_USER` / `WP_ADMIN_PASSWORD` (used to log into `/wp-admin`)
        *   `WP_USER` / `WP_USER_PASSWORD` (secondary author user)
        *   `FTP_USER` / `FTP_PASSWORD` (used to log into the FTP server)

### Changing Credentials
To change passwords before starting the stack, modify the text files in the `secrets/` directory. If the stack is already running, run `make down` to stop the stack, modify the secrets, (if there is a need to remove existing data, do `make fclean`) and then run `make` to reinitialize the stack with the new passwords.

---

## 5. Checking that Services are Running Correctly

You can inspect the status of the infrastructure using Makefile commands or standard Docker commands:

*   **Verify Container Status**:
    ```bash
    make ps
    # or: docker ps
    ```
    You should see running containers named `nginx`, `wordpress`, `mariadb`, `redis`, `ftp`, `adminer`, `portainer`, and `static-site`. Their statuses should display `Up` (e.g., `Up 5 minutes`).

*   **Inspect Service Logs**:
    If a service does not function properly, follow real-time logs across all containers:
    ```bash
    make logs
    # or: docker compose -f srcs/docker-compose.yml -p inception logs -f
    ```
    Or check individual container logs:
    ```bash
    docker logs static-site
    docker logs portainer
    docker logs adminer
    docker logs ftp
    docker logs wordpress
    ```
