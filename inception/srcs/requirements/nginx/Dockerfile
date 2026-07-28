FROM debian:bullseye

# Install NGINX and OpenSSL
RUN apt-get update && apt-get install -y --no-install-recommends \
    nginx \
    openssl \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Copy configuration and tools
COPY conf/nginx.conf /etc/nginx/sites-available/default
COPY tools/nginx_start.sh /usr/local/bin/

# Make entrypoint executable
RUN chmod +x /usr/local/bin/nginx_start.sh

# Expose port 443 for TLS connections
EXPOSE 443

ENTRYPOINT ["/usr/local/bin/nginx_start.sh"]
