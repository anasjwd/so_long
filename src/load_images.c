/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:59:41 by ajawad            #+#    #+#             */
/*   Updated: 2024/03/03 11:00:05 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_image(t_image *element, char *file_path, t_data *game_data)
{
	element->img = mlx_xpm_file_to_image(game_data->mlx, file_path,
			&element->width, &element->height);
	if (NULL == element->img)
	{
		ft_putstr_fd("Error: couldn't load images\n", 2);
		exit_game(game_data, EXIT_FAILURE);
	}
	element->addr = mlx_get_data_addr(element->img, &element->bits_per_pixel,
			&element->line_length, &element->endian);
	if (NULL == element->addr)
	{
		ft_putstr_fd("Error: couldn't load images\n", 2);
		exit_game(game_data, EXIT_FAILURE);
	}
	element = NULL;
}

void	load_ground_and_wall_image(t_data *game_data)
{
	load_image(&game_data->ground, "assets/ground/ground.xpm", game_data);
	load_image(&game_data->wall, "assets/wall/wall.xpm", game_data);
}

void	load_collectibles_and_exit_images(t_data *game_data)
{
	load_image(&game_data->collectibles[0], "assets/collectibles/apple.xpm",
		game_data);
	load_image(&game_data->collectibles[1],
		"assets/collectibles/strawberry.xpm", game_data);
	load_image(&game_data->exit[0], "assets/exit/exit_close.xpm", game_data);
	load_image(&game_data->exit[1], "assets/exit/exit_open.xpm", game_data);
}

void	load_player_images(t_player *pacman, t_data *game_data)
{
	load_image(&pacman->right[0], "assets/pacman_right/right1.xpm", game_data);
	load_image(&pacman->right[1], "assets/pacman_right/right2.xpm", game_data);
	load_image(&pacman->right[2], "assets/pacman_right/right3.xpm", game_data);
	load_image(&pacman->left[0], "assets/pacman_left/left1.xpm", game_data);
	load_image(&pacman->left[1], "assets/pacman_left/left2.xpm", game_data);
	load_image(&pacman->left[2], "assets/pacman_left/left3.xpm", game_data);
	load_image(&pacman->up[0], "assets/pacman_up/up1.xpm", game_data);
	load_image(&pacman->up[1], "assets/pacman_up/up2.xpm", game_data);
	load_image(&pacman->up[2], "assets/pacman_up/up3.xpm", game_data);
	load_image(&pacman->down[0], "assets/pacman_down/down1.xpm", game_data);
	load_image(&pacman->down[1], "assets/pacman_down/down2.xpm", game_data);
	load_image(&pacman->down[2], "assets/pacman_down/down3.xpm", game_data);
}

void	load_images(t_data *game_data)
{
	load_ground_and_wall_image(game_data);
	load_collectibles_and_exit_images(game_data);
	load_player_images(&game_data->pacman, game_data);
}
