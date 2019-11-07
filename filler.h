/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:22:41 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/07 07:02:48 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "libft/includes/ft_printf.h"
# include <fcntl.h>

typedef struct			s_coord
{
	int					x;
	int					y;
	char				player;
}						t_coord;

typedef struct			s_lst_coord
{
	struct s_coord		*tab;
	int					last;
	struct s_lst_coord	*next;
}						t_lst_coord;

typedef struct			s_p
{
	struct s_lst_coord	*first;
	int					board_size;
	char				player_token;

}						t_p;

int		display(t_p *p);
void 	parser(t_p *p);
int		new_node(t_coord *tab, t_p *p);
void 	init_tab(t_coord *tab, t_p *p);
void	printlist(t_p *p);

#endif
