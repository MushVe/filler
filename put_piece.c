/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 01:45:44 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/22 05:14:05 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	doubleprint(char **s, t_p *p)
{
	int	i;

	i = -1;
	while (s[++i])
		dprintf(p->res_fd, "\t> %s\n", s[i]);
}

/*
** enregistrer X le plus proche
** memoriser valeur de i et j valide pour poser piece
** si piece valide suivante plus proche, ecraser valeur
** (x_trouvé - x_adversaire > x_suivant - x_adverse)
** (y_trouvé - y_adversaire > y_suivant - y_adverse)
** si fin board, renvoyer meilleure valeur
*/


int		is_closer(t_axis new_res, t_axis best_res, t_axis token_tested)
{
	t_axis	new_position;
	t_axis	best_position;

	new_position.x = ft_abs(new_res.x - token_tested.x);
	new_position.y = ft_abs(new_res.y - token_tested.y);
	best_position.x = ft_abs(best_res.x - token_tested.x);
	best_position.y = ft_abs(best_res.y - token_tested.y);
	if (new_position.x < best_position.x || new_position.y < best_position.y)
		return (1);
	return (0);
}

void	find_closest_ennemy(t_p *p)
{
	int		i;

	i = -1;
	while (++i && !(p->board.data[i].player != -1))
	{
		if (p->board.data[i].player == p->toi.token)
		{
			if (is_closer(p->new_tmp, p->best_tmp, p->board.data[i].axis))
			{
				p->best_tmp.x = p->new_tmp.x;
				p->best_tmp.y = p->new_tmp.y;
			}
		}
	}
}

t_axis	find_best_location(t_p *p)
{
	p->board.axis.x = -1;
	while (++p->board.axis.x < p->board.height)
	{
		p->board.axis.y = -1;
		while (++p->board.axis.y < p->board.length)
		{
			if (can_put_piece(p) == 1) // new_res affectect here
			{
				find_closest_ennemy(p);
				if (is_closer(p->new_final, p->best_final, p->best_tmp))
				{
					p->best_final.x = p->new_final.x;
					p->best_final.y = p->new_final.y;
				}
			}
		}
	}
	return (p->best_tmp);
}


int		put_piece(t_p *p)
{
	dprintf(p->res_fd, "before fill board\n");
	fill_board(p);
	dprintf(p->res_fd, "before find_best\n");
	find_best_location(p); // new affectect here in can_put_piece()
	dprintf(p->res_fd, "end put_piece\n");
	return (0);
}

/*
int		put_piece(t_p *p)
{
	int	x_board;
	int	y_board;
	int	x_tmp_b;
	int	y_tmp_b;
	int	x_piece;
	int	y_piece;
	int	a;
	int	b;

	fill_board(p);
	x_board = -1;
	while (++x_board < p->board.height)
	{
		y_board = -1;
		while (++y_board < p->board.length)
		{
			x_piece = -1;
			a = 0;
			b = 0;
			if ((p->piece.max_height + x_board < p->board.height)
				&& (p->piece.max_length + y_board < p->board.length))
			{
				while (++x_piece < p->piece.max_height + 1)
				{
					y_piece = -1;
					while (++y_piece < p->piece.max_length + 1)
					{
						x_tmp_b = x_piece + x_board;
						y_tmp_b = y_piece + y_board;
						if (p->piece.content[x_piece][y_piece] == '*'
							&& p->board.grid[x_tmp_b][y_tmp_b] == p->moi.token)
							a++;
						if (p->piece.content[x_piece][y_piece] == '*'
							&& p->board.grid[x_tmp_b][y_tmp_b] == p->toi.token)
							b++;
					}
				}
				if (a == 1 && b == 0)
				{
					p->best_res.x = x_board;
					p->best_res.y = y_board;
					return (0);
				}
			}
		}
	}
	return (0);
}
*/
