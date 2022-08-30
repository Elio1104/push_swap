SHELL	=	/bin/bash

# Variables

NAME		= push_swap
LIBFT		= libft
INC			= inc
HEADER		= -I libft/includes/ -I inc/
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= gcc
FLAGS		= -Wall -Werror -Wextra
RM			= rm -f
ECHO		= echo -e

# Colors

DEF_COLOR	=	\033[0;39m
ORANGE		=	\033[0;33m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

# Sources

ALG_DIR		=	algo/
ALG_FILES	=	push_swap sorting ultimate_algo

MOV_DIR		=	moves/
MOV_FILES	=	swap rotate reverse_rotate push

UTI_DIR		=	utils/
UTI_FILES	=	utils

SRC_FILES	+=	$(addprefix $(ALG_DIR), $(ALG_FILES))
SRC_FILES	+=	$(addprefix $(MOV_DIR), $(MOV_FILES))
SRC_FILES	+=	$(addprefix $(UTI_DIR), $(UTI_FILES))


SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		=	.cache_exists

###

start:
			@make -C $(LIBFT)
			@cp $(LIBFT)/libft.a .
			@$(ECHO) -n "$(YELLOW)[Push_swap]:\t$(DEF_COLOR)"
			@$(ECHO) -n "$(RED)[$(DEF_COLOR)"
			@make all
			@$(ECHO) -n "$(RED)]$(DEF_COLOR)"

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJF)
			@$(CC) $(FLAGS) $(OBJ) $(HEADER) libft.a -o $(NAME)		

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
			@$(ECHO) -n "$(ORANGE)=$(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(ALG_DIR)
			@mkdir -p $(OBJ_DIR)$(MOV_DIR)
			@mkdir -p $(OBJ_DIR)$(UTI_DIR)
			@touch $(OBJF)

clean:
			@$(RM) -r $(OBJ_DIR)
			@$(RM) $(OBJF)
			@make clean -C $(LIBFT)
			@$(ECHO) -n "$(BLUE)[Push_swap]:\tobject files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(LIBFT)/libft.a
			@$(RM) libft.a
			@$(ECHO) -n "$(CYAN)[LIBFT]:\texec. files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"
			@$(ECHO) -n "$(CYAN)[Push_swap]:\texec. files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"

re:			fclean start
			@$(ECHO) -n "\n$(GREEN)Cleaned and rebuilt everything for [Push_swap]!$(DEF_COLOR)\n"

.PHONY:		start all clean fclean re
