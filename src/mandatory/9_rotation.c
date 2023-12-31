/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_rotation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:57:52 by cogata            #+#    #+#             */
/*   Updated: 2023/11/16 13:57:54 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	rotation_in_x(t_coordinate *point_1, t_coordinate *point_2, t_map *map)
{
	float			pi;
	float			angle;
	t_coordinate	aux_point_1;
	t_coordinate	aux_point_2;

	pi = M_PI;
	angle = map->position.x_angle * pi / 180;
	aux_point_1.y = point_1->y;
	aux_point_1.z = point_1->z;
	aux_point_2.y = point_2->y;
	aux_point_2.z = point_2->z;
	point_1->y = (aux_point_1.y * cos(angle)) - (aux_point_1.z * sin(angle));
	point_1->z = (aux_point_1.y * sin(angle)) + (aux_point_1.z * cos(angle));
	point_2->y = (aux_point_2.y * cos(angle)) - (aux_point_2.z * sin(angle));
	point_2->z = (aux_point_2.y * sin(angle)) + (aux_point_2.z * cos(angle));
}

void	rotation_in_y(t_coordinate *point_1, t_coordinate *point_2, t_map *map)
{
	float			pi;
	float			angle;
	t_coordinate	aux_point_1;
	t_coordinate	aux_point_2;

	pi = M_PI;
	angle = map->position.y_angle * pi / 180;
	aux_point_1.x = point_1->x;
	aux_point_1.z = point_1->z;
	aux_point_2.x = point_2->x;
	aux_point_2.z = point_2->z;
	point_1->x = (aux_point_1.x * cos(angle)) + (aux_point_1.z * sin(angle));
	point_1->z = (-aux_point_1.x * sin(angle)) + (aux_point_1.z * cos(angle));
	point_2->x = (aux_point_2.x * cos(angle)) + (aux_point_2.z * sin(angle));
	point_2->z = (-aux_point_2.x * sin(angle)) + (aux_point_2.z * cos(angle));
}

void	rotation_in_z(t_coordinate *point_1, t_coordinate *point_2, t_map *map)
{
	float			pi;
	float			angle;
	t_coordinate	aux_point_1;
	t_coordinate	aux_point_2;

	pi = M_PI;
	angle = map->position.z_angle * pi / 180;
	aux_point_1.x = point_1->x;
	aux_point_1.y = point_1->y;
	aux_point_2.x = point_2->x;
	aux_point_2.y = point_2->y;
	point_1->x = (aux_point_1.x * cos(angle)) - (aux_point_1.y * sin(angle));
	point_1->y = (aux_point_1.x * sin(angle)) + (aux_point_1.y * cos(angle));
	point_2->x = (aux_point_2.x * cos(angle)) - (aux_point_2.y * sin(angle));
	point_2->y = (aux_point_2.x * sin(angle)) + (aux_point_2.y * cos(angle));
}
