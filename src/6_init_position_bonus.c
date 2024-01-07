/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_init_position_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:39:16 by cogata            #+#    #+#             */
/*   Updated: 2024/01/07 18:14:16 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_initial_scale(t_map *map)
{
	float	w_scale;
	float	h_scale;

	// map->position.scale = 1;
	w_scale = (float)WIDTH / map->width;
	h_scale = (float)HEIGHT / map->height;
	map->position.scale = h_scale;
	if (h_scale > w_scale)
		map->position.scale = w_scale;
	map->position.scale *= 0.6;
}

void	centralize(t_map *map)
{
	uint32_t	w;
	uint32_t	h;

	h = 0;
	while (h < map->height)
	{
		w = 0;
		while (w < map->width)
		{
			map->matrix[h][w].x -= map->width / 2;
			map->matrix[h][w].y -= map->height / 2;
			w++;
		}
		h++;
	}
}

void	find_z_factor(t_map *map)
{
	uint32_t	w;
	uint32_t	h;
	int			max_z;
	int			min_z;

	max_z = 0;
	min_z = 0;
	h = 0;
	while (h < map->height)
	{
		w = 0;
		while (w < map->width)
		{
			if (map->matrix[h][w].z > max_z)
				max_z = map->matrix[h][w].z;
			else if (map->matrix[h][w].z < min_z)
				min_z = map->matrix[h][w].z;
			w++;
		}
		h++;
	}
	if (max_z - min_z > 10 * (int)map->height)
		map->position.z_factor = 0.05;
	else if (max_z - min_z >= (int)map->height)
		map->position.z_factor = 0.1;
}

void	init_position(t_map *map)
{
	double	x_offset;
	double	y_offset;

	centralize(map);
	find_initial_scale(map);
	map->position.z_factor = 0.5;
	find_z_factor(map);
	// if (map->width % 2 != 0)
	// 	x_offset = WIDTH / 2;
	// else
	// 	x_offset = (((WIDTH + (WIDTH / map->width)) / 2.0));
	// if (map->height % 2 != 0)
	// 	y_offset = HEIGHT / 2;
	// else
	// 	y_offset = (((HEIGHT + (HEIGHT / map->height)) / 2.0));
	// map->position.x_offset = x_offset;
	// map->position.y_offset = y_offset;
	map->position.x_offset = WIDTH / 2;
	map->position.y_offset = HEIGHT / 2;
	map->position.projection = '1';
}
