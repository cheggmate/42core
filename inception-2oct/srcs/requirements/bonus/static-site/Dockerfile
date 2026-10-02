FROM debian:bookworm

RUN	apt-get update && apt-get install -y \
	python3 \
	&& rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/www/static

COPY site/ /var/www/static/

WORKDIR /var/www/static

EXPOSE 8080

ENTRYPOINT ["python3", "-m", "http.server", "8080"]