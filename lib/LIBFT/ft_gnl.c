/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:52:47 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/06/10 19:07:50 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char		*line_to_return;
	char		*full_line;
	static char	*line_backup;

	if (!line_backup)
		line_backup = ft_strdup("");
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(line_backup);
		line_backup = NULL;
		return (NULL);
	}
	full_line = ft_read(line_backup, fd);
	line_to_return = ft_build_line_to_return(full_line);
	line_backup = get_line_after_bslash_n(full_line);
	free(full_line);
	if (*line_to_return == '\0' && *line_backup == '\0')
	{
		free(line_to_return);
		free(line_backup);
		line_backup = NULL;
		line_to_return = NULL;
		return (NULL);
	}
	return (line_to_return);
}

char	*ft_read(char *joined, int fd)
{
	char	*buffer;
	char	*old_joined;
	int		read_size;

	read_size = 1;
	old_joined = joined;
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (read_size > 0 && !ft_strchr(joined, '\n'))
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		buffer[read_size] = '\0';
		joined = ft_strjoin(joined, buffer);
	}
	if (old_joined != joined)
		free(old_joined);
	free(buffer);
	return (joined);
}

char	*ft_build_line_to_return(char *line)
{
	int		line_len;
	char	*line_to_return;

	if (ft_strchr(line, '\n'))
		line_len = ft_strchr(line, '\n') - line + 1;
	else
		line_len = ft_strlen(line);
	line_to_return = (char *) malloc((line_len + 1) * sizeof(char));
	line_to_return[line_len--] = '\0';
	while (line_len >= 0)
	{
		line_to_return[line_len] = line[line_len];
		line_len--;
	}
	return (line_to_return);
}

char	*get_line_after_bslash_n(char *line)
{
	int		i;
	char	*new_line_begin;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n' && line[i + 1] != '\0')
	{
		i += 1;
		new_line_begin = ft_strdup(line + i);
	}
	else
		new_line_begin = ft_strdup("");
	return (new_line_begin);
}
