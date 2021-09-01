
include philosopher.mk

SRCS_DIR	=	srcs
OBJS_DIR	=	objs

H_FILES	= philo.h
HEAD_DIR = ./includes/

CC		=	clang	
RM		=	rm -rf
CFLAGS	=	-Wall -Werror -Wextra -g -pthread #-fsanitize=thread
INC 	=	-I $(HEADER)

NAME	=  philo

HEADER	= $(addprefix $(HEAD_DIR)/, $(H_FILES))	
SRCS	=	$(addprefix $(SRCS_DIR)/, $(FILES))
OBJS 	=	$(addprefix $(OBJS_DIR)/, $(FILES:.c=.o))

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
			@$(CC) $(CFLAGS) $(OBJS) $(INC) -o $(NAME)
		@printf "$(GREEN)$(NAME) created with '$(CFLAGS)' flags\n$(END)"
		@printf "$(PURPLE)Philosophers are ready to think!$(END)"
			

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJS_DIR)
	    	@$(CC) $(INC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
		@mkdir -p $@
		@printf "$(GREEN)Create object directory\n$(END)"

clean	:	
			@$(RM) $(OBJS_DIR)
			@printf "$(RED)Object directory is deleted\n$(END)"

fclean	:	clean
			@$(RM) $(NAME)
			@printf "$(YELLOW)Everything is clean!\n$(END)"

re		:	fclean all