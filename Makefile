# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/04 13:00:08 by cseguier          #+#    #+#              #
#    Updated: 2020/02/08 01:36:03 by cseguier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = players/cseguier.filler #cseguier.filler

LIBFT = libft/libftprintf.a

FILE = main.c parser.c put_piece.c get_piece.c can_put_piece.c \
	fill_board.c hit_map.c get_board.c init_and_reset.c

INC = -I libft 

SRC = $(FILE:%=%)
OBJ = $(FILE:%.c=objs/%.o)

FLAG = -Wall -Werror -Wextra # -fsanitize=address -g3
CC = gcc $(FLAG) $(INC)

RM = rm -rf

all: $(NAME)

$(NAME) : $(LIBFT) $(DISPLAY) $(OBJ)
	@$(CC) -o $@ $(OBJ) -L libft/ -lftprintf 

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
