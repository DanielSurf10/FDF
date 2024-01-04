/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_scale_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:39:27 by cogata            #+#    #+#             */
/*   Updated: 2024/01/04 16:22:13 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale(t_coordinate *point_1, t_coordinate *point_2, t_map *map)
{
	point_1->x *= map->position.scale;
	point_1->y *= map->position.scale;
	point_1->z *= map->position.scale * map->position.z_factor;
	point_2->x *= map->position.scale;
	point_2->y *= map->position.scale;
	point_2->z *= map->position.scale * map->position.z_factor;
}
