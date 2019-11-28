/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 06:39:48 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/28 05:28:46 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_size(char *line, t_p *p)
{
	int	i;

	i = -1;
	while (!(ft_isdigit(line[++i])))
		;
	p->b_hig = ft_atoi(line + i);
	while (line[++i] != ' ')
		;
	p->b_len = ft_atoi(line + i);
	return (p->b_len * p->b_hig);
}

void	get_players(char *line, t_p *p)
{
	if (ft_strstr(line, "p1"))
	{
		p->me_token = 'O';
		p->av_token = 'X';
	}
	else
	{
		p->me_token = 'X';
		p->av_token = 'O';
	}
	dprintf(p->fd, "player? me: %c av: %c\n", p->me_token, p->av_token);
}

int		get_board(char *line, t_coord *tab, t_p *p)
{
	int	i;

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

int		get_board_init(char *line, t_coord **tab, t_p *p)
{
	p->size = get_size(line, p);
	if (!(*tab = (t_coord *)ft_memalloc(sizeof(t_coord) * p->size)))
		return (-1);
	init_tab(*tab, p);
	return (0);
}

int		parser(t_p *p)
{
	char	*line;
	int		i;
	t_coord	*tab;

	i = 1;
	line = NULL;
	tab = NULL;
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
			p->p_it = 0;
			get_max_size(p);
			put_piece(p);
			dprintf(p->fd, "%d %d\n", p->res_y, p->res_x);
			ft_printf("%d %d\n", p->res_x, p->res_y);
			new_node(tab, p);
			ft_doublefree(p->piece);
			ft_doublefree(p->board);
			init(p);
		}
		if (ft_strstr(line, "Piece"))
		{
			dprintf(p->fd, "piece size? ");
			new_node(tab, p);
			get_piece_size(line, p);
			dprintf(p->fd, "hig: %d len: %d\n", p->p_hig, p->p_len);
		}
		ft_memdel((void *)&line);
	}
	return (0);
}
