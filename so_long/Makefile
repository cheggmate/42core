# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotong <jotong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 16:59:19 by jotong            #+#    #+#              #
#    Updated: 2025/07/17 22:39:39 by jotong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG		= -Wall -Wextra -Werror -I$(LIBFT_FOLDER) -I$(MINILIBX_FOLDER)

NAME		= so_long
REQ_SRC		= ft_so_long.c
HEADER		= so_long.h
OBJ 		= $(REQ_SRC:.c=.o)

# BONUS folders
# BONUS_FOLDER	= bonus

# BONUS Server files
# NAME_S_BONUS	= server_bonus
# REQ_SRC_S_BONUS	= ft_server_bonus.c ft_server_funcs_bonus.c ft_server_sndr_bonus.c
# HEADER_S_BONUS	= server_bonus.h
# OBJ_S_BONUS		= $(addprefix $(BONUS_FOLDER)/,$(REQ_SRC_S_BONUS:.c=.o))

# Library folders
LIBFT_FOLDER	= libft
LIBFT			= ${LIBFT_FOLDER}/libft.a
MINILIBX_FOLDER = minilibx_opengl_20191021
MINILIBX		= ${MINILIBX_FOLDER}/libmlx.a

# Default target
all: $(LIBFT) $(MINILIBX) $(NAME)

# Compile and archive .o files
$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	$(CC) $(FLAG) -L${MINILIBX_FOLDER} -lmlx -framework OpenGL -framework appkit -o $(NAME)

# Libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_FOLDER)

# minilibx
$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_FOLDER)

# Compile .c to .o
%.o : %.c
	@$(CC) $(FLAG) -v -Imlx -c $< -o $@ # remove verbose flag before submission

# Compile .c to .o
# $(BONUS_FOLDER)/%.o : $(BONUS_FOLDER)/%.c
# 	@$(CC) $(FLAG) -c $< -o $@

# BONUS: Compile and archive .o files
# $(NAME_S_BONUS): $(OBJ_S_BONUS) $(LIBFT)
# 	$(CC) $(FLAG) -v -o $@ $^ 

# Bonus rules
# bonus:
# 	@$(MAKE) $(NAME_S_BONUS)

# Individual bonus targets
# start_server_bonus: 
# 	@$(MAKE) $(NAME_S_BONUS)

# Clean OBJ files
clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_FOLDER) $(MINILIBX_FOLDER) clean 

# Clean all
fclean: clean
	@rm -f $(NAME) $(NAME)
	@$(MAKE) -C $(LIBFT_FOLDER) $(MINILIBX_FOLDER) fclean

# Rebuild everything
re: fclean all

# Used to declare targets that are not actual files but command names
.PHONY: all clean fclean re