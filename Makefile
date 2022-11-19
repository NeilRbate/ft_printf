# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 09:43:44 by jbarbate          #+#    #+#              #
#    Updated: 2022/11/18 15:57:49 by jbarbate         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc
SRCS = ./srcs/*.c
HEADER = -I ./includes/ft_printf.h libft.a
OBJS = ${SRCS:.c=.o}
NAME = ./a.out
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${GCC} ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${OBJS} ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
