# User Documentation

This guide provides simple, step-by-step instructions for end users and administrators to manage and interact with the Inception web infrastructure stack.

---

## 1. Services Provided by the Stack

The stack is composed of three interconnected services working together to serve a secure WordPress website:

1.  **NGINX (Web Server)**: The gateway to the infrastructure. It listens on port 443 (HTTPS) only, encrypting all communication using TLSv1.2 or TLSv1.3. It forwards dynamic PHP requests to WordPress and serves static files directly.
2.  **WordPress (Content Management System)**: Runs the website logic using PHP-FPM. It handles content rendering, user posts, and administrative dashboards.
3.  **MariaDB (Database)**: Stores all persistent data for the WordPress site, including user accounts, post content, comments, and configuration settings.

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

## 3. Accessing the Website and Administration Panel

Before accessing the site, you must add `jotong.42.fr` to your local host resolution file `/etc/hosts`:
```bash
# Run this on the machine you are browsing from (your host or VM)
127.0.0.1 jotong.42.fr
```

### Accessing the Frontend (Public Site)
Open your web browser and navigate to:
*   [https://jotong.42.fr](https://jotong.42.fr)

*Note: Because the site uses a self-signed TLS certificate, your browser will display a certificate warning (e.g., "Your connection is not private"). This is normal for development. You can bypass this warning (click "Advanced" -> "Proceed to jotong.42.fr").*

### Accessing the Admin Dashboard (WordPress Backoffice)
To log in and manage the website:
1.  Navigate to [https://jotong.42.fr/wp-admin](https://jotong.42.fr/wp-admin).
2.  Enter the administrator credentials.

---

## 4. Locating and Managing Credentials

To maintain security, credentials are not hardcoded. They are stored in two locations at the root of the project:

1.  **Database Credentials**:
    *   `secrets/db_password.txt`: Holds the password for the database user `wp_db_user`.
    *   `secrets/db_root_password.txt`: Holds the administrator (root) password for the MariaDB database.
2.  **WordPress User Credentials**:
    *   `secrets/credentials.txt`: Contains variables defining the WordPress site administrator and regular user details.
        *   `WP_ADMIN_USER` / `WP_ADMIN_PASSWORD` (used to log into `/wp-admin`)
        *   `WP_USER` / `WP_USER_PASSWORD` (secondary author user)

### Changing Credentials
To change passwords before starting the stack, modify the text files in the `secrets/` directory. If the stack is already running, run `make fclean`, modify the secrets, and then run `make` to initialize the database with the new passwords.

---

## 5. Checking that Services are Running Correctly

You can inspect the status of the infrastructure with standard Docker commands:

*   **Verify Container Status**:
    ```bash
    docker ps
    ```
    You should see three running containers named `nginx`, `wordpress`, and `mariadb`. Their statuses should display `Up` (e.g., `Up 5 minutes`).

*   **Inspect Service Logs**:
    If the website does not load, you can check the process logs of all containers:
    ```bash
    docker compose -f srcs/docker-compose.yml logs -f
    ```
    Or check a single container's logs (e.g., WordPress):
    ```bash
    docker logs wordpress
    ```
