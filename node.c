/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 03:47:45 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/04 05:07:28 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_list(t_lst_coord **list)
{
	t_lst_coord	*cpy;
	t_lst_coord	*tmp;

	cpy = *list;
	tmp = NULL;
	while (cpy)
	{
		tmp = cpy->next;
		ft_memdel((void*)&cpy->str);
		ft_memdel((void*)&cpy);
		cpy = NULL;
		cpy = tmp;
	}
}

int		new_node(char *data, int size, t_p *p)
{
	t_lst_coord	*cpy;
	t_lst_coord	*node;

	cpy = p->first;
	if (!(node = (t_lst_coord*)ft_memalloc(sizeof(t_lst_coord))))
		return (0);
	node->str = ft_strdup(data);
	ft_memdel((void*)&data);
	node->size = size;
	if (p->null == 1)
		node->null = 1;
	else
		node->null = 0;
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

char	*get_node(int aim, t_p *p)
{
	t_lst_coord	*cpy;
	int		i;

	cpy = p->first;
	i = -1;
	while (++i < aim && cpy)
		cpy = cpy->next;
	return (cpy->str);
}