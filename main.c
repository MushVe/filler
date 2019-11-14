/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:22:41 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/14 05:30:51 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void init_tab(t_coord *tab, t_p *p)
{
	size_t	i = 0;
	while (++i < p->size)
	{
		tab[i].x = -1;
		tab[i].y = -1;
		tab[i].player = -1;
	}
}

void	init(t_p *p)
{
	p->first = NULL;
	p->p_data = NULL;
	p->board = NULL;
	p->player_token = 0;
	p->p_len = 0;
	p->p_hig = 0;
	p->p_it = 0;
	p->board_len = 0;
	p->board_hig = 0;
	p->size = 0;
	p->cpt = 0;
}

int	main()
{
	t_p p;

	//init struct ect
	init(&p);
//	ft_printf("Very start\n");
	parser(&p); //create and fill grid
//	ft_printf("Grid created and filled\n");
//	ft_printf("size = %d\n", p.size);
//	printlist(&p);
	display(&p); //print
	put_piece(&p);
	
//	ft_printf("End and OK\n");
	return (0);
}