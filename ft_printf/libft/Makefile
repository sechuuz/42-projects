# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 16:54:45 by sechavez          #+#    #+#              #
#    Updated: 2025/11/20 12:03:17 by sechavez         ###   ########.fr        #
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
ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
OBJECTS = $(SOURCES:.c=.o)
SRCBONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
ft_lstclear_bonus.c  ft_lstdelone_bonus.c ft_lstiter_bonus.c \
ft_lstlast_bonus.c \
ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
OBJBONUS = $(SRCBONUS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $@ $^
 
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJBONUS)
	ar rcs $(NAME) $^

clean:
	rm -f $(OBJECTS) $(OBJBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME) 

.PHONY: all bonus clean fclean