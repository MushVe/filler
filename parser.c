/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 06:39:48 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/22 06:34:03 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int get_size(char *line, t_p *p)
{
	int i;

	i = -1;
	while (!(ft_isdigit(line[++i])))
		;
	p->b_hig = ft_atoi(line + i);
	while (line[++i] != ' ')
		;
	p->b_len = ft_atoi(line + i);
	return (p->b_len * p->b_hig);
}

int get_board(char *line, t_coord *tab, t_p *p)
{
	int i;
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

void get_players(char *line, t_p *p)
{
	if (ft_strstr(line, "p1"))
		p->token = 'o';
	else
		p->token = 'x';
	dprintf(p->fd, "player? %c\n", p->token);
}

int	get_board_init(char *line, t_coord **tab, t_p *p)
{
	p->size = get_size(line, p);
	if (!(*tab = (t_coord *)ft_memalloc(sizeof(t_coord) * p->size)))
		return (-1);
	init_tab(*tab, p);
	return (0);
}

int parser(t_p *p)
{
	char *line;
	int i;
	t_coord *tab;
	int res;
	int res_y;
	int res_x;

	i = 1;
	line = NULL;
	tab = NULL;


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
			get_players(line, p);
		if (p->size == 0 && ft_strstr(line, "Plateau"))
			get_board_init(line, &tab, p);
		if (ft_isdigit(line[0]))
			get_board(line, tab, p);
		if (p->p_cpt > 0)
			get_piece_data(line, p);
		if (p->p_cpt == 0 && p->p_it != 0)
		{
			dprintf(p->fd, "\tTAB\n");
			ft_doubleprint(p->piece);
			dprintf(p->fd, "\tPAS TAB\n");
			p->p_it = 0;
			get_true_size(p);
			res = put_piece(p);
			dprintf(p->fd, "res: %d, len: %d\n", res, p->b_len);
			res_y = res / p->b_len;
			res_x = res - (p->b_len * res_y);
			dprintf(p->fd, "\tpiece output: ");
			dprintf(p->fd, "%d %d\n", res_x, res_y);
			ft_printf("%d %d\n", res_x, res_y);
			ft_doublefree(p->piece);
		}
		if (ft_strstr(line, "Piece"))
		{
			dprintf(p->fd, "size maggle? ");
			new_node(tab, p);
			get_piece_size(line, p);
			dprintf(p->fd, "%d %d\n", p->p_hig, p->p_len);
		}
		ft_memdel((void *)&line);
	}
	return (0);
}
