/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 01:45:44 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/20 10:57:57 by cseguier         ###   ########.fr       */
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

void	count_toi_token(t_p *p)
{
	p->toi.token_cpt = 0;
	while (++p->board.axis.x < p->board.height)
	{
		p->board.axis.y = -1;
		while (++p->board.axis.y < p->board.length)
		{
			if(p->board.grid[p->board.axis.x][p->board.axis.y] == p->toi.token)
				p->toi.token_cpt++;
		}
	}
}

int		create_token_tab(t_p *p)
{
	int	size;
	int	i;

	i = -1;
	size = sizeof(t_axis) * (p->toi.token_cpt + 1);
	if (!(p->toi.locations = ft_memalloc(size)))
		return (0);
	while (++i < size)
	{
		p->toi.locations[i].x = -1; 
		p->toi.locations[i].y = -1;
	}
	return (1);
}

void	find_toi_token(t_p *p)
{
	int	i;

	i = -1;
	count_toi_token(p);
	if (!(create_token_tab(p)))
		return (0);
	p->board.axis.x = -1;
	while (++p->board.axis.x < p->board.height)
	{
		p->board.axis.y = -1;
		while (++p->board.axis.y < p->board.length)
		{
			if(p->board.grid[p->board.axis.x][p->board.axis.y] == p->toi.token)
			{
				p->toi.locations[++i].x = p->board.axis.x;
				p->toi.locations[i].y = p->board.axis.y;
			}
		}
	}
	return (0);
}

t_axis	get_close_toi(t_axis new_res, t_axis best_res, t_axis *toi_locations)
{
	
}

int		is_closer(t_axis new_res, t_axis best_res, t_axis *toi_locations)
{
	t_axis	new_position;
	t_axis	best_position;
	t_axis	close_toi;

	close_toi = get_close_toi(new_res, best_res, toi_locations);
	new_position.x = ft_abs(new_res.x - close_toi.x);
	new_position.y = ft_abs(new_res.y - close_toi.y);
	best_position.x = ft_abs(best_res.x - close_toi.x);
	best_position.y = ft_abs(best_res.y - close_toi.y);
	if (new_position.x < best_position.x || new_position.y < best_position.y)
		return (1);
	return (0);
}

/*
** enregistrer X le plus proche
** memoriser valeur de i et j valide pour poser piece
** si piece valide suivante plus proche, ecraser valeur
** (x_trouvé - x_adversaire > x_suivant - x_adverse)
** (y_trouvé - y_adversaire > y_suivant - y_adverse)
** si fin board, renvoyer meilleure valeur
*/

int		put_piece(t_p *p)
{
	fill_board(p);
	find_toi_token(p);
	p->board.axis.x = -1;
	while (++p->board.axis.x < p->board.height)
	{
		p->board.axis.y = -1;
		while (++p->board.axis.y < p->board.length)
		{
			if (can_put_piece(p) == 1)
			{
				// abs(x_suivant - x_adverse) < abs(x_trouvé - x_adversaire)
				// abs(y_suivant - y_adverse) < abs(y_trouvé - y_adversaire)
				if (is_closer(p->new_res, p->best_res, p->toi.locations))
				{
					p->best_res.x = p->new_res.x;
					p->best_res.y = p->new_res.y;
				}
			}
		}
	}
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
