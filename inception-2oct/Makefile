ENV_FILE := ./srcs/.env

ifneq (,$(wildcard $(ENV_FILE)))
    include $(ENV_FILE)
    export
endif

NAME := inception

all: setup build up

setup:
	@if [ ! -f srcs/.env ]; then \
		echo "Error: Environment file is missing. Please create it based on the example provided in DEV_DOC.md."; \
		exit 1; \
	fi
	@if [ ! -f secrets/db_password.txt ]; then \
		echo "Error: db_password.txt file in the secrets folder doesnt exist. Please create it based on the example provided in DEV_DOC.md."; \
		exit 1; \
	fi
	@if [ ! -f secrets/db_root_password.txt ]; then \
		echo "Error: db_root_password.txt file in the secrets folder doesnt exist. Please create it based on the example provided in DEV_DOC.md."; \
		exit 1; \
	fi
	@if [ ! -f secrets/credentials.txt ]; then \
		echo "Error: credentials.txt file in the secrets folder doesnt exist. Please create it based on the example provided in DEV_DOC.md."; \
		exit 1; \
	fi
	@if [ -z "$(LOGIN)" ]; then \
		echo "Error: LOGIN variable is not defined in $(ENV_FILE)."; \
		exit 1; \
	fi
	@mkdir -p /home/$(LOGIN)/data/wordpress
	@mkdir -p /home/$(LOGIN)/data/mariadb
	@mkdir -p /home/$(LOGIN)/data/portainer
	@if ! grep -q "$(DOMAIN_NAME)" /etc/hosts; then \
		echo "Adding $(DOMAIN_NAME) to /etc/hosts..."; \
		echo "127.0.0.1 $(DOMAIN_NAME)" | sudo tee -a /etc/hosts > /dev/null; \
	fi
	

build:
	docker compose -f srcs/docker-compose.yml -p $(NAME) build

up:
	docker compose -f srcs/docker-compose.yml -p $(NAME) --env-file srcs/.env up -d

down:
	docker compose -f srcs/docker-compose.yml -p $(NAME) down

ps:
	docker compose -f srcs/docker-compose.yml -p $(NAME) ps

logs:
	docker compose -f srcs/docker-compose.yml -p $(NAME) logs -f

clean:
	docker compose -f srcs/docker-compose.yml -p $(NAME) down --volumes --rmi all

fclean: clean
	@sudo rm -rf /home/$(LOGIN)/data

re: fclean all

.PHONY: all setup build up down ps logs clean fclean re
