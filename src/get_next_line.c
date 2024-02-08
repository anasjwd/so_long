#include "../include/get_next_line.h"

char	*ft_return(char *buffer, char *read_buff, char **array)
{
	if (ft_strlen(buffer))
		return (free(read_buff), buffer);
	else if (*array != NULL)
		return (free(*array), *array = NULL, free(read_buff), free(buffer),
			NULL);
	else
		return (free(read_buff), free(buffer), NULL);
}

char	*ft_get_line(int fd, char *buffer, char **array, char *read_buff)
{
	ssize_t	read_byte;

	if (*array != NULL && ft_strlen(*array) > 0)
	{
		buffer = gnl_strjoin(buffer, *array);
		if (ft_check_newline(buffer))
		{
			*array = ft_get_remaining(*array, 1);
			return (free(read_buff), buffer);
		}
		free(*array);
		*array = NULL;
	}
	while (1)
	{
		read_byte = read(fd, read_buff, BUFFER_SIZE);
		if (read_byte <= 0)
			return (ft_return(buffer, read_buff, array));
		read_buff[read_byte] = '\0';
		buffer = gnl_strjoin(buffer, read_buff);
		if (ft_check_newline(read_buff) == 1)
			return (*array = ft_get_remaining(read_buff, 0), free(read_buff),
				buffer);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*array;
	char		*buffer;
	char		*read_buff;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((size_t)BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	read_buff = malloc((size_t)BUFFER_SIZE + 1 * sizeof(char));
	if (!read_buff)
		return (NULL);
	buffer = ft_get_line(fd, buffer, &array, read_buff);
	return (buffer);
}
