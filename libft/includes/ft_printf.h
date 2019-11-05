/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:22:41 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/05 06:09:11 by cseguier         ###   ########.fr       */
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

typedef struct	s_pf
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
}				t_pf;

int				ptf_new_node(char *data, int size, t_pf *p);
void			ptf_free_list(t_lst **list);
void			ptf_init(t_pf *p);
int				ptf_print_node(t_pf *p);
int				isflag(char c, t_pf *p);
int				isoption(char c);
int				ft_printf(const char *restrict format, ...);
int				ptf_parser(const char *restrict format, t_pf *p, va_list ap);
int				ptf_process(char c, va_list ap, t_pf *p);
char			*add_preci(char *res, t_pf *p, char c);
char			*add_width(char *res, t_pf *p);
char			*adjust_width(char *res, char *it, int i, t_pf *p);
char			*add_x(char *res, char c, t_pf *p);
char			*add_sign(char *res, t_pf *p);
char			*get_int(va_list ap, t_pf *p);
char			*get_long(va_list ap);
char			*get_longlong(va_list ap);
char			*get_uint(char c, va_list ap, t_pf *p);
char			*get_ulong(char c, va_list ap);
char			*get_ulonglong(char c, va_list ap);
char			*get_char(char c, va_list ap, t_pf *p);
char			*get_string(char c, va_list ap);
char			*get_double(char c, va_list ap);
char			*get_longdouble(char c, va_list ap);
char			*convert_signed(long long n);
char			*convert_unsigned(unsigned long long n);

#endif
