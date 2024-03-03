/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:51:54 by ajawad            #+#    #+#             */
/*   Updated: 2024/03/03 11:51:56 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	process_input(t_data *game_data)
{
	if (game_data->pacman.animation_end == 0)
		return ;
	get_element_coordinates(game_data->map, game_data->pacman.starting_pos,
		'P');
	update_player_movement(game_data);
	update_fruit_collection_and_exit_status(game_data);
	change_player_position(game_data);
	get_mvmnt_direction_images(&game_data->pacman);
	print_num_of_movements(&game_data->pacman, &game_data->number_of_moves);
	game_data->pacman.animation_end = 0;
}

void	update(t_data *game_data)
{
	t_player	*pacman;

	pacman = &game_data->pacman;
	if (pacman->animation_delay == 6)
	{
		pacman->x += pacman->dx;
		pacman->y += pacman->dy;
		pacman->animation_frame_index++;
		if (pacman->animation_frame_index == 3)
		{
			pacman->x = 0;
			pacman->y = 0;
			pacman->animation_frame_index = -1;
			pacman->animation_end = 1;
		}
		pacman->animation_delay = 0;
	}
	pacman->animation_delay++;
}

void	render(t_data *game_data)
{
	t_image		*ground;
	t_player	*pacman;
	t_image		*exit_open;

	pacman = &game_data->pacman;
	if (pacman->animation_end == 1 || pacman->animation_frame_index == -1)
		return ;
	ground = &game_data->ground;
	exit_open = &game_data->exit[1];
	mlx_put_image_to_window(game_data->mlx, game_data->win, ground->img,
		pacman->starting_pos[1] * 30, pacman->starting_pos[0] * 30);
	mlx_put_image_to_window(game_data->mlx, game_data->win, ground->img,
		pacman->target_pos[1] * 30, pacman->target_pos[0] * 30);
	mlx_put_image_to_window(game_data->mlx, game_data->win,
		pacman->image_ptr[pacman->animation_frame_index].img,
		pacman->starting_pos[1] * 30 + pacman->x, pacman->starting_pos[0] * 30
		+ pacman->y);
	if (game_data->open_exit == 1)
	{
		mlx_put_image_to_window(game_data->mlx, game_data->win, exit_open->img,
			game_data->exit_position[1] * 30, game_data->exit_position[0] * 30);
		game_data->open_exit = 0;
	}
}

int	game_loop(t_data *game_data)
{
	if (game_data->pacman.player_starts_moving == 1)
	{
		process_input(game_data);
		update(game_data);
		render(game_data);
	}
	return (0);
}
