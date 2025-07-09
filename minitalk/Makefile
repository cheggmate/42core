# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotong <jotong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 16:59:19 by jotong            #+#    #+#              #
#    Updated: 2025/07/09 23:20:14 by jotong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG			= -Wall -Wextra -Werror

# Server files
NAME_S			= server
REQ_SRC_S		= ft_printf.c ft_server.c ft_server_funcs.c
HEADER_S		= server.h
OBJ_S 			= $(REQ_SRC_S:.c=.o)

# Client files
NAME_C			= client
REQ_SRC_C		= ft_client.c
HEADER_C		= client.h
OBJ_C 			= $(REQ_SRC_C:.c=.o)

# Library folders
LIBFT_FOLDER	= libft
LIBFT			= ${LIBFT_FOLDER}/libft.a

# Compile and archive .o files
$(NAME_C): $(OBJ_C)
	$(CC) $(FLAG) -o $@ $^ $(OBJ_C) $(LIBFT)

$(NAME_S): $(OBJ_S)
	$(CC) $(FLAG) -o $@ $^ $(OBJ_S) $(LIBFT)

# Default target
all: libft $(NAME_C) $(NAME_S)

# other targets
server: libft $(NAME_S)
client: libft $(NAME_C)

# Libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_FOLDER)
	

# Compile .c to .o
%.o : %.c ${HEADER}
			@cc $(FLAG) -c $< -o $@

# Clean OBJ files
clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_FOLDER) clean 

# Clean all
fclean: clean
	@rm -f $(NAME_C) $(NAME_S)
	@$(MAKE) -C $(LIBFT_FOLDER) fclean

# Rebuild everything
re: fclean all

# Used to declare targets that are not actual files but command names
.PHONY: all server client clean fclean re