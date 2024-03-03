/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:55:53 by ajawad            #+#    #+#             */
/*   Updated: 2024/03/03 10:57:24 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map_surrounded_by_wall(t_data *game_data)
{
	int	idx;

	idx = 0;
	while (game_data->map[0][idx] && game_data->map[game_data->height - 1][idx])
	{
		if (game_data->map[0][idx] != '1' || \
			game_data->map[game_data->height - 1][idx++] != '1')
		{
			ft_putstr_fd("Error: the map should be surrounded by walls\n", 2);
			dbl_free(game_data->map);
			exit(EXIT_FAILURE);
		}
	}
	idx = 1;
	while (game_data->map[idx] && game_data->map[idx][0]
		&& game_data->map[idx][game_data->width - 1])
	{
		if (game_data->map[idx][0] != '1'
			|| game_data->map[idx++][game_data->width - 1] != '1')
		{
			ft_putstr_fd("Error: the map should be surrounded by walls\n", 2);
			dbl_free(game_data->map);
			exit(EXIT_FAILURE);
		}
	}
}

void	flood_fill(char **map, int y, int x, char f)
{
	if (map[y][x] == '1' || map[y][x] == f)
		return ;
	map[y][x] = f;
	flood_fill(map, y - 1, x, f);
	flood_fill(map, y + 1, x, f);
	flood_fill(map, y, x - 1, f);
	flood_fill(map, y, x + 1, f);
}

int	check_flood_fill(char **map)
{
	int	idx_i;
	int	idx_j;

	idx_i = 0;
	while (map[idx_i])
	{
		idx_j = 0;
		while (map[idx_i][idx_j])
		{
			if (map[idx_i][idx_j] == 'E' || map[idx_i][idx_j] == 'C')
				return (0);
			idx_j++;
		}
		idx_i++;
	}
	return (1);
}

void	check_valid_path_to_necessary_elements(t_data *game_data)
{
	int		player_coordinates[2];
	char	**map_copy;

	map_copy = get_map_copy(game_data->map, game_data->height);
	if (map_copy == NULL)
		return (free(game_data->map), perror("Fatal"), exit(EXIT_FAILURE));
	get_element_coordinates(game_data->map, player_coordinates, 'P');
	flood_fill(map_copy, player_coordinates[0], player_coordinates[1], 'f');
	if (0 == check_flood_fill(map_copy))
	{
		write(2, "Error: invalid path to necessary element\n", 41);
		dbl_free(game_data->map);
		dbl_free(map_copy);
		exit(EXIT_FAILURE);
	}
	dbl_free(map_copy);
}
