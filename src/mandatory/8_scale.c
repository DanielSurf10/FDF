/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_scale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:57:46 by cogata            #+#    #+#             */
/*   Updated: 2023/11/16 13:57:49 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	scale(t_coordinate *point_1, t_coordinate *point_2, t_map *map)
{
	point_1->x *= map->position.scale;
	point_1->y *= map->position.scale;
	point_1->z *= map->position.scale * map->position.z_factor;
	point_2->x *= map->position.scale;
	point_2->y *= map->position.scale;
	point_2->z *= map->position.scale * map->position.z_factor;
}
