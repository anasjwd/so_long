#include "../include/so_long.h"

void	get_next_enemy_pos(t_game *game, int *cord)
{
	static int	i;
	static int	j;

	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N')
			{
				cord[0] = i;
				cord[1] = j++;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	cord[0] = -1;
	cord[1] = -1;
	i = 0;
	j = 0;
}

void	enemy_standing(t_game *game)
{
	static int	i;
	int			cord[2];

	if (i % 1000 == 0)
	{
		get_next_enemy_pos(game, cord);
		while (cord[0] != -1 && cord[1] != -1)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->ground.img,
				cord[1] * 50, cord[0] * 50);
			mlx_put_image_to_window(game->mlx, game->win,
				game->enemy.standing[game->enemy.standing_animation_frame].img,
				cord[1] * 50, cord[0] * 50);
			get_next_enemy_pos(game, cord);
		}
		game->enemy.standing_animation_frame++;
	}
	i++;
	if (i == 5000)
	{
		i = 0;
		game->enemy.standing_animation_frame = 0;
	}
}

void	right_attack(t_game *game)
{
	static int	counter;

	if (counter % 1000 == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->ground.img,
			game->enemy.enemy_attacking_pos[1] * 50,
			game->enemy.enemy_attacking_pos[0] * 50);
		mlx_put_image_to_window(game->mlx, game->win,
			game->enemy.right_attack[game->enemy.attack_animation_frame].img,
			game->enemy.enemy_attacking_pos[1] * 50,
			game->enemy.enemy_attacking_pos[0] * 50);
		game->enemy.attack_animation_frame++;
	}
	counter++;
	if (counter == 5000)
		destroy_window(game);
}

void	front_attack(t_game *game)
{
	static int	counter;

	if (counter % 1000 == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->ground.img,
			game->enemy.enemy_attacking_pos[1] * 50,
			game->enemy.enemy_attacking_pos[0] * 50);
		mlx_put_image_to_window(game->mlx, game->win,
			game->enemy.front_attack[game->enemy.attack_animation_frame].img,
			game->enemy.enemy_attacking_pos[1] * 50,
			game->enemy.enemy_attacking_pos[0] * 50);
		game->enemy.attack_animation_frame++;
	}
	counter++;
	if (counter == 5000)
		destroy_window(game);
}

void	back_attack(t_game *game)
{
	static int	counter;

	if (counter % 1000 == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->ground.img,
			game->enemy.enemy_attacking_pos[1] * 50,
			game->enemy.enemy_attacking_pos[0] * 50);
		mlx_put_image_to_window(game->mlx, game->win,
			game->enemy.back_attack[game->enemy.attack_animation_frame].img,
			game->enemy.enemy_attacking_pos[1] * 50,
			game->enemy.enemy_attacking_pos[0] * 50);
		game->enemy.attack_animation_frame++;
	}
	counter++;
	if (counter == 5000)
		destroy_window(game);
}

void	left_attack(t_game *game)
{
	static int	counter;

	if (counter % 1000 == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->ground.img,
			game->enemy.enemy_attacking_pos[1] * 50,
			game->enemy.enemy_attacking_pos[0] * 50);
		mlx_put_image_to_window(game->mlx, game->win,
			game->enemy.left_attack[game->enemy.attack_animation_frame].img,
			game->enemy.enemy_attacking_pos[1] * 50,
			game->enemy.enemy_attacking_pos[0] * 50);
		game->enemy.attack_animation_frame++;
	}
	counter++;
	if (counter == 5000)
		destroy_window(game);
}

void	enemy_attack_direction(t_game *game, int x, int y)
{
	game->enemy.enemy_attacking_pos[0] = game->player.p_last_pos[0] + y;
	game->enemy.enemy_attacking_pos[1] = game->player.p_last_pos[1] + x;
	game->player_isdead = 1;
	if (game->player.p_last_pos[0] > game->enemy.enemy_attacking_pos[0])
		game->enemy.attack_direction = &front_attack;
	else if (game->player.p_last_pos[0] < game->enemy.enemy_attacking_pos[0])
		game->enemy.attack_direction = &back_attack;
	else if (game->player.p_last_pos[1] < game->enemy.enemy_attacking_pos[1])
		game->enemy.attack_direction = &left_attack;
	else if (game->player.p_last_pos[1] > game->enemy.enemy_attacking_pos[1])
		game->enemy.attack_direction = &right_attack;
}
