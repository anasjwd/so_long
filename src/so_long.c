#include "../include/so_long.h"
#define RANDOM_MAX 32767
#define RANDOM_A 1103515245
#define RONDOM_C 12345

unsigned int	random_number(void)
{
	static unsigned int	random_seed;

	random_seed = (RANDOM_A * random_seed + RONDOM_C) % RANDOM_MAX;
	return (random_seed);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_putstr_fd("Error: no map is provided\n", STDERR_FILENO);
		return (1);
	}
	if (!check_file_extention(av[1]))
	{
		ft_putstr_fd("Error: map file should end with \".ber\"\n",
			STDERR_FILENO);
		return (1);
	}
	ft_memset(&game, 0, sizeof(game));
	game.player.animation_end = 1;
    //calc_num_of_collectibles(game.map);
	game.mapfd = open(av[1], O_RDONLY);
	if (-1 == game.mapfd)
		return (perror("open"), EXIT_FAILURE);
	initialize_game(&game);
	mlx_hook(game.win, 17, 0, destroy_window, &game);
	mlx_hook(game.win, 3, 3, player_movements_keyup, &game);
	mlx_loop_hook(game.mlx, update_game_state, &game);
	mlx_loop(game.mlx);
	return (0);
}

int	destroy_window(t_game *game)
{
	dbl_free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}

int	check_file_extention(char *file_name)
{
	int		idx1;
	int		idx2;
	char	*extention;

	extention = ".ber";
	idx1 = ft_strlen(file_name);
	idx2 = 4;
	while (idx2 >= 0)
	{
		if (file_name[idx1] != extention[idx2])
			return (0);
		idx1--;
		idx2--;
	}
	return (1);
}

void	dbl_free(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}