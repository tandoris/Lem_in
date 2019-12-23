# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 19:56:30 by lboukrou          #+#    #+#              #
#    Updated: 2019/12/23 21:46:05 by lboukrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= lem_in
################################################################################
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror #-fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls -g #-g3 -fsanitize=address
INCS		= -Iincludes -I $(LIB_PATH)
COLOR		= \033[31m
FINCOLOR	= \033[0m
################################################################################
SRC_PATH	=	srcs
INC_PATH	=	includes
OBJ_PATH	=	obj
LIB_PATH	=	libft
LIB			=	$(LIB_PATH)/libft.a
SRC_NAME	=   error.c \
				graph_functions.c \
				parse_utils.c \
				parse.c \
				display_utils.c \
				utils.c \
				free.c \
				parse_reading.c \
				free_graph.c

INC_NAME	=	lem_in.h
OBJ_NAME	=	$(SRC_NAME:.c=.o)
################################################################################
SRC	= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ	= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC	= $(addprefix $(INC_PATH)/,$(INC_NAME))
################################################################################

all: $(NAME)

$(LIB):
	make -C $(LIB_PATH)
$(OBJ_PATH): 
	mkdir $(OBJ_PATH) 
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@ 
$(NAME): $(OBJ_PATH) $(OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
clean:
	make -C $(LIB_PATH) clean
	rm -rf $(OBJ_PATH)
fclean:
	make -C $(LIB_PATH) fclean
	rm -f $(LIB)
	rm -rf $(OBJ_PATH)
	rm -rf $(NAME)
re: fclean all
.PHONY : all clean fclean re
################################################################################