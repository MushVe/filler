/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 01:45:44 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/17 02:39:14 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	doubleprint(char **s, t_p *p)
{
	int	i;

	i = -1;
	while (s[++i])
		dprintf(p->fd, "\t> %s\n", s[i]);
}

/*
int		find_nearest_enemy(t_p *p)
{
	// p->p.i_av = -1;
	// while (++p->p.i_av < p->board.height)
	// {
	// 	p->p.j_av = -1;
	// 	while (++p->p.j_av < p->board.length)
	// 	{
	// 		if (p->board.grid[p->p.i_av][p->p.j_av] == p->av_token)
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
	while (++i_board < p->board.height)
	{
		j_board = -1;
		while (++j_board < p->board.length)
		{
			if(p->board.grid[i_board][j_board] == p->toi.token)
			{
				i_tmp;
				j_tmp;
				// compare
			}
	if (ft_abs(p->new_res.x - p->p.i_av) < ft_abs(p->best_res.x - p->p.i_av)
		|| ft_abs(p->new_res.y - p->p.j_av) < ft_abs(p->best_res.y - p->p.j_av));

		}
	}


	return (0);
}

int		is_closer(t_p *p)
{
	if (ft_abs(p->new_res.x - p->p.i_av) < ft_abs(p->best_res.x - p->p.i_av)
		|| ft_abs(p->new_res.y - p->p.j_av) < ft_abs(p->best_res.y - p->p.j_av))
		return (1);
	return (0);
}


** enregistrer X le plus proche
** memoriser valeur de i et j valide pour poser piece
** si piece valide suivante plus proche, ecraser valeur
** (i_trouvé - i_adversaire > i_suivant - i_adverse)
** (j_trouvé - j_adversaire > j_suivant - j_adverse)
** si fin board, renvoyer meilleure valeur
*/
/*
int		put_piece(t_p *p)
{
	fill_board(p);
	find_nearest_enemy(p);
	p->board.axis.x = -1;
	while (++p->board.axis.x < p->board.height)
	{
		p->board.axis.y = -1;
		while (++p->board.axis.y < p->board.length)
		{
			if (can_put_piece(p) == 1)
			{
				// abs(i_suivant - i_adverse) < abs(i_trouvé - i_adversaire)
				// abs(j_suivant - j_adverse) < abs(j_trouvé - j_adversaire)
				if (is_closer(p))
				{
					p->best_res.x = p->new_res.x;
					p->best_res.y = p->new_res.y;
				}
			}
		}
	}
	return (0);
}
*/

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
	i_board = -1;
	while (++i_board < p->board.height)
	{
		j_board = -1;
		while (++j_board < p->board.length)
		{
			i_piece = -1;
			a = 0;
			b = 0;
			if ((p->piece.max_height + i_board < p->board.height)
				&& (p->piece.max_length + j_board < p->board.length))
			{
				while (++i_piece < p->piece.max_height + 1)
				{
					j_piece = -1;
					while (++j_piece < p->piece.max_length + 1)
					{
						i_tmp_b = i_piece + i_board;
						j_tmp_b = j_piece + j_board;
						if (p->piece.content[i_piece][j_piece] == '*'
							&& p->board.grid[i_tmp_b][j_tmp_b] == p->moi.token)
							a++;
						if (p->piece.content[i_piece][j_piece] == '*'
							&& p->board.grid[i_tmp_b][j_tmp_b] == p->toi.token)
							b++;
					}
				}
				if (a == 1 && b == 0)
				{
					p->best_res.x = i_board;
					p->best_res.y = j_board;
					return (0);
				}
			}
		}
	}
	return (0);
}
