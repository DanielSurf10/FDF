/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:07:19 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/30 18:45:52 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int set_brightness(int color, float brightness)
{
	int	brightness_rgba;

	brightness_rgba = brightness * 255;
	return ((color & 0xFFFFFF00) | brightness_rgba);
}

double	float_part(double x)
{
	return (x - ((int)x));
}

double	rev_float_part(double x)
{
	return (1.0 - float_part(x));
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// #define ipart_(X) ((int)(X))
// #define round_(X) ((int)(((double)(X))+0.5))
// #define fpart_(X) (((double)(X))-(double)ipart_(X))
// #define rfpart_(X) (1.0-fpart_(X))
//
// #define swap_(a, b) do{ __typeof__(a) tmp;	tmp = a; a = b; b = tmp; }while(0)

void	xiaolin_algorithm(mlx_image_t *img, t_line line)
{
	int		x1 = line.point_1.x;
	int		x2 = line.point_2.x;
	int		y1 = line.point_1.y;
	int		y2 = line.point_2.y;
	int		color;
	t_point	delta;

	double	gradient;
	double	dx;
	double	dy;
	double	xend;
	double	yend;
	double	xgap;
	double	ygap;
	int		xpxl1;
	int		ypxl1;
	double	intery;
	double	interx;
	int		xpxl2;
	int		ypxl2;
	int		i;


	delta.x = abs(line.point_2.x - line.point_1.x);
	delta.y = abs(line.point_2.y - line.point_1.y);
	t_point	point_to_plot;

	dx = x2 - x1;
	dy = y2 - y1;
	if ( fabs(dx) > fabs(dy) ) {			// Quando o delta x é maior que o y
		if ( x2 < x1 ) {
			swap(&x1, &x2);
			swap(&y1, &y2);
		}
		gradient = dy / dx;
		xend = round(x1);
		yend = y1 + gradient * (xend - x1);
		xgap = rev_float_part(x1 + 0.5);
		xpxl1 = xend;
		ypxl1 = yend;


		// point_to_plot.x = xpxl1;
		// point_to_plot.y = ypxl1;

		point_to_plot = create_point(xpxl1, ypxl1);
		color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
		point_to_plot.color = set_brightness(color, rev_float_part(yend)*xgap);

		put_pixel(img, point_to_plot);


		// point_to_plot.x = xpxl1;
		// point_to_plot.y = ypxl1 + 1;

		point_to_plot = create_point(xpxl1, ypxl1 + 1);
		color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
		point_to_plot.color = set_brightness(color, float_part(yend)*xgap);

		put_pixel(img, point_to_plot);


		intery = yend + gradient;
		xend = round(x2);
		yend = y2 + gradient * (xend - x2);
		xgap = float_part(x2 + 0.5);
		xpxl2 = xend;
		ypxl2 = yend;


		// point_to_plot.x = xpxl2;
		// point_to_plot.y = ypxl2;

		point_to_plot = create_point(xpxl2, ypxl2);
		color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
		point_to_plot.color = set_brightness(color, rev_float_part(yend) * xgap);

		put_pixel(img, point_to_plot);


		// point_to_plot.x = xpxl2;
		// point_to_plot.y = ypxl2 + 1;

		point_to_plot = create_point(xpxl2, ypxl2 + 1);
		color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
		point_to_plot.color = set_brightness(color, float_part(yend) * xgap);

		put_pixel(img, point_to_plot);


		i = xpxl1 + 1;
		while (i < xpxl2)
		{

			// point_to_plot.x = i;
			// point_to_plot.y = intery;

			point_to_plot = create_point(i, intery);
			color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
			point_to_plot.color = set_brightness(color, rev_float_part(intery));

			put_pixel(img, point_to_plot);


			// point_to_plot.x = i;
			// point_to_plot.y = intery + 1;

			point_to_plot = create_point(i, intery + 1);
			color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
			point_to_plot.color = set_brightness(color, float_part(intery));

			put_pixel(img, point_to_plot);


			intery += gradient;
			i++;
		}
	} else {								// Quando o delta y é maior que o x
		if ( y2 < y1 ) {
			swap(&x1, &x2);
			swap(&y1, &y2);
		}
		gradient = dx / dy;
		yend = round(y1);
		xend = x1 + gradient * (yend - y1);
		ygap = rev_float_part(y1 + 0.5);
		ypxl1 = yend;
		xpxl1 = xend;


		// point_to_plot.x = xpxl1;
		// point_to_plot.y = ypxl1;

		point_to_plot = create_point(xpxl1, ypxl1);
		color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
		point_to_plot.color = set_brightness(color, rev_float_part(xend) * ygap);

		put_pixel(img, point_to_plot);


		// point_to_plot.x = xpxl1 + 1;
		// point_to_plot.y = ypxl1;

		point_to_plot = create_point(xpxl1 + 1, ypxl1);
		color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
		point_to_plot.color = set_brightness(color, float_part(xend) * ygap);

		put_pixel(img, point_to_plot);


		interx = xend + gradient;
		yend = round(y2);
		xend = x2 + gradient * (yend - y2);
		ygap = float_part(y2 + 0.5);
		ypxl2 = yend;
		xpxl2 = xend;


		// point_to_plot.x = xpxl2;
		// point_to_plot.y = ypxl2;

		point_to_plot = create_point(xpxl2, ypxl2);
		color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
		point_to_plot.color = set_brightness(color, rev_float_part(xend) * ygap);

		put_pixel(img, point_to_plot);


		// point_to_plot.x = xpxl2 + 1;
		// point_to_plot.y = ypxl2;

		point_to_plot = create_point(xpxl2 + 1, ypxl2);
		color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
		point_to_plot.color = set_brightness(color, float_part(xend) * ygap);

		put_pixel(img, point_to_plot);


		i = ypxl1 + 1;
		while (i < ypxl2)
		{

			// point_to_plot.x = interx;
			// point_to_plot.y = i;

			point_to_plot = create_point(interx, i);
			color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
			point_to_plot.color = set_brightness(color, rev_float_part(interx));

			put_pixel(img, point_to_plot);


			point_to_plot.x = interx + 1;
			point_to_plot.y = i;

			point_to_plot = create_point(interx + 1, i);
			color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
			point_to_plot.color = set_brightness(color, float_part(interx));

			put_pixel(img, point_to_plot);


			interx += gradient;
			i++;
		}
	}
}
