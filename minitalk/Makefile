# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotong <jotong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 16:59:19 by jotong            #+#    #+#              #
#    Updated: 2025/07/09 17:00:37 by jotong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG		= -Wall -Wextra -Werror
NAME		= server
REQ_SRC		= ft_printf.c 
OBJ 		= $(REQ_SRC:.c=.o)
HEADER		= server.h

# Compile and archive .o files into libft.a
$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

# Default target
all: $(NAME)

# Compile .c to .o
%.o : %.c ${HEADER}
			@cc $(FLAG) -c $< -o $@


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