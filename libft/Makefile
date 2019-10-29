# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cseguier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 17:07:19 by cseguier          #+#    #+#              #
#    Updated: 2019/06/27 13:42:46 by cseguier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libftprintf.a

FILE = 	ft_abs.c ft_atoi.c ft_bzero.c ft_capitalize.c ft_foreach.c \
		ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_itoa.c ft_itoa_base.c ft_lowcase.c ft_lstadd.c ft_lstdel.c  \
		ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
		ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
		ft_memmove.c ft_memset.c ft_pow.c ft_putchar.c ft_putchar_fd.c \
		ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putnstr.c \
		ft_putstr.c ft_putstr_fd.c ft_quicksort.c ft_sqrt.c ft_strcat.c \
		ft_strccpy.c ft_strcdup.c ft_strchr.c ft_strclr.c ft_strcmp.c \
		ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_stricpy.c \
		ft_stridup.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
		ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
		ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
		ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
		ft_tolower.c ft_toupper.c ft_upcase.c get_next_line.c \
		ft_printf.c parser.c node.c flag_process.c add_stuff.c add_width.c \
		convert.c check.c get_type.c get_double.c get_unsigned.c

SRC = $(FILE:%=%)

OBJ = $(FILE:%.c=objs/%.o)

CFLAGS = -Wall -Werror -Wextra
CC = gcc $(CFLAGS)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
		@ar rcs $(NAME) $(OBJ) 
		@ranlib $(NAME)

objs/%.o: src/%.c
		@mkdir -p objs
		@$(CC) -c $< -o $@

objs/%.o: ft_printf/%.c
		@mkdir -p objs
		@$(CC) -c $< -o $@

clean:
		@$(RM) $(OBJ)
		@rm -df objs

fclean: clean
		@$(RM) $(NAME)

re: fclean all
