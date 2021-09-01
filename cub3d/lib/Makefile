# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 13:33:21 by cramdani          #+#    #+#              #
#    Updated: 2021/08/13 01:46:47 by cramdani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	=	\033[0;32m
BLUE	=	\033[0;34m
END		=	\033[m

NAME 	=	lib.a

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

LIB		= $(LIBFT_P)/libft.a $(MLX_P)/libmlx.a

all		:	${NAME}

$(NAME) : ${OBJS} 
		@make -C ${LIBFT_P}
		@make -C ${MLX_P}
		@cp $(LIBFT_P)/libft.a .
		@cp $(MLX_P)/libmlx.a .
		@printf "$(GREEN)Libraries are ready to run\n$(END)"

clean	:
		@make fclean -C ${LIBFT_P}
		@make clean -C ${MLX_P} 

fclean	:	clean
			@${RM} libft.a libmlx.a 
			@printf "$(BLUE)Libraries are cleaned\n$(END)"

re		:	fclean all

.PHONY	:	all clean fclean re
