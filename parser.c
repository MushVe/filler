/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 06:39:48 by cseguier          #+#    #+#             */
/*   Updated: 2019/11/07 07:20:43 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get_board_size(char *line)
{
	int	i;
	int	a;
	int	b;

	i = -1;
	while (!(ft_isdigit(line[++i]))) ;
	a = ft_atoi(line + i);
	while (line[++i] != ' ') ;
	b = ft_atoi(line + i);
	return (a * b);
}

void parser(t_p *p)
{
	int		i;
	char	*line;
	int		fd;

	i = 1;
	line = NULL;
	if (-1 == (fd = open("camO", O_RDONLY)))
	{
		ft_printf("error\n");
		return ;
	}
	while (0 < (i = get_next_line(fd, &line)))
	{
	//	ft_printf(line);
		if (ft_strstr(line, "$$$ exec p1"))
		{
			if (ft_strstr(line, "cseguier"))
				p->player_token = 'o';
			else
				p->player_token = 'x';
		}
		if (ft_strstr(line, "Plateau") && p->board_size == 0)
			p->board_size = get_board_size(line);
		free(line);
	}
}