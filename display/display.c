/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 01:22:49 by cseguier          #+#    #+#             */
/*   Updated: 2020/01/28 07:13:28 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

size_t		align(size_t size)
{
	return ((size + 4096) & ~4096);
}

void set_square(SDL_Rect *square, int x, int y, int grid_cell_size)
{
	square->x = x * grid_cell_size;
	square->y = y * grid_cell_size;
	square->w = grid_cell_size;
	square->h = grid_cell_size;
}

char *detect_uwu(char *seek_u)
{	
	return strchr(seek_u, 'u');
}

int main()
{
	int fd;
	struct stat stat;
	int	player;
	int x = 0;
	int	y = 0;
	int	last = 0;
	int	stop = 0;

	fd = open("camO", O_RDONLY);
	fstat(fd, &stat);

	char *to_parse = mmap(NULL, align(stat.st_size), PROT_READ, MAP_PRIVATE, fd, 0);
	int grid_cell_size = 20;
	int grid_lenght;
	int grid_height;
	
	int i = -1;
	while (to_parse[++i] != 'P')
		;
	while (to_parse[++i] != ' ')
		;
	grid_lenght = ft_atoi(to_parse + i);
	while (to_parse[++i] != ' ')
		;
	grid_height = ft_atoi(to_parse + i);

	ft_putstr("size: "); ft_putnbr(grid_height); ft_putstr(" : "); ft_putnbr(grid_lenght); ft_putstr("\n"); 

	int window_lenght = (grid_lenght * grid_cell_size) + 1;
	int window_height = (grid_height * grid_cell_size) + 1;

	SDL_Color background = {20, 20, 20, 255}; 
	SDL_Color grid_line_color = {70, 70, 70, 255};
	SDL_Color x_square_color = {22, 200, 200, 255};
	SDL_Color o_square_color = {200, 200, 22, 255};
	SDL_Color x_new_square_color = {44, 200, 200, 255};
	SDL_Color o_new_square_color = {200, 200, 44, 255};

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Initialize SDL: %s", SDL_GetError());
		return EXIT_FAILURE;}

	SDL_Window *window;
	SDL_Renderer *renderer;

	if (SDL_CreateWindowAndRenderer(window_lenght, window_height, 0, &window, &renderer) < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Create window & renderer: %s", SDL_GetError());
		return EXIT_FAILURE;}

	SDL_SetWindowTitle(window, "SDL Grid");

	SDL_bool quit = SDL_FALSE;

	SDL_Rect x_square;
	SDL_Rect o_square;
	SDL_Rect x_new_square;
	SDL_Rect o_new_square;


	int	x_cpt = -1;
	int	y_cpt = -1;
	i = 0;
	while (!quit)
	{
		SDL_Event event;
		SDL_SetRenderDrawColor(renderer, background.r, background.g, background.b, background.a);
		SDL_RenderClear(renderer);
		while (SDL_PollEvent(&event)) 
		{
			switch (event.type) 
			{
				case SDL_QUIT:
					quit = SDL_TRUE;
					break;
			}
		}

		if (to_parse[i] == '\0')
			stop = 1;
		while (!stop && to_parse[++i] != '\0')
		{
			ft_putendl("hoi");
			if (!(ft_strcmp(to_parse + i, "Plateau")))
			{
				while (to_parse[++i] != '\n');
				while (to_parse[++i] != '\n');
				i++;
				y_cpt = -1;
				while (++y_cpt < grid_height)
				{
					x_cpt = -1;
					while (++x_cpt < grid_lenght + 4)
					{
						ft_putnbr(x_cpt); ft_putstr(" : "); ft_putnbr(y_cpt); ft_putstr(" > ");
						ft_putchar(to_parse[i + x_cpt + ((grid_lenght + 4) * y_cpt)]); ft_putendl("");
ft_putstr(" > "); ft_putstr(" > "); ft_putnbr(i + x_cpt + ((grid_lenght + 4) * y_cpt)); ft_putendl("");
						// if (to_parse[i + x_cpt + ((grid_lenght + 4) * y_cpt)] == 'O'
						// 	|| to_parse[i + x_cpt + ((grid_lenght + 4) * y_cpt)] == 'o'
						// 	|| to_parse[i + x_cpt + ((grid_lenght + 4) * y_cpt)] == 'X'
						// 	|| to_parse[i + x_cpt + ((grid_lenght + 4) * y_cpt)] == 'x')
						// {
							player = to_parse[i + x_cpt + ((grid_lenght + 4) * y_cpt)];
							x = x_cpt - 4;
							y = y_cpt;
							ft_putstr("player: "); ft_putchar(player); ft_putstr(" : ");
							ft_putnbr(x); ft_putstr(" : ");ft_putnbr(y); ft_putendl(";");
							switch (player)
							{
								case 'X':
									set_square(&x_square, x, y, grid_cell_size);
									SDL_SetRenderDrawColor(renderer, x_square_color.r, x_square_color.g, x_square_color.b, x_square_color.a);
									SDL_RenderFillRect(renderer, &x_square);
									break;
								case 'O':
									set_square(&o_square, x, y, grid_cell_size);
									SDL_SetRenderDrawColor(renderer, o_square_color.r, o_square_color.g, o_square_color.b, o_square_color.a);
									SDL_RenderFillRect(renderer, &o_square);
									break;
								case 'x':
									set_square(&x_new_square, x, y, grid_cell_size);
									SDL_SetRenderDrawColor(renderer, x_new_square_color.r, x_new_square_color.g, x_new_square_color.b, x_new_square_color.a);
									SDL_RenderFillRect(renderer, &x_new_square);
									break;
								case 'o':
									set_square(&o_new_square, x, y, grid_cell_size);
									SDL_SetRenderDrawColor(renderer, o_new_square_color.r, o_new_square_color.g, o_new_square_color.b, o_new_square_color.a);
									SDL_RenderFillRect(renderer, &o_new_square);
									break;
								default: break;
							}
						// }
					}
				}
				i = i + x_cpt + ((grid_lenght + 4) * y_cpt) - 1;
			}
		}
		if (!stop && ft_strcmp(to_parse + i, "Piece"))
		{
			ft_putendl("666");
			SDL_SetRenderDrawColor(renderer, grid_line_color.r,
				grid_line_color.g, grid_line_color.b, grid_line_color.a);
			for (int x = 0; x < 1 + grid_lenght * grid_cell_size; x += grid_cell_size) 
				SDL_RenderDrawLine(renderer, x, 0, x, window_height);
			for (int y = 0; y < 1 + grid_height * grid_cell_size; y += grid_cell_size)
					SDL_RenderDrawLine(renderer, 0, y, window_lenght, y);
			SDL_RenderPresent(renderer);
			SDL_Delay(3000);
		}




















	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}