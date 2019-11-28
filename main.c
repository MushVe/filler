/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 06:42:17 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/28 00:57:44 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void init_tab(t_coord *tab, t_p *p)
{
	int	i = 0;
	while (++i < p->size)
	{
		tab[i].x = -1;
		tab[i].y = -1;
		tab[i].player = -1;
	}
}

void	init(t_p *p)
{
	p->first = NULL;
	p->board = NULL;
	p->p_len = 0;
	p->p_hig = 0;
	p->p_it = 0;
	p->p_max_len = 0;
	p->p_max_hig = 0;
	p->res_x = 0;
	p->res_y = 0;
	p->valid = 0;
	p->p_cpt = 0;
	p->b_len = 0;
	p->b_hig = 0;
	p->size = 0;
	p->cpt = 0;
}

int	main()
{
	t_p p;

	if (-1 == (p.fd = open("res", O_WRONLY | O_CREAT | O_TRUNC)))
		return (0);

	dprintf(p.fd, "AAAAAHHH\n");
	init(&p);
	p.me_token = 0;
	p.av_token = 0;
	parser(&p);
//	printlist(&p);
//	display(&p);
	return (0);
}

// int	main()
// {
// 	t_p *p;

// 	p = malloc(sizeof(t_p));
// 	int fd = open("res", O_RDWR);
// 	init(p);
// 	char *line;
// 	t_coord *tab;
// 	int res;
// 	// int res_y;
// 	// int res_x;

// 	line = NULL;
	
// //	int fd;
// //	if (-1 == (fd = open("camO", O_RDONLY)))
// //		return (0);
// //	while (0 < (i = get_next_line(fd, &line)))
// 	while (1)
// 	{
	

// 		free(line);
// 		while (get_next_line(0, &line))
// 		{
// 		dprintf(fd, "%s\n", line);
// 		if (ft_strstr(line, "Piece"))
// 		{
// 			dprintf(fd, "%s", "HERE WE ARE BORN TO BE KING !!!!\n");
// 			//ft_printf("size maggle? ");
// 			// new_node(tab, p);
// 			// get_piece_size(line, p);
// 			//ft_printf("%d %d\n", p->p_hig, p->p_len);
// 		}
// 		//ft_printf("WAIIIIII\n");
// 		if (ft_strstr(line, " fin: "))
// 			return (0);
// 		if (ft_strstr(line, "$$$ exec p1"))
// 		{
// 			if (ft_strstr(line, "cseguier"))
// 			{
// 				p->player_token = 'o';
// 				p->my_turn = 1;
// 			}
// 			else
// 			{
// 				p->player_token = 'x';
// 				p->my_turn = 0;
// 			}
// 		}
// 		if (ft_strstr(line, "<got") && p->my_turn == 0)
// 			p->my_turn = 1;
// 		if (p->size == 0 && ft_strstr(line, "Plateau"))
// 		{
// 			p->size = get_size(line, p);
// 			if (!(tab = (t_coord *)ft_memalloc(sizeof(t_coord) * p->size)))
// 				return (0);
// 			init_tab(tab, p);
// 		}
// 		if (ft_isdigit(line[0]))
// 			get_board(line, tab, p);
// 		if (p->p_hig > 0)
// 		{
// 			//ft_printf("get piece h: %d, line: %s\n", p->p_hig, line);
// 			p->p_it = get_piece_data(line, p);
// 			p->p_hig--;
// 		}
// 		if (p->my_turn == 1 && p->p_hig == 0 && p->p_it != 0)
// 		{
// 			p->p_it = 0;
// 			p->my_turn = 0;
			
			
// 			printf("%d %d\n", 12, 14);
			
// 			res = put_piece(p);
// 		//	ft_printf("res: %d, len: %d\n", res, p->board_len);
// 			// res_y = res / p->board_len;
// 			// res_x = res - (p->board_len * res_y);
// 			// ft_printf("%d %d\n", res_x, res_y);
// 			ft_memdel((void *)&p->p_data);
// 		}
// 		if (ft_strstr(line, "Piece"))
// 		{
			
// 			printf("%d %d\n", 12, 14);
// 			//ft_printf("size maggle? ");
// 			new_node(tab, p);
// 			get_piece_size(line, p);
// 			//ft_printf("%d %d\n", p->p_hig, p->p_len);
// 		}
// 		ft_memdel((void *)&line);
// //	parser(&p);
// //	printlist(&p);
// //	display(&p);
// 	 for (size_t i = 0; i < 30; i++)
// 	 {
// 		if (i == 30) return 0;
// 	 }
	 
// 	}
// 	}
// 	return (0);
// }