/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 01:45:44 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/15 01:53:31 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get_piece_size(char *line, t_p *p)
{
	size_t	i;
	
	i = -1;
	while (!(ft_isdigit(line[++i]))) ;
	p->p_len = ft_atoi(line + i);
	while (line[++i] != ' ') ;
	p->p_hig = ft_atoi(line + i);
	if (!(p->p_data = (char*)ft_memalloc(sizeof(char) * p->p_len * p->p_hig)))
		return (0);
	return (0);
}

int	get_piece_data(char *line, t_p *p)
{
	int	i;

	i = -1;
	// ft_printf("hey?\n");
	while (line[++i] != '\0')
	{
		// ft_printf("i: %d, it: %d\n", i, p->p_it);
		p->p_data[i + p->p_it] = line[i];
	}
	// ft_printf("uuwuu?\n");
	return (i);
}

void	fill_board(t_p *p)
{
	t_lst_coord	*cpy;
	size_t		i;

	// ft_printf("size: %d\n", p->size);
	if (!(p->board = (char*)ft_memalloc(sizeof(char) * p->size)))
		return ;
	i = -1;
	while (++i < p->size)
	{
		// ft_printf("wesh i: %d\n", i);
		p->board[i] = '.';
	}
	cpy = p->first;
	i = -1;
	while (cpy->tab[++i].player != -1)
		p->board[cpy->tab[i].x + (cpy->tab[i].y * p->board_len)]
			= cpy->tab[i].player;
}

int	put_piece(t_p *p)
{
	int	i_board;
	int	i_piece;
	int	a;
	int	b;
	int	x; //	x = i_board - (p->board_len * y)
	int	y; //	y = i_board / p->board_len

	fill_board(p);
	// ft_printf("print?\n%s\n", p->board);
	// for (size_t i = 0; i < p->board_hig; i++) {
	// 	for (size_t j = 0; j < p->board_len; j++)
	// 		ft_putchar(p->board[(i * p->board_len) + j]);
	// 	ft_putchar('\n');
	// }

	i_board = -1;
	while (p->board[++i_board])
	{
		i_piece = -1;
		a = 0;
		b = 0;
		y = i_board / p->board_len;
		x = i_board - (p->board_len * y);
		while (p->p_data[++i_piece])
		{
			if (p->p_data[i_piece] == '*'
				&& p->board[(x + (y * p->board_len)) + i_piece] == p->player_token)
				a++;
			if (p->p_data[i_piece] == '*'
				&& p->board[(x + (y * p->board_len)) + i_piece] != '.'
				&& p->board[(x + (y * p->board_len)) + i_piece] != p->player_token)
				b++;
		}
		if (a == 1 && b == 0)
			return (i_board);
	}



	// while (++i < p->size)
	// {

	// }

	return (0);
}


//  012
//  345

//		y = i / largeur
//		x = i - (largeur * y)
//		i = x + (largeur * y)

//   0  1  2  3  4  5  6
//   7  8  9 10 11 12 13
//  14 15 16 17 18 19 20
