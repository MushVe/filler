/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 05:54:24 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/27 06:21:57 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		*create_piece(t_p *p)
{
	p->piece.content = ft_memalloc(sizeof(char*) * (p->piece.height + 1));
	return (p->piece.content);
}

void		*create_piece_row(t_p *p, int i)
{
	p->piece.content[i] = ft_memalloc(sizeof(char) * (p->piece.length + 1));
	return (p->piece.content[i]);
}

int			get_piece_size(char *line, t_p *p)
{
	int	i;

	i = -1;
	while (!(ft_isdigit(line[++i])))
		;
	p->piece.height = ft_atoi(line + i);
	p->piece.cpt = p->piece.height;
	while (line[++i] != ' ')
		;
	p->piece.length = ft_atoi(line + i);
	i = -1;
	if (!(create_piece(p)))
		return (-1);
	while (++i < p->piece.height)
		if (!(create_piece_row(p, i)))
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
	while (++i < p->piece.height)
	{
		j = -1;
		while (++j < p->piece.length)
		{
			if (p->piece.content[i][j] == '*')
			{
				if (p->piece.max_length < j)
					p->piece.max_length = j;
				if (p->piece.max_height < i)
					p->piece.max_height = i;
			}
		}
	}
	return (0);
}
