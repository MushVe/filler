/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_reset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 05:50:29 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/27 06:22:15 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_tab(t_p *p)
{
	int	i;

	i = 0;
	while (++i < p->board.size)
	{
		p->board.data[i].axis.x = -1;
		p->board.data[i].axis.y = -1;
		p->board.data[i].player = -1;
	}
}

void	init(t_p *p)
{
	p->board.grid = NULL;
	p->board.size = 0;
	p->board.cpt = 0;
	p->piece.content = NULL;
	p->piece.length = 0;
	p->piece.height = 0;
	p->piece.max_length = 0;
	p->piece.max_height = 0;
	p->piece.it = 0;
	p->piece.cpt = 0;
	p->new_tmp.x = 0;
	p->new_tmp.y = 0;
	p->best_tmp.x = 0;
	p->best_tmp.y = 0;
	p->best_final.x = 0;
	p->best_final.y = 0;
	p->piece_size = 0;
}

void	init_once(t_p *p)
{
	p->end = 0;
	p->board.data = NULL;
	p->board.length = 0;
	p->board.height = 0;
	p->moi.token = 0;
	p->toi.token = 0;
	p->hit_map = NULL;
}

void	end_free(t_p *p)
{
	if (p->piece.content)
		ft_doublefree(p->piece.content);
	ft_doublefree_int(p->hit_map, p->board.height);
	ft_memdel((void*)&p->board.data);
}

void	reset_everything(t_p *p)
{
	ft_doublefree(p->piece.content);
	ft_doublefree(p->board.grid);
	ft_memdel((void*)&p->board.data);
	init(p);
}
