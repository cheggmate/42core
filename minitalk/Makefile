# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 16:59:19 by jotong            #+#    #+#              #
#    Updated: 2025/07/15 16:59:53 by jotong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG			= -Wall -Wextra -Werror -I$(LIBFT_FOLDER)

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

# BONUS folders
BONUS_FOLDER	= bonus

# BONUS Server files
NAME_S_BONUS	= server_bonus
REQ_SRC_S_BONUS	= ft_server_bonus.c ft_server_funcs_bonus.c ft_server_sndr_bonus.c
HEADER_S_BONUS	= server_bonus.h
OBJ_S_BONUS		= $(addprefix $(BONUS_FOLDER)/,$(REQ_SRC_S_BONUS:.c=.o))

# BONUS Client files
NAME_C_BONUS	= client_bonus
REQ_SRC_C_BONUS	= ft_client_bonus.c ft_client_funcs_bonus.c ft_client_rcvr_bonus.c
HEADER_C_BONUS	= client_bonus.h
OBJ_C_BONUS		= $(addprefix $(BONUS_FOLDER)/,$(REQ_SRC_C_BONUS:.c=.o))

# Library folders
LIBFT_FOLDER	= libft
LIBFT			= ${LIBFT_FOLDER}/libft.a

# Default target
all: $(LIBFT) $(NAME_C) $(NAME_S)

# Compile and archive .o files
$(NAME_C): $(OBJ_C) $(LIBFT)
	$(CC) $(FLAG) -o $@ $^

$(NAME_S): $(OBJ_S) $(LIBFT)
	$(CC) $(FLAG) -o $@ $^

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

# Compile .c to .o
$(BONUS_FOLDER)/%.o : $(BONUS_FOLDER)/%.c
	@$(CC) $(FLAG) -c $< -o $@

# BONUS: Compile and archive .o files
$(NAME_C_BONUS): $(OBJ_C_BONUS) $(LIBFT)
	$(CC) $(FLAG) -o $@ $^

$(NAME_S_BONUS): $(OBJ_S_BONUS) $(LIBFT)
	$(CC) $(FLAG) -v -o $@ $^ 

# Bonus rules
bonus:
	@$(MAKE) $(NAME_S_BONUS)
	@$(MAKE) $(NAME_C_BONUS)

# Individual bonus targets
start_server_bonus: 
	@$(MAKE) $(NAME_S_BONUS)
start_client_bonus: 
	@$(MAKE) $(NAME_C_BONUS)

# Clean OBJ files
clean:
	@rm -f $(OBJ_S) $(OBJ_C) $(OBJ_S_BONUS) $(OBJ_C_BONUS) 
	@$(MAKE) -C $(LIBFT_FOLDER) clean 

# Clean all
fclean: clean
	@rm -f $(NAME_C) $(NAME_S) $(NAME_C_BONUS) $(NAME_S_BONUS)
	@$(MAKE) -C $(LIBFT_FOLDER) fclean

# Rebuild everything
re: fclean all

# Used to declare targets that are not actual files but command names
.PHONY: all start_server start_client bonus start_server_bonus start_client_bonus clean fclean re