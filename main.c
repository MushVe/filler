/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:22:41 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/07 06:08:45 by cseguier         ###   ########.fr       */
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


void	hard1(t_coord *tab)
{
	int i = 0;
	tab[i].x = 5;
	tab[i].y = 10;
	tab[i].player = 'O';
	i++;
	tab[i].x = 7;
	tab[i].y = 4;
	tab[i].player = 'X';
	i++;
	tab[i].x = -1;
	tab[i].y = -1;
	tab[i].player = -1;
}

void	hard2(t_coord *tab)
{
	int i = 0;
	tab[i].x = 5;
	tab[i].y = 10;
	tab[i].player = 'o';
	i++;
	tab[i].x = 7;
	tab[i].y = 4;
	tab[i].player = 'X';
	i++;
	tab[i].x = 6;
	tab[i].y = 10;
	tab[i].player = 'o';
	i++;
	tab[i].x = 6;
	tab[i].y = 11;
	tab[i].player = 'o';
	i++;
	tab[i].x = -1;
	tab[i].y = -1;
	tab[i].player = -1;
}

void	hard3(t_coord *tab)
{
	int i = 0;
	tab[i].x = 5;
	tab[i].y = 10;
	tab[i].player = 'O';
	i++;
	tab[i].x = 7;
	tab[i].y = 4;
	tab[i].player = 'x';
	i++;
	tab[i].x = 6;
	tab[i].y = 10;
	tab[i].player = 'O';
	i++;
	tab[i].x = 6;
	tab[i].y = 11;
	tab[i].player = 'O';
	i++;
	tab[i].x = 8;
	tab[i].y = 4;
	tab[i].player = 'x';
	i++;
	tab[i].x = 9;
	tab[i].y = 4;
	tab[i].player = 'x';
	i++;
	tab[i].x = -1;
	tab[i].y = -1;
	tab[i].player = -1;

}

void	hard4(t_coord *tab)
{
	int i = 0;
	tab[i].x = 5;
	tab[i].y = 10;
	tab[i].player = 'O';
	i++;
	tab[i].x = 7;
	tab[i].y = 4;
	tab[i].player = 'X';
	i++;
	tab[i].x = 6;
	tab[i].y = 10;
	tab[i].player = 'o';
	i++;
	tab[i].x = 6;
	tab[i].y = 11;
	tab[i].player = 'o';
	i++;
	tab[i].x = 8;
	tab[i].y = 4;
	tab[i].player = 'X';
	i++;
	tab[i].x = 9;
	tab[i].y = 4;
	tab[i].player = 'X';
	i++;
	tab[i].x = 6;
	tab[i].y = 12;
	tab[i].player = 'o';
	i++;
	tab[i].x = 7;
	tab[i].y = 12;
	tab[i].player = 'o';
	i++;
	tab[i].x = -1;
	tab[i].y = -1;
	tab[i].player = -1;
}

int hardcode(t_p *p)
{
	t_coord	*tab;

	tab = NULL;

	if (!(tab = (t_coord*)ft_memalloc(sizeof(t_coord) * p->board_size)))
		return (0);
	//hardcode for test display

	ft_printf("Before INIT\n");
	init_tab(tab, p);
	printlist(p);
	ft_printf("Before fill tab\n");
	hard1(tab);
	printlist(p);
	ft_printf("Before new node\n");
	new_node(tab, p);
	ft_printf("First hardcode row ok\n");

	init_tab(tab, p);
	hard2(tab);
	new_node(tab, p);
	init_tab(tab, p);
	hard3(tab);
	new_node(tab, p);
	init_tab(tab, p);
	hard4(tab);
	new_node(tab, p);
	ft_printf("Hardcode end ok\n");

	return (0);
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
	parser(&p); //create grid
//	p.board_size = 15 * 17;
	ft_printf("Grid created\n");
	ft_printf("%d\n", p.board_size);
	hardcode(&p); //fill grid
	ft_printf("Content Hardcoded\n");
	printlist(&p);
	display(&p); //print 
	ft_printf("End and OK\n");
	return (0);
}