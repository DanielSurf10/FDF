/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:07:50 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/22 22:55:29 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale(t_fdf *fdf_data, t_line *line)
{
	line->point_1.x *= fdf_data->camera.scale_width * 0.9;
	line->point_1.y *= fdf_data->camera.scale_height * 0.9;
	line->point_2.x *= fdf_data->camera.scale_width * 0.9;
	line->point_2.y *= fdf_data->camera.scale_height * 0.9;
	// line->point_1.x *= 100;
	// line->point_1.y *= 100;
	// line->point_2.x *= 100;
	// line->point_2.y *= 100;
}

void	rotate_x(t_fdf *fdf_data, t_line *line)
{
	float	angle;
	t_line	old_line;

	old_line = *line;
	angle = fdf_data->camera.x_angle * (PI / 180.0);
	line->point_1.y = (old_line.point_1.y * cos(angle)) - (old_line.point_1.z * sin(angle));
	line->point_1.z = (old_line.point_1.y * sin(angle)) + (old_line.point_1.z * cos(angle));
	line->point_2.y = (old_line.point_2.y * cos(angle)) - (old_line.point_2.z * sin(angle));
	line->point_2.z = (old_line.point_2.y * sin(angle)) + (old_line.point_2.z * cos(angle));
}

void	rotate_y(t_fdf *fdf_data, t_line *line)
{
	float	angle;
	t_line	old_line;

	old_line = *line;
	angle = fdf_data->camera.y_angle * (PI / 180.0);
	line->point_1.x = (old_line.point_1.x * cos(angle)) + (old_line.point_1.z * sin(angle));
	line->point_1.z = (-old_line.point_1.x * sin(angle)) + (old_line.point_1.z * cos(angle));
	line->point_2.x = (old_line.point_2.x * cos(angle)) + (old_line.point_2.z * sin(angle));
	line->point_2.z = (-old_line.point_2.x * sin(angle)) + (old_line.point_2.z * cos(angle));
}

void	rotate_z(t_fdf *fdf_data, t_line *line)
{
	float	angle;
	t_line	old_line;

	old_line = *line;
	angle = fdf_data->camera.z_angle * (PI / 180.0);
	line->point_1.x = (old_line.point_1.x * cos(angle)) - (old_line.point_1.y * sin(angle));
	line->point_1.y = (old_line.point_1.x * sin(angle)) + (old_line.point_1.y * cos(angle));
	line->point_2.x = (old_line.point_2.x * cos(angle)) - (old_line.point_2.y * sin(angle));
	line->point_2.y = (old_line.point_2.x * sin(angle)) + (old_line.point_2.y * cos(angle));
}

void	move(t_fdf *fdf_data, t_line *line)
{
	line->point_1.x += WIDTH / 2;
	line->point_1.y += HEIGHT / 2;
	line->point_2.x += WIDTH / 2;
	line->point_2.y += HEIGHT / 2;
}

void	transform_line(t_fdf *fdf_data, t_line *line)
{
	scale(fdf_data, line);
	rotate_z(fdf_data, line);
	rotate_x(fdf_data, line);
	rotate_y(fdf_data, line);
	move(fdf_data, line);
}
