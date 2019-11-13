/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 06:39:48 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/13 04:03:11 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

size_t	get_size(char *line)
{
	size_t	i;
	size_t	a;
	size_t	b;

	i = -1;
	while (!(ft_isdigit(line[++i]))) ;
	a = ft_atoi(line + i);
	while (line[++i] != ' ') ;
	b = ft_atoi(line + i);
	return (a * b);
}

size_t	get_content(char *line, t_coord *tab, t_p *p)
{
	size_t	i;
	i = -1;

//	ft_printf("i: ");
	while (line[++i] != '\0')
	{
	//	ft_printf("%d, ", i);
		if (!(ft_isdigit(line[i])) && line[i] != ' ' && line[i] != '.')
		{
		//	ft_printf("\nGet info: c: %c\tx: %d\ty: %d\t",
		//		line[i], i-4, ft_atoi(line));
			tab[p->cpt].player = line[i];
			tab[p->cpt].x = (i - 4) + p->cpt;
			tab[p->cpt].y = ft_atoi(line);
			p->cpt++;
//	ft_printf("cpt?? %d\n", p->cpt);

//	ft_printf("info ok\n");
		}
	}
	return (p->cpt);
}

int	parser(t_p *p)
{
	char		*line;
	int			fd;
	size_t		i;
	t_coord		*tab;

	i = 1;
	p->cpt = 0;
	line = NULL;
//	ft_printf("Parser go in\n");
	if (-1 == (fd = open("camO", O_RDONLY)))
	{
	//	ft_printf("error\n");
		return (0);
	}
	while (0 < (i = get_next_line(fd, &line)))
	{
	// ft_printf(line);
		if (ft_strstr(line, "$$$ exec p1"))
		{
			if (ft_strstr(line, "cseguier"))
				p->player_token = 'o';
			else
				p->player_token = 'x';
		//	ft_printf("Gotcha player\n");
		}
		if (p->size == 0 && ft_strstr(line, "Plateau"))
		{
			p->size = get_size(line);
		//	ft_printf("Gotcha plato\n");
			if (!(tab = (t_coord*)ft_memalloc(sizeof(t_coord) * p->size)))
				return (0);
		//	ft_printf("Malloc ok\n");
			init_tab(tab, p);
		//	ft_printf("Init Tab ok\n");
		}
		if (ft_strstr(line, "<got"))
		{
			new_node(tab, p);
			return (0);
		}
		
		if (ft_isdigit(line[0]))
		{
			p->cpt = get_content(line, tab, p);
		//	ft_printf("Gotcha content\n");
		}
		free(line);
	}
	new_node(tab, p);
	return (0);
}