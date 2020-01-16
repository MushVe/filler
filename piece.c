/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 01:45:44 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/16 05:22:06 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		create_row(t_p *p, int i)
{
	return (p->board.grid[i] = ft_memalloc(sizeof(char) * (p->board.len + 1)));
}

void	fill_blank_board(t_p *p)
{
	int	i;
	int	j;

	i = -1;
	while (++i < p->board.hig)
	{
		j = -1;
		while (++j < p->board.len)
			p->board.grid[i][j] = '.';
	}
}

void	fill_data_board(t_p *p)
{
	int i;
	int	x;
	int	y;

	x = p->board.data[i].axis.x;
	y = p->board.data[i].axis.y;
	i = -1;
	while (p->board.data[++i].player != -1)
		p->board.grid[y][x] = p->board.data[i].player;
}

int		fill_board(t_p *p)
{
	int	i;

	i = -1;
	if (!(p->board.grid = ft_memalloc(sizeof(char*) * (p->board.hig + 1))))
		return (-1);
	while (++i < p->board.hig)
		if (!(create_row(p, i)))
			return (-1);
	fill_blank_board(p);
	fill_data_board(p);
	return (0);
}

void	doubleprint(char **s, t_p *p)
{
	int	i;

	i = -1;
	while (s[++i])
		dprintf(p->fd, "\t> %s\n", s[i]);
}

int		find_nearest_enemy(t_p *p)
{
	// p->p.i_av = -1;
	// while (++p->p.i_av < p->board.hig)
	// {
	// 	p->p.j_av = -1;
	// 	while (++p->p.j_av < p->board.len)
	// 	{
	// 		if (p->board.grid[p->p.i_av][p->p.j_av] == p->av_token)
	// 			return (1);
	// 	}
	// }

	int	i_board;
	int	j_board;
	int	i_tmp;
	int	j_tmp;
	
	i_board = -1;
	i_tmp = 0;
	j_tmp = 0;
	while (++i_board < p->board.hig)
	{
		j_board = -1;
		while (++j_board < p->board.len)
		{
			if(p->board.grid[i_board][j_board] == p->av_token)
			{
				i_tmp;
				j_tmp;
				// compare
			}
	if (ft_abs(p->new_res.x - p->p.i_av) < ft_abs(p->best_res.x - p->p.i_av)
		|| ft_abs(p->new_res.y - p->p.j_av) < ft_abs(p->best_res.y - p->p.j_av));

		}
	}


	return (0);
}

int		is_closer(t_p *p)
{
	if (ft_abs(p->new_res.x - p->p.i_av) < ft_abs(p->best_res.x - p->p.i_av)
		|| ft_abs(p->new_res.y - p->p.j_av) < ft_abs(p->best_res.y - p->p.j_av))
		return (1);
	return (0);
}

/*
** enregistrer X le plus proche
** memoriser valeur de i et j valide pour poser piece
** si piece valide suivante plus proche, ecraser valeur
** (i_trouvé - i_adversaire > i_suivant - i_adverse)
** (j_trouvé - j_adversaire > j_suivant - j_adverse)
** si fin board, renvoyer meilleure valeur
*/

int		put_piece(t_p *p)
{
	fill_board(p);
	find_nearest_enemy(p);
	p->board.axis.x = -1;
	while (++p->board.axis.x < p->board.hig)
	{
		p->board.axis.y = -1;
		while (++p->board.axis.y < p->board.len)
		{
			if (can_put_piece(p) == 1)
			{
				// abs(i_suivant - i_adverse) < abs(i_trouvé - i_adversaire)
				// abs(j_suivant - j_adverse) < abs(j_trouvé - j_adversaire)
				if (is_closer(p))
				{	p->best_res.x = p->new_res.x;
					p->best_res.y = p->new_res.y;
				}
			}
		}
	}
	return (0);
}
