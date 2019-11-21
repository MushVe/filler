# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/04 13:00:08 by cseguier          #+#    #+#              #
#    Updated: 2019/11/21 03:55:04 by cseguier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = players/cseguier.filler

LIBFT = libft/libftprintf.a

FILE = main.c node.c parser.c piece.c
#FILE = filler.c

INC = -I libft 

SRC = $(FILE:%=%)
OBJ = $(FILE:%.c=objs/%.o)

FLAG = -Wall -Werror -Wextra #-fsanitize=address
CC = gcc $(FLAG) $(INC)

RM = rm -rf

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
		@$(CC) -o $@ $(OBJ) -L libft/ -lftprintf
#		@echo "\n\
#                        ..\n\
#                      / __)  Done.\n\
#               .-^^^-/ /\n\
#            __/       /\n\
#           <__.|_|-|_|\n"

$(LIBFT) :
		@make -C libft/ all

objs/%.o: %.c
		@mkdir -p objs
		@$(CC) $(INC) -o $@ -c $<

clean:
		@$(RM) $(OBJ)
		@rm -rf objs
		@make -C libft/ clean

fclean: clean
		@$(RM) $(NAME)
		@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
