/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 01:45:44 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/27 03:32:11 by cseguier         ###   ########.fr       */
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

static void	fill_hit_map(t_p *p, int turn)
{
	int i;
	int	x;
	int	y;

	i = -1;
	while (p->board.data[++i].player != -1)
	{
		if (p->board.data[i].player == p->toi.token)
		{
			x = p->board.data[i].axis.x;
			y = p->board.data[i].axis.y;
			if (p->hit_map[y][x] == 0)
				p->hit_map[y][x] = turn;
		}
	}
}

// void	print_a_double_grid_of_integer(int **the_double_grid_of_tingle, int height, int length, int fd)
// {
// 	for (int i = 0; i < height; i++)
// 	{
// 		for (int j = 0; j < length; j++)
// 		{
// 			dprintf(fd, "\t%d", the_double_grid_of_tingle[i][j]);
// 		}
// 		dprintf(fd, "\n");
// 	}
	
// 	dprintf(fd, "\n");
	
// }

// The Leaks Kingdoms of Realm Empire
int create_hit_map(t_p *p, int turn)
{
	int length;
	int height;

	length = p->board.length;
	height = p->board.height;
	
	//Calloc == ft_memalloc
	if (p->hit_map == NULL)
	{
		p->hit_map = ft_memalloc(sizeof(int *) * height);
		if (p->hit_map == NULL)
			return (0);
		for (int i = 0; i < height; i++)
		{
			p->hit_map[i] = ft_memalloc(sizeof(int) * length);
			if (p->hit_map[i] == NULL)
				return (0);

		}
	}
	
	fill_hit_map(p, turn);
	// print_a_double_grid_of_integer(p->hit_map, height, length, p->res_fd);
	return (1);
}

//count_piece_size_enemy
int dracula(t_p *p, int newest)
{
	int i;
	int j;
	int cpt;

	i = -1;
	j = -1;
	cpt = 0;
	// dprintf(p->res_fd, "newest %d\n", newest);
	while (++i < p->board.height)
	{
		while (++j < p->board.length)
		{
			if (p->hit_map[i][j] == newest)
				cpt++;
		}
		j = -1;
	}

	// dprintf(p->res_fd, "cpt %d\n", cpt);
	return (cpt);
}

/**
 * Remember to free the t_axis returned by this fuction
 * /!\ Possible error with the coord system
 * if (hit_map[y][x] == newest)
			{
				enemy_coord[cpt].x = x;
				enemy_coord[cpt].y = y;
			}
 * tread carefully
 */
t_axis *find_newest_enemy(t_p *p, int newest)
{
	int height; 
	int length;
	int x;
	int y;
	int cpt;
	t_axis *enemy_coord;
	
	height = p->board.height;
	length = p->board.length;
	p->piece_size = dracula(p, newest);
	cpt = 0;
	if (p->piece_size <= 0)
		return NULL;
	if (!(enemy_coord = ft_memalloc(p->piece_size * sizeof(t_axis))))
		return (NULL);
	x = -1;
	while (++x < height)
	{
		y = -1;
		while (++y < length)
		{
			if (p->hit_map[x][y] == newest)
			{
				
				enemy_coord[cpt].x = x;
				enemy_coord[cpt].y = y;
				if (cpt + 1 < p->piece_size)
					cpt++;
			}		
		}
	}
	return (enemy_coord);
}

int is_closer_heuristic_one(t_p *p, t_axis *enemy_coord, int enemy_coord_size, t_axis *best_distance)
{
	t_axis	valid_pos;
	t_axis	abs_distance;
	int		res;
	int		i;

	i = -1;
	res = 0;
	valid_pos.x = p->new_tmp.x;
	valid_pos.y = p->new_tmp.y;
	while (++i < enemy_coord_size)
	{
		abs_distance.x = ft_abs(valid_pos.x - enemy_coord[i].x);
		abs_distance.y = ft_abs(valid_pos.y - enemy_coord[i].y);
		if (best_distance->x >= abs_distance.x && best_distance->y >= abs_distance.y)
		{
			best_distance->x = abs_distance.x;
			best_distance->y = abs_distance.y;
			res = 1;
		}
	}
	return (res);
}

void	find_best_location(t_p *p, int turn)
{
	t_axis *enemy_coord;
	t_axis best_distance;

	p->board.axis.x = -1;
	enemy_coord = NULL;
	best_distance.x = INT_MAX;
	best_distance.y = INT_MAX;
	while (++p->board.axis.x < p->board.height)
	{
		p->board.axis.y = -1;
		while (++p->board.axis.y < p->board.length)
		{
			if (can_put_piece(p) == 1) // new_tmp affectect here
			{
				if (!(enemy_coord = find_newest_enemy(p, turn)))
					return ;
				if (is_closer_heuristic_one(p, enemy_coord, p->piece_size, &best_distance))
				{
					p->best_final.x = p->new_tmp.x;
					p->best_final.y = p->new_tmp.y;
				}
			}
		}
	}
	ft_memdel((void*)&enemy_coord);
}

/**
 * turn isnt incremented, as it isnt 
 * a static variable anymore
 * print the map to see what happens
 */
int		put_piece(t_p *p)
{
	int turn = 1;
	fill_board(p);
	if (!(create_hit_map(p, turn)))
		return (-1);
	find_best_location(p, turn);
	ft_printf("%d %d\n", p->best_final.x, p->best_final.y);
	turn++;
	return (0);
}

