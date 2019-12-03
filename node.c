/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 03:47:45 by cseguier          #+#    #+#             */
/*   Updated: 2019/12/03 04:04:11 by cseguier         ###   ########.fr       */
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

t_lst_coord *last_elem = NULL;

t_coord	*copytab(t_coord *tab, t_p *p)
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
		return (-1);
	node->tab = copytab(tab, p);
	ft_memdel((void*)&tab);
	node->last = 1;
	node->next = NULL;
	if (!cpy)
	{
		p->first = node;
		return (0);
	}
	while (cpy->next != NULL)
		cpy = cpy->next;
	cpy->last = 0;
	cpy->next = node;
	last_elem = node;
	return (0);
}

void	printlist(t_p *p)
{
	t_lst_coord	*cpy;
	int			i;
	int			fd;

	if (-1 == (fd = open("data", O_WRONLY | O_CREAT | O_TRUNC)))
		return ;
	
	dprintf(fd, "H%dL%d\n", p->b_hig, p->b_len);
	cpy = p->first;
	while (cpy)
	{
		i = -1;
		while (cpy->tab[++i].player != -1)
		{
			dprintf(fd, "x%d", cpy->tab[i].x);
			dprintf(fd, "y%d", cpy->tab[i].y);
			dprintf(fd, "p%d", cpy->tab[i].player);
			dprintf(fd, "l%d\n", cpy->last);
		}
		dprintf(fd, "u");
		cpy = cpy->next;
	}
	close(fd);
}
