FROM debian:bookworm

# Install MariaDB server and client
RUN export DEBIAN_FRONTEND=noninteractive \
    && apt-get update \
    && apt-get install -y --no-install-recommends \
    mariadb-server \
    mariadb-client \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Copy configurations and entrypoint scripts
COPY conf/my.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY tools/mariadb_start.sh /usr/local/bin/

# Make entrypoint script executable
RUN chmod +x /usr/local/bin/mariadb_start.sh

# Expose port 3306 for SQL connections
EXPOSE 3306

ENTRYPOINT ["/usr/local/bin/mariadb_start.sh"]
