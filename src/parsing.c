/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:44:34 by ajawad            #+#    #+#             */
/*   Updated: 2024/03/03 10:44:38 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map_is_rectangle(t_data *game_data)
{
	game_data->width = ft_strlen(game_data->map[0]);
	while (game_data->map[game_data->height])
	{
		if (ft_strlen(game_data->map[game_data->height]) != game_data->width)
		{
			ft_putstr_fd("Error: map should be a rectangle.\n", 2);
			dbl_free(game_data->map);
			exit(EXIT_FAILURE);
		}
		game_data->height++;
	}
}

void	check_elements(t_data *game_data)
{
	int	idx_i;
	int	idx_j;

	idx_i = 0;
	while (game_data->map[idx_i])
	{
		idx_j = 0;
		while (game_data->map[idx_i][idx_j])
		{
			if (0 == check_element_is_valid(game_data->map[idx_i][idx_j]))
			{
				ft_putstr_fd("Error:\nthe map can be composed of only these 5 characters:\n\
                0 for an empty space,\n\
                1 for a wall,\n\
                C for a collectible,\n\
                E for a map exit,\n\
                P for the player's starting position.\n", 2);
				dbl_free(game_data->map);
				exit(EXIT_FAILURE);
			}
			idx_j++;
		}
		idx_i++;
	}
}

void	check_num_of_elements(char **map)
{
	int	idx_i;
	int	p_counter;
	int	e_counter;
	int	c_counter;

	idx_i = 0;
	p_counter = num_of_element(map, 'P');
	e_counter = num_of_element(map, 'E');
	c_counter = num_of_element(map, 'C');
	if (1 != p_counter)
	{
		write(2, "Error: map should contain one starting position\n", 61);
		exit(EXIT_FAILURE);
	}
	if (1 != e_counter)
	{
		write(2, "Error: map should contain one and only one exit\n", 48);
		exit(EXIT_FAILURE);
	}
	if (1 > c_counter)
	{
		write(2, "Error: map contains less that 1 collectible\n", 44);
		exit(EXIT_FAILURE);
	}
}

void	check_map_is_valid(t_data *game_data)
{
	check_map_is_rectangle(game_data);
	check_elements(game_data);
	check_num_of_elements(game_data->map);
	check_map_surrounded_by_wall(game_data);
	check_valid_path_to_necessary_elements(game_data);
}

void	parsing_map(t_data *game_data)
{
	game_data->map = get_map(game_data->map_fd);
	check_map_is_valid(game_data);
	game_data->num_of_fruits = num_of_element(game_data->map, 'C');
	get_element_coordinates(game_data->map, game_data->exit_position, 'E');
}
