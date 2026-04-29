# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 16:54:45 by sechavez          #+#    #+#              #
#    Updated: 2026/04/29 16:19:03 by sechavez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c  ft_lstdelone_bonus.c ft_lstiter_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c \
		./ft_printf/ft_printf.c ./ft_printf/pf_check_format.c \
		./ft_printf/pf_handle_char.c ./ft_printf/pf_handle_int.c \
		./ft_printf/pf_handle_str.c \
		./ft_printf/pf_handle_address.c ./ft_printf/pf_bufuhextoa.c \
		./ft_printf/pf_handle_unsint.c ./ft_printf/pf_handle_hex.c \
		./ft_printf/pf_parse_format.c ./ft_printf/pf_print_padding.c \
		./ft_printf/pf_format_num.c ./ft_printf/pf_format_text.c \
		./ft_printf/pf_bufitoa.c \
		get_next_line.c get_next_line_utils.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $@ $^
 
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(OBJBONUS)
	make -C ./ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C ./ft_printf clean

re: fclean $(NAME) 

.PHONY: all bonus clean fclean