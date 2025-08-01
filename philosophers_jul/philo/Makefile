# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotong <jotong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/27 19:18:22 by jotong            #+#    #+#              #
#    Updated: 2025/08/01 22:14:14 by jotong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FLAG		= -Wall -Wextra -Werror
NAME		= philo
REQ_SRC		= ft_philo.c ft_mem_utils.c ft_thread_utils. ft_std_utils.c \
				ft_init_utils.c ft_resource_mgmt.c ft_resource_mgmt.c

HEADER		= philo.h
OBJ 		= $(REQ_SRC:.c=.o)

# # BONUS folders
# BONUS_FOLDER	= bonus

# # BONUS Server files
# FLAG_BONUS		= -Wall -Wextra -Werror -I../$(LIBFT_FOLDER) -I../$(MINILIBX_FOLDER)
# NAME_BONUS		= so_long_bonus
# REQ_SRC_S_BONUS	= ft_so_long_bonus.c ft_map_utils_bonus.c ft_mem_utils_bonus.c ft_map_utils2_bonus.c \
# 				ft_display_utils_bonus.c ft_user_actions_bonus.c ft_player_utils_bonus.c \
# 				ft_map_loader_utils_bonus.c ft_mem_utils2_bonus.c ft_display_utils2_bonus.c \
# 				ft_asset_checks_bonus.c ft_path_check_bonus.c ft_enemy_movement_bonus.c
# HEADER_BONUS	= $(BONUS_FOLDER)/so_long_bonus.h
# OBJ_BONUS		= $(addprefix $(BONUS_FOLDER)/,$(REQ_SRC_S_BONUS:.c=.o))

# Library folder
PHILO_FOLDER	= philo

# Default target
all: $(NAME)

# Compile and archive .o files
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAG) -o $(NAME)

# Compile .c to .o
%.o : %.c
	@$(CC) $(FLAG) -c $< -o $@

# Compile .c to .o
$(BONUS_FOLDER)/%.o : $(BONUS_FOLDER)/%.c
	@$(CC) $(FLAG) -c $< -o $@

# BONUS: Compile and archive .o files
$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) $(FLAG_BONUS)

# Bonus rules
bonus:
	@$(MAKE) $(NAME_BONUS)

# Clean OBJ files
clean:
	@rm -f $(OBJ) $(OBJ_BONUS)

# Clean all
fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

# Rebuild everything
re: fclean all

# Used to declare targets that are not actual files but command names
.PHONY: all bonus clean fclean re