/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:29:35 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/15 19:18:21 by danbarbo         ###   ########.fr       */
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
	return (map->map[x + y * map->height]);
}

void	set_node_map(t_map *map, t_point point, int x, int y)
{
	map->map[x + y * map->height] = point;
}
