/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:48:11 by ajawad            #+#    #+#             */
/*   Updated: 2024/03/03 11:48:44 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	dbl_free(char **ptr)
{
	int	idx_i;

	idx_i = 0;
	while (ptr[idx_i])
	{
		free(ptr[idx_i]);
		idx_i++;
	}
	free(ptr);
}

void	destroy_player_images(void *mlx, t_player *pacman)
{
	int	idx;

	idx = 0;
	while (idx < 3)
	{
		if (pacman->right[idx].img != NULL)
			mlx_destroy_image(mlx, pacman->right[idx].img);
		if (pacman->left[idx].img != NULL)
			mlx_destroy_image(mlx, pacman->left[idx].img);
		if (pacman->up[idx].img != NULL)
			mlx_destroy_image(mlx, pacman->up[idx].img);
		if (pacman->down[idx].img != NULL)
			mlx_destroy_image(mlx, pacman->down[idx].img);
		idx++;
	}
}

void	destroy_collectibles_exit_images(void *mlx, t_image *collectibles,
		t_image *exit)
{
	int	idx;

	idx = 0;
	while (idx < 2)
	{
		if (collectibles[idx].img != NULL)
			mlx_destroy_image(mlx, collectibles[idx].img);
		if (exit[idx].img != NULL)
			mlx_destroy_image(mlx, exit[idx].img);
		idx++;
	}
}

void	destroy_wall_and_ground_images(void *mlx, t_image *ground,
		t_image *wall)
{
	if (ground->img != NULL)
		mlx_destroy_image(mlx, ground->img);
	if (wall->img != NULL)
		mlx_destroy_image(mlx, wall->img);
}

void	exit_game(t_data *game_data, int flag)
{
	mlx_destroy_window(game_data->mlx, game_data->win);
	dbl_free(game_data->map);
	close(game_data->map_fd);
	destroy_player_images(game_data->mlx, &game_data->pacman);
	destroy_collectibles_exit_images(game_data->mlx, game_data->collectibles,
		game_data->exit);
	destroy_wall_and_ground_images(game_data->mlx, &game_data->ground,
		&game_data->wall);
	free(game_data->mlx);
	exit(flag);
}
