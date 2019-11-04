/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:50:48 by cseguier          #+#    #+#             */
/*   Updated: 2019/04/11 18:06:40 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

double	ft_pow(double x, int y)
{
	double	tmp;

	if (y == 0)
		return (1);
	tmp = ft_pow(x, y / 2);
	if (y % 2 == 0)
		return (tmp * tmp);
	else
	{
		if (y > 0)
			return (x * tmp * tmp);
		else
			return ((tmp * tmp) / x);
	}
}
