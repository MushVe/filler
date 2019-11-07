/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:22:41 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/07 06:34:50 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
# include <fcntl.h>
#include <stdio.h>


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

void parser(t_p *p)
{
	int		i;
	char	*line;
	int		fd;

	i = 1;
	line = NULL;
	if (-1 == (fd = open("camO", O_RDONLY)))
		{
			ft_printf("error\n");
			return ;
		}
	while (0 < (i = get_next_line(fd, &line)))
	{
		//just get grid size for the moment and go test display
		ft_printf(line);
		if (ft_strstr(line, "Plateau"))
		{
			if (ft_strstr(line, "15 17"))
				p->board_size = 15 * 17;
			if (ft_strstr(line, "24 40"))
				p->board_size = 24 * 40;
			if (ft_strstr(line, "100 99"))
				p->board_size = 100 * 99;
			break;
		}
		free(line);
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
	ft_printf("%d\n", p.board_size);
	printlist(&p);
	display(&p); //print 
	ft_printf("End and OK\n");
	return (0);
}