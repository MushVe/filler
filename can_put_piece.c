/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_put_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 04:19:56 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/16 05:21:46 by cseguier         ###   ########.fr       */
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
	if ((p->piece.max_hig + p->board.axis.x < p->board.hig)
		&& (p->piece.max_len + p->board.axis.y < p->board.len))
	{
		while (++p->piece.axis.x < p->piece.max_hig + 1)
		{
			p->piece.axis.y = -1;
			while (++p->piece.axis.y < p->piece.max_len + 1)
				contact_count(p);
		}
		if (p->moi.token_cpt == 1 && p->toi.token_cpt == 0)
		{
			p->new_res.x = p->board.axis.x;
			p->new_res.y = p->board.axis.y;
			return (1);
		}
	}
	return (0);
}