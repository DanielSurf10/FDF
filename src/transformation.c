/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:07:50 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/21 20:15:35 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale(t_fdf *fdf_data, t_line *line)
{
	line->point_1.x *= fdf_data->camera.scale_width;
	line->point_1.y *= fdf_data->camera.scale_height;
	line->point_2.x *= fdf_data->camera.scale_width;
	line->point_2.y *= fdf_data->camera.scale_height;
}

void	rotate_x(t_fdf *fdf_data, t_line *line)
{
	float	angle;

	angle = fdf_data->camera.x_angle * (PI / 180.0);
	line->point_1.y = (line->point_1.y * cos(angle)) - (line->point_1.z * sin(angle));
	line->point_1.z = (line->point_1.y * sin(angle)) - (line->point_1.z * cos(angle));
	line->point_2.y = (line->point_2.y * cos(angle)) - (line->point_2.z * sin(angle));
	line->point_2.z = (line->point_2.y * sin(angle)) - (line->point_2.z * cos(angle));
}

void	rotate_y(t_fdf *fdf_data, t_line *line)
{
	float	angle;

	angle = fdf_data->camera.y_angle * (PI / 180.0);
	line->point_1.x = (line->point_1.x * cos(angle)) + (line->point_1.z * sin(angle));
	line->point_1.z = (-line->point_1.x * sin(angle)) + (line->point_1.z * cos(angle));
	line->point_2.x = (line->point_2.x * cos(angle)) + (line->point_2.z * sin(angle));
	line->point_2.z = (-line->point_2.x * sin(angle)) + (line->point_2.z * cos(angle));
}

void	rotate_z(t_fdf *fdf_data, t_line *line)
{
	float	angle;

	angle = fdf_data->camera.z_angle * (PI / 180.0);
	line->point_1.x = (line->point_1.x * cos(angle)) - (line->point_1.y * sin(angle));
	line->point_1.y = (line->point_1.x * sin(angle)) + (line->point_1.y * cos(angle));
	line->point_2.x = (line->point_2.x * cos(angle)) - (line->point_2.y * sin(angle));
	line->point_2.y = (line->point_2.x * sin(angle)) + (line->point_2.y * cos(angle));
}

void	transform_line(t_fdf *fdf_data, t_line *line)
{
	rotate_x(fdf_data, line);
	rotate_y(fdf_data, line);
	rotate_z(fdf_data, line);
	// move(fdf_data, line);
}
