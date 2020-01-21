/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_put_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 04:19:56 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/21 05:57:19 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	is_moi_contact(t_p *p, t_axis to_put)
{
	return (p->piece.content[p->piece.axis.x][p->piece.axis.y] == '*'
		&& p->board.grid[to_put.x][to_put.y] == p->moi.token);
}

static int	is_toi_contact(t_p *p, t_axis to_put)
{
	return (p->piece.content[p->piece.axis.x][p->piece.axis.y] == '*'
		&& p->board.grid[to_put.x][to_put.y] == p->toi.token);
}

static void	contact_count(t_p *p)
{
	t_axis	to_put;

	to_put.x = p->piece.axis.x + p->board.axis.x;
	to_put.y = p->piece.axis.y + p->board.axis.y;
	if (is_moi_contact(p, to_put))
		p->moi.token_cpt++;
	if (is_toi_contact(p, to_put))
		p->toi.token_cpt++;
}

int			can_put_piece(t_p *p)
{
	p->piece.axis.x = -1;
	p->moi.token_cpt = 0;
	p->toi.token_cpt = 0;
	if ((p->piece.max_height + p->board.axis.x < p->board.height)
		&& (p->piece.max_length + p->board.axis.y < p->board.length))
	{
		while (++p->piece.axis.x < p->piece.max_height + 1)
		{
			p->piece.axis.y = -1;
			while (++p->piece.axis.y < p->piece.max_length + 1)
				contact_count(p);
		}
		if (p->moi.token_cpt == 1 && p->toi.token_cpt == 0)
		{
			p->new_tmp.x = p->board.axis.x;
			p->new_tmp.y = p->board.axis.y;
			return (1);
		}
	}
	return (0);
}
