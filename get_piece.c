/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 05:54:24 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/27 05:57:21 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_piece_size(char *line, t_p *p)
{
	int	i;
	
	i = -1;
	while (!(ft_isdigit(line[++i]))) ;
	p->p_hig = ft_atoi(line + i);
	p->p_cpt = ft_atoi(line + i);
	while (line[++i] != ' ') ;
	p->p_len = ft_atoi(line + i);
	i = -1;
	if (!(p->piece = (char**)ft_memalloc(sizeof(char*) * (p->p_hig + 1))))
		return (-1);
	while (++i < p->p_hig)
		if (!(p->piece[i] = (char*)ft_memalloc(sizeof(char) * (p->p_len + 1))))
			return (-1);
	return (0);
}

int		get_piece_data(char *line, t_p *p)
{
	int	i;

	i = -1;
	while (line[++i])
		p->piece[p->p_it][i] = line[i];
	p->p_cpt--;
	return (p->p_it++);
}

static int	get_true_len(int i, int j, t_p *p)
{
	int	first;
	int last;

	while (p->piece[j][++i])
	{
		first = -1;
		last = -1;
		if (p->piece[j][i] == '*')
		{
			if (first == -1)
				first = i;
			last = i;
		}
	}
	if (p->p_true_len < (last - first))
		p->p_true_len = last - first;
	return (0);
}

static int	get_true_hig(int i, int j, t_p *p)
{
	int	check;

	p->p_true_hig = p->p_hig;
	while (++i < p->p_hig)
	{
		j = -1;
		check = 0;
		while (p->piece[i][++j])
			if (p->piece[i][j] == '*')
				check++;
		if (check != 0)
			p->p_true_hig--;
	}
	return (0);
}

int		get_true_size(t_p *p)
{
	int	i;

	i = -1;
	while (p->piece[++i])
		get_true_len(-1, i, p);
	get_true_hig(-1, -1, p);
	
	return (0);
}
