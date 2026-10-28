# --- Stage 1: Build the application ---
FROM ubuntu:24.04 AS builder

# Install build essentials
RUN apt-get update && apt-get install -y \
    build-essential \
    clang \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy your source code into the container
# (Assumes your main files/Makefile are in the same folder as this Dockerfile)
COPY . .

# Compile the project
RUN cc -Wall -Wextra -Werror mini_serv.c -o mini_serv

# --- Stage 2: Final lightweight runtime environment ---
FROM ubuntu:24.04

# Create a non-root user for security
RUN useradd -m miniserv_user

WORKDIR /home/miniserv_user

# Copy the compiled binary from the builder stage
# (Adjust "mini_serv" if your binary output has a different name)
COPY --from=builder /app/mini_serv .

# Change ownership to the non-root user
RUN chown -R miniserv_user:miniserv_user /home/miniserv_user

# Switch to the non-root user
USER miniserv_user

# Expose the default port (miniserv usually takes a port as a command line argument)
EXPOSE 8080

# Run the server. It expects a port number as an argument.
ENTRYPOINT ["./mini_serv"]
CMD ["8080"]
