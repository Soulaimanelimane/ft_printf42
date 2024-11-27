# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slimane <slimane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 10:53:02 by slimane           #+#    #+#              #
#    Updated: 2024/11/22 23:47:23 by slimane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SFILES = ft_printf.c  ft_put_char.c  ft_put_hexa.c ft_put_str.c ft_putnbr.c ft_putsnbr.c

OFILES = ${SFILES:.c=.o}

all:${NAME}

${NAME}:${OFILES}
	ar r ${NAME} ${OFILES}

%.o: %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OFILES}

fclean:clean
	rm -f ${NAME}

re:fclean all