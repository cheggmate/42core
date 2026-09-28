FROM debian:bookworm

# Install PHP and extensions, plus curl and mariadb-client
RUN apt-get update && apt-get install -y --no-install-recommends \
    php-fpm \
    php-mysql \
    php-curl \
    php-gd \
    php-intl \
    php-mbstring \
    php-soap \
    php-xml \
    php-xmlrpc \
    php-zip \
    mariadb-client \
    curl \
    ca-certificates \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Install WP-CLI
RUN curl -o /usr/local/bin/wp https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x /usr/local/bin/wp

# Copy configuration and automatically place in active PHP pool directory
COPY conf/www.conf /tmp/www.conf
RUN PHP_VER=$(ls /etc/php | head -n 1) && mkdir -p /etc/php/${PHP_VER}/fpm/pool.d/ && cp /tmp/www.conf /etc/php/${PHP_VER}/fpm/pool.d/www.conf
COPY tools/wordpress_start.sh /usr/local/bin/

# Make script executable
RUN chmod +x /usr/local/bin/wordpress_start.sh

# Expose port 9000
EXPOSE 9000

# Set workspace directory
WORKDIR /var/www/html

ENTRYPOINT ["/usr/local/bin/wordpress_start.sh"]
