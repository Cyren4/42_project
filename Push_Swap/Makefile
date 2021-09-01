# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 13:33:21 by cramdani          #+#    #+#              #
#    Updated: 2021/06/17 16:17:31 by cramdani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	push_swap

export CC		=	gcc
export CFLAGS	=	-Wall -Wextra -Werror 
export RM		=	rm -f
LIBFT_PATH	= libft
HEADER	=	push_swap.h

OBJS	=	${SRCS:.c=.o}

SRCS 	= 	$(wildcard *.c)

all		:	${NAME} ${CHECKER}

$(NAME) : ${OBJS} main.o
		@(cd $(LIBFT_PATH) && $(MAKE))
		cp ${LIBFT_PATH}/libft.a ./ 
		$(CC) -o $@ $(CFLAGS) $^ libft.a

%.o		:	%.c %.h
			$(CC)  $(GCC_FLAGS) -c  $< 

clean	:
		${RM} ${OBJS} main.o 
		@cd ${LIBFT_PATH} && $(MAKE) fclean

fclean	:	clean
			${RM} ${NAME} libft.a

re		:	fclean all

.PHONY	:	all clean fclean re