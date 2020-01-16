/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 05:54:24 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/16 02:17:54 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			get_piece_size(char *line, t_p *p)
{
	int	i;

	i = -1;
	while (!(ft_isdigit(line[++i])))
		;
	p->piece.hig = ft_atoi(line + i);
	p->piece.cpt = p->piece.hig;
	while (line[++i] != ' ')
		;
	p->piece.len = ft_atoi(line + i);
	i = -1;
	if (!(p->piece.content = ft_memalloc(sizeof(char*) * (p->piece.hig + 1))))
		return (-1);
	while (++i < p->piece.hig)
		if (!(p->piece.content[i] = ft_memalloc(sizeof(char) * (p->piece.len + 1))))
			return (-1);
	return (0);
}

int			get_piece_content(char *line, t_p *p)
{
	int	i;

	i = -1;
	while (line[++i])
		p->piece.content[p->piece.it][i] = line[i];
	p->piece.cpt--;
	return (p->piece.it++);
}

int			get_max_size(t_p *p)
{
	int	i;
	int	j;

	i = -1;
	while (++i < p->piece.hig)
	{
		j = -1;
		while (++j < p->piece.len)
		{
			if (p->piece[i][j] == '*')
			{
				if (p->piece.max_len < j)
					p->piece.max_len = j;
				if (p->piece.max_hig < i)
					p->piece.max_hig = i;
			}
		}
	}
	return (0);
}
