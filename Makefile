# **************************************************************************** #
#																			  #
#														 :::	  ::::::::	#
#	Makefile										   :+:	  :+:	:+:	#
#													 +:+ +:+		 +:+	  #
#	By: lboukrou <lboukrou@student.42.fr>		  +#+  +:+	   +#+		 #
#												 +#+#+#+#+#+   +#+			#
#	Created: 2019/12/15 20:23:36 by lboukrou		  #+#	#+#			  #
#	Updated: 2019/12/15 20:45:23 by lboukrou		 ###   ########.fr		#
#																			  #
# **************************************************************************** #

NAME		=	lem_in
CC			=	gcc
CFLAGS		=	-Werror -Wall -Wextra
LIB_PATH	=	libft
LIB			=	$(LIB_PATH)/libft.a

INC_DIR		=	includes
INCS		=	-I $(INC_DIR) -I $(LIB_PATH)
INC_NAME	=	lem_in.h

SRC_DIR		=	srcs
SRC			=	error.c \
					graph_functions.c \
					parse_utils.c \
					parse.c \
					display_utils.c \
					utils.c

OBJ_DIR		=	obj

SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): obj $(LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIB)

obj:
	mkdir obj

$(LIB):
	make -C $(LIB_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -c -o $@ $<

clean:
	make -C $(LIB_PATH) clean
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re