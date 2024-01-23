/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:07:50 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/23 15:13:43 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale(t_fdf *fdf_data, t_point *point)
{
	point->x *= fdf_data->camera.scale_width * 0.9;
	point->y *= fdf_data->camera.scale_height * 0.9;
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
	point->x += WIDTH / 2;
	point->y += HEIGHT / 2;
}

void	transform_line(t_fdf *fdf_data, t_line *line)
{
	scale(fdf_data, &(line->point_1));
	scale(fdf_data, &(line->point_2));
	rotate_z(fdf_data, &(line->point_1));
	rotate_z(fdf_data, &(line->point_2));
	rotate_x(fdf_data, &(line->point_1));
	rotate_x(fdf_data, &(line->point_2));
	rotate_y(fdf_data, &(line->point_1));
	rotate_y(fdf_data, &(line->point_2));
	move(fdf_data, &(line->point_1));
	move(fdf_data, &(line->point_2));
}

void	transform_point(t_fdf *fdf_data, t_point *point)
{
	scale(fdf_data, point);
	rotate_x(fdf_data, point);
	rotate_y(fdf_data, point);
	rotate_z(fdf_data, point);
	move(fdf_data, point);
}
