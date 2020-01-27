/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:22:41 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/27 06:32:33 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "libft/includes/ft_printf.h"
# include <fcntl.h>
# include <limits.h>

typedef struct			s_axis
{
	int					x;
	int					y;
}						t_axis;

typedef struct			s_data
{
	t_axis				axis;
	char				player;
}						t_data;

typedef struct			s_board
{
	t_data				*data;
	char				**grid;
	int					length;
	int					height;
	int					size;
	int					cpt;
	t_axis				axis;
}						t_board;

typedef struct			s_piece
{
	char				**content;
	int					length;
	int					height;
	int					max_length;
	int					max_height;
	int					cpt;
	int					it;
	t_axis				axis;

}						t_piece;

typedef struct			s_player
{
	char				token;
	int					token_cpt;
	t_axis				axis;
}						t_player;

typedef struct			s_p
{
	t_piece				piece;
	t_board				board;
	t_player			moi;
	t_player			toi;
	t_axis				new_tmp;
	t_axis				best_tmp;
	t_axis				best_final;
	int					end;
	int					**hit_map;
	int					res_fd;
	int					data_fd;
	int					piece_size;
}						t_p;

int						display(t_p *p);
void					init(t_p *p);
int						parser(t_p *p);
void					init_tab(t_p *p);
void					init_once(t_p *p);
void					end_free(t_p *p);
void					reset_everything(t_p *p);
int						fill_board(t_p *p);
int						get_piece_size(char *line, t_p *p);
int						get_piece_content(char *line, t_p *p);
int						put_piece(t_p *p);
int						can_put_piece(t_p *p);
int						get_board_size(char *line, t_p *p);
int						get_max_size(t_p *p);
int						get_board_data(char *line, t_p *p);
t_axis					*find_newest_enemy(t_p *p, int newest);
int						create_hit_map(t_p *p, int turn);
void					fill_hit_map(t_p *p, int turn);
int						get_board_size(char *line, t_p *p);
int						get_board_data(char *line, t_p *p);

#endif
