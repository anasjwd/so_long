#include "../include/so_long.h"

void	draw_map(t_game *game)
{
	size_t row;
	size_t col;

	row = 0;
	col = 0;
	while (game->map[row][col])
	{
		if (col == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->wall[4].img, col
				* 50, row * 50);
		else if (col == game->map_width - 1)
			mlx_put_image_to_window(game->mlx, game->win, game->wall[3].img, col
				* 50, row * 50);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->wall[0].img, col
				* 50, row * 50);
		col++;
	}
	row++;
	while (game->map[row] && row < game->map_height - 1)
	{
		col = 0;
		while (game->map[row][col])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->ground.img, col
				* 50, row * 50);
			if (col == 0)
				mlx_put_image_to_window(game->mlx, game->win, game->wall[2].img,
					col * 50, row * 50);
			else if (col == game->map_width - 1)
				mlx_put_image_to_window(game->mlx, game->win, game->wall[1].img,
					col * 50, row * 50);
			if (game->map[row][col] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit[0].img,
					col * 50, row * 50);
			col++;
		}
		row++;
	}
	col = 0;
	while (game->map[row][col])
	{
		mlx_put_image_to_window(game->mlx, game->win, game->wall[0].img, col
			* 50, row * 50);
		col++;
	}
	row = 1;
	col = 1;
	while (row < game->map_height - 1)
	{
		col = 1;
		while (col < game->map_width - 1)
		{
			if (game->map[row][col] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->obstacles[0].img, col * 50, row * 50);
			col++;
		}
		row++;
	}
	row = 1;
	while (row < game->map_height - 1)
	{
		col = 1;
		while (col < game->map_width - 1)
		{
			if (game->map[row][col] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->collectible.img, col * 50, row * 50);
			col++;
		}
		row++;
	}
}