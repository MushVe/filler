/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:22:41 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/21 05:50:27 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "libft/includes/ft_printf.h"
# include <fcntl.h>
#include <stdio.h>

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
	char				token;
	int					p_len;
	int					p_hig;
	int					p_it;
	int					p_xmax;
	int					p_ymax;
	int					valid;
	int					my_turn;
	char				*p_data;
	char				*board;
	size_t				b_len;
	size_t				b_hig;
	size_t				size;
	size_t				cpt;

	int fd;


}						t_p;

int		display(t_p *p);
int 	parser(t_p *p);
int		new_node(t_coord *tab, t_p *p);
void 	init_tab(t_coord *tab, t_p *p);
void	printlist(t_p *p);
int		get_piece_size(char *line, t_p *p);
int		get_piece_data(char *line, t_p *p);
int		put_piece(t_p *p);
size_t get_size(char *line, t_p *p);
size_t get_board(char *line, t_coord *tab, t_p *p);

#endif
