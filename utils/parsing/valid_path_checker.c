#include "../../includes/so_long.h"

void	flood_fill(char **map, int x, int y, char f)
{
	if (map[x][y] == '1' || map[x][y] == f)
		return ;
	map[x][y] = 'f';
	flood_fill(map, x + 1, y, 'f');
	flood_fill(map, x - 1, y, 'f');
	flood_fill(map, x, y - 1, 'f');
	flood_fill(map, x, y + 1, 'f');
}

void	get_cord(char **map, int *cord)
{
	int x;
	int y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
			{
				cord[0] = x;
				cord[1] = y;
			}
			y++;
		}
		x++;
	}
}

int	path_checker(char **map)
{	
	int	i;
	int	j;
	int len;

	i = 0;
	len = map_lines(map);
	while (map[i++] && i < len - 1)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				return (-1);
			j++;
		}
	}
	return (1);
}

int	check_for_path(char **map)
{
	int	cord[2];

	get_cord(map, cord);
	flood_fill(map, cord[0], cord[1], 'f');
	if (-1 == path_checker(map))
		return (-1);
	return (1);
}
