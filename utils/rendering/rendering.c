#include "../../includes/so_long.h"
#define WIDTH 1000
#define HEIGHT 900

void	rendering(char **map, t_mlx *mlx)
{
	t_data	wall;
	t_data	ground;
	t_data	character;
	t_data	door;
	t_data	coin;
	int	width;
	int	height;
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	x = 0;
	y = 0;
	character.img = mlx_xpm_file_to_image(mlx->ptr, "utils/elements/char.xpm", &width, &height);
	coin.img = mlx_xpm_file_to_image(mlx->ptr, "utils/elements/flos.xpm", &width, &height);
	if (coin.img == NULL)
		printf("ALLO !\n");
	door.img = mlx_xpm_file_to_image(mlx->ptr, "utils/elements/door.xpm", &width, &height);
	wall.img = mlx_xpm_file_to_image(mlx->ptr, "utils/elements/wall.xpm", &width, &height);
	ground.img = mlx_xpm_file_to_image(mlx->ptr, "utils/elements/ground.xpm", &width, &height);	
	
	character.addr = mlx_get_data_addr(character.img, &character.bits_per_pixel, &character.line_length, &character.endian);
	coin.addr = mlx_get_data_addr(coin.img, &coin.bits_per_pixel, &coin.line_length, &coin.endian);
	door.addr = mlx_get_data_addr(door.img, &door.bits_per_pixel, &door.line_length, &door.endian);
	wall.addr = mlx_get_data_addr(wall.img, &wall.bits_per_pixel, &wall.line_length, &wall.endian);
	ground.addr = mlx_get_data_addr(ground.img, &ground.bits_per_pixel, &ground.line_length, &ground.endian);
	while (map[i] && y < HEIGHT)
	{
		j = 0;
		while (map[i][j] && x < WIDTH)
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx->ptr, mlx->win, wall.img, x, y);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(mlx->ptr, mlx->win, ground.img, x, y);
			// else if (map[i][j] == 'P')
			// {
			// 	mlx_put_image_to_window(mlx->ptr, mlx->win, ground.img, x, y);
			// 	mlx_put_image_to_window(mlx->ptr, mlx->win, character.img, x* 60, y * 102);
			// }
			else if (map[i][j] == 'E')
			{
				mlx_put_image_to_window(mlx->ptr, mlx->win, ground.img, x, y);
				mlx_put_image_to_window(mlx->ptr, mlx->win, door.img, x, y);
			}
			else if (map[i][j] == 'C')
			{
				mlx_put_image_to_window(mlx->ptr, mlx->win, ground.img, x, y);
				printf("allo\n");
				mlx_put_image_to_window(mlx->ptr, mlx->win, coin.img, x, y);
			}
			x += width;
			j++;
		}
		y += height;
		x = 0;
		i++;
	}
	free(wall.img);
	free(character.img);
	free(door.img);
	free(coin.img);
	free(ground.img);
}
