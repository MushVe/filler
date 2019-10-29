#include <SDL.h>
#include <stdbool.h>
#include "../libft/includes/ft_printf.h"
#include "../libft/includes/libft.h"
# include <fcntl.h>

int main()
{
	int grid_cell_size = 20;
	int grid_width = 17;
	int grid_height = 15;

	// + 1 so that the last grid lines fit in the screen.
	int window_width = (grid_width * grid_cell_size) + 1;
	int window_height = (grid_height * grid_cell_size) + 1;

	// create X square
	SDL_Rect x_square = {
		.x = 14 * grid_cell_size,
		.y = 12 * grid_cell_size,
		.w = grid_cell_size,
		.h = grid_cell_size,
	};

	// create O square
	SDL_Rect o_square = {
		.x = 2 * grid_cell_size,
		.y = 8 * grid_cell_size,
		.w = grid_cell_size,
		.h = grid_cell_size,
	};

	// Dark theme.
	SDL_Color grid_background = {22, 22, 22, 255}; // Barely Black
	SDL_Color grid_line_color = {44, 44, 44, 255}; // Dark grey
	SDL_Color x_square_color = {22, 200, 200, 255};
	SDL_Color x_old_square_color = {22, 100, 100, 255};
	SDL_Color o_square_color = {200, 200, 22, 255};
	SDL_Color o_old_square_color = {100, 100, 22, 255};

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Initialize SDL: %s",
					 SDL_GetError());
		return EXIT_FAILURE;
	}

	SDL_Window *window;
	SDL_Renderer *renderer;
	if (SDL_CreateWindowAndRenderer(window_width, window_height, 0, &window,
									&renderer) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
					 "Create window and renderer: %s", SDL_GetError());
		return EXIT_FAILURE;
	}

	SDL_SetWindowTitle(window, "SDL Grid");

	SDL_bool quit = SDL_FALSE;

	while (!quit) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				quit = SDL_TRUE;
				break;
			}
		}

		// Draw grid background.
		SDL_SetRenderDrawColor(renderer, grid_background.r, grid_background.g,
				grid_background.b, grid_background.a);
		// SDL_RenderClear(renderer);

		// Draw grid lines.
		SDL_SetRenderDrawColor(renderer, grid_line_color.r, grid_line_color.g,
				grid_line_color.b, grid_line_color.a);

		for (int x = 0; x < 1 + grid_width * grid_cell_size;
				x += grid_cell_size) {
			SDL_RenderDrawLine(renderer, x, 0, x, window_height);
		}

		for (int y = 0; y < 1 + grid_height * grid_cell_size;
				y += grid_cell_size) {
			SDL_RenderDrawLine(renderer, 0, y, window_width, y);
		}

		// draw x square
		SDL_SetRenderDrawColor(renderer, x_square_color.r, x_square_color.g,
				x_square_color.b, x_square_color.a);
		SDL_RenderFillRect(renderer, &x_square);

		// draw o square
		SDL_SetRenderDrawColor(renderer, o_square_color.r, o_square_color.g,
				o_square_color.b, o_square_color.a);
		SDL_RenderFillRect(renderer, &o_square);


		// display all
		SDL_RenderPresent(renderer);

	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}
