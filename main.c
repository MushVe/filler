/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 06:42:17 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/15 04:18:01 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_tab(t_p *p)
{
	int	i;

	i = 0;
	while (++i < p->size)
	{
		p->tab[i].x = -1;
		p->tab[i].y = -1;
		p->tab[i].player = -1;
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
	p->tmp_x = 0;
	p->tmp_y = 0;
	p->valid = 0;
	p->p_cpt = 0;
	p->size = 0;
	p->cpt = 0;
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
	p.tab = NULL;
	p.me_token = 0;
	p.av_token = 0;
	p.b_len = 0;
	p.b_hig = 0;
	parser(&p);
	close(p.fd);
	//close(p.data_fd);
	// display(&p);
	return (0);
}
