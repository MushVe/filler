/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 01:45:44 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/28 04:39:17 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		fill_board(t_p *p)
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

void	doubleprint(char **s, t_p *p)
{
	int	i;

	i = -1;
	while (s[++i])
		dprintf(p->fd, "\t> %s\n", s[i]);
}

int		put_piece(t_p *p)
{
	int	i_board;
	int	j_board;
	int	i_tmp_b;
	int	j_tmp_b;
	int	i_piece;
	int	j_piece;
	int	a;
	int	b;

	fill_board(p);
	// doubleprint(p->board, p);
	i_board = -1;
	while (++i_board < p->b_hig)
	{
		j_board = -1;
		while (++j_board < p->b_len)
		{
			i_piece = -1;
			a = 0;
			b = 0;
			// dprintf(p->fd, "i_board: %d j_board: %d ", i_board, j_board);
			// dprintf(p->fd, "imx: %d jmx: %d\n", p->p_max_hig, p->p_max_len);
			if ((p->p_max_hig + i_board < p->b_hig)
				&& (p->p_max_len + j_board < p->b_len))
			{
				while (++i_piece < p->p_max_hig + 1)
				{
					j_piece = -1;
					while (++j_piece < p->p_max_len + 1)
					{
						i_tmp_b = i_piece + i_board;
						j_tmp_b = j_piece + j_board;
						// dprintf(p->fd, "| %c", p->piece[i_piece][j_piece]);
						// dprintf(p->fd, " | %c", p->board[i_tmp_b][j_tmp_b]);
						// dprintf(p->fd, " | i_p: %d", i_piece);
						// dprintf(p->fd, " | j_p: %d", j_piece);
						// dprintf(p->fd, " | i_tmp_b: %d", i_tmp_b);
						// dprintf(p->fd, " | j_tpm_b: %d", j_tmp_b);
						if (p->piece[i_piece][j_piece] == '*'
							&& p->board[i_tmp_b][j_tmp_b] == p->me_token)
							a++;
						if (p->piece[i_piece][j_piece] == '*'
							&& p->board[i_tmp_b][j_tmp_b] == p->av_token)
							b++;
						// dprintf(p->fd, "   |   a: %d | b: %d\n", a, b);
					}
				}
				if (a == 1 && b == 0)
				{
					// dprintf(p->fd, "final a: %d, b: %d\n", a, b);
					p->res_x = i_board;
					p->res_y = j_board;
					return (0);
				}
			}
		}
	}
	// dprintf(p->fd, "RETURN 0\n");
	return (0);
}
