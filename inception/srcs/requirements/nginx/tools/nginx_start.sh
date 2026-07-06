#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

if [ ! -f /etc/ssl/certs/nginx-selfsigned.crt ]; then
    echo "Creating self-signed TLS certificate for jotong.42.fr..."
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
        -keyout /etc/ssl/private/nginx-selfsigned.key \
        -out /etc/ssl/certs/nginx-selfsigned.crt \
        -subj "/C=FR/ST=Paris/L=Paris/O=42/OU=42/CN=jotong.42.fr"
fi

echo "Running NGINX in foreground..."
exec nginx -g "daemon off;"
