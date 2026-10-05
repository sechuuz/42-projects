# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/28 21:58:58 by sechavez          #+#    #+#              #
#    Updated: 2026/10/03 17:18:39 by sechavez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= codexion
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -pthread
RM		= rm -f

SRCS	= codexion.c \
		init.c \
		utils.c \
		setup.c \
		heap.c \
		heap_utils.c \
		dongles.c \
		routines.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re