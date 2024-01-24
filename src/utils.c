/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:29:35 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/24 13:05:45 by danbarbo         ###   ########.fr       */
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

int	ternary(int condition, int if_true, int if_false)
{
	if (condition)
		return (if_true);
	return (if_false);
}

void	put_pixel(mlx_image_t *img, t_point point)
{
	if (point.x >= 0 && point.x < WIDTH && point.y >= 0 && point.y < HEIGHT)
		mlx_put_pixel(img, point.x, point.y, point.color.color_int);
}
