/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:22:41 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/05 06:46:35 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
# include <fcntl.h>


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
	tab[i].player = 'o';
	i++;
	tab[i].x = 7;
	tab[i].y = 4;
	tab[i].player = 'x';
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
	tab[i].player = 'x';
	i++;
	tab[i].x = 6;
	tab[i].y = 10;
	tab[i].player = 'o';
	i++;
	tab[i].x = 6;
	tab[i].y = 11;
	tab[i].player = 'o';
}

void	hard3(t_coord *tab)
{
	int i = 0;
	tab[i].x = 5;
	tab[i].y = 10;
	tab[i].player = 'o';
	i++;
	tab[i].x = 7;
	tab[i].y = 4;
	tab[i].player = 'x';
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
	tab[i].player = 'x';
	i++;
	tab[i].x = 9;
	tab[i].y = 4;
	tab[i].player = 'x';

}

void	hard4(t_coord *tab)
{
	int i = 0;
	tab[i].x = 5;
	tab[i].y = 10;
	tab[i].player = 'o';
	i++;
	tab[i].x = 7;
	tab[i].y = 4;
	tab[i].player = 'x';
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
	tab[i].player = 'x';
	i++;
	tab[i].x = 9;
	tab[i].y = 4;
	tab[i].player = 'x';
	i++;
	tab[i].x = 6;
	tab[i].y = 12;
	tab[i].player = 'o';
	i++;
	tab[i].x = 7;
	tab[i].y = 12;
	tab[i].player = 'o';
}

int hardcode(t_p *p)
{
	t_coord	*tab;

	tab = NULL;

	if (!(tab = (t_coord*)ft_memalloc(sizeof(t_coord) * p->board_size)))
		return (0);
	//hardcode for test display

	ft_printf("FFF\n");
	init_tab(tab, p);
	ft_printf("GGG\n");
	hard1(tab);
	ft_printf("HHH\n");
	new_node(tab, p);
	ft_printf("III\n");

	init_tab(tab, p);
	hard2(tab);
	new_node(tab, p);
	init_tab(tab, p);
	hard3(tab);
	new_node(tab, p);
	init_tab(tab, p);
	hard4(tab);
	new_node(tab, p);
	ft_printf("JJJ\n");

	return (0);
}

void parser(t_p *p)
{
	int		i;
	char	*line;
	int		fd;

	i = 1;
	line = NULL;
	fd = open("cam0", O_RDONLY);
	while (0 < (i = get_next_line(fd, &line)))
	{
		//just get grid size for the moment and go test display
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

	ft_printf("000\n");
	parser(&p); //create grid
	ft_printf("111\n");
	hardcode(&p); //fill grid
	ft_printf("222\n");
	display(&p); //print 
	ft_printf("333\n");
	return (0);
}