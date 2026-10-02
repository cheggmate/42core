#!/bin/bash
set -e

mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld
mkdir -p /var/log/mysql
chown -R mysql:mysql /var/log/mysql

# 1. Initialize data directory system tables if fresh
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Preregistering system schemas..."
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
fi

DB_ROOT_PASS=$(cat /run/secrets/db_root_password)
DB_PASS=$(cat /run/secrets/db_password)

echo "Generating temporary configuration parameters..."
INIT_FILE="/tmp/mariadb_init.sql"
cat << EOF > "$INIT_FILE"
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASS}';
CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;
CREATE USER IF NOT EXISTS '${SQL_USER}'@'%' IDENTIFIED BY '${DB_PASS}';
GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO '${SQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

chown mysql:mysql "$INIT_FILE"

echo "Launching primary database process in foreground..."
exec mysqld --user=mysql --bind-address=0.0.0.0 --init-file="$INIT_FILE"