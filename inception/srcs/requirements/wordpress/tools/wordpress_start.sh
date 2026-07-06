#!/bin/bash
# Exit immediately if a command exits with a non-zero status
set -e

# Load credentials from docker secrets
if [ -f /run/secrets/credentials ]; then
    echo "Loading WordPress credentials from secret..."
    . /run/secrets/credentials
else
    echo "Error: Credentials secret not found!" >&2
    exit 1
fi

# Load DB password from secret
if [ -f /run/secrets/db_password ]; then
    DB_PASS=$(cat /run/secrets/db_password)
else
    echo "Error: Database password secret not found!" >&2
    exit 1
fi

# Wait for MariaDB service to be fully up and ready
echo "Checking MariaDB connection..."
until mysql -h"mariadb" -u"${SQL_USER}" -p"${DB_PASS}" -e "show databases;" >/dev/null 2>&1; do
    echo "Waiting for MariaDB to start..."
    sleep 2
done
echo "MariaDB is ready."

# Check if WordPress is already installed
if [ ! -f /var/www/html/wp-config.php ]; then
    echo "WordPress not found. Performing fresh installation..."
    
    # Download WordPress core
    wp core download --allow-root --path=/var/www/html

    # Create wp-config.php
    wp config create --allow-root \
        --dbname="${SQL_DATABASE}" \
        --dbuser="${SQL_USER}" \
        --dbpass="${DB_PASS}" \
        --dbhost="mariadb:3306" \
        --path="/var/www/html"

    # Install WordPress site
    wp core install --allow-root \
        --url="${DOMAIN_NAME}" \
        --title="${WP_TITLE}" \
        --admin_user="${WP_ADMIN_USER}" \
        --admin_password="${WP_ADMIN_PASSWORD}" \
        --admin_email="${WP_ADMIN_EMAIL}" \
        --path="/var/www/html"

    # Create a secondary user (author) as required by subject (two users, admin not named admin)
    wp user create --allow-root \
        "${WP_USER}" "${WP_USER_EMAIL}" \
        --role=author \
        --user_pass="${WP_USER_PASSWORD}" \
        --path="/var/www/html"
    
    echo "WordPress installation complete."
fi

# Ensure correct permissions on the files
chown -R www-data:www-data /var/www/html

# Create the php run directory
mkdir -p /run/php

echo "Starting PHP-FPM..."
exec php-fpm7.4 -F
