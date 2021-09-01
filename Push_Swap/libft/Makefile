# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 10:38:04 by cramdani          #+#    #+#              #
#    Updated: 2021/06/17 16:43:33 by cramdani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(wildcard *.c)

OBJS	= ${SRCS:.c=.o}

NAME	=	libft.a
HEADER	= ./libft.h

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror 


all:	${NAME}

.o :	.c
		${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

${NAME}: 	 ${OBJS}
			ar rc ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re 
