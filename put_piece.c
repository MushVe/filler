/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 01:45:44 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/22 07:45:51 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	doubleprint(char **s, t_p *p)
{
	int	i;

	i = -1;
	while (s[++i])
		dprintf(p->res_fd, "\t> %s\n", s[i]);
}

/*
** chercher ennemy le plus proche
** memoriser valeur de i et j valide pour poser piece
** si piece valide suivante plus proche, ecraser valeur
** (x_trouvé - x_adversaire > x_suivant - x_adverse)
** (y_trouvé - y_adversaire > y_suivant - y_adverse)
** si fin board, renvoyer meilleure valeur
*/

int		is_closer(t_axis new_res, t_axis best_res, t_axis token_tested)
{
	t_axis	new_position;
	t_axis	best_position;

	new_position.x = ft_abs(new_res.x - token_tested.x);
	new_position.y = ft_abs(new_res.y - token_tested.y);
	best_position.x = ft_abs(best_res.x - token_tested.x);
	best_position.y = ft_abs(best_res.y - token_tested.y);
	if (new_position.x < best_position.x || new_position.y < best_position.y)
		return (1);
	return (0);
}

void	find_closest_ennemy(t_p *p)
{
	int	i;

	i = -1;
	while (p->board.data[++i].player != -1)
	{
		if (p->board.data[i].player == p->toi.token)
		{
dprintf(p->res_fd, "in find_closest\n\t\t\tX\tY\n");
dprintf(p->res_fd, "new_tmp:\t%d\t%d\n", p->new_tmp.x, p->new_tmp.y);
dprintf(p->res_fd, "best_tmp:\t%d\t%d\n", p->best_tmp.x, p->best_tmp.y);
dprintf(p->res_fd, "best_final:\t%d\t%d\n\n", p->best_final.x, p->best_final.y);
			if (is_closer(p->new_tmp, p->best_tmp, p->board.data[i].axis))
			{
				p->best_tmp.x = p->new_tmp.x;
				p->best_tmp.y = p->new_tmp.y;
				p->toi.axis = p->board.data[i].axis;
dprintf(p->res_fd, "in if is_closer\n\t\t\tX\tY\n");
dprintf(p->res_fd, "new_tmp:\t%d\t%d\n", p->new_tmp.x, p->new_tmp.y);
dprintf(p->res_fd, "best_tmp:\t%d\t%d\n", p->best_tmp.x, p->best_tmp.y);
dprintf(p->res_fd, "best_final:\t%d\t%d\n\n", p->best_final.x, p->best_final.y);
			}
		}
	}
}

// boucles merdees, find closest fait pas le taf qu'il devrait (il reparcourt)
// (le board au lieu de tester les positions autour d'une coordoonee donnee)

void	find_best_location(t_p *p)
{
dprintf(p->res_fd, "\nbegin\n\t\t\tX\tY\n");
dprintf(p->res_fd, "new_tmp:\t%d\t%d\n", p->new_tmp.x, p->new_tmp.y);
dprintf(p->res_fd, "best_tmp:\t%d\t%d\n", p->best_tmp.x, p->best_tmp.y);
dprintf(p->res_fd, "best_final:\t%d\t%d\n\n", p->best_final.x, p->best_final.y);
	p->board.axis.x = -1;
	while (++p->board.axis.x < p->board.height)
	{
		p->board.axis.y = -1;
		while (++p->board.axis.y < p->board.length)
		{
			if (can_put_piece(p) == 1) // new_res affectect here
			{
				find_closest_ennemy(p);
				if (is_closer(p->best_tmp, p->best_final, p->toi.axis))
				{
					p->best_final.x = p->best_tmp.x;
					p->best_final.y = p->best_tmp.y;
				}
			}
		}
	}
dprintf(p->res_fd, "end\n\t\t\tX\tY\n");
dprintf(p->res_fd, "new_tmp:\t%d\t%d\n", p->new_tmp.x, p->new_tmp.y);
dprintf(p->res_fd, "best_tmp:\t%d\t%d\n", p->best_tmp.x, p->best_tmp.y);
dprintf(p->res_fd, "best_final:\t%d\t%d\n\n", p->best_final.x, p->best_final.y);
	ft_printf("%d %d\n", p->best_final.x, p->best_final.y);
}

int		put_piece(t_p *p)
{
	fill_board(p);
	find_best_location(p); // new affectect here in can_put_piece()
	return (0);
}
