/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:12:11 by cogata            #+#    #+#             */
/*   Updated: 2023/12/23 16:15:20 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_len(char *next_line)
{
	int	i;

	i = 0;
	if (next_line == NULL || next_line == 0)
		return (0);
	else
	{
		while (next_line[i] != '\0')
		{
			if (next_line[i] == '\n')
				return (i);
			i++;
		}
		return (i);
	}
}

static char	*ft_get_line(char *next_line)
{
	int		i;
	char	*line;
	int		len_line;

	len_line = ft_count_len(next_line);
	line = ft_calloc((len_line + 2), 1);
	i = 0;
	while (next_line[i] != '\0' && next_line[i] != '\n')
	{
		line[i] = next_line[i];
		i++;
	}
	if (next_line[i] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else
		line[i] = '\0';
	return (line);
}

static char	*ft_get_next_line(char *next_line)
{
	int		i;
	int		j;
	int		len;
	char	*new_line;

	i = 0;
	while (next_line[i] != '\n' && next_line[i] != '\0')
		i++;
	if (next_line[i] == '\0')
	{
		free(next_line);
		return (NULL);
	}
	i++;
	j = i;
	while (next_line[i] != '\0')
		i++;
	len = i - j + 1;
	new_line = ft_calloc(len, 1);
	if (new_line == NULL)
		return (NULL);
	i = 0;
	while (i < len)
		new_line[i++] = next_line[j++];
	return (new_line);
}

static char	*ft_read_file(char *buffer, char *next_line, int fd)
{
	char	*temp;
	int		bytes_read;

	bytes_read = 1;
	while (ft_strchr(buffer, '\n') == 0 && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if ((!*next_line && !*buffer && bytes_read == 0) || bytes_read < 0)
		{
			free(next_line);
			next_line = NULL;
			free(buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = next_line;
		next_line = ft_strjoin(temp, buffer);
		free(temp);
	}
	return (next_line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*next_line;
	char		*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(next_line);
		next_line = NULL;
		return (NULL);
	}
	if (next_line == 0)
		next_line = ft_strdup("");
	buffer = ft_calloc((BUFFER_SIZE + 1), 1);
	if (buffer == NULL)
		return (NULL);
	next_line = ft_read_file(buffer, next_line, fd);
	if (next_line == NULL)
		return (NULL);
	line = ft_get_line(next_line);
	temp = next_line;
	next_line = ft_get_next_line(temp);
	if (next_line != NULL)
		free(temp);
	return (free(buffer), line);
}
