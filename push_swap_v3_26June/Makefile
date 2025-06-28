# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/15 20:28:40 by jotong            #+#    #+#              #
#    Updated: 2025/06/28 08:29:50 by jotong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= cc
FLAG		= -Wall -Wextra -Werror
NAME		= push_swap
REQ_SRC		= ft_push_swap.c ft_push_utils.c ft_rotate_utils.c ft_swap_utils.c ft_other_utils.c ft_libft_utils.c \
				ft_libft_utils2.c ft_libft_utils3.c ft_split_sort_logic.c ft_other_utils2.c ft_check_utils.c \
				ft_median_utils.c ft_prep_utils.c ft_list_split.c ft_list_ops.c \
				 ft_list_split2.c ft_other_utils3.c ft_sort_flow.c
OBJ 		= $(REQ_SRC:.c=.o)
HEADER		= ft_push_swap.h

# Default target
all: $(NAME)

# Compile .o files into ft_push_swap
$(NAME): $(OBJ)
	${CC} ${FLAG} ${OBJ} -o ${NAME} -lm

# Compile .c to .o
%.o : %.c ${HEADER}
			$(CC) $(FLAG) -c $< -o $@

# Clean OBJ files
clean:
	@rm -f $(OBJ)

# Clean all
fclean: clean
	@rm -f $(NAME)

# Rebuild everything
re: fclean all

# Used to declare targets that are not actual fieles but command names
.PHONY: all clean fclean re