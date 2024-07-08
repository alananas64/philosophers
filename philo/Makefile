# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nosman <nosman@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 07:31:41 by nosman            #+#    #+#              #
#    Updated: 2024/07/08 13:42:44 by nosman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 		philo
CC 		= 		cc
CFLAGS	=		-Wall -Wextra -Werror -g3 -pthread #do i  need all of the flags?
SRCS	= 		philo.c utils.c parsing.c  \
				initialize_philos.c routine.c \
				actions.c monitoring.c \


OBJS 	=		$(SRCS:.c=.o)



REMOVE		=		rm -rf

all: 			$(NAME)

%.o: %.c
				$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):  		$(OBJS)
		 		$(CC) $(CFLAGS) $^ -o $(NAME)

clean:
				${REMOVE} ${OBJS}

fclean: 		clean
				${REMOVE} ${NAME}

re: 			fclean all

.PHONY: 		all clean fclean re
