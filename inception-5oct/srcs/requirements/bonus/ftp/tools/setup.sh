#!/bin/bash
set -e

# Load credentials from docker secrets if available
if [ -f /run/secrets/credentials ]; then
    echo "Loading FTP credentials from secret..."
    . /run/secrets/credentials
fi

# Fallback values if environment/secret variables are missing
FTP_USER="${FTP_USER:-${WP_USER:-ftpuser}}"
FTP_PASSWORD="${FTP_PASSWORD:-${WP_USER_PASSWORD:-ftppass123}}"

echo "Configuring FTP user: ${FTP_USER}"

# Create the FTP user if it does not already exist
if ! id "${FTP_USER}" >/dev/null 2>&1; then
    # Create system user with home directory set to /var/www/html
    useradd -m -d /var/www/html -s /bin/bash "${FTP_USER}"
    echo "${FTP_USER}:${FTP_PASSWORD}" | chpasswd
    # Add user to www-data group so it shares ownership of WordPress files
    usermod -aG www-data "${FTP_USER}"
else
    # Update password if user already exists
    echo "${FTP_USER}:${FTP_PASSWORD}" | chpasswd
fi

# Ensure vsftpd secure chroot directory exists
mkdir -p /var/run/vsftpd/empty

# Ensure WordPress directory permissions allow ftp user and www-data access
if [ -d /var/www/html ]; then
    chown -R www-data:www-data /var/www/html
    chmod -R 775 /var/www/html
fi

echo "Starting VSFTPD server..."
exec /usr/sbin/vsftpd /etc/vsftpd.conf
