/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:07:19 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/31 16:57:46 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	inicializate(t_xiaolin *xiaolin, t_line line)
{
	xiaolin->x1 = line.point_1.x;
	xiaolin->x2 = line.point_2.x;
	xiaolin->y1 = line.point_1.y;
	xiaolin->y2 = line.point_2.y;
	xiaolin->delta.x = abs(line.point_2.x - line.point_1.x);
	xiaolin->delta.y = abs(line.point_2.y - line.point_1.y);
	xiaolin->dx = xiaolin->x2 - xiaolin->x1;
	xiaolin->dy = xiaolin->y2 - xiaolin->y1;
	xiaolin->original_line = line;
}

static void	process_delta_x_is_greater(mlx_image_t *img, t_xiaolin *xiaolin)
{
	inicializate_x_greater(img, xiaolin);
	while (xiaolin->i < xiaolin->xpxl2)
	{
		xiaolin->point_to_plot = create_point(xiaolin->i, xiaolin->intery);
		xiaolin->color = color_gradient(xiaolin->point_to_plot,
				xiaolin->original_line.point_1, xiaolin->original_line.point_2,
				xiaolin->delta);
		xiaolin->point_to_plot.color = set_brightness(xiaolin->color,
				rev_float_part(xiaolin->intery));
		put_pixel(img, xiaolin->point_to_plot);
		xiaolin->point_to_plot = create_point(xiaolin->i, xiaolin->intery + 1);
		xiaolin->color = color_gradient(xiaolin->point_to_plot,
				xiaolin->original_line.point_1, xiaolin->original_line.point_2,
				xiaolin->delta);
		xiaolin->point_to_plot.color = set_brightness(xiaolin->color,
				float_part(xiaolin->intery));
		put_pixel(img, xiaolin->point_to_plot);
		xiaolin->intery += xiaolin->gradient;
		xiaolin->i++;
	}
}

static void	proces_delta_x_is_lesser(mlx_image_t *img, t_xiaolin *xiaolin)
{
	inicializate_x_lesser(img, xiaolin);
	while (xiaolin->i < xiaolin->ypxl2)
	{
		xiaolin->point_to_plot = create_point(xiaolin->interx, xiaolin->i);
		xiaolin->color = color_gradient(xiaolin->point_to_plot,
				xiaolin->original_line.point_1, xiaolin->original_line.point_2,
				xiaolin->delta);
		xiaolin->point_to_plot.color = set_brightness(xiaolin->color,
				rev_float_part(xiaolin->interx));
		put_pixel(img, xiaolin->point_to_plot);
		xiaolin->point_to_plot = create_point(xiaolin->interx + 1, xiaolin->i);
		xiaolin->color = color_gradient(xiaolin->point_to_plot,
				xiaolin->original_line.point_1, xiaolin->original_line.point_2,
				xiaolin->delta);
		xiaolin->point_to_plot.color = set_brightness(xiaolin->color,
				float_part(xiaolin->interx));
		put_pixel(img, xiaolin->point_to_plot);
		xiaolin->interx += xiaolin->gradient;
		xiaolin->i++;
	}
}

void	xiaolin_algorithm(mlx_image_t *img, t_line line)
{
	t_xiaolin	xiaolin;

	inicializate(&xiaolin, line);
	if (fabs(xiaolin.dx) > fabs(xiaolin.dy))
	{
		if (xiaolin.x2 < xiaolin.x1)
		{
			swap(&xiaolin.x1, &xiaolin.x2);
			swap(&xiaolin.y1, &xiaolin.y2);
		}
		process_delta_x_is_greater(img, &xiaolin);
	}
	else
	{
		if (xiaolin.y2 < xiaolin.y1)
		{
			swap(&xiaolin.x1, &xiaolin.x2);
			swap(&xiaolin.y1, &xiaolin.y2);
		}
		proces_delta_x_is_lesser(img, &xiaolin);
	}
}
