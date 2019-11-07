/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:22:41 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/07 07:20:49 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void init_tab(t_coord *tab, t_p *p)
{
	int i = 0;
	while (++i < p->board_size)
	{
		tab[i].x = -1;
		tab[i].y = -1;
		tab[i].player = -1;
	}
}

int	main()
{
	t_p p;

	//init struct ect
	p.first = NULL;
	p.board_size = 0;
	ft_printf("Very start\n");
	parser(&p); //create and fill grid
	ft_printf("Grid created and filled\n");
//	ft_printf("%d\n", p.board_size);
//	printlist(&p);
//	display(&p); //print 
	ft_printf("End and OK\n");
	return (0);
}