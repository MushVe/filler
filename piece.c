/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 01:45:44 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/14 05:13:51 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		fill_board(t_p *p)
{
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
	// dprintf(p->fd, "%p last_elem\n", last_elem);
	i = -1;
	while (p->tab[++i].player != -1)
		p->board[p->tab[i].y][p->tab[i].x] = p->tab[i].player;
	return (0);
}

void	doubleprint(char **s, t_p *p)
{
	int	i;

	i = -1;
	while (s[++i])
		dprintf(p->fd, "\t> %s\n", s[i]);
}

int		is_ok(t_p *p, int i_brd, int j_brd)
{
	int	i_tmp_b;
	int	j_tmp_b;
	int	i_piece;
	int	j_piece;
	int	a;
	int	b;

	i_piece = -1;
	a = 0;
	b = 0;
	if ((p->p_max_hig + i_brd < p->b_hig) && (p->p_max_len + j_brd < p->b_len))
	{
		while (++i_piece < p->p_max_hig + 1)
		{
			j_piece = -1;
			while (++j_piece < p->p_max_len + 1)
			{
				i_tmp_b = i_piece + i_brd;
				j_tmp_b = j_piece + j_brd;
				if (p->piece[i_piece][j_piece] == '*'
					&& p->board[i_tmp_b][j_tmp_b] == p->me_token)
					a++;
				if (p->piece[i_piece][j_piece] == '*'
					&& p->board[i_tmp_b][j_tmp_b] == p->av_token
					|| p->board[i_tmp_b][j_tmp_b] == p->av_token + 32)
					b++;
			}
		}
		if (a == 1 && b == 0)
		{
			p->res_x = i_brd;
			p->res_y = j_brd;
			return (1);
		}
	}
	return (0);
}

/*
** ennemy[0] == i_board
** ennemy[1] == j_board
*/

int		*find_nearest_enemy(t_p *p)
{
	int	*ennemy;

	if (!(ennemy = (int*)ft_memalloc(sizeof(int) * 2)))
		return (-1);
	ennemy[0] = -1;
	while (++ennemy[0] < p->b_hig)
	{
		ennemy[1] = -1;
		while (++ennemy[1] < p->b_len)
		{
			if (p->board[ennemy[0]][ennemy[1]] == p->av_token + 32)
				return (ennemy);
		}
	}
	return (NULL);
}

int		put_piece(t_p *p)
{
	int	i_board;
	int	j_board;
	int	*ennemy;

	fill_board(p);
	ennemy = find_nearest_enemy(p);
	// doubleprint(p->board, p);
	i_board = -1;
	while (++i_board < p->b_hig)
	{
		j_board = -1;
		while (++j_board < p->b_len)
		{
			// run for it and block it
			



			if (is_ok(p, i_board, j_board) == 1)
				return (0);
		}
	}
	return (0);
}
