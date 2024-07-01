NAME	=	philo
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -pthread -Ofast -fsanitize=thread -I.

MODE	=	none

ifeq ($(MODE), debug)
	CFLAGS	+=	-g3 -fsanitize=undefined -fno-omit-frame-pointer -fexceptions #-fsanitize-memory-track-origins
endif

ifeq ($(MODE), secure)

	CFLAGS	+=	-Werror=format-security \
				-U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=3 \
				-D_GLIBCXX_ASSERTIONS \
				-fstack-clash-protection -fstack-protector-strong \
				-Wl,-z,nodlopen -Wl,-z,noexecstack \
				-Wl,-z,relro -Wl,-z,now
#				-fstrict-flex-arrays=3
endif

REM		=	**/.DS_Store

SRC		=	philo.c \
			parse.c \
			philo_init.c

SRC		=	philo.c \


OBJ_DIR	=	./object

OBJ		=	$(SRC:.c=.o)

$(NAME) : $(OBJ)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM)r $(OBJ)

fclean: clean
	$(RM)r $(NAME) $(OBJ_DIR) $(REM)

re: fclean all

.PHONY: clean fclean re
