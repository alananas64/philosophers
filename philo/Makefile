NAME	=	philo
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g3 #-pthread

SRC		=	philo.c \
			utils.c

OBJ		=	$(SRC:%.c=%.o)

$(NAME): $(OBJ) $(SRC)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM)r $(OBJ)

fclean: clean
	$(RM)r $(NAME)

re: fclean all

.PHONY: all clean fclean re
