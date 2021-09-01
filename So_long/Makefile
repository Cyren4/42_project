# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 13:33:21 by cramdani          #+#    #+#              #
#    Updated: 2021/07/12 15:56:30 by cramdani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include so_long.mk
include so_long_bonus.mk

NAME 	=	so_long
NAME_BONUS 	=	so_long_bonus

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror 
RM		=	rm -f

OS := $(shell uname -s)
ifeq ($(OS),Darwin) ## mac 
	CFLAGS += -D MACOS -fsanitize=address
	MLX_P	= mlx
	LFLAGS = -L mlx -lmlx -framework OpenGL -framework AppKit -lz
endif
ifeq ($(OS),Linux) ##linux
	MLX_P	= minilibx-linux
	LFLAGS	= -lXext -lX11 -lm
endif

LIBFT_P	= libft

LIB			= $(LIBFT_P)/libft.a $(MLX_P)/libmlx.a

OBJS	=	${SRCS:.c=.o}
OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

all		:	${NAME}
bonus	: ${NAME_BONUS}	

$(NAME) : ${OBJS} 
		make -C ${LIBFT_P}
		make -C ${MLX_P}
		$(CC) -o $@ $^ $(LIB) $(LFLAGS) $(CFLAGS)  

$(NAME_BONUS) : ${OBJS_BONUS} 
		make -C ${LIBFT_P}
		make -C ${MLX_P}
		$(CC) -o $@ $^ $(LIB) $(LFLAGS) $(CFLAGS)  

%.o		:	%.c %.h
			@$(CC) -w $(CFLAGS)  -c  $< ${LIB} 

clean	:
		${RM} ${OBJS} ${OBJS_BONUS}
		make fclean -C ${LIBFT_P}
		make clean -C ${MLX_P} 

fclean	:	clean
			${RM} ${NAME} ${NAME_BONUS}  

re		:	fclean all

.PHONY	:	all clean fclean re
