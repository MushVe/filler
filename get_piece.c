/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 05:54:24 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/28 00:37:52 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			get_piece_size(char *line, t_p *p)
{
	int	i;
	
	i = -1;
	while (!(ft_isdigit(line[++i])))
		;
	p->p_hig = ft_atoi(line + i);
	p->p_cpt = p->p_hig;
	while (line[++i] != ' ')
		;
	p->p_len = ft_atoi(line + i);
	i = -1;
	if (!(p->piece = (char**)ft_memalloc(sizeof(char*) * (p->p_hig + 1))))
		return (-1);
	while (++i < p->p_hig)
		if (!(p->piece[i] = (char*)ft_memalloc(sizeof(char) * (p->p_len + 1))))
			return (-1);
	return (0);
}

int			get_piece_data(char *line, t_p *p)
{
	int	i;

	i = -1;
	while (line[++i])
		p->piece[p->p_it][i] = line[i];
	p->p_cpt--;
	return (p->p_it++);
}

int			get_max_size(t_p *p)
{
	int	i;
	int	j;

	i = -1;
	while (++i < p->p_hig)
	{
		j = -1;
		while (++j < p->p_len)
		{
			if (p->piece[i][j] == '*')
			{
				if (p->p_max_len < j)
					p->p_max_len = j;
				if (p->p_max_hig < i)
					p->p_max_hig = i;
			}
		}
	}
	return (0);
}

// static int	get_max_len(int i, int j, t_p *p)
// {
// 	int	first;
// 	int last;

// 	first = -1;
// 	while (++i < p->p_hig)
// 	{
// 		last = -1;
// 		if (p->piece[j][i] == '*')
// 		{
// 			if (first == -1)
// 				first = i;
// 			last = i;
// 	dprintf(p->fd, "first %d last %d\n", first, last);
// 		}
// 	}
// 	if (p->p_max_len < (last - first))
// 		p->p_max_len = last - first;
// 	dprintf(p->fd, "tru len %d\n", p->p_max_len);
// 	return (0);
// }

// static int	get_max_hig(int i, int j, t_p *p)
// {
// 	int	check;

// 	p->p_max_hig = p->p_hig;
// 	dprintf(p->fd, "tru hig before %d\n", p->p_max_hig);
// 	while (++i < p->p_hig)
// 	{
// 		j = -1;
// 		check = 0;
// 		while (++j < p->p_len)
// 			if (p->piece[i][j] == '*')
// 				check++;
// 		if (check != 0)
// 			p->p_max_hig--;
// 	}
// 	dprintf(p->fd, "tru hig after %d\n", p->p_max_hig);
// 	return (0);
// }