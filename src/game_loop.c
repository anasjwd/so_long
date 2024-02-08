#include "../include/so_long.h"
#define ANIMATION_LENGTH 5

void	render_player(t_game *game)
{
	game->player.mvmnt_direction(game);
	if (game->player.p_last_pos[1] * 50
		+ game->player.x == game->player.p_current_pos[1] * 50
		&& game->player.p_last_pos[0] * 50
		+ game->player.y == game->player.p_current_pos[0] * 50)
	{
		game->player.animation_end = 1;
		game->player.dx = 0;
		game->player.dy = 0;
		game->player.x = 0;
		game->player.y = 0;
	}
}

void	process_input_update_render(t_game *game)
{
	if (0 == game->player.animation_end)
	{
		if (game->player.animation_delay == 0
			|| game->player.animation_delay == 1000)
		{
			game->player.x += game->player.dx;
			game->player.y += game->player.dy;
			game->player.animation_delay = 0;
			game->player.animation_frame_index = (++game->player.animation_frame_index)
				% ANIMATION_LENGTH;
			render_player(game);
		}
		game->player.animation_delay++;
	}
}

int	update_game_state(t_game *game)
{
	if (1 == game->player_isdead)
		game->enemy.attack_direction(game);
	else if (0 == game->player.animation_end) // 1 == game->player.ismoving ||
		process_input_update_render(game);
	else if (0 == game->player.ismoving && 1 == game->player.animation_end)
		player_standing(game);
	if (0 == game->player_isdead)
		enemy_standing(game);
	return (0);
}