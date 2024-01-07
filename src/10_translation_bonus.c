/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_translation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:39:42 by cogata            #+#    #+#             */
/*   Updated: 2024/01/07 15:15:59 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	get_translation(t_map *map, int *x, int *y)
// {
//
// 	if (WIDTH % 2 != 0)
// 		*x += map->position.x_offset * 1.05;
// 	if (HEIGHT % 2 == 0)
// 		*y = 0.5;
// }

void	translate(t_coordinate *point_1, t_coordinate *point_2, t_map *map)
{
	// int	x_offset;
	// int y_offset;

	// get_translation(map, &x_offset, &y_offset);
	point_1->x += map->position.x_offset;
	point_1->y += map->position.y_offset;
	point_2->x += map->position.x_offset;
	point_2->y += map->position.y_offset;
}
