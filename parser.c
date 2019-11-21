/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 06:39:48 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/21 06:43:16 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

size_t get_size(char *line, t_p *p)
{
	size_t i;

	i = -1;
	while (!(ft_isdigit(line[++i])))
		;
	p->b_hig = ft_atoi(line + i);
	while (line[++i] != ' ')
		;
	p->b_len = ft_atoi(line + i);
	return (p->b_len * p->b_hig);
}

size_t get_board(char *line, t_coord *tab, t_p *p)
{
	size_t i;
	i = -1;

	while (line[++i] != '\0')
	{
		if (!(ft_isdigit(line[i])) && line[i] != ' ' && line[i] != '.')
		{
			tab[p->cpt].player = line[i];
			tab[p->cpt].x = (i - 4);
			tab[p->cpt].y = ft_atoi(line);
			p->cpt++;
		}
	}
	return (0);
}

int parser(t_p *p)
{
	char *line;
	size_t i;
	t_coord *tab;
	int res;
	int res_y;
	int res_x;

	i = 1;
	line = NULL;


		dprintf(p->fd, "aller la\n");
	// int camo;
	// if (-1 == (camo = open("camO", O_RDONLY)))
	// 	return (0);
	// while (0 < (i = get_next_line(camo, &line)))
	while (0 < (i = get_next_line(0, &line)))
	{
		dprintf(p->fd, "> %s\n", line);
		if (ft_strstr(line, " fin: "))
			return (0);
		if (ft_strstr(line, "$$$ exec"))
		{
			if (ft_strstr(line, "p1"))
				p->token = 'o';
			else
				p->token = 'x';
			dprintf(p->fd, "player? %c\n", p->token);
		}
		if (p->size == 0 && ft_strstr(line, "Plateau"))
		{
			p->size = get_size(line, p);
			if (!(tab = (t_coord *)ft_memalloc(sizeof(t_coord) * p->size)))
				return (0);
			init_tab(tab, p);
		}
		if (ft_isdigit(line[0]))
			get_board(line, tab, p);
		if (p->p_hig > 0)
		{
		//	dprintf(p->fd, "get piece h: %d, line: %s\n", p->p_hig, line);
			p->p_it = get_piece_data(line, p);
			p->p_hig--;
		}
		if (p->p_hig == 0 && p->p_it != 0)
		{
			p->p_it = 0;
			res = put_piece(p);
			dprintf(p->fd, "res: %d, len: %d\n", res, (int)p->b_len);
			res_y = res / p->b_len;
			res_x = res - (p->b_len * res_y);
			dprintf(p->fd, "\tpiece output: ");
			dprintf(p->fd, "%d %d\n", res_y, res_x);
			ft_printf("%d %d\n", res_y, res_x);
			ft_memdel((void *)&p->p_data);
		}
		if (ft_strstr(line, "Piece"))
		{
			dprintf(p->fd, "size maggle?");
			new_node(tab, p);
			get_piece_size(line, p);
			dprintf(p->fd, "%d %d\n", p->p_hig, p->p_len);
		}
		ft_memdel((void *)&line);
	}
	return (0);
}
