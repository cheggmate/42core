# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/15 20:28:40 by jotong            #+#    #+#              #
#    Updated: 2025/07/05 20:31:24 by jotong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= cc
FLAG		= -Wall -Wextra -Werror 
NAME		= push_swap
REQ_SRC		= ft_push_swap.c ft_push_utils.c ft_rotate_utils.c ft_swap_utils.c ft_other_utils.c ft_libft_utils.c \
				ft_libft_utils2.c ft_libft_utils3.c ft_split_sort_logic_stacka.c ft_other_utils2.c ft_check_utils.c \
				ft_median_utils.c ft_prep_utils.c ft_list_ops.c ft_other_utils3.c ft_sort_flow.c ft_libft_utils4.c \
				ft_split_sort_logic_stackb.c ft_optimise.c ft_optimise2.c ft_list_ops2.c ft_sort_b.c ft_sort_a.c
BONUS_SRC	= get_next_line.c ft_libft_utils.c ft_libft_utils2.c ft_libft_utils4.c get_next_line_main.c \
				ft_prep_utils.c ft_push_utils.c ft_rotate_utils.c ft_swap_utils.c ft_other_utils.c
OBJ 		= $(REQ_SRC:.c=.o)
HEADER		= ft_push_swap.h
B_HDR		= get_next_line.h
BONUS_OBJ	= $(BONUS_SRC:.c=.o)
BONUS_NAME	= checker

# Default target
all: $(NAME)

# Compile .o files into ft_push_swap
$(NAME): $(OBJ)
	${CC} ${FLAG} ${OBJ} -o ${NAME} -lm -g -O0

# Compile .c to .o
%.o : %.c ${HEADER} ${B_HDR}
			$(CC) $(FLAG) -g -O0 -c $< -o $@ 

bonus: $(BONUS_OBJ)
	${CC} ${FLAG} ${BONUS_OBJ} -o ${BONUS_NAME}


# Clean OBJ files
clean:
	@rm -f $(OBJ) ${BONUS_OBJ}

# Clean all
fclean: clean
	@rm -f $(NAME) ${BONUS_NAME}

# Rebuild everything
re: fclean all

# Used to declare targets that are not actual files but command names
.PHONY: all clean fclean re