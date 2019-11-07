# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/04 13:00:08 by cseguier          #+#    #+#              #
#    Updated: 2019/11/07 07:02:55 by cseguier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cseguier.filler

LIBFT = libft/libftprintf.a

FILE = main.c node.c display.c parser.c
#FILE = filler.c

INC = -I libft 

SRC = $(FILE:%=%)
OBJ = $(FILE:%.c=objs/%.o)

FLAG = -Wall -Werror -Wextra #-fsanitize=address
CC = gcc $(FLAG) $(INC)

RM = rm -f

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
		@$(CC) -o $@ $(OBJ) -L libft/ -lftprintf -I display/include -L display/lib -l SDL2-2.0.0
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
		@rm -df objs
		@make -C libft/ clean

fclean: clean
		@$(RM) $(NAME)
		@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
