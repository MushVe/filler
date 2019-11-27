/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 01:45:44 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/27 03:21:15 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get_piece_size(char *line, t_p *p)
{
	int	i;
	
	i = -1;
	while (!(ft_isdigit(line[++i]))) ;
	p->p_hig = ft_atoi(line + i);
	p->p_cpt = ft_atoi(line + i);
	while (line[++i] != ' ') ;
	p->p_len = ft_atoi(line + i);
	i = -1;
	if (!(p->piece = (char**)ft_memalloc(sizeof(char*)* (p->p_hig + 1))))
		return (-1);
	while (++i < p->p_hig)
		if (!(p->piece[i] = (char*)ft_memalloc(sizeof(char) * (p->p_len + 1))))
			return (0);
	return (0);
}

int	get_piece_data(char *line, t_p *p)
{
	int	i;

	i = -1;
	while (line[++i])
		p->piece[p->p_it][i] = line[i];
	p->p_cpt--;
	return (p->p_it++);
}

void	fill_board(t_p *p)
{
	t_lst_coord	*cpy;
	int			i;

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

int	get_true_len(int i, int j, t_p *p)
{
	int	first;
	int last;

	while (p->piece[j][++i])
	{
		first = -1;
		last = -1;
		if (p->piece[j][i] == '*')
		{
			if (first == -1)
				first = i;
			last = i;
		}
	}
	if (p->p_true_len < (last - first))
		p->p_true_len = last - first;
	return (0);
}

int	get_true_hig(int i, int j, t_p *p)
{
	int	check;

	p->p_true_hig = p->p_hig;
	while (++i < p->p_hig)
	{
		j = -1;
		check = 0;
		while (p->piece[i][++j])
			if (p->piece[i][j] == '*')
				check++;
		if (check != 0)
			p->p_true_hig--;
	}
	return (0);
}


int	get_true_size(t_p *p)
{
	int	i;

	i = -1;
	while (p->piece[++i])
		get_true_len(-1, i, p);
	get_true_hig(-1, -1, p);
	
	return (0);
}

int	put_piece(t_p *p)
{
	int	i_board;
	int	i_piece;
	int	j_piece;
	int	a;
	int	b;
	int	x; //	x = i_board - (p->b_len * y)
	int	y; //	y = i_board / p->b_len
	int	x_inc;
	int	y_inc;
	int	inc;

	fill_board(p);
	dprintf(p->fd, "%s\n", p->board);
	i_board = -1;
	while (p->board[++i_board])
	{
		j_piece = -1;
		a = 0;
		b = 0;
		y = i_board / p->b_len;
		x = i_board - (p->b_len * y);
		dprintf(p->fd, "i_board: %d, x: %d, y: %d\n", i_board, x, y);
		dprintf(p->fd, "xmx: %d, ymx: %d, len: %d\t", p->p_xmax, p->p_ymax, p->b_len);
		dprintf(p->fd, "b_len: %d, b_hig: %d\n", p->b_len, p->b_hig);
		if ((p->p_ymax + y < p->b_len) && (p->p_xmax + x < p->b_hig))
		{
			while (p->piece[++j_piece])
			{
				i_piece = -1;
				while (p->piece[j_piece][++i_piece])
				{
					y_inc = y + i_piece;
					x_inc = x + j_piece;
					inc = (y_inc + (x_inc * p->b_len));
					dprintf(p->fd, "data: %c", p->piece[j_piece][i_piece]);
					dprintf(p->fd, " | %c", p->board[inc]);
					dprintf(p->fd, " i_p: %d", i_piece);
					dprintf(p->fd, " j_p: %d", j_piece);
					dprintf(p->fd, " x_b: %d", x_inc);
					dprintf(p->fd, " y_b: %d", y_inc);
					dprintf(p->fd, " i_board: %d", inc);
					if (p->piece[j_piece][i_piece] == '*' && (p->board[inc] == p->token || (p->board[inc] == p->token - 32)))
						a++;
					if (p->piece[j_piece][i_piece] == '*' && p->board[inc] != '.' && (p->board[inc] != p->token && (p->board[inc] != p->token - 32)))
						b++;
					dprintf(p->fd, " a: %d, b: %d\n", a, b);
				}
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



// int	get_true_hig(int i, int j, t_p *p)
// {
// 	int	first;
// 	int last;

// 	dprintf(p->fd, "%d\n",  p->p_hig);
// 	while (p->piece[i][++j])
// 	{
// 		dprintf(p->fd, "\t\twhile %c, i: %d, j: %d\n", p->piece[i][j], i, j);
// 		i = -1;
// 		while (++i < p->p_hig)
// 		{
// 			dprintf(p->fd, "\t\t\twhile %c, i: %d, j: %d\n", p->piece[i][j], i, j);
// 			first = -1;
// 			last = -1;
// 			if (p->piece[i][j] == '*')
// 			{
// 				dprintf(p->fd, "\t\t\t\tif, i: %d, j: %d\n", i, j);
// 				if (first == -1)
// 				{
// 					first = i + 1;
// 					dprintf(p->fd, "ou es tu\n");
// 				}
// 				last = i + 1;
// 				dprintf(p->fd, "sors de la\n");
// 			}
// 		}
// 		dprintf(p->fd, "\ttru: %d, last: %d, first: %d\n",
// 					p->p_true_hig, last, first);
// 		if (p->p_true_hig < (last - first))
// 			p->p_true_hig = last - first;
// 		dprintf(p->fd, "dit moi tout\n");
// 	}
// 	return (0);
// }