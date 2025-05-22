# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotong <jotong@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 14:55:51 by wjhoe             #+#    #+#              #
#    Updated: 2025/05/22 12:48:44 by jotong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ${FTPRINTF_PATH}/output.txt
# BON_SRCS = test_char.c test_decimal.c test_hex.c test_percent.c \
# 		test_pointer.c test_string.c test_unsigned.c test_bonus.c \
# 		test_return_value.c
MAN_SRCS = test_mandatory.c
LIB = libftprintf.a
OBJS = printcompare
FTPRINTF_PATH = ..
FTPRINTF = ${FTPRINTF_PATH}/${LIB}
# B_FTPRINTF_PATH = ..
# B_FTPRINTF = ${FTPRINTF_PATH}/${LIB}

CC = cc 
RM = rm -fr

all:
		@echo
		@echo "\tUsage: [make m] or [make b] to test the respective functions"
		@echo "\tThis tester will generate an output in your root directory called output.txt"
		@echo "\tWithin it you will see your function compared directly to printf"
		@echo "\t[make b] will include test cases for [make m], you shouldn't have to run both"
		@echo
		@echo "\tWarning:"
		@echo "\tAlso note that there will be errors while compiling"
		@echo "\tBut no flags are being used so there should still be output"
		@echo "\tThis is to test for cases where is UB for printf but still has an output"
		@echo
		@echo "\tNote: make re will automatically compile bonus"
		@echo "\tYou can change it in the rule below to compile mandatory instead"
		@echo

m: fclean ${FTPRINTF}
		${CC} ${MAN_SRCS} -L. ${FTPRINTF} -o ${OBJS}
		./${OBJS} > ${NAME}
		@make clean
		@echo
		@echo "Mandatory tests completed. Results in ${NAME}"
		@echo


# b: fclean ${FTPRINTF}
# 		${CC} ${SRCS} ${BON_SRCS} -L. ${FTPRINTF} -o ${OBJS}
# 		./${OBJS} > ${NAME}
# 		@echo
# 		@echo "Bonus tests completed. Results in ${NAME}"
# 		@echo

${FTPRINTF}:
		make -C ${FTPRINTF_PATH} all

# ${B_FTPRINTF}:
# 		make -C ${B_FTPRINTF_PATH} bonus

open: ${NAME}
		open ${NAME}

clean:
		${RM} ${OBJS}
		make -C ${FTPRINTF_PATH} clean

fclean: clean
		${RM} ${NAME}
		make -C ${FTPRINTF_PATH} fclean

re: fclean b

# .PHONY: all clean fclean re bonus mandatory open
.PHONY: all clean fclean re mandatory open