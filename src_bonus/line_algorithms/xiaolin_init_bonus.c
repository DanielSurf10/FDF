/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:36:06 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/31 16:57:46 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	init_x_greater(mlx_image_t *img, t_xiaolin *xiaolin)
{
	xiaolin->gradient = xiaolin->dy / xiaolin->dx;
	xiaolin->xend = round(xiaolin->x1);
	xiaolin->yend = xiaolin->y1 + xiaolin->gradient
		* (xiaolin->xend - xiaolin->x1);
	xiaolin->xgap = rev_float_part(xiaolin->x1 + 0.5);
	xiaolin->xpxl1 = xiaolin->xend;
	xiaolin->ypxl1 = xiaolin->yend;
	xiaolin->point_to_plot = create_point(xiaolin->xpxl1, xiaolin->ypxl1);
	xiaolin->color = color_gradient(xiaolin->point_to_plot,
			xiaolin->original_line.point_1, xiaolin->original_line.point_2,
			xiaolin->delta);
	xiaolin->point_to_plot.color = set_brightness(xiaolin->color,
			rev_float_part(xiaolin->yend) * xiaolin->xgap);
	put_pixel(img, xiaolin->point_to_plot);
	xiaolin->point_to_plot = create_point(xiaolin->xpxl1, xiaolin->ypxl1 + 1);
	xiaolin->color = color_gradient(xiaolin->point_to_plot,
			xiaolin->original_line.point_1, xiaolin->original_line.point_2,
			xiaolin->delta);
	xiaolin->point_to_plot.color = set_brightness(xiaolin->color,
			float_part(xiaolin->yend) * xiaolin->xgap);
	put_pixel(img, xiaolin->point_to_plot);
	xiaolin->intery = xiaolin->yend + xiaolin->gradient;
	xiaolin->xend = round(xiaolin->x2);
	xiaolin->yend = xiaolin->y2 + xiaolin->gradient
		* (xiaolin->xend - xiaolin->x2);
}

void	inicializate_x_greater(mlx_image_t *img, t_xiaolin *xiaolin)
{
	init_x_greater(img, xiaolin);
	xiaolin->xgap = float_part(xiaolin->x2 + 0.5);
	xiaolin->xpxl2 = xiaolin->xend;
	xiaolin->ypxl2 = xiaolin->yend;
	xiaolin->point_to_plot = create_point(xiaolin->xpxl2, xiaolin->ypxl2);
	xiaolin->color = color_gradient(xiaolin->point_to_plot,
			xiaolin->original_line.point_1, xiaolin->original_line.point_2,
			xiaolin->delta);
	xiaolin->point_to_plot.color = set_brightness(xiaolin->color,
			rev_float_part(xiaolin->yend) * xiaolin->xgap);
	put_pixel(img, xiaolin->point_to_plot);
	xiaolin->point_to_plot = create_point(xiaolin->xpxl2, xiaolin->ypxl2 + 1);
	xiaolin->color = color_gradient(xiaolin->point_to_plot,
			xiaolin->original_line.point_1, xiaolin->original_line.point_2,
			xiaolin->delta);
	xiaolin->point_to_plot.color = set_brightness(xiaolin->color,
			float_part(xiaolin->yend) * xiaolin->xgap);
	put_pixel(img, xiaolin->point_to_plot);
	xiaolin->i = xiaolin->xpxl1 + 1;
}

static void	init_x_lesser(mlx_image_t *img, t_xiaolin *xiaolin)
{
	xiaolin->gradient = xiaolin->dx / xiaolin->dy;
	xiaolin->yend = round(xiaolin->y1);
	xiaolin->xend = xiaolin->x1 + xiaolin->gradient
		* (xiaolin->yend - xiaolin->y1);
	xiaolin->ygap = rev_float_part(xiaolin->y1 + 0.5);
	xiaolin->ypxl1 = xiaolin->yend;
	xiaolin->xpxl1 = xiaolin->xend;
	xiaolin->point_to_plot = create_point(xiaolin->xpxl1,
			xiaolin->ypxl1);
	xiaolin->color = color_gradient(xiaolin->point_to_plot,
			xiaolin->original_line.point_1, xiaolin->original_line.point_2,
			xiaolin->delta);
	xiaolin->point_to_plot.color = set_brightness(xiaolin->color,
			rev_float_part(xiaolin->xend) * xiaolin->ygap);
	put_pixel(img, xiaolin->point_to_plot);
	xiaolin->point_to_plot = create_point(xiaolin->xpxl1 + 1, xiaolin->ypxl1);
	xiaolin->color = color_gradient(xiaolin->point_to_plot,
			xiaolin->original_line.point_1, xiaolin->original_line.point_2,
			xiaolin->delta);
	xiaolin->point_to_plot.color = set_brightness(xiaolin->color,
			float_part(xiaolin->xend) * xiaolin->ygap);
	put_pixel(img, xiaolin->point_to_plot);
	xiaolin->interx = xiaolin->xend + xiaolin->gradient;
	xiaolin->yend = round(xiaolin->y2);
}

void	inicializate_x_lesser(mlx_image_t *img, t_xiaolin *xiaolin)
{
	init_x_lesser(img, xiaolin);
	xiaolin->xend = xiaolin->x2 + xiaolin->gradient
		* (xiaolin->yend - xiaolin->y2);
	xiaolin->ygap = float_part(xiaolin->y2 + 0.5);
	xiaolin->ypxl2 = xiaolin->yend;
	xiaolin->xpxl2 = xiaolin->xend;
	xiaolin->point_to_plot = create_point(xiaolin->xpxl2, xiaolin->ypxl2);
	xiaolin->color = color_gradient(xiaolin->point_to_plot,
			xiaolin->original_line.point_1, xiaolin->original_line.point_2,
			xiaolin->delta);
	xiaolin->point_to_plot.color = set_brightness(xiaolin->color,
			rev_float_part(xiaolin->xend) * xiaolin->ygap);
	put_pixel(img, xiaolin->point_to_plot);
	xiaolin->point_to_plot = create_point(xiaolin->xpxl2 + 1, xiaolin->ypxl2);
	xiaolin->color = color_gradient(xiaolin->point_to_plot,
			xiaolin->original_line.point_1, xiaolin->original_line.point_2,
			xiaolin->delta);
	xiaolin->point_to_plot.color = set_brightness(xiaolin->color,
			float_part(xiaolin->xend) * xiaolin->ygap);
	put_pixel(img, xiaolin->point_to_plot);
	xiaolin->i = xiaolin->ypxl1 + 1;
}
