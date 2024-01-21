#include "../includes/so_long.h"
#define WIDTH 1000
#define HEIGHT 900

int	destroy_win(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(EXIT_SUCCESS);
}

int	escape(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		destroy_win(mlx);
	return (0);
}

/*void	exit_the_game(t_mlx *mlx,char **map)
{
	dbl_free(map);
}*/

int	main(int ac, char **av)
{
	t_mlx	mlx;
	char	**map;
	int		mapfd;

	if (ac < 2)
		return (ft_putstr_fd("No map!\n", 2), exit(EXIT_FAILURE), 0);
	mapfd = open(av[1], O_RDONLY);
	if (-1 == mapfd)
		return (perror("open"), exit(errno), 0);	
	map = parsing_map(mapfd);
	int i = 0;
	int j;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			printf("%c", map[i][j++]);
		printf("\n");
		i++;
	}
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, "Hello world!");
	rendering(map, &mlx);
	dbl_free(map);
	mlx_hook(mlx.win, 2, 1L << 0, escape, &mlx);
	mlx_hook(mlx.win, 17, 0, destroy_win, &mlx);
	mlx_loop(mlx.ptr);
}
