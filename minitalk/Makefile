# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotong <jotong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 16:59:19 by jotong            #+#    #+#              #
#    Updated: 2025/07/10 23:20:53 by jotong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG			= -Wall -Wextra -Werror

# Server files
NAME_S			= server
REQ_SRC_S		= ft_server.c ft_server_funcs.c
HEADER_S		= server.h
OBJ_S 			= $(REQ_SRC_S:.c=.o)

# Client files
NAME_C			= client
REQ_SRC_C		= ft_client.c ft_client_funcs.c
HEADER_C		= client.h
OBJ_C 			= $(REQ_SRC_C:.c=.o)

# Library folders
LIBFT_FOLDER	= libft
LIBFT			= ${LIBFT_FOLDER}/libft.a

# Compile and archive .o files
$(NAME_C): $(OBJ_C) $(LIBFT)
	$(CC) $(FLAG) -o $@ $^

$(NAME_S): $(OBJ_S) $(LIBFT)
	$(CC) $(FLAG) -o $@ $^

# Default target
all: $(LIBFT) $(NAME_C) $(NAME_S)

# other targets
start_server: 
	@$(MAKE) $(NAME_S)
start_client: 
	@$(MAKE) $(NAME_C)

# Libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_FOLDER)
	

# Compile .c to .o
%.o : %.c
	@$(CC) $(FLAG) -c $< -o $@

# Clean OBJ files
clean:
	@rm -f $(OBJ_S) $(OBJ_C)
	@$(MAKE) -C $(LIBFT_FOLDER) clean 

# Clean all
fclean: clean
	@rm -f $(NAME_C) $(NAME_S)
	@$(MAKE) -C $(LIBFT_FOLDER) fclean

# Rebuild everything
re: fclean all

# Used to declare targets that are not actual files but command names
.PHONY: all start_server start_client clean fclean re