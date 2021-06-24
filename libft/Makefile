# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 10:38:04 by cramdani          #+#    #+#              #
#    Updated: 2021/06/24 19:33:07 by cramdani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include srcs.mk

OBJS	= ${SRCS:.c=.o}

NAME	=	libft.a
HEADER	= ./libft.h

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I${HEADER}


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
