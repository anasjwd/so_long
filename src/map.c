#include "../include/so_long.h"

char	*initialize_pointer(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (perror("Fatal"), exit(EXIT_FAILURE), NULL);
	str[0] = '\0';
	return (str);
}

void	get_map(t_game *game)
{
	char	*line;
	char	*ptr;
	char	*tmp;
	int		row;

	ptr = initialize_pointer();
	line = get_next_line(game->mapfd);
	while (line)
	{
		game->map_height++;
		tmp = ptr;
		ptr = ft_strjoin(ptr, line);
		if (!ptr)
			return (perror("Fatal"), exit(EXIT_FAILURE));
		free(tmp);
		free(line);
		line = get_next_line(game->mapfd);
	}
	game->map = ft_split(ptr, '\n');
	free(ptr);
	if (!game->map)
		return (perror("Fatal"), exit(EXIT_FAILURE));
	game->map_width = ft_strlen(game->map[0]);
	row = 1;
	while (game->map[row])
		if (game->map_width != ft_strlen(game->map[row++]))
			return (dbl_free(game->map),
				ft_putstr_fd("Error: map should be rectangular.\n", 2),
				exit(EXIT_FAILURE));
}

void	get_map_copy(t_game *game)
{
	int	i;

	i = 0;
	game->map_copy = malloc(sizeof(char *) * (game->map_height + 1));
	game->map_copy[game->map_height] = NULL;
	while (game->map[i])
	{
		game->map_copy[i] = ft_strdup(game->map[i]);
		if (!game->map_copy[i])
			return (dbl_free(game->map), dbl_free(game->map_copy));
		i++;
	}
}

void	get_element_cord(char **map, int *cord, char element)
{
	int y;
	int x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == element)
			{
				cord[0] = y;
				cord[1] = x;
				return ;
			}
			x++;
		}
		y++;
	}
}