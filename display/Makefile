# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/04 13:00:08 by cseguier          #+#    #+#              #
#    Updated: 2020/01/28 02:35:47 by cseguier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../dis.play

LIBFT = ../libft/libftprintf.a

FILE = display.c

INC = -I include -L lib -l SDL2-2.0.0

SRC = $(FILE:%=%)
OBJ = $(FILE:%.c=%.o)

CC = gcc

RM = rm -rf

all: $(NAME)

$(NAME) : $(SRC)
	@$(CC) -o $(NAME) $(SRC) $(INC) -I ../libft -L ../libft/ -lftprintf 

clean:
	@$(RM) $(OBJ)
	@rm -rf objs

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
