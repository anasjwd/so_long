#include "../include/so_long.h"

void    check_num_of_collectables(t_game *game)
{
    int cord[2];

    if (game->collected == game->num_of_collectibles)
    {
        get_element_cord(game->map, cord, 'E');
        mlx_put_image_to_window(game->mlx, game->win, game->ground.img, cord[1] * 50, cord[0] * 50);
        mlx_put_image_to_window(game->mlx, game->win, game->exit[1].img, cord[1] * 50, cord[0] * 50);
    }
}

void	change_position_in_map(t_game *game)
{
	int	x;
	int	y;

	x = game->player.dx / 10;
	y = game->player.dy / 10;
	get_element_cord(game->map, game->player.p_last_pos, 'P');
	if (game->map[game->player.p_last_pos[0] + y][game->player.p_last_pos[1]
		+ x] == 'N')
	{
		enemy_attack_direction(game, x, y);
		return ;
	}
	if (game->map[game->player.p_last_pos[0] + y][game->player.p_last_pos[1]
		+ x] != '1' && game->map[game->player.p_last_pos[0]
		+ y][game->player.p_last_pos[1] + x] != 'E')
	{
        if (game->map[game->player.p_last_pos[0]
		+ y][game->player.p_last_pos[1] + x] == 'C')
        {
            game->collected++;
		    check_num_of_collectables(game);
        }
		game->map[game->player.p_last_pos[0]][game->player.p_last_pos[1]] = '0';
		game->map[game->player.p_last_pos[0] + y][game->player.p_last_pos[1]
			+ x] = 'P';
		game->player.animation_end = 0;
	}
    else if (game->map[game->player.p_last_pos[0] + y][game->player.p_last_pos[1]
    + x] == 'E' && game->collected == game->num_of_collectibles)
    {
        destroy_window(game);
    }
	else
		game->player.ismoving = 0;
	get_element_cord(game->map, game->player.p_current_pos, 'P');
}

void	player_standing(t_game *game)
{
	static int	i;
	static int	j;

	get_element_cord(game->map, game->player.p_current_pos, 'P');
	if (i % 1000 == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->ground.img,
			game->player.p_current_pos[1] * 50, game->player.p_current_pos[0]
			* 50);
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.player[j].img, game->player.p_current_pos[1] * 50,
			game->player.p_current_pos[0] * 50);
		j++;
	}
	i++;
	if (i == 6000)
	{
		i = 0;
		j = 0;
	}
}

void	move_up_down_right(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->ground.img,
		game->player.p_last_pos[1] * 50, game->player.p_last_pos[0] * 50);
	mlx_put_image_to_window(game->mlx, game->win, game->ground.img,
		game->player.p_current_pos[1] * 50, game->player.p_current_pos[0] * 50);
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.player_mv_right[game->player.animation_frame_index].img,
		(game->player.p_last_pos[1]) * 50 + game->player.x,
		(game->player.p_last_pos[0]) * 50 + game->player.y);
}

void	move_left(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->ground.img,
		game->player.p_last_pos[1] * 50, game->player.p_last_pos[0] * 50);
	mlx_put_image_to_window(game->mlx, game->win, game->ground.img,
		game->player.p_current_pos[1] * 50, game->player.p_current_pos[0] * 50);
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.player_mv_left[game->player.animation_frame_index].img,
		(game->player.p_last_pos[1]) * 50 + game->player.x,
		(game->player.p_last_pos[0]) * 50 + game->player.y);
}

int	player_movements_keyup(int keycode, t_game *game)
{
	int	i;

	if (0 == game->player.animation_end)
		return (0);
	if (ESCAPE == keycode)
		destroy_window(game);
	if (KEY_DOWN == keycode)
	{
		game->player.dx = 0;
		game->player.dy = 10;
	}
	if (KEY_UP == keycode)
	{
		game->player.dx = 0;
		game->player.dy = -10;
	}
	if (KEY_LEFT == keycode)
	{
		game->player.dx = -10;
		game->player.dy = 0;
	}
	if (KEY_RIGHT == keycode)
	{
		game->player.dx = 10;
		game->player.dy = 0;
	}
	if ((game->player.dx != 0 || game->player.dy != 0)
		&& 1 == game->player.animation_end)
	{
		change_position_in_map(game);
		if (game->player.dy == 10 || game->player.dy == -10
			|| game->player.dx == 10)
			game->player.mvmnt_direction = &move_up_down_right;
		else if (game->player.dx == -10)
			game->player.mvmnt_direction = &move_left;
	}
	/*FOR DEBUGGING*/
	i = 0;
	while (game->map[i])
	{
		write(1, game->map[i], ft_strlen(game->map[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

// int player_movements_keyup(int keycode, t_game *game)
// {
//     (void)keycode;
//     game->player.ismoving = 0;
//     return (0);
// }
