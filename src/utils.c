/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:29:35 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/17 16:43:32 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *str)
{
	int	i;
	int	height;

	i = 0;
	height = 0;
	while (str && str[i])
	{
		if (str[i] == '\n' || (str[i] != '\n' && str[i + 1] == '\0'))
			height++;
		i++;
	}
	return (height);
}

int	get_width(char *str)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (str && str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\n'
				|| str[i + 1] == '\0'))
			width++;
		i++;
	}
	return (width);
}

t_point	get_node_map(t_map *map, int x, int y)
{
	return (map->map[x + y * map->width]);
}

void	set_node_map(t_map *map, t_point point, int x, int y)
{
	map->map[x + y * map->width] = point;
}

// char	*ft_read_all(int fd)
// {
// 	int		chars_readed;
// 	char	*temp_buffer;
// 	char	*file_string;
// 	char	*aux;
//
// 	chars_readed = 1;
// 	temp_buffer = (char *) malloc((BUFFER_SIZE + 1));
// 	file_string = ft_strdup("");
// 	while (chars_readed > 0)
// 	{
// 		chars_readed = read(fd, temp_buffer, BUFFER_SIZE);
// 		temp_buffer[chars_readed] = '\0';
// 		aux = file_string;
// 		file_string = ft_strjoin(file_string, temp_buffer);
// 		free(aux);
// 	}
// 	free(temp_buffer);
// 	return (file_string);
// }
