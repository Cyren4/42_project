# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 17:16:06 by cramdani          #+#    #+#              #
#    Updated: 2021/06/24 19:37:43 by cramdani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include printf_srcs.mk

NAME		=	libftprintf.a

HEADER		=	ft_printf.h

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror 

LIBFT_PATH	=	libft

OBJS		=	${SRCS:.c=.o}

BOOBS		=	${BONUS:.c=.o}

all :			${NAME}

.c.o :
				${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME} :		${OBJS}
				make -C  ${LIBFT_PATH}
				cp ${LIBFT_PATH}/libft.a ./${NAME}
				ar rc ${NAME} ${OBJS}
				ranlib ${NAME}

RM	=			rm -f

bonus	: 	 all ${BOOBS}
			ar rc ${NAME} ${OBJS} ${BOOBS}

clean	:
				${RM} ${OBJS}
				@cd ${LIBFT_PATH} && $(MAKE) clean

fclean:			clean
				${RM} ${NAME}
				@cd ${LIBFT_PATH} && $(MAKE) fclean

re:				fclean all

.PHONY:			all clean fclean re

