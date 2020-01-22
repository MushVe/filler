/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 06:39:48 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/22 06:58:32 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_board_size(char *line, t_p *p)
{
	int	i;

	i = -1;
	while (!(ft_isdigit(line[++i])))
		;
	p->board.height = ft_atoi(line + i);
	while (line[++i] != ' ')
		;
	p->board.length = ft_atoi(line + i);
	return (p->board.length * p->board.height);
}

int		get_board_data(char *line, t_p *p)
{
	int	i;

	i = -1;
	while (line[++i] != '\0')
	{
		if (!(ft_isdigit(line[i])) && line[i] != ' ' && line[i] != '.')
		{
			p->board.data[p->board.cpt].player = line[i];
			p->board.data[p->board.cpt].axis.x = (i - 4);
			p->board.data[p->board.cpt].axis.y = ft_atoi(line);
			p->board.cpt++;
		}
	}
	return (0);
}

void	get_players(char *line, t_p *p)
{
	if (ft_strstr(line, "p1"))
	{
		p->moi.token = 'O';
		p->toi.token = 'X';
	}
	else
	{
		p->moi.token = 'X';
		p->toi.token = 'O';
	}
}

int		init_board(char *line, t_p *p)
{
	p->board.size = get_board_size(line, p);
	if (!(p->board.data = ft_memalloc(sizeof(t_data) * p->board.size)))
		return (-1);
	init_tab(p);
	return (0);
}

void	reset_everything(t_p *p)
{
// 	ft_memdel((void*)&p->tab);
	ft_doublefree(p->piece.content);
	ft_doublefree(p->board.grid);
	init(p);
}

int		parser(t_p *p)
{
	char	*line;
	int		i;

	i = 1;
	line = NULL;
	while (0 < (i = get_next_line(0, &line)))
	{
		// dprintf(p->res_fd, "> %s\n", line);
		if (ft_strstr(line, " fin: "))
			return (0);
		if (ft_strstr(line, "$$$ exec"))
			get_players(line, p);
		if (p->board.size == 0 && ft_strstr(line, "Plateau"))
			init_board(line, p);
		if (ft_isdigit(line[0]))
			get_board_data(line, p);
		if (p->piece.cpt > 0)
			get_piece_content(line, p);
		if (p->piece.cpt == 0 && p->piece.it != 0)
		{
			// dprintf(p->res_fd, "Enter if\n");
			p->piece.it = 0;
			// dprintf(p->res_fd, "before get max size\n");
			get_max_size(p);
			// dprintf(p->res_fd, "before put piece\n");
			put_piece(p);
			// dprintf(p->res_fd, "after print\n");
			reset_everything(p);
			printlist(p);
		}
		if (ft_strstr(line, "Piece"))
			get_piece_size(line, p);
		ft_memdel((void *)&line);
	}
	return (0);
}
