#include "display/include/SDL.h"
#include <stdbool.h>
#include "libft/includes/ft_printf.h"
#include "libft/includes/libft.h"
#include <fcntl.h>
#include "filler.h"

void set_square(SDL_Rect *square, t_coord tab, int grid_cell_size)
{
	square->x = tab.x * grid_cell_size;
	square->y = tab.y * grid_cell_size;
	square->w = grid_cell_size;
	square->h = grid_cell_size;
}

int display(t_p *p)
{
	int grid_cell_size = 20;
	int grid_width = 17;
	int grid_height = 15;

	int window_width = (grid_width * grid_cell_size) + 1;
	int window_height = (grid_height * grid_cell_size) + 1;
	
	int i;

	ft_printf("999\n");
	t_lst_coord	*cpy;
	cpy = p->first;
	ft_printf("AAA\n");

	SDL_Color background = {20, 20, 20, 255}; 
	SDL_Color grid_line_color = {70, 70, 70, 255};
	SDL_Color x_square_color = {22, 200, 200, 255};
	SDL_Color x_old_square_color = {22, 100, 100, 255};
	SDL_Color o_square_color = {200, 200, 22, 255};
	SDL_Color o_old_square_color = {100, 100, 22, 255};

	ft_printf("BBB\n");

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Initialize SDL: %s", SDL_GetError());
		return EXIT_FAILURE;
	}

	ft_printf("CCC\n");

	SDL_Window *window;
	SDL_Renderer *renderer;

	ft_printf("DDD\n");

	if (SDL_CreateWindowAndRenderer(window_width, window_height, 0, &window, &renderer) < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Create window & renderer: %s", SDL_GetError());
		return EXIT_FAILURE;
	}

	ft_printf("EEE\n");

	SDL_SetWindowTitle(window, "SDL Grid");

	SDL_bool quit = SDL_FALSE;

	SDL_Rect x_square;
	SDL_Rect o_square;
	SDL_Rect x_old_square;
	SDL_Rect o_old_square;

	ft_printf("444\n");

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

	ft_printf("555\n");

		i = -1;
		while (cpy->tab[++i].player != -1)
		{
			switch (cpy->tab[i].player)
			{
				case 'x':
					set_square(&x_square, cpy->tab[i], grid_cell_size);
					SDL_SetRenderDrawColor(renderer, x_square_color.r, x_square_color.g, x_square_color.b, x_square_color.a);
					SDL_RenderFillRect(renderer, &x_square);
					break;
				case 'o':
					set_square(&o_square, cpy->tab[i], grid_cell_size);
					SDL_SetRenderDrawColor(renderer, o_square_color.r, o_square_color.g, o_square_color.b, o_square_color.a);
					SDL_RenderFillRect(renderer, &o_square);
					break;
				case 'X':
					set_square(&x_old_square, cpy->tab[i], grid_cell_size);
					SDL_SetRenderDrawColor(renderer, x_old_square_color.r, x_old_square_color.g, x_old_square_color.b, x_old_square_color.a);
					SDL_RenderFillRect(renderer, &x_old_square);
					break;
				case 'O':
					set_square(&o_old_square, cpy->tab[i], grid_cell_size);
					SDL_SetRenderDrawColor(renderer, o_old_square_color.r, o_old_square_color.g, o_old_square_color.b, o_old_square_color.a);
					SDL_RenderFillRect(renderer, &o_old_square);
					break;
				default: break;
			}
		}

	ft_printf("666\n");

		SDL_SetRenderDrawColor(renderer, grid_line_color.r, grid_line_color.g, grid_line_color.b, grid_line_color.a);
		for (int x = 0; x < 1 + grid_width * grid_cell_size; x += grid_cell_size) 
			SDL_RenderDrawLine(renderer, x, 0, x, window_height);
		for (int y = 0; y < 1 + grid_height * grid_cell_size; y += grid_cell_size)
			SDL_RenderDrawLine(renderer, 0, y, window_width, y);
		SDL_RenderPresent(renderer);
				SDL_Delay(1000);
		cpy = cpy->next;

	ft_printf("777\n");
	}

	ft_printf("888\n");
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}