//#include <iostream>
#include <SDL.h>
#include <stdbool.h>
#include "../libft/includes/ft_printf.h"
#include "../libft/includes/libft.h"
# include <fcntl.h>
//using namespace std;

int main()
{
	// if(SDL_Init(SDL_INIT_VIDEO) < 0)
	// return -1;

	// SDL_Window *window = SDL_CreateWindow("SDL2 Window",
	// 	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, 0);

	// if(!window)
	// 	return -1;

	// SDL_Surface *window_surface = SDL_GetWindowSurface(window);

	// if(!window_surface)
	// 	return -1;

	// bool keep_window_open = true;
	// while(keep_window_open)
	// {
	// 	SDL_Event e;
	// 	while(SDL_PollEvent(&e) > 0)
	// 	{
	// 		switch(e.type)
	// 		{
	// 			case SDL_QUIT:
	// 				keep_window_open = false;
	// 			break;
	// 		}

	// int		fd;
	// char	*line;
	// int		i;
	// int		x;
	// int		y;

	// i = 1;
	// y = -1;
	// line = NULL;
	// if (0 > (fd = open("result.txt", O_RDONLY)))
	// 	return (0);

	// int grid_cell_size = 10;
	// int grid_width = 0;
	// int grid_height = 0;
	// int window_width = 0;
	// int window_height = 0;
	// int check = 1;

	// while (0 < (i = get_next_line(fd, &line)))
	// {
		
	// 	if (ft_strstr("Plateau", line), check == 1)
	// 	{
	// 		check = 0;
	// 		grid_height = ft_atoi(line + 7);
	// 		grid_width = ft_atoi(line + 9);
	// 		window_width = (grid_width * grid_cell_size) + 1;
	// 		window_height = (grid_height * grid_cell_size) + 1;

	// 		SDL_Color grid_background = {22, 22, 22, 255};
	// 		SDL_Color grid_line_color = {44, 44, 44, 255};
	// 		SDL_Color grid_cursor_ghost_color = {44, 44, 44, 255};
	// 		SDL_Color grid_cursor_color = {255, 255, 255, 255};

	// 		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
	// 				SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
	// 				"Initialize SDL: %s", SDL_GetError());
 	// 			return EXIT_FAILURE;
	// 		}
	// 	SDL_Window *window;
	// 	SDL_Renderer *renderer;
	// if (SDL_CreateWindowAndRenderer(window_width, window_height, 0, &window,
	// 	&renderer) < 0) { SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
	// 		"Create window and renderer: %s", SDL_GetError());
	// 	return EXIT_FAILURE;


	// 	SDL_SetRenderDrawColor(renderer, grid_background.r, grid_background.g,
	// 						   grid_background.b, grid_background.a);
	// 	SDL_RenderClear(renderer);

	// 	SDL_SetRenderDrawColor(renderer, grid_line_color.r, grid_line_color.g,
	// 						   grid_line_color.b, grid_line_color.a);

	// 	for (int x = 0; x < 1 + grid_width * grid_cell_size;
	// 		 x += grid_cell_size) {
	// 		SDL_RenderDrawLine(renderer, x, 0, x, window_height);
	// 	}

	// 	for (int y = 0; y < 1 + grid_height * grid_cell_size;
	// 		 y += grid_cell_size) {
	// 		SDL_RenderDrawLine(renderer, 0, y, window_width, y);
	// 	}

	// SDL_RenderPresent(renderer);

	// }

	// 	}
	// 	else return (0);

	// 	x = -1;
	// 	++y;
	// 	while (line[++x] != '\0')
	// {
	// 	if (x >= 3 && y >= 2)
	// {
	// 	if (line[x] == 'o')
	// {
	// 	ft_printf("x: %d\n : %d\ny: %d\n : %d\n", x, ((x-3)*12),y, ((y-2)*12));
	// 	SDL_Rect rect = {((x - 3) * 12), ((y - 2) * 12), 10, 10}; // x, y, width, height
	// 	SDL_FillRect(window_surface, &rect,
	// 		SDL_MapRGB(window_surface->format, 150, 150, 50));
	// 	SDL_UpdateWindowSurface(window);
	// }
	// if (line[x] == 'O')
	// {
	// 	ft_printf("x: %d\n : %d\ny: %d\n : %d\n", x, ((x-3)*12),y, ((y-2)*12));
	// 	SDL_Rect rect = {((x - 3) * 12), ((y - 2) * 12), 10, 10}; // x, y, width, height
	// 	SDL_FillRect(window_surface, &rect,
	// 		SDL_MapRGB(window_surface->format, 250, 250, 50));
	// 	SDL_UpdateWindowSurface(window);
	// }
	// if (line[x] == 'x')
	// {
	// 	ft_printf("x: %d\n : %d\ny: %d\n : %d\n", x, ((x-3)*12),y, ((y-2)*12));
	// 	SDL_Rect rect = {((x - 3) * 12), ((y - 2) * 12), 10, 10}; // x, y, width, height
	// 	SDL_FillRect(window_surface, &rect,
	// 		SDL_MapRGB(window_surface->format, 50, 150, 150));
	// 	SDL_UpdateWindowSurface(window);
	// }
	// if (line[x] == 'X')
	// {
	// 	ft_printf("x: %d\n : %d\ny: %d\n : %d\n", x, ((x-3)*12),y, ((y-2)*12));
	// 	SDL_Rect rect = {((x - 3) * 12), ((y - 2) * 12), 10, 10}; // x, y, width, height
	// 	SDL_FillRect(window_surface, &rect,
	// 		SDL_MapRGB(window_surface->format, 50, 250, 250));
	// 	SDL_UpdateWindowSurface(window);
	// }
//	}

	//ft_memdel((void*)&line);
	// }
	// if (i < 0)
	// 	return (0);
	// }






//     int grid_cell_size = 36;
//     int grid_width = 29;
//     int grid_height = 23;

//     // + 1 so that the last grid lines fit in the screen.
//     int window_width = (grid_width * grid_cell_size) + 1;
//     int window_height = (grid_height * grid_cell_size) + 1;

//     // Dark theme.
//     SDL_Color grid_background = {22, 22, 22, 255}; // Barely Black
//     SDL_Color grid_line_color = {44, 44, 44, 255}; // Dark grey

//     if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//         SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Initialize SDL: %s",
//                      SDL_GetError());
//         return EXIT_FAILURE;
//     }

//     SDL_Window *window;
//     SDL_Renderer *renderer;
//     if (SDL_CreateWindowAndRenderer(window_width, window_height, 0, &window,
//                                     &renderer) < 0) {
//         SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
//                      "Create window and renderer: %s", SDL_GetError());
//         return EXIT_FAILURE;
//     }

//     SDL_SetWindowTitle(window, "SDL Grid");

// 	int keep_window_open = 1;
// 	while(keep_window_open)
// 	{

// 		//if (SDL_QUIT)
// 		//	{ft_printf("???\n"); keep_window_open = 0;}
// 		SDL_SetRenderDrawColor(renderer, grid_background.r, grid_background.g,
// 							   grid_background.b, grid_background.a);
// 		SDL_RenderClear(renderer);

// 		SDL_SetRenderDrawColor(renderer, grid_line_color.r, grid_line_color.g,
// 		 					   grid_line_color.b, grid_line_color.a);

// 		for (int x = 0; x < 1 + grid_width * grid_cell_size;
// 			 x += grid_cell_size) {
// 			SDL_RenderDrawLine(renderer, x, 0, x, window_height);
// 		}

// 		for (int y = 0; y < 1 + grid_height * grid_cell_size;
// 			 y += grid_cell_size) {
// 			SDL_RenderDrawLine(renderer, 0, y, window_width, y);
// 		}

// 		SDL_RenderPresent(renderer);
// 		SDL_Delay(5000);
// 	}

// 	SDL_DestroyRenderer(renderer);
// 	SDL_DestroyWindow(window);
// 	SDL_Quit();

// 	return EXIT_SUCCESS;

	
// }


    int grid_cell_size = 36;
    int grid_width = 29;
    int grid_height = 23;

    // + 1 so that the last grid lines fit in the screen.
    int window_width = (grid_width * grid_cell_size) + 1;
    int window_height = (grid_height * grid_cell_size) + 1;

    // Place the grid cursor in the middle of the screen.
    SDL_Rect grid_cursor = {
        .x = (grid_width - 1) / 2 * grid_cell_size,
        .y = (grid_height - 1) / 2 * grid_cell_size,
        .w = grid_cell_size,
        .h = grid_cell_size,
    };

    // The cursor ghost is a cursor that always shows in the cell below the
    // mouse cursor.
    SDL_Rect grid_cursor_ghost = {grid_cursor.x, grid_cursor.y, grid_cell_size,
                                  grid_cell_size};

    // Dark theme.
    SDL_Color grid_background = {22, 22, 22, 255}; // Barely Black
    SDL_Color grid_line_color = {44, 44, 44, 255}; // Dark grey
    SDL_Color grid_cursor_ghost_color = {44, 44, 44, 255};
    SDL_Color grid_cursor_color = {255, 255, 255, 255}; // White

    // Light Theme.
    // SDL_Color grid_background = {233, 233, 233, 255}; // Barely white
    // SDL_Color grid_line_color = {200, 200, 200, 255}; // Very light grey
    // SDL_Color grid_cursor_ghost_color = {200, 200, 200, 255};
    // SDL_Color grid_cursor_color = {160, 160, 160, 255}; // Grey

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
    SDL_bool mouse_active = SDL_FALSE;
    SDL_bool mouse_hover = SDL_FALSE;

    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                case SDLK_w:
                case SDLK_UP:
                    grid_cursor.y -= grid_cell_size;
                    break;
                case SDLK_s:
                case SDLK_DOWN:
                    grid_cursor.y += grid_cell_size;
                    break;
                case SDLK_a:
                case SDLK_LEFT:
                    grid_cursor.x -= grid_cell_size;
                    break;
                case SDLK_d:
                case SDLK_RIGHT:
                    grid_cursor.x += grid_cell_size;
                    break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                grid_cursor.x = (event.motion.x / grid_cell_size) * grid_cell_size;
                grid_cursor.y = (event.motion.y / grid_cell_size) * grid_cell_size;
                break;
            case SDL_MOUSEMOTION:
                grid_cursor_ghost.x = (event.motion.x / grid_cell_size) * grid_cell_size;
                grid_cursor_ghost.y = (event.motion.y / grid_cell_size) * grid_cell_size;

                if (!mouse_active)
                    mouse_active = SDL_TRUE;
                break;
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_ENTER && !mouse_hover)
                    mouse_hover = SDL_TRUE;
                else if (event.window.event == SDL_WINDOWEVENT_LEAVE && mouse_hover)
                    mouse_hover = SDL_FALSE;
                break;
            case SDL_QUIT:
                quit = SDL_TRUE;
                break;
            }
        }

        // Draw grid background.
        SDL_SetRenderDrawColor(renderer, grid_background.r, grid_background.g,
                               grid_background.b, grid_background.a);
        SDL_RenderClear(renderer);

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

        // Draw grid ghost cursor.
        if (mouse_active && mouse_hover) {
            SDL_SetRenderDrawColor(renderer, grid_cursor_ghost_color.r,
                                   grid_cursor_ghost_color.g,
                                   grid_cursor_ghost_color.b,
                                   grid_cursor_ghost_color.a);
            SDL_RenderFillRect(renderer, &grid_cursor_ghost);
        }

        // Draw grid cursor.
        SDL_SetRenderDrawColor(renderer, grid_cursor_color.r,
                               grid_cursor_color.g, grid_cursor_color.b,
                               grid_cursor_color.a);
        SDL_RenderFillRect(renderer, &grid_cursor);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}

// int main()
// {
//     if(SDL_Init(SDL_INIT_VIDEO) < 0)
//     {
//   //      std::cout << "Failed to initialize the SDL2 library\n";
//     //    std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
//         return -1;
//     }

//     SDL_Window *window = SDL_CreateWindow("SDL2 Window",
//                                           SDL_WINDOWPOS_CENTERED,
//                                           SDL_WINDOWPOS_CENTERED,
//                                           680, 480,
//                                           0);

//     if(!window)
//     {
//       //  std::cout << "Failed to create window\n";
//       //  std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
//         return -1;
//     }

//     SDL_Surface *window_surface = SDL_GetWindowSurface(window);

//     if(!window_surface)
//     {
//    //     std::cout << "Failed to get the surface from the window\n";
//     //    std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
//         return -1;
//     }
    
//     bool keep_window_open = true;
//     while(keep_window_open)
//     {
//         SDL_Event e;
//         while(SDL_PollEvent(&e) > 0)
//         {
//             switch(e.type)
//             {
//                 case SDL_QUIT:
//                     keep_window_open = false;
//                     break;
//             }
// SDL_Rect rect = {0, 0, 100, 100}; // x, y, width, height
// SDL_FillRect(window_surface, &rect, SDL_MapRGB(window_surface->format, 0x50, 0x50, 0x50));
//             SDL_UpdateWindowSurface(window);
//         }
//     }
// }
