/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 06:39:48 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/15 03:12:50 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

size_t	get_size(char *line, t_p *p)
{
	size_t	i;

	i = -1;
	while (!(ft_isdigit(line[++i]))) ;
	p->board_hig = ft_atoi(line + i);
	while (line[++i] != ' ') ;
	p->board_len = ft_atoi(line + i);
	return (p->board_len * p->board_hig);
}

size_t	get_content(char *line, t_coord *tab, t_p *p)
{
	size_t	i;
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

int	parser(t_p *p)
{
	char		*line;
	int			fd;
	size_t		i;
	t_coord		*tab;
	int res;
	int res_y;
	int	res_x;

	i = 1;
	line = NULL;
//	ft_printf("Parser go in\n");
	if (-1 == (fd = open("camO", O_RDONLY)))
	{
	//	ft_printf("error\n");
		return (0);
	}
	while (0 < (i = get_next_line(fd, &line)))
	//while (0 < (i = get_next_line(0, &line)))
	{
	// ft_printf(line);
		if (ft_strstr(line, "$$$ exec p1"))
		{
			if (ft_strstr(line, "cseguier"))
			{
				p->player_token = 'o';
				p->my_turn == 1;
			}
			else
			{
				p->player_token = 'x';
				p->my_turn == 0;
			}
		//	ft_printf("Gotcha player\n");
		}
		if (p->size == 0 && ft_strstr(line, "Plateau"))
		{
			p->size = get_size(line, p);
		//	ft_printf("Gotcha plato\n");
			if (!(tab = (t_coord*)ft_memalloc(sizeof(t_coord) * p->size)))
				return (0);
		//	ft_printf("Malloc ok\n");
			init_tab(tab, p);
		//	ft_printf("Init Tab ok\n");
		}
		if (ft_isdigit(line[0]))
		{
			get_content(line, tab, p);
		//	ft_printf("Gotcha content\n");
		}
		if (p->p_hig > 0)
		{
			// ft_printf("h: %d\n", p->p_hig);
			p->p_it = get_piece_data(line, p);
			p->p_hig--;
		}
		if (p->p_it != 0 && p->p_hig == 0)
		{
			res = put_piece(p);
			res_y = res / p->board_len;
			res_x = res - (p->board_len * res_y);
			ft_printf("%d %d\n", res_x, res_y);
		}
		if (ft_strstr(line, "Piece"))
		{
			// ft_printf("is piece\n");
			new_node(tab, p);
			// ft_printf("uh\n");
			get_piece_size(line, p);
		}
		ft_memdel((void*)&line);

	}
//	ft_printf("data piece : %s\n", p->p_data);
//	new_node(tab, p);
	return (0);
}
