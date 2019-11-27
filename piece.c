/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 01:45:44 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/27 06:30:41 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	fill_board(t_p *p)
{
	t_lst_coord	*cpy;
	int			i;
	int			j;
	i = -1;
	if (!(p->board = (char**)ft_memalloc(sizeof(char*) * (p->b_hig + 1))))
		return (-1);
	while (++i < p->b_hig)
		if (!(p->board[i] = (char*)ft_memalloc(sizeof(char) * (p->b_len + 1))))
			return (-1);
	i = -1;
	while (++i < p->b_hig)
	{
		j = -1;
		while (++j < p->b_len)
			p->board[i][j] = '.';
	}
	cpy = p->first;
	i = -1;
	while (cpy->tab[++i].player != -1)
		p->board[cpy->tab[i].y][cpy->tab[i].x] = cpy->tab[i].player;
	return (0);
}

void doubleprint(char **s, t_p *p)
{
	int	i;

	i = -1;
	while (s[++i])
		dprintf(p->fd, "\t> %s\n", s[i]);
}

int	put_piece(t_p *p)
{
	int	i_board;
	int	j_board;
	int	i_tmp_board;
	int	j_tmp_board;
	int	i_piece;
	int	j_piece;
	int	a;
	int	b;

	fill_board(p);
	doubleprint(p->board, p);
	i_board = -1;
	while (++i_board < p->b_hig)
	{
		j_board = -1;
		while (++j_board < p->b_len)
		{
			i_piece = -1;
			a = 0;
			b = 0;
			dprintf(p->fd, "i_board: %d, j_board: %d\n", i_board, j_board);
			dprintf(p->fd, "xmx: %d, ymx: %d\t", p->p_true_hig, p->p_true_len);
			dprintf(p->fd, "b_len: %d, b_hig: %d\n", p->b_len, p->b_hig);
			if ((p->p_true_len + i_board < p->b_len) && (p->p_true_hig + j_board < p->b_hig))
			{
				while (++i_piece < p->p_hig)
				{
					j_piece = -1;
					while (++j_piece < p->p_len)
					{ //add cap for piece to avoid getting out of the board
						i_tmp_board = i_piece + i_board;
						j_tmp_board = j_piece + j_board;
						dprintf(p->fd, "| %c", p->piece[i_piece][j_piece]);
						dprintf(p->fd, " | %c", p->board[i_tmp_board][j_tmp_board]);
						dprintf(p->fd, " | i_p: %d", i_piece);
						dprintf(p->fd, " | j_p: %d", j_piece);
						dprintf(p->fd, " | i_b: %d", i_board);
						dprintf(p->fd, " | j_b: %d", j_board);
						if (p->piece[i_piece][j_piece] == '*'
							&& (p->board[i_tmp_board][j_tmp_board] == p->token
							|| (p->board[i_tmp_board][j_tmp_board] == p->token - 32)))
							a++;
						if (p->piece[i_piece][j_piece] == '*'
							&& p->board[i_tmp_board][j_tmp_board] != '.'
							&& (p->board[i_tmp_board][j_tmp_board] != p->token
							&& (p->board[i_tmp_board][j_tmp_board] != p->token - 32)))
							b++;
						dprintf(p->fd, "   |   a: %d | b: %d\n", a, b);
					}
				}
				if (a == 1 && b == 0)
				{
					dprintf(p->fd, "final a: %d, b: %d\n", a, b);
					p->res_x = i_board;
					p->res_y = j_board;
					return (0);
				}
			}
		}
	}
	dprintf(p->fd, "RETURN 0\n");
	return (0);
}

// int	put_piece(t_p *p)
// {
// 	int	i_board;
// 	int	i_piece;
// 	int	j_piece;
// 	int	a;
// 	int	b;
// 	int	x; //	x = i_board - (p->b_len * y)
// 	int	y; //	y = i_board / p->b_len
// 	int	x_inc;
// 	int	y_inc;
// 	int	inc;

// 	fill_board(p);
// 	dprintf(p->fd, "%s\n", p->board);
// 	i_board = -1;
// 	while (p->board[++i_board])
// 	{
// 		j_piece = -1;
// 		a = 0;
// 		b = 0;
// 		y = i_board / p->b_len;
// 		x = i_board - (p->b_len * y);
// 		dprintf(p->fd, "i_board: %d, x: %d, y: %d\n", i_board, x, y);
// 		dprintf(p->fd, "xmx: %d, ymx: %d\t", p->p_true_hig, p->p_true_len);
// 		dprintf(p->fd, "b_len: %d, b_hig: %d\n", p->b_len, p->b_hig);
// 		if ((p->p_true_len + x < p->b_len) && (p->p_true_hig + y < p->b_hig))
// 		{
// 			while (p->piece[++j_piece])
// 			{
// 				i_piece = -1;
// 				while (p->piece[j_piece][++i_piece])
// 				{
// 					y_inc = y + j_piece;
// 					x_inc = x + i_piece;
// 					inc = (x_inc + (y_inc * p->b_len));
// 			dprintf(p->fd, "| %c", p->piece[j_piece][i_piece]);
// 			dprintf(p->fd, " | %c", p->board[inc]);
// 			dprintf(p->fd, " | i_p: %d", i_piece);
// 			dprintf(p->fd, " | j_p: %d", j_piece);
// 			dprintf(p->fd, " | x_b: %d", x_inc);
// 			dprintf(p->fd, " | y_b: %d", y_inc);
// 			dprintf(p->fd, " | i_b: %d", inc);
// 					if (p->piece[j_piece][i_piece] == '*' && (p->board[inc] == p->token || (p->board[inc] == p->token - 32)))
// 						a++;
// 					if (p->piece[j_piece][i_piece] == '*' && p->board[inc] != '.' && (p->board[inc] != p->token && (p->board[inc] != p->token - 32)))
// 						b++;
// 					dprintf(p->fd, " | a: %d | b: %d\n", a, b);
// 				}
// 				}
// 			if (a == 1 && b == 0)
// 			{
// 				dprintf(p->fd, "final a: %d, b: %d\n", a, b);
// 				return (i_board);
// 			}
// 		}
// 	}
// 	dprintf(p->fd, "RETURN 0\n");
// 	return (0);
// }


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