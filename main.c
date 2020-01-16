/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 06:42:17 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/16 04:38:19 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_tab(t_p *p)
{
	int	i;

	i = 0;
	while (++i < p->size)
	{
		p->board.data[i].x = -1;
		p->board.data[i].y = -1;
		p->board.data[i].player = -1;
	}
}

void	init(t_p *p)
{
	p->board.grid = NULL;
	p->piece.len = 0;
	p->piece.hig = 0;
	p->piece.max_len = 0;
	p->piece.max_hig = 0;
	p->piece.it = 0;
	p->piece.cpt = 0;
	p->res_x = 0;
	p->res_y = 0;
	p->tmp_x = 0;
	p->tmp_y = 0;
	p->valid = 0;
	p->size = 0;
	p->cpt = 0;
}


void	init(t_p *p)
{
	p->board.data = NULL;
	p->board.len = 0;
	p->board.hig = 0;
	p->me__token = 0;
	p->adv_token = 0;
}

// void	printlist(t_p *p)
// {
// 	int	i;

// 	i = -1;
// 	dprintf(p->data_fd, "H%dL%d\n", p->b_hig, p->b_len);
// 	while (++i < p->b_hig * p->b_len)
// 	{
// 		dprintf(p->data_fd, "x%d", p->tab[i].x);
// 		dprintf(p->data_fd, "y%d", p->tab[i].y);
// 		dprintf(p->data_fd, "p%d", p->tab[i].player);
// 		dprintf(p->data_fd, "\n");
// 	}
// 	dprintf(p->data_fd, "u");
// }

int		main(void)
{
	t_p p;

	if (-1 == (p.fd = open("res", O_WRONLY | O_CREAT | O_TRUNC)))
		return (0);
	//if (-1 == (p.data_fd = open("data", O_WRONLY | O_CREAT | O_TRUNC)))
	//	return (0);
	//dprintf(p.fd, "AAAAAHHH\n");
	init(&p);
	init_once(&p);
	parser(&p);
	close(p.fd);
	//close(p.data_fd);
	// display(&p);
	return (0);
}
