/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 02:20:47 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/17 03:22:12 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	*create_row(t_p *p, int i)
{
	p->board.grid[i] = ft_memalloc(sizeof(char) * (p->board.length + 1));
	return (p->board.grid[i]);
}

static void	fill_blank_board(t_p *p)
{
	int	i;
	int	j;

	i = -1;
	while (++i < p->board.height)
	{
		j = -1;
		while (++j < p->board.length)
			p->board.grid[i][j] = '.';
	}
}

static void	fill_data_board(t_p *p)
{
	int i;
	int	x;
	int	y;

	i = -1;
	while (p->board.data[++i].player != -1)
	{
		x = p->board.data[i].axis.x;
		y = p->board.data[i].axis.y;
		p->board.grid[y][x] = p->board.data[i].player;
	}
}

int			fill_board(t_p *p)
{
	int	i;

	i = -1;
	if (!(p->board.grid = ft_memalloc(sizeof(char*) * (p->board.height + 1))))
		return (-1);
	while (++i < p->board.height)
		if (!(create_row(p, i)))
			return (-1);
	fill_blank_board(p);
	fill_data_board(p);
	return (0);
}
