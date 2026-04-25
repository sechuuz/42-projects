# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/24 13:39:29 by sechavez          #+#    #+#              #
#    Updated: 2026/04/23 18:43:24 by sechavez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a
LIBFT_PATH = ./libft
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = 	ft_printf.c pf_check_format.c pf_handle_char.c pf_handle_int.c pf_handle_str.c \
		pf_handle_address.c pf_bufuhextoa.c pf_handle_unsint.c pf_handle_hex.c \
		pf_parse_format.c pf_print_padding.c \
		pf_format_num.c pf_format_text.c pf_bufitoa.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

bonus : $(NAME)

$(NAME) : $(OBJ) $(LIBFT_PATH)/$(LIBFT)
	cp $(LIBFT_PATH)/$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

$(LIBFT_PATH)/$(LIBFT) :
	make -C $(LIBFT_PATH) all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re bonus