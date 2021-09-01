# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 13:33:21 by cramdani          #+#    #+#              #
#    Updated: 2021/06/23 21:47:08 by cramdani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER 	=	server
CLIENT	=	client

SERVER_B 	=	server_bonus
CLIENT_B	=	client_bonus

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror 
RM		=	rm -f

OBJS	=	${SRCS:.c=.o}

SRCS 	= 	$(wildcard *.c)
SRCS	:= $(filter-out server.c client.c server_bonus.c client_bonus.c, $(SRCS))

all		:	${SERVER} ${CLIENT}

$(SERVER) : ${OBJS} server.o
		$(CC) -o $@ $(CFLAGS) $^ 

$(CLIENT) : ${OBJS} client.o
		$(CC) -o $@ $(CFLAGS) $^ 

$(SERVER_B) : ${OBJS} server_bonus.o
		$(CC) -o $@ $(CFLAGS) $^ 

$(CLIENT_B) : ${OBJS} client_bonus.o
		$(CC) -o $@ $(CFLAGS) $^ 

%.o		:	%.c %.h
			$(CC)  $(GCC_FLAGS) -c  $< 

clean	:
		${RM} ${OBJS} server.o client.o server_bonus.o client_bonus.o

fclean	:	clean
			${RM} ${OBJS} ${SERVER} ${CLIENT} ${SERVER_B} ${CLIENT_B}

re		:	fclean all

bonus : ${SERVER_B} ${CLIENT_B}

.PHONY	:	all clean fclean re bonus
