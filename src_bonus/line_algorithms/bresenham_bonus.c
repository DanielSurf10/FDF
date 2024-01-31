/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:54:56 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/31 16:57:46 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static t_bresenham	inicializate(t_line line)
{
	t_bresenham	variables;

	variables.line = line;
	variables.original_line = line;
	variables.delta.x = abs(line.point_2.x - line.point_1.x);
	variables.delta.y = abs(line.point_2.y - line.point_1.y);
	variables.delta_x = abs(variables.line.point_2.x
			- variables.line.point_1.x);
	variables.delta_y = -abs(variables.line.point_2.y
			- variables.line.point_1.y);
	variables.slope_x = ternary(variables.line.point_1.x
			< variables.line.point_2.x, 1, -1);
	variables.slope_y = ternary(variables.line.point_1.y
			< variables.line.point_2.y, 1, -1);
	variables.error_1 = variables.delta_x + variables.delta_y;
	return (variables);
}

static t_point	get_point(t_bresenham variables)
{
	t_point	point;

	point.x = variables.line.point_1.x;
	point.y = variables.line.point_1.y;
	point.color = color_gradient(variables.line.point_1,
			variables.original_line.point_1, variables.original_line.point_2,
			variables.delta);
	return (point);
}

void	bresenham_algorithm(mlx_image_t *img, t_line line)
{
	t_bresenham	variables;

	variables = inicializate(line);
	while (1)
	{
		put_pixel(img, get_point(variables));
		if (variables.line.point_1.x == variables.line.point_2.x
			&& variables.line.point_1.y == variables.line.point_2.y)
			break ;
		variables.error_2 = 2 * variables.error_1;
		if (variables.error_2 >= variables.delta_y)
		{
			if (variables.line.point_1.x == variables.line.point_2.x)
				break ;
			variables.error_1 += variables.delta_y;
			variables.line.point_1.x += variables.slope_x;
		}
		if (variables.error_2 <= variables.delta_x)
		{
			if (variables.line.point_1.y == variables.line.point_2.y)
				break ;
			variables.error_1 += variables.delta_x;
			variables.line.point_1.y += variables.slope_y;
		}
	}
}
