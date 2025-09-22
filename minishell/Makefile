# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotong <jotong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/11 23:09:18 by jotong            #+#    #+#              #
#    Updated: 2025/09/22 23:08:10 by jotong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC			= -Iinclude
SRC_DIR		= src
OBJ_DIR		= obj
FLAG		= -Wall -Wextra -Werror -I$(LIBFT_DIR) $(INC) -g
NAME		= minishell
REQ_SRC		= $(SRC_DIR)/main.c, $(SRC_DIR)/signals.c
HEADER		= minishell.h
OBJ 		= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(REQ_SRC))

# BONUS folders
BONUS_FOLDER	= bonus

# BONUS Server files
# FLAG_BONUS		= -Wall -Wextra -Werror -I../$(LIBFT_FOLDER)
# REQ_SRC_S_BONUS	= 
# HEADER_BONUS	= $(BONUS_FOLDER)/minishell.h
# OBJ_BONUS		= $(addprefix $(BONUS_FOLDER)/,$(REQ_SRC_S_BONUS:.c=.o))

# Library folders
LIBFT_DIR		= lib/libft
LIBFT			= ${LIBFT_FOLDER}/libft.a

# Default target
all: $(LIBFT) $(NAME)

# Compile and archive .o files
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(FLAG) $(LIBFT) -o $(NAME)

# Libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Compile .c to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(FLAG) -c $< -o $@

# Compile .c to .o
# $(BONUS_FOLDER)/%.o : $(BONUS_FOLDER)/%.c
# 	@$(CC) $(FLAG) -c $< -o $@

# BONUS: Compile and archive .o files
# $(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
# 	$(CC) $(OBJ_BONUS) $(FLAG_BONUS) $(LIBFT) -o $(NAME_BONUS)

# Bonus rules
# bonus:
# 	@$(MAKE) $(NAME_BONUS)

# Clean OBJ files
clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean 
# @rm -f $(OBJ) $(OBJ_BONUS)

# Clean all
fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

# Used to declare targets that are not actual files but command names
.PHONY: all clean fclean re