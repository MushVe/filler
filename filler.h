/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:22:41 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/15 01:31:32 by cseguier         ###   ########.fr       */
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
	char				player_token;
	int					p_len;
	int					p_hig;
	int					p_it;
	int					valid;
	char				*p_data;
	char				*board;
	size_t				board_len;
	size_t				board_hig;
	size_t				size;
	size_t				cpt;

}						t_p;

int		display(t_p *p);
int 	parser(t_p *p);
int		new_node(t_coord *tab, t_p *p);
void 	init_tab(t_coord *tab, t_p *p);
void	printlist(t_p *p);
int		get_piece_size(char *line, t_p *p);
int		get_piece_data(char *line, t_p *p);
int		put_piece(t_p *p);

#endif
