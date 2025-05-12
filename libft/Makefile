FLAG = -Wall -Wextra -Werror


NAME = libft.a

all: atoi bzero isalnum isalpha isascii isdigit isprint memchr memcpy \
	memmove memset substr strchr strlcat strlcpy strlen strncmp strnstr \
	strrchr strtrim tolower toupper

atoi: ft_atoi.c
	cc -c ft_atoi.c -o ft_atoi.o

bzero: ft_bzero.c
	cc -c ft_bzero.c -o ft_bzero.o

isalnum: ft_isalnum.c
	cc -c ft_isalnum.c -o ft_bzero.o

isalpha: ft_isalpha.c
	cc -c ft_isalpha.c -o ft_isalpha.o

isascii: ft_isascii.c
	cc -c ft_isascii.c -o ft_isascii.o

isdigit: ft_isdigit.c
	cc -c ft_isdigit.c -o ft_isdigit.o

isprint: ft_isprint.c
	cc -c ft_isprint.c -o ft_isprint.o

memchr: ft_memchr.c
	cc -c ft_memchr.c -o ft_memchr.o

memcpy: ft_memcpy.c
	cc -c ft_memcpy.c -o ft_memcpy.o

memmove: ft_memmove.c
	cc -c ft_memmove.c -o ft_memmove.o

memset: ft_memset.c
	cc -c ft_memset.c -o ft_memset.o

substr: ft_substr.c
	cc -c ft_substr.c -o ft_substr.o

strchr: ft_strchr.c
	cc -c ft_strchr.c -o ft_strchr.o

strlcat: ft_strlcat.c
	cc -c ft_strlcat.c -o ft_strlcat.o

strlcpy: ft_strlcpy.c
	cc -c ft_strlcpy.c -o ft_strlcpy.o

strlen: ft_strlen.c
	cc -c ft_strlen.c -o ft_strlcpy.o

strncmp: ft_strncmp.c
	cc -c ft_strncmp.c -o ft_strncmp.o

strnstr: ft_strnstr.c
	cc -c ft_strnstr.c -o ft_strnstr.o

strrchr: ft_strrchr.c
	cc -c ft_strrchr.c -o ft_strrchr.o

strtrim: ft_strtrim.c
	cc -c ft_strtrim.c -o ft_strtrim.o

tolower: ft_tolower.c
	cc -c ft_tolower.c -o ft_tolower.o

toupper: ft_toupper.c
	cc -c ft_toupper.c -o ft_toupper.o

calloc: ft_calloc.c
	cc -c ft_calloc.c -o ft_calloc.o

calloc: ft_strdup.c
	cc -c ft_strdup.c -o ft_strdup.o

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memchr.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_substr.c \
	  ft_strchr.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strtrim.c \
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

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re