#include "../../includes/so_long.h"

int	check_elements(char **map, int len)
{
	int	i;
	int	j;
	int	start;
	int	exit;
	int	collectible;

	i = 0;
	start = 0;
	collectible = 0;
	exit = 0;
	while (map[i++] && i < len - 1)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				start += 1;
			else if (map[i][j] == 'C')
				collectible += 1;
			else if (map[i][j] == 'E')
				exit += 1;
			else if (map[i][j] != '1' && map[i][j] != '0')
				return (-1);
			j++;
		}
	}
	if (start != 1 || collectible < 1 || exit != 1)
		return (-1);
	return (1);
}
