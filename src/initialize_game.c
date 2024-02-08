#include "../include/so_long.h"

void	init_and_create_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error: failed to init mlx.\n", STDERR_FILENO);
		// TO DO: function to free everything and exit;
		// remember: everything is set to null via memeset,
			//so you can free & close them even if not allocated;
	}
	game->win = mlx_new_window(game->mlx, CELL_WIDTH * game->map_width,
			CELL_HEIGHT * game->map_height, "so_long");
	if (!game->win)
	{
		ft_putstr_fd("Error: failed to create a window.\n", STDERR_FILENO);
		// TO DO: function to free & close everything and exit;
	}
}

void	initialize_game(t_game *game)
{
	parsing_map(game);
	init_and_create_window(game);
	load_images(game); // TO DO
	draw_map(game);    // TO DO
}
