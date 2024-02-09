# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gd-auria <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 11:45:53 by gd-auria          #+#    #+#              #
#    Updated: 2024/02/07 14:16:10 by gd-auria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_calloc.c ft_putx.c ft_a_putx.c

OUT = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

.c.o:
				${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): $(OUT)
				ar rcs $(NAME) $(OUT)

all:	$(NAME)

clean:
				rm -f $(NAME) $(BOUT)

fclean: clean
				rm -f $(NAME)

re:		fclean all
