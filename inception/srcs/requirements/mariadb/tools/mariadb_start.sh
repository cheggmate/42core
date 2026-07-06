#!/bin/bash
# Exit immediately if a command exits with a non-zero status
set -e

# Ensure mysqld directory exists and has correct permissions
mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld
chown -R mysql:mysql /var/lib/mysql

# Check if database is already initialized
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "First time database setup..."
    mysql_install_db --user=mysql --datadir=/var/lib/mysql

    # Read sensitive information from mounted secrets
    DB_ROOT_PASS=$(cat /run/secrets/db_root_password)
    DB_PASS=$(cat /run/secrets/db_password)

    # Start MariaDB in temporary safe mode (no networking to protect it)
    mysqld_safe --skip-networking &
    PID=$!

    # Wait for the MariaDB daemon to start
    until mysqladmin ping --silent; do
        sleep 1
    done

    # Run SQL statements to configure database, root account, and user account
    mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASS}';"
    mysql -u root -p"${DB_ROOT_PASS}" -e "CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;"
    mysql -u root -p"${DB_ROOT_PASS}" -e "CREATE USER IF NOT EXISTS '${SQL_USER}'@'%' IDENTIFIED BY '${DB_PASS}';"
    mysql -u root -p"${DB_ROOT_PASS}" -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO '${SQL_USER}'@'%';"
    mysql -u root -p"${DB_ROOT_PASS}" -e "FLUSH PRIVILEGES;"

    # Stop temporary database daemon
    mysqladmin -u root -p"${DB_ROOT_PASS}" shutdown
    wait $PID
fi

echo "Starting MariaDB service..."
exec mysqld --user=mysql
