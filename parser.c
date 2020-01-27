/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 06:39:48 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/27 06:19:46 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

int		get_infos(t_p *p, char *line)
{
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
	return (1);
}

int		parser(t_p *p)
{
	char	*line;
	int		i;

	i = 1;
	line = NULL;
	while (0 < (i = get_next_line(0, &line)))
	{
		if (!(get_infos(p, line)))
			return (0);
		if (p->piece.cpt == 0 && p->piece.it != 0 && p->end == 0)
		{
			p->piece.it = 0;
			get_max_size(p);
			put_piece(p);
			reset_everything(p);
		}
		if (ft_strstr(line, "Piece"))
			get_piece_size(line, p);
		ft_memdel((void *)&line);
	}
	return (0);
}
