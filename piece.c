/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 01:45:44 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/15 05:19:11 by cseguier         ###   ########.fr       */
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
	p->p.i_piece = -1;
	p->p.a = 0;
	p->p.b = 0;
	if ((p->p_max_hig + i_brd < p->b_hig) && (p->p_max_len + j_brd < p->b_len))
	{
		while (++p->p.i_piece < p->p_max_hig + 1)
		{
			p->p.j_piece = -1;
			while (++p->p.j_piece < p->p_max_len + 1)
			{
				p->p.i_tmp = p->p.i_piece + i_brd;
				p->p.j_tmp = p->p.j_piece + j_brd;
				if (p->piece[p->p.i_piece][p->p.j_piece] == '*'
					&& p->board[p->p.i_tmp][p->p.j_tmp] == p->me_token)
					p->p.a++;
				if (p->piece[p->p.i_piece][p->p.j_piece] == '*'
					&& (p->board[p->p.i_tmp][p->p.j_tmp] == p->av_token
					|| p->board[p->p.i_tmp][p->p.j_tmp] == p->av_token + 32))
					p->p.b++;
			}
		}
		if (p->p.a == 1 && p->p.b == 0)
		{
			p->res_x = i_brd;
			p->res_y = j_brd;
			return (1);
		}
	}
	return (0);
}

int		find_nearest_enemy(t_p *p)
{
	// p->p.i_av = -1;
	// while (++p->p.i_av < p->b_hig)
	// {
	// 	p->p.j_av = -1;
	// 	while (++p->p.j_av < p->b_len)
	// 	{
	// 		if (p->board[p->p.i_av][p->p.j_av] == p->av_token)
	// 			return (1);
	// 	}
	// }

	int	i_board;
	int	j_board;
	int	i_tmp;
	int	j_tmp;
	
	i_board = -1;
	i_tmp = 0;
	j_tmp = 0;
	while (++i_board < p->b_hig)
	{
		j_board = -1;
		while (++j_board < p->b_len)
		{
			if(p->board[i_board][j_board] == p->av_token)
			{
				i_tmp
				j_tmp
				// compare
			}
	if (ft_abs(p->res_x - p->p.i_av) < ft_abs(p->tmp_x - p->p.i_av)
		|| ft_abs(p->res_y - p->p.j_av) < ft_abs(p->tmp_y - p->p.j_av));

		}
	}


	return (0);
}

int		is_closer(t_p *p)
{
	if (ft_abs(p->res_x - p->p.i_av) < ft_abs(p->tmp_x - p->p.i_av)
		|| ft_abs(p->res_y - p->p.j_av) < ft_abs(p->tmp_y - p->p.j_av))
		return (1);
	return (0);
}

/*
** enregistrer X le plus proche
** memoriser valeur de i et j valide pour poser piece
** si piece valide suivante plus proche, ecraser valeur
** (i_trouvé - i_adversaire > i_suivant - i_adverse)
** (j_trouvé - j_adversaire > j_suivant - j_adverse)
** si fin board, renvoyer meilleure valeur
*/

int		put_piece(t_p *p)
{
	int	i_board;
	int	j_board;

	fill_board(p);
	find_nearest_enemy(p);
	i_board = -1;
	while (++i_board < p->b_hig)
	{
		j_board = -1;
		while (++j_board < p->b_len)
		{
			if (is_ok(p, i_board, j_board) == 1)
			{
				// abs(i_suivant - i_adverse) < abs(i_trouvé - i_adversaire)
				// abs(j_suivant - j_adverse) < abs(j_trouvé - j_adversaire)
				if (is_closer(p))
				{	p->tmp_x = p->res_x;
					p->tmp_y = p->res_y;
				}
			}
		}
	}
	return (0);
}
