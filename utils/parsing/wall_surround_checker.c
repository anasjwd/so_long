#include "../../includes/so_long.h"

int	check_walls(char **map, int len)
{
	int	i;
	int	line_len;

	i = 0;
	line_len = ft_strlen(map[0]);
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (-1);
		i++;
	}
	i = 1;
	while (i < len - 1)
	{
		if (map[i][0] != '1' || map[i][line_len - 1] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (map[len - 1][i])
	{
		if (map[len - 1][i] != '1')
			return (-1);
		i++;
	}
	return (1);
}
