/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 03:47:45 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/27 02:49:32 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// void	free_list(t_lst_coord **list)
// {
// 	t_lst_coord	*cpy;
// 	t_lst_coord	*tmp;

// 	cpy = *list;
// 	tmp = NULL;
// 	while (cpy)
// 	{
// 		tmp = cpy->next;
// 		ft_memdel((void*)&cpy);
// 		cpy = NULL;
// 		cpy = tmp;
// 	}
// }

t_coord		*copytab(t_coord *tab, t_p *p)
{
	t_coord	*res;
	int		i;

	res = NULL;
	if (!(res = (t_coord*)ft_memalloc(sizeof(t_coord) * p->size)))
		return (0);
	init_tab(res, p);
	i = -1;
	while (tab[++i].player != -1)
	{
		res[i].x = tab[i].x;
		res[i].y = tab[i].y;
		res[i].player = tab[i].player;
	}
	return (res);
}

int		new_node(t_coord *tab, t_p *p)
{
	t_lst_coord	*cpy;
	t_lst_coord	*node;

	cpy = p->first;
	if (!(node = (t_lst_coord*)ft_memalloc(sizeof(t_lst_coord))))
		return (0);
	node->tab = copytab(tab, p);
	node->last = 1;
	node->next = NULL;
	if (!cpy)
	{
		p->first = node;
		return (1);
	}
	while (cpy->next != NULL)
	{
		cpy->last = 0;
		cpy = cpy->next;
	}
	cpy->next = node;
	return (1);
}

void	printlist(t_p *p)
{
	t_lst_coord	*cpy;
	int			i;

	dprintf(p->fd, "NOW PRINT\n");
	cpy = p->first;
	while (cpy)
	{
		i = -1;
		while (cpy->tab[++i].player != -1)
		{
			dprintf(p->fd, "i: %d\t", i);
			dprintf(p->fd, "x: %d\t", cpy->tab[i].x);
			dprintf(p->fd, "y: %d\t", cpy->tab[i].y);
			dprintf(p->fd, "p: %d\t", cpy->tab[i].player);
			dprintf(p->fd, "last: %d\n", cpy->last);
		}
		cpy = cpy->next;
	}
}


// char	*get_node(int aim, t_p *p)
// {
// 	t_lst_coord	*cpy;
// 	int		i;

// 	cpy = p->first;
// 	i = -1;
// 	while (++i < aim && cpy)
// 		cpy = cpy->next;
// 	return (0);
// }