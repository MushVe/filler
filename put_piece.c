/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 01:45:44 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/27 05:57:02 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_closer(t_p *p, t_axis *enemy_coord, int size, t_axis *best_dist)
{
	t_axis	valid_pos;
	t_axis	abs_dist;
	int		res;
	int		i;

	i = -1;
	res = 0;
	valid_pos.x = p->new_tmp.x;
	valid_pos.y = p->new_tmp.y;
	while (++i < size)
	{
		abs_dist.x = ft_abs(valid_pos.x - enemy_coord[i].x);
		abs_dist.y = ft_abs(valid_pos.y - enemy_coord[i].y);
		if (best_dist->x >= abs_dist.x && best_dist->y >= abs_dist.y)
		{
			best_dist->x = abs_dist.x;
			best_dist->y = abs_dist.y;
			res = 1;
		}
	}
	return (res);
}

void	find_best_location(t_p *p, int turn)
{
	t_axis *enemy_coord;
	t_axis best_dist;

	p->board.axis.x = -1;
	enemy_coord = NULL;
	best_dist.x = INT_MAX;
	best_dist.y = INT_MAX;
	while (++p->board.axis.x < p->board.height)
	{
		p->board.axis.y = -1;
		while (++p->board.axis.y < p->board.length)
		{
			if (can_put_piece(p) == 1)
			{
				if (!(enemy_coord = find_newest_enemy(p, turn)))
					return ;
				if (is_closer(p, enemy_coord, p->piece_size, &best_dist))
				{
					p->best_final.x = p->new_tmp.x;
					p->best_final.y = p->new_tmp.y;
				}
			}
			ft_memdel((void*)&enemy_coord);
		}
	}
}

int		put_piece(t_p *p)
{
	fill_board(p);
	if (!(create_hit_map(p, 1)))
		return (-1);
	find_best_location(p, 1);
	ft_printf("%d %d\n", p->best_final.x, p->best_final.y);
	return (0);
}
