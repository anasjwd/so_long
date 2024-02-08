#include "../include/so_long.h"

void	parsing_map(t_game *game)
{
	get_map(game);
	check_map_is_valid(game);
}

int	check_numof_elements(t_game *game)
{
	int	i;
	int	j;
	int	player;
	int	exit;
	int	collectibles;

	i = 0;
	player = 0;
	collectibles = 0;
	exit = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				player++;
			else if (game->map[i][j] == 'E')
				exit++;
			else if (game->map[i][j] == 'C')
				game->num_of_collectibles++;
			j++;
		}
		i++;
	}
	if (player != 1 || game->num_of_collectibles < 1 || exit != 1)
		return (-1);
	return (1);
}

int	check_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[0][i] && game->map[game->map_height - 1][i])
	{
		if (game->map[0][i] != '1' || game->map[game->map_height - 1][i] != '1')
			return (-2);
		i++;
	}
	i = 0;
	while (game->map[i])
	{
		j = 1;
		while (game->map[i][j])
		{
			if (!IS_VALID_ELEMENT(game->map[i][j]))
				return (-1);
			j++;
		}
		if (game->map[i][0] != '1' || game->map[i][j - 1] != '1')
			return (-2);
		i++;
	}
	return (1);
}
void	flood_fill(char **map, int x, int y, char f)
{
	if (x < 0 || y < 0 || !map[x] || map[x][y] == '\0' || map[x][y] == '1'
		|| map[x][y] == f)
		return ;
	map[x][y] = f;
	flood_fill(map, x + 1, y, f);
	flood_fill(map, x - 1, y, f);
	flood_fill(map, x, y - 1, f);
	flood_fill(map, x, y + 1, f);
}

int	check_for_path(t_game *game)
{
	int		cord[2];
	size_t	i;
	size_t	j;

	get_map_copy(game);
	get_element_cord(game->map, cord, 'P');
	flood_fill(game->map_copy, cord[0], cord[1], 'F');
	i = 0;
	while (game->map_copy[i++] && i < game->map_height - 1)
	{
		j = 0;
		while (game->map_copy[i][j])
		{
			if (game->map_copy[i][j] == 'E' || game->map_copy[i][j] == 'C')
				return (dbl_free(game->map_copy), -1);
			j++;
		}
	}
	return (dbl_free(game->map_copy), 1);
}

void	check_map_is_valid(t_game *game)
{
	int check;

	check = check_elements(game);
	if (-2 == check)
	{
		dbl_free(game->map);
		ft_putstr_fd("Error: the map should be surrounded by walls.\n", 2);
		exit(EXIT_FAILURE);
	}
	if (-1 == check)
	{
		dbl_free(game->map);
		ft_putstr_fd("Error: use of an invalid element in the map.\n", 2);
		ft_putstr_fd("valid elements:\nP: for the player.\nE: for the exit.\n",
			2);
		ft_putstr_fd("C: for the collectibles\n1: for the walls.\n0: for the ground.\n",
			2);
		exit(EXIT_FAILURE);
	}
	if (-1 == check_numof_elements(game))
	{
		dbl_free(game->map);
		ft_putstr_fd("Error: the map should contain only one player, \
			one exit and more than 0 collectible\n", 2);
		exit(EXIT_FAILURE);
	}
	if (-1 == check_for_path(game))
	{
		dbl_free(game->map);
		ft_putstr_fd("Error: invalid path to necessary element.\n", 2);
		system("leaks a.out");
		exit(EXIT_FAILURE);
	}
}