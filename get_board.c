/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 05:53:48 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/27 05:54:07 by cseguier         ###   ########.fr       */
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
	if (p->board.cpt == p->board.size)
	{
		p->end = 1;
		ft_printf("0 0\n");
	}
	return (0);
}
