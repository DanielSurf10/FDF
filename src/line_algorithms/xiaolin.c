/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:07:19 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/30 17:43:12 by danbarbo         ###   ########.fr       */
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
	return (x - (double)((int)x));
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

	// double	gradient;
	double	dx;
	double	dy;

	delta.x = abs(line.point_2.x - line.point_1.x);
	delta.y = abs(line.point_2.y - line.point_1.y);
	t_point	point_to_plot;

	dx = (double)x2 - (double)x1;
	dy = (double)y2 - (double)y1;
	if ( fabs(dx) > fabs(dy) ) {
		if ( x2 < x1 ) {
			swap(&x1, &x2);
			swap(&y1, &y2);
		}
		double gradient = dy / dx;
		double xend = round(x1);
		double yend = y1 + gradient*(xend - x1);
		double xgap = rev_float_part(x1 + 0.5);
		int xpxl1 = xend;
		int ypxl1 = (int) yend;

		point_to_plot.x = xpxl1;
		point_to_plot.y = ypxl1;
		color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
		point_to_plot.color = set_brightness(color, rev_float_part(yend)*xgap);
		put_pixel(img, point_to_plot);

		point_to_plot.x = xpxl1;
		point_to_plot.y = ypxl1 + 1;
		color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
		point_to_plot.color = set_brightness(color, float_part(yend)*xgap);
		put_pixel(img, point_to_plot);
		double intery = yend + gradient;

		xend = round(x2);
		yend = y2 + gradient*(xend - x2);
		xgap = float_part(x2+0.5);
		int xpxl2 = xend;
		int ypxl2 = (int) yend;

		point_to_plot.x = xpxl2;
		point_to_plot.y = ypxl2;
		color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
		point_to_plot.color = set_brightness(color, rev_float_part(yend) * xgap);
		put_pixel(img, point_to_plot);

		point_to_plot.x = xpxl2;
		point_to_plot.y = ypxl2 + 1;
		color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
		point_to_plot.color = set_brightness(color, float_part(yend) * xgap);
		put_pixel(img, point_to_plot);

		int x;
		for(x=xpxl1+1; x < xpxl2; x++) {

			point_to_plot.x = x;
			point_to_plot.y = (int) intery;
			color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
			point_to_plot.color = set_brightness(color, rev_float_part(intery));
			put_pixel(img, point_to_plot);

			point_to_plot.x = x;
			point_to_plot.y = ((int) intery) + 1;
			color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
			point_to_plot.color = set_brightness(color, float_part(intery));
			put_pixel(img, point_to_plot);
			intery += gradient;
		}
	} else {
		if ( y2 < y1 ) {
			swap(&x1, &x2);
			swap(&y1, &y2);
		}
		double gradient = dx / dy;
		double yend = round(y1);
		double xend = x1 + gradient*(yend - y1);
		double ygap = rev_float_part(y1 + 0.5);
		int ypxl1 = yend;
		int xpxl1 = (int) xend;

		point_to_plot.x = xpxl1;
		point_to_plot.y = ypxl1;
		color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
		point_to_plot.color = set_brightness(color, rev_float_part(xend)*ygap);
		put_pixel(img, point_to_plot);

		point_to_plot.x = xpxl1 + 1;
		point_to_plot.y = ypxl1;
		color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
		point_to_plot.color = set_brightness(color, float_part(xend)*ygap);
		put_pixel(img, point_to_plot);
		double interx = xend + gradient;

		yend = round(y2);
		xend = x2 + gradient*(yend - y2);
		ygap = float_part(y2+0.5);
		int ypxl2 = yend;
		int xpxl2 = (int) xend;

		point_to_plot.x = xpxl2;
		point_to_plot.y = ypxl2;
		color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
		point_to_plot.color = set_brightness(color, rev_float_part(xend) * ygap);
		put_pixel(img, point_to_plot);

		point_to_plot.x = xpxl2 + 1;
		point_to_plot.y = ypxl2;
		color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
		point_to_plot.color = set_brightness(color, float_part(xend) * ygap);
		put_pixel(img, point_to_plot);

		int y;
		for(y=ypxl1+1; y < ypxl2; y++) {

			point_to_plot.x = (int) interx;
			point_to_plot.y = y;
			color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
			point_to_plot.color = set_brightness(color, rev_float_part(interx));
			put_pixel(img, point_to_plot);

			point_to_plot.x = ((int) interx) + 1;
			point_to_plot.y = y;
			color = color_gradient(point_to_plot, line.point_1, line.point_2, delta);
			point_to_plot.color = set_brightness(color, float_part(interx));
			put_pixel(img, point_to_plot);
			interx += gradient;
		}
	}
}
