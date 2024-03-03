/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:45:06 by ajawad            #+#    #+#             */
/*   Updated: 2024/03/03 11:45:22 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_ground_and_walls(t_data *game_data)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (game_data->map[row])
	{
		col = 0;
		while (game_data->map[row][col])
		{
			if ('1' == game_data->map[row][col])
				mlx_put_image_to_window(game_data->mlx, game_data->win,
					game_data->wall.img, col * 30, row * 30);
			else
				mlx_put_image_to_window(game_data->mlx, game_data->win,
					game_data->ground.img, col * 30, row * 30);
			col++;
		}
		row++;
	}
}

void	draw_collectibles_and_exit(t_data *game_data)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (game_data->map[row])
	{
		col = 0;
		while (game_data->map[row][col])
		{
			if ('C' == game_data->map[row][col])
				mlx_put_image_to_window(game_data->mlx, game_data->win,
					game_data->collectibles[random_number() % 2].img, col * 30,
					row * 30);
			else if ('E' == game_data->map[row][col])
				mlx_put_image_to_window(game_data->mlx, game_data->win,
					game_data->exit[0].img, col * 30, row * 30);
			col++;
		}
		row++;
	}
}

void	draw_player(t_data *game_data)
{
	int	player_position[2];

	get_element_coordinates(game_data->map, player_position, 'P');
	mlx_put_image_to_window(game_data->mlx, game_data->win,
		game_data->pacman.up[0].img, player_position[1] * 30, player_position[0]
		* 30);
}

void	draw_map(t_data *game_data)
{
	draw_ground_and_walls(game_data);
	draw_collectibles_and_exit(game_data);
	draw_player(game_data);
}
