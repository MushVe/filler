/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 05:42:58 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/27 06:05:41 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		dracula(t_p *p, int newest)
{
	int	i;
	int	j;
	int	cpt;

	i = -1;
	j = -1;
	cpt = 0;
	while (++i < p->board.height)
	{
		while (++j < p->board.length)
		{
			if (p->hit_map[i][j] == newest)
				cpt++;
		}
		j = -1;
	}
	return (cpt);
}

void			fill_hit_map(t_p *p, int turn)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (p->board.data[++i].player != -1)
	{
		if (p->board.data[i].player == p->toi.token)
		{
			x = p->board.data[i].axis.x;
			y = p->board.data[i].axis.y;
			if (p->hit_map[y][x] == 0)
				p->hit_map[y][x] = turn;
		}
	}
}

int				create_hit_map(t_p *p, int turn)
{
	int	i;

	if (p->hit_map == NULL)
	{
		p->hit_map = ft_memalloc(sizeof(int *) * p->board.height);
		if (p->hit_map == NULL)
			return (0);
		i = -1;
		while (++i < p->board.height)
		{
			p->hit_map[i] = ft_memalloc(sizeof(int) * p->board.length);
			if (p->hit_map[i] == NULL)
				return (0);
		}
	}
	fill_hit_map(p, turn);
	return (1);
}

static t_axis	*create_enemy_coord(t_p *p, int newest)
{
	t_axis *enemy_coord;

	p->piece_size = dracula(p, newest);
	if (p->piece_size <= 0)
		return (NULL);
	if (!(enemy_coord = ft_memalloc(p->piece_size * sizeof(t_axis))))
		return (NULL);
	return (enemy_coord);
}

t_axis			*find_newest_enemy(t_p *p, int newest)
{
	int		x;
	int		y;
	int		cpt;
	t_axis	*enemy_coord;

	cpt = 0;
	x = -1;
	if (!(enemy_coord = create_enemy_coord(p, newest)))
		return (0);
	while (++x < p->board.height)
	{
		y = -1;
		while (++y < p->board.length)
		{
			if (p->hit_map[x][y] == newest)
			{
				enemy_coord[cpt].x = x;
				enemy_coord[cpt].y = y;
				if (cpt + 1 < p->piece_size)
					cpt++;
			}
		}
	}
	return (enemy_coord);
}
