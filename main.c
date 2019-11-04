/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:22:41 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/04 05:16:12 by cseguier         ###   ########.fr       */
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

void hardcode()
{
	//hardcode for test display

}

void parser()
{
	get_next_line()
	{
		//just get grid size for the moment and go test display
	}
}

int	main()
{
	t_p p;
	//init struct ect
	parser(); //create grid
	hardcode(); //fill grid
	display(&p); //print 
	return (0);
}