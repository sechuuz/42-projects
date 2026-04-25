# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 12:15:50 by sechavez          #+#    #+#              #
#    Updated: 2026/04/21 17:43:58 by sechavez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft.a
LIBFTPATH = ./libft
CC = cc
CFLAGS = -Wall -Werror -Wextra -Isrc/inc -I$(LIBFTPATH)
SRC = push_swap.c \
		src/ops/push_swap_ops.c \
		src/ops/push_swap_op_execute.c \
		src/utils/push_swap_stacks.c \
		src/utils/push_swap_checks.c \
		src/utils/push_swap_utils_1.c src/utils/push_swap_utils_2.c \
		src/utils/push_swap_utils_3.c src/utils/push_swap_utils_4.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFTPATH)/$(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFTPATH)/$(LIBFT) -o $(NAME)

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

.PHONY: all clean fclean re