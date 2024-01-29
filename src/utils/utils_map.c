/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:02:34 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/27 21:41:39 by danbarbo         ###   ########.fr       */
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

int	get_max_z_value(t_map map)
{
	int	i;
	int	max_value;
	int	map_size;

	i = 0;
	map_size = map.height * map.width;
	max_value = map.map[0].z;
	while (i < map_size)
	{
		if (max_value < map.map[i].z)
			max_value = map.map[i].z;
		i++;
	}
	return (max_value);
}
