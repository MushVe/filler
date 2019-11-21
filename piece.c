/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 01:45:44 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/21 06:49:03 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get_piece_size(char *line, t_p *p)
{
	size_t	i;
	
	i = -1;
	while (!(ft_isdigit(line[++i]))) ;
	p->p_hig = ft_atoi(line + i);
	while (line[++i] != ' ') ;
	p->p_len = ft_atoi(line + i);
	if (!(p->p_data = (char*)ft_memalloc(sizeof(char)
		* (p->p_len * p->p_hig) + 1)))
		return (0);
	return (0);
}

int	get_piece_data(char *line, t_p *p)
{
	int	i;
	int	first;

	first = -1;
	i = -1;
	while (line[++i] != '\0')
	{
		p->p_data[i + p->p_it] = line[i];
		// if (line[i] == '*' )
		// {
		// 	if (first == -1)
		// 		first = i;
		// 	if(p->p_xmax < i - first)
		// 		p->p_xmax = i - first;
		// }	
	}
	return (i);
}

void	fill_board(t_p *p)
{
	t_lst_coord	*cpy;
	size_t		i;

	if (!(p->board = (char*)ft_memalloc(sizeof(char) * p->size)))
		return ;
	i = -1;
	while (++i < p->size)
		p->board[i] = '.';
	cpy = p->first;
	i = -1;
	while (cpy->tab[++i].player != -1)
		p->board[cpy->tab[i].x + (cpy->tab[i].y * p->b_len)]
			= cpy->tab[i].player;
}

// int	resize(char *data)
// {
// 	int	i;

// 	i = -1;

// 	// incrementer jusqu'au premier *
// 	// memoriser debut nouvelle chaine
// 	// incrementer jusqu'a la fin
// 	// decrementer jusqu'au dernier *
// 	// memoriser fin nouvelle chaine
// 	// verifier taille derniere ligne = taille ligne la plus large
// 	// incrementer si necessaire
// 	// dup la nouvelle chaine

// 	return (0);
// }

// int	not_too_big(int x, int y, int i_board, t_p *p)
// {
// 	char	*data_cpy;

// 	if (!(data_cpy = ft_strdup(p->p_data)));
// 		return (-1);
// 	resize(data_cpy);

// 	// juste check ligne la plus large ?
// 	// et colone la plus haute ?
// 	// dans deux while ?
// 	// et please go recup cette valeur avant proprement dans structure
// 	// DANS GET PIECE PUTAIN
// 	// ALLER LA

// 	int i;
// 	int j;

// 	j = -1;
// 	while (i_board)




// 	return (0);
// }

int	put_piece(t_p *p)
{
	int	i_board;
	int	i_piece;
	int	a;
	int	b;
	int	x; //	x = i_board - (p->b_len * y)
	int	y; //	y = i_board / p->b_len
	int	x_inc;
	int	y_inc;
	int	inc;

	fill_board(p);
	i_board = -1;
	while (p->board[++i_board])
	{
		i_piece = -1;
		a = 0;
		b = 0;
		y = i_board / p->b_len;
		x = i_board - (p->b_len * y);
		dprintf(p->fd, "i_board: %d, x: %d, y: %d\n", i_board, x, y);
		dprintf(p->fd, "max: %d x: %d len: %d\n", p->p_xmax, x, (int)p->b_len);
		if (p->p_xmax + x < (int)p->b_len)
		{
		while (p->p_data[++i_piece])
		{

			y_inc = y + (i_piece % p->p_len);
			x_inc = x + (i_piece / (y_inc + 1));
			inc = (x_inc + (y_inc * p->b_len));
			dprintf(p->fd, "\tpdata: %c ", p->p_data[i_piece]);
			dprintf(p->fd, "board: %c", p->board[inc]);
			dprintf(p->fd, "\ti_piece: %d", i_piece);
			dprintf(p->fd, "\ti_board: %lu\n", x + (y * p->b_len));
			if (p->p_data[i_piece] == '*'
				&& (p->board[inc] == p->token
				|| (p->board[inc] == p->token - 32)))
				a++;
			if (p->p_data[i_piece] == '*'
				&& p->board[inc] != '.'
				&& (p->board[inc] != p->token
				&& (p->board[inc] != p->token - 32)))
				b++;
			dprintf(p->fd, "a: %d, b: %d\n", a, b);
		}
		if (a == 1 && b == 0)
		{
			dprintf(p->fd, "final a: %d, b: %d\n", a, b);
			return (i_board);
		}
		}
	}
	dprintf(p->fd, "RETURN 0\n");
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
