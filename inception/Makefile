NAME = inception

all: setup build up

setup:
	@mkdir -p /home/jotong/data/wordpress
	@mkdir -p /home/jotong/data/mariadb
	@mkdir -p secrets
# 	@if [ ! -f secrets/db_password.txt ]; then echo "wp_db_pass_12345" > secrets/db_password.txt; fi
# 	@if [ ! -f secrets/db_root_password.txt ]; then echo "db_root_pass_12345" > secrets/db_root_password.txt; fi
# 	@if [ ! -f secrets/credentials.txt ]; then \
# 		echo "WP_ADMIN_USER=jotong_admin" > secrets/credentials.txt; \
# 		echo "WP_ADMIN_PASSWORD=admin_pass_12345" >> secrets/credentials.txt; \
# 		echo "WP_ADMIN_EMAIL=jotong@student.42.fr" >> secrets/credentials.txt; \
# 		echo "WP_USER=jotong_user" >> secrets/credentials.txt; \
# 		echo "WP_USER_PASSWORD=user_pass_12345" >> secrets/credentials.txt; \
# 		echo "WP_USER_EMAIL=jotong_user@student.42.fr" >> secrets/credentials.txt; \
# 	fi
# 	@if [ ! -f srcs/.env ]; then \
# 		echo "DOMAIN_NAME=jotong.42.fr" > srcs/.env; \
# 		echo "SQL_DATABASE=wordpress" >> srcs/.env; \
# 		echo "SQL_USER=wp_db_user" >> srcs/.env; \
# 		echo "WP_TITLE=Inception_jotong" >> srcs/.env; \
# 	fi

	@if [ ! -f .env ]; then \
		echo "No env file found"; \
	fi

build:
	docker compose -f srcs/docker-compose.yml build

up:
	docker compose -f srcs/docker-compose.yml --env-file srcs/.env up -d

down:
	docker compose -f srcs/docker-compose.yml down

clean:
	docker compose -f srcs/docker-compose.yml down --volumes --rmi all

fclean: clean
	@sudo rm -rf /home/jotong/data
	@rm -rf secrets
	@rm -f srcs/.env

re: fclean all

.PHONY: all setup build up down clean fclean re
