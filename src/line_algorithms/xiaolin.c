/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:07:19 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/30 19:38:57 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// #define ipart_(X) ((int)(X))
// #define round_(X) ((int)(((double)(X))+0.5))
// #define fpart_(X) (((double)(X))-(double)ipart_(X))
// #define rfpart_(X) (1.0-fpart_(X))
//
// #define swap_(a, b) do{ __typeof__(a) tmp;	tmp = a; a = b; b = tmp; }while(0)

void	xiaolin_algorithm(mlx_image_t *img, t_line line)
{
	// int		xiaolin.x1;
	// int		xiaolin.x2;
	// int		xiaolin.y1;
	// int		xiaolin.y2;
	// int		color;
	// t_point	xiaolin.delta;
	// double	gradient;
	// double	xiaolin.dx;
	// double	xiaolin.dy;
	// double	xiaolin.xend;
	// double	xiaolin.yend;
	// double	xiaolin.xgap;
	// double	xiaolin.ygap;
	// int		xiaolin.xpxl1;
	// int		xiaolin.ypxl1;
	// double	intery;
	// double	interx;
	// int		xiaolin.xpxl2;
	// int		xiaolin.ypxl2;
	// int		i;
	// t_point	xiaolin.point_to_plot;
	t_xiaolin	xiaolin;

	xiaolin.x1 = line.point_1.x;
	xiaolin.x2 = line.point_2.x;
	xiaolin.y1 = line.point_1.y;
	xiaolin.y2 = line.point_2.y;
	xiaolin.delta.x = abs(line.point_2.x - line.point_1.x);
	xiaolin.delta.y = abs(line.point_2.y - line.point_1.y);

	xiaolin.dx = xiaolin.x2 - xiaolin.x1;
	xiaolin.dy = xiaolin.y2 - xiaolin.y1;
	if ( fabs(xiaolin.dx) > fabs(xiaolin.dy) ) {			// Quando o xiaolin.delta x é maior que o y
		if ( xiaolin.x2 < xiaolin.x1 ) {
			swap(&xiaolin.x1, &xiaolin.x2);
			swap(&xiaolin.y1, &xiaolin.y2);
		}
		xiaolin.gradient = xiaolin.dy / xiaolin.dx;
		xiaolin.xend = round(xiaolin.x1);
		xiaolin.yend = xiaolin.y1 + xiaolin.gradient * (xiaolin.xend - xiaolin.x1);
		xiaolin.xgap = rev_float_part(xiaolin.x1 + 0.5);
		xiaolin.xpxl1 = xiaolin.xend;
		xiaolin.ypxl1 = xiaolin.yend;


		// xiaolin.point_to_plot.x = xiaolin.xpxl1;
		// xiaolin.point_to_plot.y = xiaolin.ypxl1;

		xiaolin.point_to_plot = create_point(xiaolin.xpxl1, xiaolin.ypxl1);
		xiaolin.color = color_gradient(xiaolin.point_to_plot, line.point_1, line.point_2, xiaolin.delta);
		xiaolin.point_to_plot.color = set_brightness(xiaolin.color, rev_float_part(xiaolin.yend) * xiaolin.xgap);

		put_pixel(img, xiaolin.point_to_plot);


		// xiaolin.point_to_plot.x = xiaolin.xpxl1;
		// xiaolin.point_to_plot.y = xiaolin.ypxl1 + 1;

		xiaolin.point_to_plot = create_point(xiaolin.xpxl1, xiaolin.ypxl1 + 1);
		xiaolin.color = color_gradient(xiaolin.point_to_plot, line.point_1, line.point_2, xiaolin.delta);
		xiaolin.point_to_plot.color = set_brightness(xiaolin.color, float_part(xiaolin.yend)*xiaolin.xgap);

		put_pixel(img, xiaolin.point_to_plot);


		xiaolin.intery = xiaolin.yend + xiaolin.gradient;
		xiaolin.xend = round(xiaolin.x2);
		xiaolin.yend = xiaolin.y2 + xiaolin.gradient * (xiaolin.xend - xiaolin.x2);
		xiaolin.xgap = float_part(xiaolin.x2 + 0.5);
		xiaolin.xpxl2 = xiaolin.xend;
		xiaolin.ypxl2 = xiaolin.yend;


		// xiaolin.point_to_plot.x = xiaolin.xpxl2;
		// xiaolin.point_to_plot.y = xiaolin.ypxl2;

		xiaolin.point_to_plot = create_point(xiaolin.xpxl2, xiaolin.ypxl2);
		xiaolin.color = color_gradient(xiaolin.point_to_plot, line.point_1, line.point_2, xiaolin.delta);
		xiaolin.point_to_plot.color = set_brightness(xiaolin.color, rev_float_part(xiaolin.yend) * xiaolin.xgap);

		put_pixel(img, xiaolin.point_to_plot);


		// xiaolin.point_to_plot.x = xiaolin.xpxl2;
		// xiaolin.point_to_plot.y = xiaolin.ypxl2 + 1;

		xiaolin.point_to_plot = create_point(xiaolin.xpxl2, xiaolin.ypxl2 + 1);
		xiaolin.color = color_gradient(xiaolin.point_to_plot, line.point_1, line.point_2, xiaolin.delta);
		xiaolin.point_to_plot.color = set_brightness(xiaolin.color, float_part(xiaolin.yend) * xiaolin.xgap);

		put_pixel(img, xiaolin.point_to_plot);


		xiaolin.i = xiaolin.xpxl1 + 1;
		while (xiaolin.i < xiaolin.xpxl2)
		{

			// xiaolin.point_to_plot.x = xiaolin.i;
			// xiaolin.point_to_plot.y = xiaolin.intery;

			xiaolin.point_to_plot = create_point(xiaolin.i, xiaolin.intery);
			xiaolin.color = color_gradient(xiaolin.point_to_plot, line.point_1, line.point_2, xiaolin.delta);
			xiaolin.point_to_plot.color = set_brightness(xiaolin.color, rev_float_part(xiaolin.intery));

			put_pixel(img, xiaolin.point_to_plot);


			// xiaolin.point_to_plot.x = i;
			// xiaolin.point_to_plot.y = xiaolin.intery + 1;

			xiaolin.point_to_plot = create_point(xiaolin.i, xiaolin.intery + 1);
			xiaolin.color = color_gradient(xiaolin.point_to_plot, line.point_1, line.point_2, xiaolin.delta);
			xiaolin.point_to_plot.color = set_brightness(xiaolin.color, float_part(xiaolin.intery));

			put_pixel(img, xiaolin.point_to_plot);


			xiaolin.intery += xiaolin.gradient;
			xiaolin.i++;
		}
	} else {								// Quando o xiaolin.delta y é maior que o x
		if ( xiaolin.y2 < xiaolin.y1 ) {
			swap(&xiaolin.x1, &xiaolin.x2);
			swap(&xiaolin.y1, &xiaolin.y2);
		}
		xiaolin.gradient = xiaolin.dx / xiaolin.dy;
		xiaolin.yend = round(xiaolin.y1);
		xiaolin.xend = xiaolin.x1 + xiaolin.gradient * (xiaolin.yend - xiaolin.y1);
		xiaolin.ygap = rev_float_part(xiaolin.y1 + 0.5);
		xiaolin.ypxl1 = xiaolin.yend;
		xiaolin.xpxl1 = xiaolin.xend;


		// xiaolin.point_to_plot.x = xiaolin.xpxl1;
		// xiaolin.point_to_plot.y = xiaolin.ypxl1;

		xiaolin.point_to_plot = create_point(xiaolin.xpxl1, xiaolin.ypxl1);
		xiaolin.color = color_gradient(xiaolin.point_to_plot, line.point_1, line.point_2, xiaolin.delta);
		xiaolin.point_to_plot.color = set_brightness(xiaolin.color, rev_float_part(xiaolin.xend) * xiaolin.ygap);

		put_pixel(img, xiaolin.point_to_plot);


		// xiaolin.point_to_plot.x = xiaolin.xpxl1 + 1;
		// xiaolin.point_to_plot.y = xiaolin.ypxl1;

		xiaolin.point_to_plot = create_point(xiaolin.xpxl1 + 1, xiaolin.ypxl1);
		xiaolin.color = color_gradient(xiaolin.point_to_plot, line.point_1, line.point_2, xiaolin.delta);
		xiaolin.point_to_plot.color = set_brightness(xiaolin.color, float_part(xiaolin.xend) * xiaolin.ygap);

		put_pixel(img, xiaolin.point_to_plot);


		xiaolin.interx = xiaolin.xend + xiaolin.gradient;
		xiaolin.yend = round(xiaolin.y2);
		xiaolin.xend = xiaolin.x2 + xiaolin.gradient * (xiaolin.yend - xiaolin.y2);
		xiaolin.ygap = float_part(xiaolin.y2 + 0.5);
		xiaolin.ypxl2 = xiaolin.yend;
		xiaolin.xpxl2 = xiaolin.xend;


		// xiaolin.point_to_plot.x = xiaolin.xpxl2;
		// xiaolin.point_to_plot.y = xiaolin.ypxl2;

		xiaolin.point_to_plot = create_point(xiaolin.xpxl2, xiaolin.ypxl2);
		xiaolin.color = color_gradient(xiaolin.point_to_plot, line.point_1, line.point_2, xiaolin.delta);
		xiaolin.point_to_plot.color = set_brightness(xiaolin.color, rev_float_part(xiaolin.xend) * xiaolin.ygap);

		put_pixel(img, xiaolin.point_to_plot);


		// xiaolin.point_to_plot.x = xiaolin.xpxl2 + 1;
		// xiaolin.point_to_plot.y = xiaolin.ypxl2;

		xiaolin.point_to_plot = create_point(xiaolin.xpxl2 + 1, xiaolin.ypxl2);
		xiaolin.color = color_gradient(xiaolin.point_to_plot, line.point_1, line.point_2, xiaolin.delta);
		xiaolin.point_to_plot.color = set_brightness(xiaolin.color, float_part(xiaolin.xend) * xiaolin.ygap);

		put_pixel(img, xiaolin.point_to_plot);


		xiaolin.i = xiaolin.ypxl1 + 1;
		while (xiaolin.i < xiaolin.ypxl2)
		{

			// xiaolin.point_to_plot.x = xiaolin.interx;
			// xiaolin.point_to_plot.y = xiaolin.i;

			xiaolin.point_to_plot = create_point(xiaolin.interx, xiaolin.i);
			xiaolin.color = color_gradient(xiaolin.point_to_plot, line.point_1, line.point_2, xiaolin.delta);
			xiaolin.point_to_plot.color = set_brightness(xiaolin.color, rev_float_part(xiaolin.interx));

			put_pixel(img, xiaolin.point_to_plot);


			xiaolin.point_to_plot.x = xiaolin.interx + 1;
			xiaolin.point_to_plot.y = xiaolin.i;

			xiaolin.point_to_plot = create_point(xiaolin.interx + 1, xiaolin.i);
			xiaolin.color = color_gradient(xiaolin.point_to_plot, line.point_1, line.point_2, xiaolin.delta);
			xiaolin.point_to_plot.color = set_brightness(xiaolin.color, float_part(xiaolin.interx));

			put_pixel(img, xiaolin.point_to_plot);


			xiaolin.interx += xiaolin.gradient;
			xiaolin.i++;
		}
	}
}
