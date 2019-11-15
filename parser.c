/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 06:39:48 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/15 06:01:40 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

size_t get_size(char *line, t_p *p)
{
	size_t i;

	i = -1;
	while (!(ft_isdigit(line[++i])))
		;
	p->board_hig = ft_atoi(line + i);
	while (line[++i] != ' ')
		;
	p->board_len = ft_atoi(line + i);
	return (p->board_len * p->board_hig);
}

size_t get_board(char *line, t_coord *tab, t_p *p)
{
	size_t i;
	i = -1;

	while (line[++i] != '\0')
	{
		if (!(ft_isdigit(line[i])) && line[i] != ' ' && line[i] != '.')
		{
			tab[p->cpt].player = line[i];
			tab[p->cpt].x = (i - 4);
			tab[p->cpt].y = ft_atoi(line);
			p->cpt++;
		}
	}
	return (0);
}

int parser(t_p *p)
{
	char *line;
	size_t i;
	t_coord *tab;
	int res;
	int res_y;
	int res_x;

	i = 1;
	line = NULL;
	
	int fd;
	if (-1 == (fd = open("camO", O_RDONLY)))
		return (0);
	while (0 < (i = get_next_line(fd, &line)))
	//while (0 < (i = get_next_line(0, &line)))
	{
	//	ft_printf("WAIIIIII\n");
		if (ft_strstr(line, "$$$ exec p1"))
		{
			if (ft_strstr(line, "cseguier"))
			{
				p->player_token = 'o';
				p->my_turn = 1;
			}
			else
			{
				p->player_token = 'x';
				p->my_turn = 0;
			}
		}
		if (ft_strstr(line, "<got") && p->my_turn == 0)
			p->my_turn = 1;
		if (p->size == 0 && ft_strstr(line, "Plateau"))
		{
			p->size = get_size(line, p);
			if (!(tab = (t_coord *)ft_memalloc(sizeof(t_coord) * p->size)))
				return (0);
			init_tab(tab, p);
		}
		if (ft_isdigit(line[0]))
			get_board(line, tab, p);
		if (p->p_hig > 0)
		{
			ft_printf("get piece h: %d, line: %s\n", p->p_hig, line);
			p->p_it = get_piece_data(line, p);
			p->p_hig--;
		}
		if (p->my_turn && p->p_hig == 0 && p->p_it)
		{
			p->p_it = 0;
			p->my_turn = 0;
			ft_printf("put piece\n");
			res = put_piece(p);
		//	ft_printf("res: %d, len: %d\n", res, p->board_len);
			res_y = res / p->board_len;
			res_x = res - (p->board_len * res_y);
			ft_printf("%d %d\n", res_x, res_y);
			ft_memdel((void *)&p->p_data);
		}
		if (ft_strstr(line, "Piece"))
		{
			new_node(tab, p);
			get_piece_size(line, p);
		}
		ft_memdel((void *)&line);
	}
	return (0);
}
