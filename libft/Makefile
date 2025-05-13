FLAG = -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME) # dont know if this is correct

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_memchr.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_purchar_fd.c \
	  ft_putstr_fd.c \
	  ft_strchr.c \
	  ft_striteri.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_strmapi.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strtrim.c \
	  ft_substr.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_calloc.c \
	  ft_strdup.c \

	  OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

%.o: %.c
	@cc $(FLAG) -c $< -o $@

TEST_SRC = tests/tests_atoi.c \
	  tests/tests_bzero.c \
	  tests/tests_isalnum.c \
	  tests/tests_isalpha.c \
	  tests/tests_isascii.c \
	  tests/tests_isdigit.c \
	  tests/tests_isprint.c \
	  tests/tests_itoa.c \
	  tests/tests_memchr.c \
	  tests/tests_memcpy.c \
	  tests/tests_memmove.c \
	  tests/tests_memset.c \
	  tests/tests_putchar_fd.c \
	  tests/tests_putstr_fd.c \
	  tests/tests_strchr.c \
	  tests/tests_striteri.c \
	  tests/tests_strlcat.c \
	  tests/tests_strlcpy.c \
	  tests/tests_strlen.c \
	  tests/tests_strmapi.c \
	  tests/tests_strncmp.c \
	  tests/tests_strnstr.c \
	  tests/tests_strrchr.c \
	  tests/tests_strtrim.c \
	  tests/tests_substr.c \
	  tests/tests_tolower.c \
	  tests/tests_toupper.c \
	  tests/tests_calloc.c \
	  tests/tests_strdup.c \

	  TEST_OBJ = $(TEST_SRC:.c=tests/.o)

#split_test: ft_strdup.c ft_strncmp.c ft_strchr.c ft_strlen.c ft_strlcpy.c ft_memcpy.c
#	cc -c tests/tests_split.c ft_strdup.c ft_strncmp.c ft_strchr.c ft_strlen.c ft_strlcpy.c ft_memcpy.c

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re