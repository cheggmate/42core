# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/29 13:54:50 by jotong            #+#    #+#              #
#    Updated: 2025/08/29 15:32:22 by jotong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FLAG			= -Wall -Wextra -Werror -g -O0 -fsanitize=address
NAME			= pipex
REQ_SRC			= ft_pipex.c
HEADER			= pipex.h
OBJ 			= $(REQ_SRC:.c=.o)

# Default target
all: $(LIBFT) $(NAME)

# Compile and archive .o files
$(NAME): $(LIBFT) $(OBJ)
	@$(MAKE) -C $(LIBFT_FOLDER)
	$(CC) $(OBJ) $(FLAG) $(LIBFT) -o $(NAME)

# Compile .c to .o
%.o : %.c
	@$(CC) $(FLAG) -c $< -o $@

# # Compile .c to .o
# $(BONUS_FOLDER)/%.o : $(BONUS_FOLDER)/%.c
# 	@$(CC) $(FLAG) -c $< -o $@

# # BONUS: Compile and archive .o files
# $(NAME_BONUS): $(OBJ_BONUS)
# 	$(CC) $(OBJ_BONUS) $(FLAG_BONUS)

# # Bonus rules
# bonus:
# 	@$(MAKE) $(NAME_BONUS)

# Library folders
LIBFT_FOLDER	= libft
LIBFT			= ${LIBFT_FOLDER}/libft.a

# Clean OBJ files
clean:
	@$(MAKE) -C $(LIBFT_FOLDER) clean 
	@rm -f $(OBJ)

# Clean all
fclean: clean
	@$(MAKE) -C $(LIBFT_FOLDER) fclean
	@rm -f $(NAME) $(LIBFT)

# Rebuild everything
re: fclean all

# Used to declare targets that are not actual files but command names
.PHONY: all clean fclean re