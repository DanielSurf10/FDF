/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:54:56 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/24 12:55:57 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham_algorithm(mlx_image_t *img, t_line line)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	error;
	int	e2;

	int	x0 = line.point_1.x;
	int	y0 = line.point_1.y;
	int	x1 = line.point_2.x;
	int	y1 = line.point_2.y;
	t_point	point_to_plot;
	t_point	delta;

	delta.x = abs(line.point_2.x - line.point_1.x);
	delta.y = abs(line.point_2.y - line.point_1.y);
	dx = abs(x1 - x0);
	dy = -abs(y1 - y0);
	sx = ternary(x0 < x1, 1, -1);
	sy = ternary(y0 < y1, 1, -1);
	error = dx + dy;
	while (1)
	{
		point_to_plot.x = x0;
		point_to_plot.y = y0;
		point_to_plot.color = get_color_gradient(point_to_plot, line.point_1, line.point_2, delta);
		point_to_plot.color.color_struct.a = -1;

		put_pixel(img, point_to_plot);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * error;
		if (e2 >= dy)
		{
			if (x0 == x1)
				break ;
			error += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			if (y0 == y1)
				break ;
			error += dx;
			y0 += sy;
		}
	}
}
