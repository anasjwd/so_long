#include "../../includes/so_long.h"

int	map_lines(char **map)
{
	int	line;

	line = 0;
	while (map[line])
		line++;
	return (line);
}

void	parsing_error()
{
	ft_putstr_fd("Oops! It seems like the map you provided for our 2D game is \
not in the correct format.\n", 2);
	exit(EXIT_FAILURE);
}

void	dbl_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

int	check_map(char **map, int len)
{
	if (-1 == check_if_rectangle(map) || -1 == check_walls(map, len))
	{
		dbl_free(map);
		return (-1);
	}
	if (-1 == check_elements(map, len) || -1 == check_for_path(map))
	{
		dbl_free(map);
		return (-1);
	}
	dbl_free(map);
	return (1);
}

char	**get_map_copy(char **map)
{
	char	**map_copy;
	int	i;
	int	map_line;

	i = 0;
	map_line = map_lines(map);
	map_copy = malloc(sizeof(char *) * (map_line + 1));
	map_copy[map_line] = NULL;
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	return (map_copy);
}

char	**parsing_map(int mapfd)
{
	char	*ptr;
	char	*line;
	char	**map;
	char	*tmp;

	ptr = malloc(sizeof(char) * 1);
	ptr[0] = '\0';
	line = get_next_line(mapfd);
	while (line)
	{
		tmp = ptr;
		ptr = ft_strjoin(ptr, line);
		free(tmp);
		free(line);
		line = get_next_line(mapfd);	
	}
	map = ft_split(ptr, '\n');
	free(ptr);
	if (!map)
			return (perror("Fatal"), exit(EXIT_FAILURE),NULL);
	if (-1 == check_map(get_map_copy(map), map_lines(map)))
	{
		dbl_free(map);
		exit(EXIT_FAILURE);
	}
	return (map);
}

/*int	main(int ac, char **av)
{
	int mapfd;
	char **map;

	(void)ac;
	mapfd = open(av[1], O_RDONLY);
	if (mapfd == -1)
	{
		perror("open");
		exit(errno);
	}
	map = parsing_map(mapfd);
	if (NULL == map)
		printf("dakshi mashi howa hadak\n");
	else
		printf("dakshi howa hadak\n");
	close(mapfd);
	dbl_free(map);
	return (0);
}*/
