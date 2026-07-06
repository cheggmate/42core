FROM debian:bullseye

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

# Copy configurations
COPY conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf
COPY tools/wordpress_start.sh /usr/local/bin/

# Make script executable
RUN chmod +x /usr/local/bin/wordpress_start.sh

# Expose port 9000
EXPOSE 9000

# Set workspace directory
WORKDIR /var/www/html

ENTRYPOINT ["/usr/local/bin/wordpress_start.sh"]
