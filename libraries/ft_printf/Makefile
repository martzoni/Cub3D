# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 11:25:42 by mmasoni           #+#    #+#              #
#    Updated: 2023/12/18 11:04:21 by mmasoni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a
CC				= GCC
CFLAGS			= -Wall -Wextra -Werror
HEADER			= ft_printf.h

SRCS			= ft_printf.c ft_printf_utils.c
OBJS			= ${SRCS:.c=.o}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADER}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
