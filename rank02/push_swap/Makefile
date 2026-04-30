# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 12:15:50 by sechavez          #+#    #+#              #
#    Updated: 2026/04/30 21:36:59 by sechavez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
LIBFT = libft.a
LIBFTPATH = ./libft
CC = cc
CFLAGS = -Wall -Werror -Wextra -Isrc/inc -I$(LIBFTPATH)
UTIL_SRC = src/ops/push_swap_ops.c \
		src/ops/push_swap_op_execute.c \
		src/utils/push_swap_stacks.c \
		src/utils/push_swap_checks.c \
		src/utils/push_swap_utils_1.c src/utils/push_swap_utils_2.c \
		src/utils/push_swap_utils_3.c src/utils/push_swap_utils_4.c
SRC = push_swap.c $(UTIL_SRC)
SRCBONUS = checker_bonus.c $(UTIL_SRC)
OBJ = $(SRC:.c=.o)
OBJBONUS = $(SRCBONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFTPATH)/$(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFTPATH)/$(LIBFT) -o $(NAME)

bonus : $(CHECKER)

$(CHECKER) : $(OBJBONUS) $(LIBFTPATH)/$(LIBFT)
	$(CC) $(CFLAGS) $(OBJBONUS) $(LIBFTPATH)/$(LIBFT) -o $(CHECKER)

$(LIBFTPATH)/$(LIBFT) :
	make -C $(LIBFTPATH) all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ) $(OBJBONUS)
	make -C $(LIBFTPATH) clean

fclean : clean
	rm -rf $(NAME)
	rm -rf $(CHECKER)
	make -C $(LIBFTPATH) fclean
	
re : fclean all

.PHONY: all clean fclean re