#include "../../includes/so_long.h"

int	check_if_rectangle(char **map)
{
	int	firstline_len;
	int	i;

	firstline_len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != (unsigned int)firstline_len)
			return (-1);
		i++;
	}
	return (1);
}
