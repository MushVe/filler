/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:22:41 by cseguier          #+#    #+#             */
/*   Updated: 2019/12/03 06:12:45 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "libft/includes/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct			s_coord
{
	int					x;
	int					y;
	char				player;
}						t_coord;

typedef struct			s_lst_coord
{
	t_coord		*tab;
	int					last;
	struct	s_lst_coord	*next;
}						t_lst_coord;

typedef struct			s_p
{
	t_lst_coord	*first;
	char				me_token;
	char				av_token;
	int					p_len;
	int					p_cpt;
	int					p_hig;
	int					p_it;
	int					p_max_len;
	int					p_max_hig;
	int					res_x;
	int					res_y;
	char				**piece;
	int					valid;
	int					my_turn;
	char				**board;
	int					b_len;
	int					b_hig;
	int					size;
	int					cpt;
	int					fd;
}						t_p;

int		display(t_p *p);
void	init(t_p *p);
int 	parser(t_p *p);
int		new_node(t_coord *tab, t_p *p);
void 	init_tab(t_coord *tab, t_p *p);
void	printlist(t_p *p);
int		get_piece_size(char *line, t_p *p);
int		get_piece_data(char *line, t_p *p);
int		put_piece(t_p *p);
int		get_size(char *line, t_p *p);
int		get_max_size(t_p *p);
int		get_board(char *line, t_coord *tab, t_p *p);

extern t_lst_coord *last_elem;

#endif
