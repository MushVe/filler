/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 06:42:17 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/22 02:39:43 by cseguier         ###   ########.fr       */
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
	p->new_final.x = 0;
	p->new_final.y = 0;
	p->best_final.x = 0;
	p->best_final.y = 0;
}


void	init_once(t_p *p)
{
	p->board.data = NULL;
	p->board.length = 0;
	p->board.height = 0;
	p->moi.token = 0;
	p->toi.token = 0;
}

void	printlist(t_p *p)
{
	int	i;

	i = -1;
	dprintf(p->data_fd, "H%dL%d\n", p->board.height, p->board.length);
	while ((++i < p->board.height * p->board.length)
		&& p->board.data[i].player != -1
		&& p->board.data[i].axis.x != -1
		&& p->board.data[i].axis.y)
	{
		dprintf(p->data_fd, "x%d", p->board.data[i].axis.x);
		dprintf(p->data_fd, "y%d", p->board.data[i].axis.y);
		dprintf(p->data_fd, "p%d", p->board.data[i].player);
		dprintf(p->data_fd, "\n");
	}
	dprintf(p->data_fd, "u");
}

int		main(void)
{
	t_p p;

	if (-1 == (p.res_fd = open("res", O_WRONLY | O_CREAT | O_TRUNC)))
		return (0);
	if (-1 == (p.data_fd = open("data", O_WRONLY | O_CREAT | O_TRUNC)))
		return (0);
	//dprintf(p.res_fd, "AAAAAHHH\n");
	init(&p);
	init_once(&p);
	parser(&p);
	close(p.res_fd);
	//close(p.data_fd);
	// display(&p);
	return (0);
}
