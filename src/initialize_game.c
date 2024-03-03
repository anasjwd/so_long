/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:33:53 by ajawad            #+#    #+#             */
/*   Updated: 2024/03/03 10:37:11 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize_mlx(t_data *game_data)
{
	game_data->mlx = mlx_init();
	if (NULL == game_data->mlx)
	{
		write(2, "Error: connection with the graphical system is not \
				established\n", 67);
		dbl_free(game_data->map);
		exit(EXIT_FAILURE);
	}
	game_data->win = mlx_new_window(game_data->mlx, game_data->width * 30,
			game_data->height * 30, "SO_LONG");
	if (NULL == game_data->win)
	{
		write(2, "Error: the window creation has failed\n", 38);
		dbl_free(game_data->map);
		free(game_data->mlx);
		exit(EXIT_FAILURE);
	}
}

void	initialize_game(t_data *game_data)
{
	parsing_map(game_data);
	initialize_mlx(game_data);
	load_images(game_data);
	draw_map(game_data);
}
