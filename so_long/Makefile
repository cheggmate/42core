# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotong <jotong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 16:59:19 by jotong            #+#    #+#              #
#    Updated: 2025/07/24 10:24:43 by jotong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG		= -Wall -Wextra -Werror -I$(LIBFT_FOLDER) -I$(MINILIBX_FOLDER)
NAME		= so_long
REQ_SRC		= ft_so_long.c ft_map_utils.c ft_mem_utils.c ft_map_utils2.c \
				ft_display_utils.c ft_user_actions.c ft_player_utils.c \
				ft_map_loader_utils.c ft_mem_utils2.c ft_display_utils2.c \
				ft_asset_checks.c
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
# MINILIBX_FOLDER = minilibx-linux
MINILIBX		= ${MINILIBX_FOLDER}/libmlx.a

# Default target
all: $(LIBFT) $(MINILIBX) $(NAME)

# Compile and archive .o files
$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	@echo "linking........"
	@echo "Linking: $(CC) $(OBJ) $(FLAG) $(LIBFT) $(MINILIBX) -lmlx -framework OpenGL -framework Appkit -o $(NAME)"
	$(CC) $(OBJ) $(FLAG) $(LIBFT) -L$(MINILIBX_FOLDER) -lmlx -framework OpenGL -framework Appkit -o $(NAME)
# 	$(CC) $(OBJ) $(FLAG) $(LIBFT) -L${MINILIBX_FOLDER} -lmlx -lXext -lX11 -lm -lz -o $(NAME)

# Libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_FOLDER)

# minilibx
$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_FOLDER)

# Compile .c to .o
%.o : %.c
	@echo "Compiling: $(CC) $(FLAG) -c $< -o $@"
	@$(CC) $(FLAG) -c $< -o $@

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
	@$(MAKE) -C $(LIBFT_FOLDER) clean 
	@$(MAKE) -C $(MINILIBX_FOLDER) clean 

# Clean all
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_FOLDER) fclean
	@$(MAKE) -C $(MINILIBX_FOLDER) clean

# Rebuild everything
re: fclean all

# Used to declare targets that are not actual files but command names
.PHONY: all clean fclean re