# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotong <jotong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 16:59:19 by jotong            #+#    #+#              #
#    Updated: 2025/07/31 22:54:10 by jotong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG		= -Wall -Wextra -Werror -I$(LIBFT_FOLDER) -I$(MINILIBX_FOLDER)
NAME		= so_long
REQ_SRC		= ft_so_long.c ft_map_utils.c ft_mem_utils.c ft_map_utils2.c \
				ft_display_utils.c ft_user_actions.c ft_player_utils.c \
				ft_map_loader_utils.c ft_mem_utils2.c ft_display_utils2.c \
				ft_asset_checks.c ft_path_check.c
HEADER		= so_long.h
OBJ 		= $(REQ_SRC:.c=.o)

# BONUS folders
BONUS_FOLDER	= bonus

# BONUS Server files
FLAG_BONUS		= -Wall -Wextra -Werror -I../$(LIBFT_FOLDER) -I../$(MINILIBX_FOLDER)
NAME_BONUS		= so_long_bonus
REQ_SRC_S_BONUS	= ft_so_long_bonus.c ft_map_utils_bonus.c ft_mem_utils_bonus.c ft_map_utils2_bonus.c \
				ft_display_utils_bonus.c ft_user_actions_bonus.c ft_player_utils_bonus.c \
				ft_map_loader_utils_bonus.c ft_mem_utils2_bonus.c ft_display_utils2_bonus.c \
				ft_asset_checks_bonus.c ft_path_check_bonus.c ft_enemy_movement_bonus.c
HEADER_BONUS	= $(BONUS_FOLDER)/so_long_bonus.h
OBJ_BONUS		= $(addprefix $(BONUS_FOLDER)/,$(REQ_SRC_S_BONUS:.c=.o))

# Library folders
LIBFT_FOLDER	= libft
LIBFT			= ${LIBFT_FOLDER}/libft.a
MINILIBX_FOLDER = minilibx_opengl_20191021
# MINILIBX_FOLDER = minilibx-linux
MINILIBX		= ${MINILIBX_FOLDER}/libmlx.a

# Default target
all: $(LIBFT) $(MINILIBX) $(NAME)

# Compile and archive .o files
$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	$(CC) $(OBJ) $(FLAG) $(LIBFT) -L$(MINILIBX_FOLDER) -lmlx -framework OpenGL -framework Appkit -o $(NAME)
# 	$(CC) $(OBJ) $(FLAG) $(LIBFT) -L${MINILIBX_FOLDER} -lmlx -lXext -lX11 -lm -lz -lbsd -o $(NAME)


# Libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_FOLDER)

# minilibx
$(MINILIBX):
	@echo "Building minilibx manually for linux.."
	@$(MAKE) -C $(MINILIBX_FOLDER)
# 	cd $(MINILIBX_FOLDER) && ./configure

# Compile .c to .o
%.o : %.c
	@$(CC) $(FLAG) -c $< -o $@

# Compile .c to .o
$(BONUS_FOLDER)/%.o : $(BONUS_FOLDER)/%.c
	@$(CC) $(FLAG) -c $< -o $@

# BONUS: Compile and archive .o files
$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT) $(MINILIBX)
	$(CC) $(OBJ_BONUS) $(FLAG_BONUS) $(LIBFT) -L$(MINILIBX_FOLDER) -lmlx -framework OpenGL -framework Appkit -o $(NAME_BONUS)
# 	$(CC) $(OBJ_BONUS) $(FLAG_BONUS) $(LIBFT) -L${MINILIBX_FOLDER} -lmlx -lXext -lX11 -lm -lz -o $(NAME_BONUS)

# Bonus rules
bonus:
	@$(MAKE) $(NAME_BONUS)

# Clean OBJ files
clean:
	@rm -f $(OBJ) $(OBJ_BONUS)
	@$(MAKE) -C $(LIBFT_FOLDER) clean 
	@$(MAKE) -C $(MINILIBX_FOLDER) clean 

# Clean all
fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_FOLDER) fclean
	@$(MAKE) -C $(MINILIBX_FOLDER) clean

# Rebuild everything
re: fclean all

# Used to declare targets that are not actual files but command names
.PHONY: all bonus clean fclean re