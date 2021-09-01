
include cub3D.mk

SRCS_DIR	=	srcs
OBJS_DIR	=	objs

HEAD_DIR 	= includes
LIB_P	=	lib
LIB		=	$(LIB_P)/libft.a $(LIB_P)/libmlx.a

CC		=	clang	
RM		=	rm -rf
CFLAGS	=	-Wall -Werror -Wextra 
INC 	=	-I $(HEADER)

NAME	= cub3D 

HEADER	=	$(addprefix $(HEAD_DIR)/, $(H_FILES))	
SRCS	=	$(addprefix $(SRCS_DIR)/, $(FILES))
OBJS 	=	$(addprefix $(OBJS_DIR)/, $(FILES:.c=.o))

all		:	$(NAME)


$(NAME)	:	$(OBJS) $(HEADER)
			make -C ${LIB_P}
			@$(CC) $(CFLAGS) $(OBJS) $(INC) -o $(NAME) $(LIB)
		@printf "$(GREEN)$(NAME) created with '$(CFLAGS)' flags\n$(END)"
		@printf "$(PURPLE)cub3D ready to work! Get lost\n$(END)"
			

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJS_DIR)
	    	@$(CC) $(INC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
		@mkdir -p $@
		@printf "$(GREEN)Create object directory\n$(END)"

clean	:	
			@make fclean -C ${LIB_P}
			@$(RM) $(OBJS_DIR)
			@printf "$(RED)Object directory is deleted\n$(END)"

fclean	:	clean
			@$(RM) $(NAME)
			@printf "$(YELLOW)Everything is clean!\n$(END)"

re		:	fclean all