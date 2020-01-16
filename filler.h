/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:22:41 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/16 04:53:09 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "libft/includes/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>

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
	t_data				*data;		// tab
	char				**grid;		// board
	int					len;		// b_len;
	int					hig;		// b_hig;
	int					size;
	t_axis				axis;		// i_board; j_board;

}						t_board;

typedef struct			s_piece
{
	char				**content;	// **piece;
	int					len;		// p_len;
	int					hig;		// p_hig;
	int					max_len;	// p_max_len;
	int					max_hig;	// p_max_hig;
	int					cpt;		// p_cpt;
	int					it;			// p_it;

	t_axis				axis;		// i_piece; j_piece;

}						t_piece;

typedef struct			s_player
{
	char				token;
	int					token_cpt;
}						t_player;

typedef struct			s_p
{
	t_piece				piece;
	t_board				board;
	t_player			moi;
	t_player			toi;

	t_axis				new_position; //res_xy //old_valid_ij //newvalid?idk
	t_axis				best_position; //old? new? res? idk

	int					i_adv;
	int					j_adv;
	int					valid;
	int					my_turn;
	int					cpt;
	int					fd;
	// int					data_fd;
}						t_p;

int		display(t_p *p);
void	init(t_p *p);
int 	parser(t_p *p);
int		new_node(t_p *p);
void 	init_tab(t_p *p);
// void	printlist(t_p *p);
int		get_piece_size(char *line, t_p *p);
int		get_piece_content(char *line, t_p *p);
int		put_piece(t_p *p);
int		get_board_size(char *line, t_p *p);
int		get_max_size(t_p *p);
int		get_board_data(char *line, t_p *p);

// extern t_lst_data *last_elem;

#endif
