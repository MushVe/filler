/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:01:55 by cseguier          #+#    #+#             */
/*   Updated: 2019/04/29 14:01:57 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*get_int(va_list ap, t_p *p)
{
	int		nbr;
	char	*res;

	nbr = va_arg(ap, int);
	if (p->op_type == 11)
	{
		if (!(res = convert_signed((short)nbr)))
			return (0);
	}
	else if (p->op_type == 12)
	{
		if (!(res = convert_signed((char)nbr)))
			return (0);
	}
	else
	{
		if (!(res = convert_signed((long long)nbr)))
			return (0);
	}
	return (res);
}

char	*get_long(va_list ap)
{
	long	nbr;
	char	*res;

	nbr = va_arg(ap, long);
	if (!(res = convert_signed((long long)nbr)))
		return (0);
	return (res);
}

char	*get_longlong(va_list ap)
{
	long long	nbr;
	char		*res;

	nbr = va_arg(ap, long long);
	if (!(res = convert_signed((long long)nbr)))
		return (0);
	return (res);
}
