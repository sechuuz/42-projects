# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 12:15:50 by sechavez          #+#    #+#              #
#    Updated: 2026/02/25 16:26:28 by sechavez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft.a
LIBFTPATH = ./libft
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = push_swap.c push_swap_stacks.c push_swap_ops.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFTPATH)/$(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LIBFTPATH)/$(LIBFT) -o $(NAME)

$(LIBFTPATH)/$(LIBFT) :
	make -C $(LIBFTPATH) all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)
	make -C $(LIBFTPATH) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFTPATH) fclean
	
re : fclean $(NAME)

run :
	./push_swap 1 2 3 5 4

.PHONY: all clean fclean re