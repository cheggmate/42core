# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotong <jotong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 15:37:26 by jotong            #+#    #+#              #
#    Updated: 2025/05/28 00:11:18 by jotong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG			= -Wall -Wextra -Werror
NAME			= get_next_line.a
HEADER			= get_next_line.h
REQ_SRC			= get_next_line.c get_next_line_utils.c 
OBJ 			= $(REQ_SRC:.c=.o)

BONUS_HEADER	= get_next_line_bonus.h
BONUS_SRC		= get_next_line_bonus.c get_next_line_utils_bonus.c 
BONUS_OBJ		= $(BONUS_SRC:.c=.o)

# Default target
all: $(NAME)

# Compile .c to .o
%.o : %.c ${HEADER} ${BONUS_HEADER}
	@cc $(FLAG) -c $< -o $@
	
# Compile and archive .o files into get_next_line.a
$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

# Bonus target - compile + add bonus .o files to get_next_line.a
bonus: $(OBJ) $(BONUS_OBJ)
	@echo "BONUS_OBJ = $(BONUS_OBJ)"
	@ar rc $(NAME) $(OBJ) $(BONUS_OBJ)
	@ranlib $(NAME)

# Clean OBJ files
clean:
	@rm -f $(OBJ) $(BONUS_OBJ)
	@echo "OBJ deleted"

# Clean all
fclean: clean
	@rm -f $(NAME) $(BONUS_OBJ)
	@echo "$(NAME) $(BONUS_OBJ) deleted"

# Rebuild everything
re: fclean all

# Used to declare targets that are not actual fieles but command names
.PHONY: all clean fclean re