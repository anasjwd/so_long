/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:00:24 by ajawad            #+#    #+#             */
/*   Updated: 2024/03/03 12:00:28 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_num_of_movements(t_player *pacman, int *number_of_moves)
{
	if (pacman->dx != 0 || pacman->dy != 0)
	{
		*number_of_moves = *number_of_moves + 1;
		ft_putnbr_fd(*number_of_moves, 1);
		write(1, "\n", 1);
	}
}

unsigned int	random_number(void)
{
	static unsigned int	random_seed;

	random_seed = (RANDOM_A * random_seed + RONDOM_C) % RANDOM_MAX;
	return (random_seed);
}

void	get_element_coordinates(char **map, int *element_coordinates,
		char element)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == element)
			{
				element_coordinates[0] = y;
				element_coordinates[1] = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	num_of_element(char **map, char element)
{
	int	idx_i;
	int	idx_j;
	int	counter;

	idx_i = 0;
	counter = 0;
	while (map[idx_i])
	{
		idx_j = 0;
		while (map[idx_i][idx_j])
			if (element == map[idx_i][idx_j++])
				counter++;
		idx_i++;
	}
	return (counter);
}
