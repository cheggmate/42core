# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/27 19:18:22 by jotong            #+#    #+#              #
#    Updated: 2025/09/17 20:40:00 by jotong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG			= -Wall -Wextra -Werror -g -O0
NAME			= philo
REQ_SRC			= ft_philo.c ft_mem_utils.c ft_thread_utils.c ft_std_utils.c \
				ft_init_utils.c ft_resource_mgmt.c ft_philo_actions.c  \
				ft_monitoring.c ft_thread_destroy_utils.c ft_time.c \
				ft_check_utils.c ft_state_set_utils.c
HEADER			= philo.h
OBJ 			= $(REQ_SRC:.c=.o)

# Default target
all: $(NAME)

# Compile and archive .o files
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAG) -o $(NAME)

# Compile .c to .o
%.o : %.c
	@$(CC) $(FLAG) -c $< -o $@

# Clean OBJ files
clean:
	@rm -f $(OBJ)

# Clean all
fclean: clean
	@rm -f $(NAME)

# Rebuild everything
re: fclean all

# Used to declare targets that are not actual files but command names
.PHONY: all bonus clean fclean re