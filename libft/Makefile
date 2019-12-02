NAME = libft.a
RM = rm -f
CC = gcc
AR = ar rc
RL = ranlib
CFLG = -Wall -Werror -Wextra -c
SRC =	ft_putchar.c \
	ft_putstr.c \
	ft_strlen.c \
	ft_putendl.c\
	ft_putnbr.c\
	ft_putstr.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_strclr.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strequ.c\
	ft_strcmp.c\
	ft_strncmp.c\
	ft_strnequ.c\
	ft_strdup.c\
	ft_memset.c\
	ft_bzero.c\
	ft_strcpy.c\
	ft_strncpy.c\
	ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_atoi.c\
	ft_strcat.c\
	ft_memcpy.c\
	ft_strncat.c\
	ft_memccpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strlcat.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strstr.c\
	ft_strnstr.c\
	ft_memalloc.c\
	ft_memdel.c\
	ft_strnew.c\
	ft_strdel.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strsub.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_putnbr_fd.c\
	ft_strsplit.c\
	ft_itoa.c\
	ft_lstadd.c\
	ft_lstdel.c\
	ft_lstdelone.c\
	ft_lstnew.c\
	ft_fchar.c\
	ft_size.c\
	get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLG) $(SRC)
	$(AR) $(NAME) $(OBJ)
	$(RL) $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.phony : all $(NAME) clean fclean re
