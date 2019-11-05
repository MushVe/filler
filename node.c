/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 03:47:45 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/05 06:43:45 by cseguier         ###   ########.fr       */
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
	node->next = NULL;
	if (!cpy)
	{
		p->first = node;
		return (1);
	}
	while (cpy->next != NULL)
		cpy = cpy->next;
	cpy->next = node;
	return (1);
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