/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 06:42:17 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/28 05:25:44 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_tab(t_coord *tab, t_p *p)
{
	int	i;

	i = 0;
	while (++i < p->size)
	{
		tab[i].x = -1;
		tab[i].y = -1;
		tab[i].player = -1;
	}
}

void	init(t_p *p)
{
	p->board = NULL;
	p->p_len = 0;
	p->p_hig = 0;
	p->p_it = 0;
	p->p_max_len = 0;
	p->p_max_hig = 0;
	p->res_x = 0;
	p->res_y = 0;
	p->valid = 0;
	p->p_cpt = 0;
	p->b_len = 0;
	p->b_hig = 0;
	p->cpt = 0;
}

int		main(void)
{
	t_p p;

	if (-1 == (p.fd = open("res", O_WRONLY | O_CREAT | O_TRUNC)))
		return (0);
	//dprintf(p.fd, "AAAAAHHH\n");
	init(&p);
	p.first = NULL;
	p.me_token = 0;
	p.av_token = 0;
	p.size = 0;
	parser(&p);
//	display(&p);
	return (0);
}
