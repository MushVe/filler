/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublefree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 04:25:40 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/22 04:42:39 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void ft_doublefree(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		ft_memdel((void*)&s[i]);
	ft_memdel((void*)&s);
}