FROM debian:bookworm

RUN apt-get update && apt-get install -y \
	curl \
	ca-certificates \
	tar \
	&& rm -rf /var/lib/apt/lists/*

# Download and extract official Portainer CE binary
RUN mkdir -p /opt/portainer && \
	curl -sSL https://github.com/portainer/portainer/releases/download/2.21.5/portainer-2.21.5-linux-amd64.tar.gz | tar -xzo -C /opt

WORKDIR /opt/portainer

EXPOSE 9000 9443

VOLUME ["/data"]

ENTRYPOINT ["/opt/portainer/portainer", "--data", "/data"]
