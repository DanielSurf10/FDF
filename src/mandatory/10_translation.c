/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_translation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:57:58 by cogata            #+#    #+#             */
/*   Updated: 2023/11/16 13:57:59 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	translate(t_coordinate *point_1, t_coordinate *point_2, t_map *map)
{
	point_1->x += map->position.x_offset;
	point_1->y += map->position.y_offset;
	point_2->y += map->position.y_offset;
	point_2->x += map->position.x_offset;
}
