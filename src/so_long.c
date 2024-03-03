/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:30:00 by ajawad            #+#    #+#             */
/*   Updated: 2024/03/03 10:33:40 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_file_extension(char *file_name)
{
	int		idx;
	int		idx1;
	char	*extension;

	extension = ".ber";
	idx = ft_strlen(file_name);
	idx1 = ft_strlen(extension);
	if (idx <= idx1)
		return (0);
	while (idx > 0 && idx1 >= 0)
	{
		if (file_name[idx] != extension[idx1])
			return (0);
		idx--;
		idx1--;
	}
	return (1);
}

int	destroy_window(t_data *game_data)
{
	exit_game(game_data, EXIT_SUCCESS);
	return (0);
}

int	get_input_from_user(int keycode, t_data *game_data)
{
	game_data->pacman.player_starts_moving = 1;
	if (ESCAPE == keycode)
		exit_game(game_data, EXIT_SUCCESS);
	if (KEY_DOWN == keycode)
	{
		game_data->pacman.next_dx = 0;
		game_data->pacman.next_dy = 10;
	}
	else if (KEY_UP == keycode)
	{
		game_data->pacman.next_dx = 0;
		game_data->pacman.next_dy = -10;
	}
	else if (KEY_LEFT == keycode)
	{
		game_data->pacman.next_dx = -10;
		game_data->pacman.next_dy = 0;
	}
	else if (KEY_RIGHT == keycode)
	{
		game_data->pacman.next_dx = 10;
		game_data->pacman.next_dy = 0;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	game_data;

	if (ac != 2)
		return (ft_putstr_fd("Error: no map to begin with\n", 2), EXIT_FAILURE);
	if (0 == check_file_extension(av[1]))
		return (ft_putstr_fd("Error: map file's extension should be .ber\n", \
					2), EXIT_FAILURE);
	ft_memset(&game_data, 0, sizeof(game_data));
	game_data.pacman.animation_end = 1;
	game_data.pacman.animation_frame_index = -1;
	game_data.map_fd = open(av[1], O_RDONLY);
	if (-1 == game_data.map_fd)
		return (perror("open"), EXIT_FAILURE);
	initialize_game(&game_data);
	mlx_hook(game_data.win, 17, 0, destroy_window, &game_data);
	mlx_hook(game_data.win, 3, 3, get_input_from_user, &game_data);
	mlx_loop_hook(game_data.mlx, game_loop, &game_data);
	mlx_loop(game_data.mlx);
	return (0);
}
