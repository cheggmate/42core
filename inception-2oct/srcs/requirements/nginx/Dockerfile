FROM debian:bookworm

# Install NGINX and OpenSSL
RUN apt-get update && apt-get install -y --no-install-recommends \
    nginx \
    openssl \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Copy configuration directly to conf.d and sites-enabled
COPY conf/nginx.conf /etc/nginx/conf.d/default.conf
COPY conf/nginx.conf /etc/nginx/sites-available/default
RUN mkdir -p /etc/nginx/sites-enabled && \
    ln -sf /etc/nginx/sites-available/default /etc/nginx/sites-enabled/default
COPY tools/nginx_start.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/nginx_start.sh

# Make entrypoint executable
RUN chmod +x /usr/local/bin/nginx_start.sh

# Expose port 443 for TLS connections
EXPOSE 443

ENTRYPOINT ["/usr/local/bin/nginx_start.sh"]
