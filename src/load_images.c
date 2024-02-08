#include "../include/so_long.h"

// TO DO: CHECK IF ANY OF THE IMAGES DIDN'T GETS UPLOADED!!!!

void	load_player_right_mv(t_game *game)
{
	game->player.player_mv_right[0].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/right_mv1.xpm", &game->player.player_mv_right[0].width,
			&game->player.player_mv_right[0].height);
	game->player.player_mv_right[0].addr = mlx_get_data_addr(game->player.player_mv_right[0].img,
			&game->player.player_mv_right[0].bits_per_pixel,
			&game->player.player_mv_right[0].line_length,
			&game->player.player_mv_right[0].endian);
	game->player.player_mv_right[1].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/right_mv2.xpm", &game->player.player_mv_right[1].width,
			&game->player.player_mv_right[1].height);
	game->player.player_mv_right[1].addr = mlx_get_data_addr(game->player.player_mv_right[1].img,
			&game->player.player_mv_right[1].bits_per_pixel,
			&game->player.player_mv_right[1].line_length,
			&game->player.player_mv_right[1].endian);
	game->player.player_mv_right[2].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/right_mv3.xpm", &game->player.player_mv_right[2].width,
			&game->player.player_mv_right[2].height);
	game->player.player_mv_right[2].addr = mlx_get_data_addr(game->player.player_mv_right[2].img,
			&game->player.player_mv_right[2].bits_per_pixel,
			&game->player.player_mv_right[2].line_length,
			&game->player.player_mv_right[2].endian);
	game->player.player_mv_right[3].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/right_mv4.xpm", &game->player.player_mv_right[3].width,
			&game->player.player_mv_right[3].height);
	game->player.player_mv_right[3].addr = mlx_get_data_addr(game->player.player_mv_right[3].img,
			&game->player.player_mv_right[3].bits_per_pixel,
			&game->player.player_mv_right[3].line_length,
			&game->player.player_mv_right[3].endian);
	game->player.player_mv_right[4].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/right_mv6.xpm", &game->player.player_mv_right[4].width,
			&game->player.player_mv_right[4].height);
	game->player.player_mv_right[4].addr = mlx_get_data_addr(game->player.player_mv_right[4].img,
			&game->player.player_mv_right[4].bits_per_pixel,
			&game->player.player_mv_right[4].line_length,
			&game->player.player_mv_right[4].endian);
}

void	load_player_left_mv(t_game *game)
{
	game->player.player_mv_left[0].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/player_left1.xpm", &game->player.player_mv_left[0].width,
			&game->player.player_mv_left[0].height);
	game->player.player_mv_left[0].addr = mlx_get_data_addr(game->player.player_mv_left[0].img,
			&game->player.player_mv_left[0].bits_per_pixel,
			&game->player.player_mv_left[0].line_length,
			&game->player.player_mv_left[0].endian);
	game->player.player_mv_left[1].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/player_left2.xpm", &game->player.player_mv_left[1].width,
			&game->player.player_mv_left[1].height);
	game->player.player_mv_left[1].addr = mlx_get_data_addr(game->player.player_mv_left[1].img,
			&game->player.player_mv_left[1].bits_per_pixel,
			&game->player.player_mv_left[1].line_length,
			&game->player.player_mv_left[1].endian);
	game->player.player_mv_left[2].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/player_left3.xpm", &game->player.player_mv_left[2].width,
			&game->player.player_mv_left[2].height);
	game->player.player_mv_left[2].addr = mlx_get_data_addr(game->player.player_mv_left[2].img,
			&game->player.player_mv_left[2].bits_per_pixel,
			&game->player.player_mv_left[2].line_length,
			&game->player.player_mv_left[2].endian);
	game->player.player_mv_left[3].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/player_left4.xpm", &game->player.player_mv_left[3].width,
			&game->player.player_mv_left[3].height);
	game->player.player_mv_left[3].addr = mlx_get_data_addr(game->player.player_mv_left[3].img,
			&game->player.player_mv_left[3].bits_per_pixel,
			&game->player.player_mv_left[3].line_length,
			&game->player.player_mv_left[3].endian);
	game->player.player_mv_left[4].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/player_left5.xpm", &game->player.player_mv_left[4].width,
			&game->player.player_mv_left[4].height);
	game->player.player_mv_left[4].addr = mlx_get_data_addr(game->player.player_mv_left[4].img,
			&game->player.player_mv_left[4].bits_per_pixel,
			&game->player.player_mv_left[4].line_length,
			&game->player.player_mv_left[4].endian);
	game->player.player_mv_left[5].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/player_left6.xpm", &game->player.player_mv_left[5].width,
			&game->player.player_mv_left[5].height);
	game->player.player_mv_left[5].addr = mlx_get_data_addr(game->player.player_mv_left[5].img,
			&game->player.player_mv_left[5].bits_per_pixel,
			&game->player.player_mv_left[5].line_length,
			&game->player.player_mv_left[5].endian);
}

void	load_player_images(t_game *game)
{
	game->player.player[0].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/player_s1.xpm", &game->player.player[0].width,
			&game->player.player[0].height);
	game->player.player[0].addr = mlx_get_data_addr(game->player.player[0].img,
			&game->player.player[0].bits_per_pixel,
			&game->player.player[0].line_length,
			&game->player.player[0].endian);
	game->player.player[1].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/player_s2.xpm", &game->player.player[1].width,
			&game->player.player[1].height);
	game->player.player[1].addr = mlx_get_data_addr(game->player.player[1].img,
			&game->player.player[1].bits_per_pixel,
			&game->player.player[1].line_length,
			&game->player.player[1].endian);
	game->player.player[2].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/player_s3.xpm", &game->player.player[2].width,
			&game->player.player[2].height);
	game->player.player[2].addr = mlx_get_data_addr(game->player.player[2].img,
			&game->player.player[2].bits_per_pixel,
			&game->player.player[2].line_length,
			&game->player.player[2].endian);
	game->player.player[3].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/player_s4.xpm", &game->player.player[3].width,
			&game->player.player[3].height);
	game->player.player[3].addr = mlx_get_data_addr(game->player.player[3].img,
			&game->player.player[3].bits_per_pixel,
			&game->player.player[3].line_length,
			&game->player.player[3].endian);
	game->player.player[4].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/player_s5.xpm", &game->player.player[4].width,
			&game->player.player[4].height);
	game->player.player[4].addr = mlx_get_data_addr(game->player.player[4].img,
			&game->player.player[4].bits_per_pixel,
			&game->player.player[4].line_length,
			&game->player.player[4].endian);
	game->player.player[5].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/player_s5.xpm", &game->player.player[5].width,
			&game->player.player[5].height);
	game->player.player[5].addr = mlx_get_data_addr(game->player.player[5].img,
			&game->player.player[5].bits_per_pixel,
			&game->player.player[5].line_length,
			&game->player.player[5].endian);
}

void	load_wall_image(t_game *game)
{
	game->wall[0].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/up_wall.xpm", &game->wall[0].width,
			&game->wall[0].height);
	game->wall[0].addr = mlx_get_data_addr(game->wall[0].img,
			&game->wall[0].bits_per_pixel, &game->wall[0].line_length,
			&game->wall[0].endian);
	game->wall[1].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/right_wall.xpm", &game->wall[1].width,
			&game->wall[1].height);
	game->wall[1].addr = mlx_get_data_addr(game->wall[1].img,
			&game->wall[1].bits_per_pixel, &game->wall[1].line_length,
			&game->wall[1].endian);
	game->wall[2].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/left_wall.xpm", &game->wall[2].width,
			&game->wall[2].height);
	game->wall[2].addr = mlx_get_data_addr(game->wall[2].img,
			&game->wall[2].bits_per_pixel, &game->wall[2].line_length,
			&game->wall[2].endian);
	game->wall[3].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/right_up_corner.xpm", &game->wall[3].width,
			&game->wall[3].height);
	game->wall[3].addr = mlx_get_data_addr(game->wall[3].img,
			&game->wall[3].bits_per_pixel, &game->wall[3].line_length,
			&game->wall[3].endian);
	game->wall[4].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/left_up_corner.xpm", &game->wall[4].width,
			&game->wall[4].height);
	game->wall[4].addr = mlx_get_data_addr(game->wall[4].img,
			&game->wall[4].bits_per_pixel, &game->wall[4].line_length,
			&game->wall[4].endian);
}

void	load_obstacles_images(t_game *game)
{
	game->obstacles[0].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/green.xpm", &game->obstacles[0].width,
			&game->obstacles[0].height);
	game->obstacles[0].addr = mlx_get_data_addr(game->obstacles[0].img,
			&game->obstacles[0].bits_per_pixel, &game->obstacles[0].line_length,
			&game->obstacles[0].endian);
	/* game->obstacles[1].img = mlx_xpm_file_to_image(game->mlx,
		"../assets/rock.xpm", &game->obstacles[1].width,
		&game->obstacles[1].height);
	 game->obstacles[1].addr = mlx_get_data_addr(game->obstacles[1].img,
		&game->obstacles[1].bits_per_pixel, &game->obstacles[1].line_length,
		&game->obstacles[1].endian);*/
}

void	load_exit_images(t_game *game)
{
	game->exit[0].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/closed_exit.xpm", &game->exit[0].width,
			&game->exit[0].height);
	game->exit[0].addr = mlx_get_data_addr(game->exit[0].img,
			&game->exit[0].bits_per_pixel, &game->exit[0].line_length,
			&game->exit[0].endian);
	game->exit[1].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/opened_exit.xpm", &game->exit[1].width,
			&game->exit[1].height);
	game->exit[1].addr = mlx_get_data_addr(game->exit[1].img,
			&game->exit[1].bits_per_pixel, &game->exit[1].line_length,
			&game->exit[1].endian);
}

void	load_ground_image(t_game *game)
{
	game->ground.img = mlx_xpm_file_to_image(game->mlx, "../assets/ground.xpm",
			&game->ground.width, &game->ground.height);
	game->ground.addr = mlx_get_data_addr(game->ground.img,
			&game->ground.bits_per_pixel, &game->ground.line_length,
			&game->ground.endian);
}

void	load_collectible_image(t_game *game)
{
	game->collectible.img = mlx_xpm_file_to_image(game->mlx,
			"../assets/collectible(3).xpm", &game->collectible.width,
			&game->collectible.height);
	game->collectible.addr = mlx_get_data_addr(game->collectible.img,
			&game->collectible.bits_per_pixel, &game->collectible.line_length,
			&game->collectible.endian);
}

void	load_enemy_images(t_game *game)
{
	game->enemy.standing[0].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/Torch_Red1.xpm", &game->enemy.standing[0].width,
			&game->enemy.standing[0].height);
	if (game->enemy.standing[0].img == NULL)
		return (printf("Error\n"), exit(1));
	game->enemy.standing[0].addr = mlx_get_data_addr(game->enemy.standing[0].img,
			&game->enemy.standing[0].bits_per_pixel,
			&game->enemy.standing[0].line_length,
			&game->enemy.standing[0].endian);
	game->enemy.standing[1].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/Torch_Red2.xpm", &game->enemy.standing[1].width,
			&game->enemy.standing[1].height);
	if (game->enemy.standing[0].img == NULL)
		return (printf("Error\n"), exit(1));
	game->enemy.standing[1].addr = mlx_get_data_addr(game->enemy.standing[1].img,
			&game->enemy.standing[1].bits_per_pixel,
			&game->enemy.standing[1].line_length,
			&game->enemy.standing[1].endian);
	game->enemy.standing[2].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/Torch_Red3.xpm", &game->enemy.standing[2].width,
			&game->enemy.standing[2].height);
	if (game->enemy.standing[0].img == NULL)
		return (printf("Error\n"), exit(1));
	game->enemy.standing[2].addr = mlx_get_data_addr(game->enemy.standing[2].img,
			&game->enemy.standing[2].bits_per_pixel,
			&game->enemy.standing[2].line_length,
			&game->enemy.standing[2].endian);
	game->enemy.standing[3].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/Torch_Red4.xpm", &game->enemy.standing[3].width,
			&game->enemy.standing[3].height);
	if (game->enemy.standing[0].img == NULL)
		return (printf("Error\n"), exit(1));
	game->enemy.standing[3].addr = mlx_get_data_addr(game->enemy.standing[3].img,
			&game->enemy.standing[3].bits_per_pixel,
			&game->enemy.standing[3].line_length,
			&game->enemy.standing[3].endian);
	game->enemy.standing[4].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/Torch_Red5.xpm", &game->enemy.standing[4].width,
			&game->enemy.standing[4].height);
	if (game->enemy.standing[0].img == NULL)
		return (printf("Error\n"), exit(1));
	game->enemy.standing[4].addr = mlx_get_data_addr(game->enemy.standing[4].img,
			&game->enemy.standing[4].bits_per_pixel,
			&game->enemy.standing[4].line_length,
			&game->enemy.standing[4].endian);
}

void	load_enemy_right_attack_images(t_game *game)
{
	game->enemy.right_attack[0].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/right_attack1.xpm", &game->enemy.right_attack[0].width,
			&game->enemy.right_attack[0].height);
	game->enemy.right_attack->addr = mlx_get_data_addr(game->enemy.right_attack[0].img,
			&game->enemy.right_attack[0].bits_per_pixel,
			&game->enemy.right_attack[0].line_length,
			&game->enemy.right_attack[0].endian);
	game->enemy.right_attack[1].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/right_attack2.xpm", &game->enemy.right_attack[1].width,
			&game->enemy.right_attack[1].height);
	game->enemy.right_attack->addr = mlx_get_data_addr(game->enemy.right_attack[1].img,
			&game->enemy.right_attack[1].bits_per_pixel,
			&game->enemy.right_attack[1].line_length,
			&game->enemy.right_attack[1].endian);
	game->enemy.right_attack[2].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/right_attack3.xpm", &game->enemy.right_attack[2].width,
			&game->enemy.right_attack[2].height);
	game->enemy.right_attack->addr = mlx_get_data_addr(game->enemy.right_attack[2].img,
			&game->enemy.right_attack[2].bits_per_pixel,
			&game->enemy.right_attack[2].line_length,
			&game->enemy.right_attack[2].endian);
	game->enemy.right_attack[3].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/right_attack4.xpm", &game->enemy.right_attack[3].width,
			&game->enemy.right_attack[3].height);
	game->enemy.right_attack->addr = mlx_get_data_addr(game->enemy.right_attack[3].img,
			&game->enemy.right_attack[3].bits_per_pixel,
			&game->enemy.right_attack[3].line_length,
			&game->enemy.right_attack[3].endian);
	game->enemy.right_attack[4].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/right_attack5.xpm", &game->enemy.right_attack[4].width,
			&game->enemy.right_attack[4].height);
	game->enemy.right_attack->addr = mlx_get_data_addr(game->enemy.right_attack[4].img,
			&game->enemy.right_attack[4].bits_per_pixel,
			&game->enemy.right_attack[4].line_length,
			&game->enemy.right_attack[4].endian);
}
void	load_enemy_front_attack_images(t_game *game)
{
	game->enemy.front_attack[0].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/front_attack1.xpm", &game->enemy.front_attack[0].width,
			&game->enemy.front_attack[0].height);
	game->enemy.front_attack->addr = mlx_get_data_addr(game->enemy.front_attack[0].img,
			&game->enemy.front_attack[0].bits_per_pixel,
			&game->enemy.front_attack[0].line_length,
			&game->enemy.front_attack[0].endian);
	game->enemy.front_attack[1].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/front_attack2.xpm", &game->enemy.front_attack[1].width,
			&game->enemy.front_attack[1].height);
	game->enemy.front_attack->addr = mlx_get_data_addr(game->enemy.front_attack[1].img,
			&game->enemy.front_attack[1].bits_per_pixel,
			&game->enemy.front_attack[1].line_length,
			&game->enemy.front_attack[1].endian);
	game->enemy.front_attack[2].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/front_attack3.xpm", &game->enemy.front_attack[2].width,
			&game->enemy.front_attack[2].height);
	game->enemy.front_attack->addr = mlx_get_data_addr(game->enemy.front_attack[2].img,
			&game->enemy.front_attack[2].bits_per_pixel,
			&game->enemy.front_attack[2].line_length,
			&game->enemy.front_attack[2].endian);
	game->enemy.front_attack[3].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/front_attack4.xpm", &game->enemy.front_attack[3].width,
			&game->enemy.front_attack[3].height);
	game->enemy.front_attack->addr = mlx_get_data_addr(game->enemy.front_attack[3].img,
			&game->enemy.front_attack[3].bits_per_pixel,
			&game->enemy.front_attack[3].line_length,
			&game->enemy.front_attack[3].endian);
	game->enemy.front_attack[4].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/front_attack5.xpm", &game->enemy.front_attack[4].width,
			&game->enemy.front_attack[4].height);
	game->enemy.front_attack->addr = mlx_get_data_addr(game->enemy.front_attack[4].img,
			&game->enemy.front_attack[4].bits_per_pixel,
			&game->enemy.front_attack[4].line_length,
			&game->enemy.front_attack[4].endian);
}

void	load_enemy_back_attack_images(t_game *game)
{
	game->enemy.back_attack[0].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/back_attack1.xpm", &game->enemy.back_attack[0].width,
			&game->enemy.back_attack[0].height);
	game->enemy.back_attack->addr = mlx_get_data_addr(game->enemy.back_attack[0].img,
			&game->enemy.back_attack[0].bits_per_pixel,
			&game->enemy.back_attack[0].line_length,
			&game->enemy.back_attack[0].endian);
	game->enemy.back_attack[1].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/back_attack2.xpm", &game->enemy.back_attack[1].width,
			&game->enemy.back_attack[1].height);
	game->enemy.back_attack->addr = mlx_get_data_addr(game->enemy.back_attack[1].img,
			&game->enemy.back_attack[1].bits_per_pixel,
			&game->enemy.back_attack[1].line_length,
			&game->enemy.back_attack[1].endian);
	game->enemy.back_attack[2].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/back_attack3.xpm", &game->enemy.back_attack[2].width,
			&game->enemy.back_attack[2].height);
	game->enemy.back_attack->addr = mlx_get_data_addr(game->enemy.back_attack[2].img,
			&game->enemy.back_attack[2].bits_per_pixel,
			&game->enemy.back_attack[2].line_length,
			&game->enemy.back_attack[2].endian);
	game->enemy.back_attack[3].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/back_attack4.xpm", &game->enemy.back_attack[3].width,
			&game->enemy.back_attack[3].height);
	game->enemy.back_attack->addr = mlx_get_data_addr(game->enemy.back_attack[3].img,
			&game->enemy.back_attack[3].bits_per_pixel,
			&game->enemy.back_attack[3].line_length,
			&game->enemy.back_attack[3].endian);
	game->enemy.back_attack[4].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/back_attack5.xpm", &game->enemy.back_attack[4].width,
			&game->enemy.back_attack[4].height);
	game->enemy.back_attack->addr = mlx_get_data_addr(game->enemy.back_attack[4].img,
			&game->enemy.back_attack[4].bits_per_pixel,
			&game->enemy.back_attack[4].line_length,
			&game->enemy.back_attack[4].endian);
}

void	load_enemy_left_attack_images(t_game *game)
{
	game->enemy.left_attack[0].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/left_attack1.xpm", &game->enemy.left_attack[0].width,
			&game->enemy.left_attack[0].height);
	game->enemy.left_attack->addr = mlx_get_data_addr(game->enemy.left_attack[0].img,
			&game->enemy.left_attack[0].bits_per_pixel,
			&game->enemy.left_attack[0].line_length,
			&game->enemy.left_attack[0].endian);
	game->enemy.left_attack[1].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/left_attack2.xpm", &game->enemy.left_attack[1].width,
			&game->enemy.left_attack[1].height);
	game->enemy.left_attack->addr = mlx_get_data_addr(game->enemy.left_attack[1].img,
			&game->enemy.left_attack[1].bits_per_pixel,
			&game->enemy.left_attack[1].line_length,
			&game->enemy.left_attack[1].endian);
	game->enemy.left_attack[2].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/left_attack3.xpm", &game->enemy.left_attack[2].width,
			&game->enemy.left_attack[2].height);
	game->enemy.left_attack->addr = mlx_get_data_addr(game->enemy.left_attack[2].img,
			&game->enemy.left_attack[2].bits_per_pixel,
			&game->enemy.left_attack[2].line_length,
			&game->enemy.left_attack[2].endian);
	game->enemy.left_attack[3].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/left_attack4.xpm", &game->enemy.left_attack[3].width,
			&game->enemy.left_attack[3].height);
	game->enemy.left_attack->addr = mlx_get_data_addr(game->enemy.left_attack[3].img,
			&game->enemy.left_attack[3].bits_per_pixel,
			&game->enemy.left_attack[3].line_length,
			&game->enemy.left_attack[3].endian);
	game->enemy.left_attack[4].img = mlx_xpm_file_to_image(game->mlx,
			"../assets/left_attack5.xpm", &game->enemy.left_attack[4].width,
			&game->enemy.left_attack[4].height);
	game->enemy.left_attack->addr = mlx_get_data_addr(game->enemy.left_attack[4].img,
			&game->enemy.left_attack[4].bits_per_pixel,
			&game->enemy.left_attack[4].line_length,
			&game->enemy.left_attack[4].endian);
}

void	load_images(t_game *game)
{
	load_wall_image(game);
	load_ground_image(game);
	load_player_images(game);
	load_player_right_mv(game);
	load_player_left_mv(game);
	load_exit_images(game);
	load_obstacles_images(game);
	load_collectible_image(game);
	load_enemy_images(game);
	load_enemy_right_attack_images(game);
	load_enemy_front_attack_images(game);
	load_enemy_back_attack_images(game);
	load_enemy_left_attack_images(game);
}
