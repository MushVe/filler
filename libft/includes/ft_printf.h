/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:22:41 by cseguier          #+#    #+#             */
/*   Updated: 2019/04/29 17:22:43 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct	s_lst
{
	char				*str;
	int					size;
	int					null;
	struct s_lst		*next;
}				t_lst;

typedef struct	s_p
{
	t_lst		*first;
	char		*res;
	int			op_plus;
	int			op_less;
	int			op_space;
	int			op_diese;
	int			op_zero;
	int			op_preci;
	int			op_point;
	int			op_width;
	int			op_type;
	int			null;
	char		flag;
}				t_p;

int				new_node(char *data, int size, t_p *p);
void			free_list(t_lst **list);
void			init(t_p *p);
int				print_node(t_p *p);
int				isflag(char c, t_p *p);
int				isoption(char c);
int				ft_printf(const char *restrict format, ...);
int				parser(const char *restrict format, t_p *p, va_list ap);
int				process(char c, va_list ap, t_p *p);
char			*add_preci(char *res, t_p *p, char c);
char			*add_width(char *res, t_p *p);
char			*adjust_width(char *res, char *it, int i, t_p *p);
char			*add_x(char *res, char c, t_p *p);
char			*add_sign(char *res, t_p *p);
char			*get_int(va_list ap, t_p *p);
char			*get_long(va_list ap);
char			*get_longlong(va_list ap);
char			*get_uint(char c, va_list ap, t_p *p);
char			*get_ulong(char c, va_list ap);
char			*get_ulonglong(char c, va_list ap);
char			*get_char(char c, va_list ap, t_p *p);
char			*get_string(char c, va_list ap);
char			*get_double(char c, va_list ap);
char			*get_longdouble(char c, va_list ap);
char			*convert_signed(long long n);
char			*convert_unsigned(unsigned long long n);

#endif
