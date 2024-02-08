#include "../include/get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

int	ft_check_newline(char *array)
{
	while (*array)
	{
		if (*array == '\n')
			return (1);
		array++;
	}
	return (0);
}

size_t	newline_idx(char *array)
{
	size_t	len;

	len = 0;
	while (array[len] != '\n' && array[len] != '\0')
		len++;
	if (array[len] == '\n')
		len++;
	return (len);
}

char	*ft_get_remaining(char *read_buff, int flag)
{
	size_t	new_line_len;
	size_t	len;
	int		idx;
	char	*array;

	new_line_len = newline_idx(read_buff);
	len = ft_strlen(read_buff);
	idx = 0;
	if (len - new_line_len == 0 && flag == 1)
		free(read_buff);
	if (len - new_line_len == 0)
	{
		return (NULL);
	}
	array = malloc((len - new_line_len) * sizeof(char) + 1);
	if (!array)
		return (NULL);
	while (read_buff[new_line_len])
		array[idx++] = read_buff[new_line_len++];
	array[idx] = '\0';
	if (flag == 1)
		free(read_buff);
	return (array);
}

char	*gnl_strjoin(char *buffer, char *array)
{
	char	*new_buffer;
	int		i;
	int		j;

	if (!buffer || !array)
		return (NULL);
	new_buffer = malloc(sizeof(char) * (ft_strlen(buffer) + newline_idx(array)
				+ 1));
	if (!new_buffer)
		return (NULL);
	i = 0;
	j = 0;
	while (buffer[i])
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	while (array[j] && array[j] != '\n')
		new_buffer[i++] = array[j++];
	if (array[j] == '\n')
		new_buffer[i++] = array[j++];
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}
