/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:58:45 by ajawad            #+#    #+#             */
/*   Updated: 2024/03/03 11:58:46 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**get_map_copy(char **map, int height)
{
	int		idx_i;
	char	**map_copy;

	map_copy = malloc(sizeof(char *) * (height + 1));
	idx_i = 0;
	while (map[idx_i])
	{
		map_copy[idx_i] = ft_strdup(map[idx_i]);
		if (NULL == map_copy[idx_i])
			return (NULL);
		idx_i++;
	}
	map_copy[idx_i] = NULL;
	return (map_copy);
}

static char	*initialize_pointer(void)
{
	char	*str;

	str = malloc(1);
	if (NULL == str)
		return (perror("Fatal"), exit(1), NULL);
	str[0] = '\0';
	return (str);
}

char	**get_map(int map_fd)
{
	char	*ptr;
	char	*line;
	char	*tmp;
	char	**map;

	ptr = initialize_pointer();
	line = get_next_line(map_fd);
	while (line != NULL)
	{
		if (line[0] == '\n')
			return (ft_putstr_fd("Error: map with empty line in invalid\n", 2),
				exit(1), NULL);
		tmp = ptr;
		ptr = ft_strjoin(ptr, line);
		free(tmp);
		free(line);
		if (NULL == ptr)
			return (perror("Fatal"), exit(1), NULL);
		line = get_next_line(map_fd);
	}
	map = ft_split(ptr, '\n');
	if (NULL == map)
		return (free(ptr), perror("Fatal"), exit(1), NULL);
	return (free(ptr), map);
}
