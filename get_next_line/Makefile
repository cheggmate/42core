# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotong <jotong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 15:37:26 by jotong            #+#    #+#              #
#    Updated: 2025/05/24 23:08:17 by jotong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG		= -Wall -Wextra -Werror
HEADER		= get_next_line.h
REQ_SRC		= get_next_line.c get_next_line_utils.c 
OBJ 		= $(REQ_SRC:.c=.o)

# Compile and archive .o files into libft.a
$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

# Default buffer size
BUFFER_SIZE ?= 100

# Default target
all: $(NAME)

# Compile .c to .o
%.o : %.c ${HEADER}
			@cc $(FLAG) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@


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