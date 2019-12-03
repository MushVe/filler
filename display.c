#include "display/include/SDL.h"
#include "filler.h"
#include <stdbool.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

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

	fd = open("data", O_RDONLY);
	fstat(fd, &stat);

	char *to_parse = mmap(NULL, align(stat.st_size), PROT_READ, MAP_PRIVATE, fd, 0);
//	printf("{%s}\n", to_parse);
	int grid_cell_size = 20;
	int grid_lenght;
	int grid_height;
	int	i = -1;
	
	while (to_parse[++i] != '\n')
	{
	//	printf("{%c}\n", to_parse[i]);
		if (to_parse[i] == 'H')
			grid_height = atoi(to_parse + i + 1);
		if (to_parse[i] == 'L')
			grid_lenght = atoi(to_parse + i + 1);
	}

	int window_lenght = (grid_lenght * grid_cell_size) + 1;
	int window_height = (grid_height * grid_cell_size) + 1;

	SDL_Color background = {20, 20, 20, 255}; 
	SDL_Color grid_line_color = {70, 70, 70, 255};
	SDL_Color x_square_color = {22, 200, 200, 255};
	SDL_Color o_square_color = {200, 200, 22, 255};

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Initialize SDL: %s", SDL_GetError());
		return EXIT_FAILURE;
	}

	SDL_Window *window;
	SDL_Renderer *renderer;

	if (SDL_CreateWindowAndRenderer(window_lenght, window_height, 0, &window, &renderer) < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Create window & renderer: %s", SDL_GetError());
		return EXIT_FAILURE;
	}

	SDL_SetWindowTitle(window, "SDL Grid");

	SDL_bool quit = SDL_FALSE;

	SDL_Rect x_square;
	SDL_Rect o_square;

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
		while (to_parse[i] != '\0')
		{
			while (to_parse[++i] != '\n' && to_parse[i] != '\0' && to_parse[i] != 'u')
			{
				printf("{c: %c}\n", to_parse[i]);
				if (to_parse[i] == 'x')
					x = atoi(to_parse + i + 1);
				if (to_parse[i] == 'y')
					y = atoi(to_parse + i + 1);
				if (to_parse[i] == 'p')
					player = atoi(to_parse + i + 1);
				if (to_parse[i] == 'l')
					last = atoi(to_parse + i + 1);
				if (to_parse[i + 1] == '\n')
				{
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
						default: break;
					}
				}
			}
			if (to_parse[i] == 'u')
			{
				i++;
				SDL_SetRenderDrawColor(renderer, grid_line_color.r, grid_line_color.g, grid_line_color.b, grid_line_color.a);
				for (int x = 0; x < 1 + grid_lenght * grid_cell_size; x += grid_cell_size) 
					SDL_RenderDrawLine(renderer, x, 0, x, window_height);
				for (int y = 0; y < 1 + grid_height * grid_cell_size; y += grid_cell_size)
					SDL_RenderDrawLine(renderer, 0, y, window_lenght, y);
				SDL_RenderPresent(renderer);
					SDL_Delay(1000);
			}
		}
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}