/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 06:39:48 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/13 06:30:00 by cseguier         ###   ########.fr       */
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

	while (line[++i] != '\0')
	{
		if (!(ft_isdigit(line[i])) && line[i] != ' ' && line[i] != '.')
		{
			tab[p->cpt].player = line[i];
			tab[p->cpt].x = (i - 4) + p->cpt;
			tab[p->cpt].y = ft_atoi(line);
			p->cpt++;
		}
	}
	return (p->cpt);
}

int	get_piece_size(char *line, t_p *p)
{
	size_t	i;
	
	i = -1;
	while (!(ft_isdigit(line[++i]))) ;
	p->p_len = ft_atoi(line + i);
	while (line[++i] != ' ') ;
	p->p_hig = ft_atoi(line + i);
	if (!(p->p_data = (int*)ft_memalloc(sizeof(int) * p->p_len * p->p_hig)))
		return (0);
	return (0);
}

int	get_piece_data(char *line, t_p *p)
{
	int	i;

	i = -1;
	while (line[++i] != '\0')
		p->p_data[i + p->p_it] = line[i];
	return (i);
}

int	parser(t_p *p)
{
	char		*line;
	int			fd;
	size_t		i;
	t_coord		*tab;

	i = 1;
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
		if (ft_isdigit(line[0]))
		{
			p->cpt = get_content(line, tab, p);
		//	ft_printf("Gotcha content\n");
		}
		ft_printf("h: %d\n", p->p_hig);
		if (p->p_hig > 1)
		{
			p->p_it = get_piece_data(line, p);
			p->p_hig--;
		}
		if (ft_strstr(line, "Piece"))
		{
			ft_printf("is piece\n");
			new_node(tab, p);
			ft_printf("uh\n");
			get_piece_size(line, p);
		}
		ft_memdel((void*)&line);
	}
	for (int i = 0; i < 2*3; i++)
		ft_printf("%c ", p->p_data[i]);
	new_node(tab, p);
	return (0);
}


//  012
//  345

//     y = i / largeur
//     x = i - (largeur * y)

//   0  1  2  3  4  5  6
//   7  8  9 10 11 12 13
//  14 15 16 17 18 19 20

     