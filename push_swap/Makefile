FLAG		= -Wall -Wextra -Werror
NAME		= ft_push_swap.a
REQ_SRC		= ft_push_swap.c ft_push_utils.c ft_rotate_utils.c ft_swap_utils.c ft_other_utils.c ft_libft_utils.c \
				ft_libft_utils2.c ft_libft_utils3.c ft_split_sort_logic.c ft_other_utils2.c ft_check_utils.c \
				ft_median_utils.c ft_prep_utils.c
OBJ 		= $(REQ_SRC:.c=.o)
HEADER		= ft_push_swap.h

# Compile and archive .o files into ft_push_swap.a
$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

# Default target
all: $(NAME)

# Compile .c to .o
%.o : %.c ${HEADER}
			@cc $(FLAG) -c $< -o $@


# Clean OBJ files
clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

# Clean all
fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

# Rebuild everything
re: fclean all

# Used to declare targets that are not actual fieles but command names
.PHONY: all clean fclean re