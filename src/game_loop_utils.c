/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:56:12 by ajawad            #+#    #+#             */
/*   Updated: 2024/03/03 11:56:14 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_mvmnt_direction_images(t_player *pacman)
{
	if (0 == pacman->dx && 10 == pacman->dy)
		pacman->image_ptr = pacman->down;
	else if (0 == pacman->dx && -10 == pacman->dy)
		pacman->image_ptr = pacman->up;
	else if (-10 == pacman->dx && 0 == pacman->dy)
		pacman->image_ptr = pacman->left;
	else if (10 == pacman->dx && 0 == pacman->dy)
		pacman->image_ptr = pacman->right;
}

void	change_player_position(t_data *game_data)
{
	int	row;
	int	col;
	int	next_row;
	int	next_col;

	row = game_data->pacman.starting_pos[0];
	col = game_data->pacman.starting_pos[1];
	next_row = game_data->pacman.target_pos[0];
	next_col = game_data->pacman.target_pos[1];
	game_data->map[row][col] = '0';
	game_data->map[next_row][next_col] = 'P';
}

int	check_if_mvmnt_is_possible(int *initial_position, int x, int y,
		t_data *game_data)
{
	int	row;
	int	col;

	row = initial_position[0] + y;
	col = initial_position[1] + x;
	if (game_data->map[row][col] != '1' && game_data->map[row][col] != 'E')
		return (1);
	else if (game_data->map[row][col] == 'E'
		&& game_data->num_of_fruits == game_data->pacman.collected_fruits)
		exit_game(game_data, EXIT_SUCCESS);
	return (0);
}

void	update_fruit_collection_and_exit_status(t_data *game_data)
{
	int	row;
	int	col;

	row = game_data->pacman.target_pos[0];
	col = game_data->pacman.target_pos[1];
	if (game_data->map[row][col] == 'C')
	{
		game_data->pacman.collected_fruits++;
		if (game_data->num_of_fruits == game_data->pacman.collected_fruits)
			game_data->open_exit = 1;
	}
}

void	update_player_movement(t_data *game_data)
{
	t_player	*pacman;
	char		**map;

	pacman = &game_data->pacman;
	map = game_data->map;
	if (check_if_mvmnt_is_possible(pacman->starting_pos, pacman->next_dx / 10,
			pacman->next_dy / 10, game_data))
	{
		pacman->dx = pacman->next_dx;
		pacman->dy = pacman->next_dy;
	}
	if (!check_if_mvmnt_is_possible(pacman->starting_pos, pacman->dx / 10,
			pacman->dy / 10, game_data))
	{
		pacman->dx = 0;
		pacman->dy = 0;
	}
	pacman->target_pos[0] = pacman->starting_pos[0] + (pacman->dy / 10);
	pacman->target_pos[1] = pacman->starting_pos[1] + (pacman->dx / 10);
}
