FLAG		= -Wall -Wextra -Werror
NAME		= libftprintf.a
REQ_SRC		= ft_printf
OBJ 		= $(REQ_SRC:.c=.o)

# Compile and archive .o files into libft.a
$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

# Default target
all: $(NAME)

# Compile .c to .o

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