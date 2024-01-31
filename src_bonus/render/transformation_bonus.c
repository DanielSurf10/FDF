/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:07:50 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/31 16:57:46 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	scale(t_fdf *fdf_data, t_point *point)
{
	point->x *= fdf_data->camera.scale_width * fdf_data->camera.scale;
	point->y *= fdf_data->camera.scale_height * fdf_data->camera.scale;
	point->z *= fdf_data->camera.z_factor * fdf_data->camera.scale;
}

void	rotate_x(t_fdf *fdf_data, t_point *point)
{
	float	angle;
	t_point	old_point;

	old_point = *point;
	angle = fdf_data->camera.x_angle * (PI / 180.0);
	point->y = (old_point.y * cos(angle)) - (old_point.z * sin(angle));
	point->z = (old_point.y * sin(angle)) + (old_point.z * cos(angle));
}

void	rotate_y(t_fdf *fdf_data, t_point *point)
{
	float	angle;
	t_point	old_point;

	old_point = *point;
	angle = fdf_data->camera.y_angle * (PI / 180.0);
	point->x = (old_point.x * cos(angle)) + (old_point.z * sin(angle));
	point->z = (-old_point.x * sin(angle)) + (old_point.z * cos(angle));
}

void	rotate_z(t_fdf *fdf_data, t_point *point)
{
	float	angle;
	t_point	old_point;

	old_point = *point;
	angle = fdf_data->camera.z_angle * (PI / 180.0);
	point->x = (old_point.x * cos(angle)) - (old_point.y * sin(angle));
	point->y = (old_point.x * sin(angle)) + (old_point.y * cos(angle));
}

void	move(t_fdf *fdf_data, t_point *point)
{
	point->x += fdf_data->camera.x_offset;
	point->y += fdf_data->camera.y_offset;
}
