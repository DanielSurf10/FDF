/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_xiaolin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:07:19 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/25 15:16:22 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int set_brightness(int color, float brightness)
{
	int	brightness_rgba;

	brightness_rgba = brightness * 255;
	return ((color & 0xFFFFFF00) | brightness_rgba);
}

#define ipart_(X) ((int)(X))
#define round_(X) ((int)(((double)(X))+0.5))
#define fpart_(X) (((double)(X))-(double)ipart_(X))
#define rfpart_(X) (1.0-fpart_(X))

#define swap_(a, b) do{ __typeof__(a) tmp;	tmp = a; a = b; b = tmp; }while(0)

void	xiaolin_algorithm(mlx_image_t *img, t_line line)
{
	int		x1 = line.point_1.x;
	int		x2 = line.point_2.x;
	int		y1 = line.point_1.y;
	int		y2 = line.point_2.y;
	int		color = line.point_1.color;
	t_point	point_to_plot;

	double dx = (double)x2 - (double)x1;
	double dy = (double)y2 - (double)y1;
	if ( fabs(dx) > fabs(dy) ) {
		if ( x2 < x1 ) {
			swap_(x1, x2);
			swap_(y1, y2);
		}
		double gradient = dy / dx;
		double xend = round_(x1);
		double yend = y1 + gradient*(xend - x1);
		double xgap = rfpart_(x1 + 0.5);
		int xpxl1 = xend;
		int ypxl1 = ipart_(yend);

		point_to_plot.x = xpxl1;
		point_to_plot.y = ypxl1;
		point_to_plot.color = set_brightness(color, rfpart_(yend)*xgap);
		put_pixel(img, point_to_plot);

		point_to_plot.x = xpxl1;
		point_to_plot.y = ypxl1 + 1;
		point_to_plot.color = set_brightness(color, fpart_(yend)*xgap);
		put_pixel(img, point_to_plot);
		double intery = yend + gradient;

		xend = round_(x2);
		yend = y2 + gradient*(xend - x2);
		xgap = fpart_(x2+0.5);
		int xpxl2 = xend;
		int ypxl2 = ipart_(yend);

		point_to_plot.x = xpxl2;
		point_to_plot.y = ypxl2;
		point_to_plot.color = set_brightness(color, rfpart_(yend) * xgap);
		put_pixel(img, point_to_plot);

		point_to_plot.x = xpxl2;
		point_to_plot.y = ypxl2 + 1;
		point_to_plot.color = set_brightness(color, fpart_(yend) * xgap);
		put_pixel(img, point_to_plot);

		int x;
		for(x=xpxl1+1; x < xpxl2; x++) {

			point_to_plot.x = x;
			point_to_plot.y = ipart_(intery);
			point_to_plot.color = set_brightness(color, rfpart_(intery));
			put_pixel(img, point_to_plot);

			point_to_plot.x = x;
			point_to_plot.y = ipart_(intery) + 1;
			point_to_plot.color = set_brightness(color, fpart_(intery));
			put_pixel(img, point_to_plot);
			intery += gradient;
		}
	} else {
		if ( y2 < y1 ) {
			swap_(x1, x2);
			swap_(y1, y2);
		}
		double gradient = dx / dy;
		double yend = round_(y1);
		double xend = x1 + gradient*(yend - y1);
		double ygap = rfpart_(y1 + 0.5);
		int ypxl1 = yend;
		int xpxl1 = ipart_(xend);

		point_to_plot.x = xpxl1;
		point_to_plot.y = ypxl1;
		point_to_plot.color = set_brightness(color, rfpart_(xend)*ygap);
		put_pixel(img, point_to_plot);

		point_to_plot.x = xpxl1 + 1;
		point_to_plot.y = ypxl1;
		point_to_plot.color = set_brightness(color, fpart_(xend)*ygap);
		put_pixel(img, point_to_plot);
		double interx = xend + gradient;

		yend = round_(y2);
		xend = x2 + gradient*(yend - y2);
		ygap = fpart_(y2+0.5);
		int ypxl2 = yend;
		int xpxl2 = ipart_(xend);

		point_to_plot.x = xpxl2;
		point_to_plot.y = ypxl2;
		point_to_plot.color = set_brightness(color, rfpart_(xend) * ygap);
		put_pixel(img, point_to_plot);

		point_to_plot.x = xpxl2 + 1;
		point_to_plot.y = ypxl2;
		point_to_plot.color = set_brightness(color, fpart_(xend) * ygap);
		put_pixel(img, point_to_plot);

		int y;
		for(y=ypxl1+1; y < ypxl2; y++) {

			point_to_plot.x = ipart_(interx);
			point_to_plot.y = y;
			point_to_plot.color = set_brightness(color, rfpart_(interx));
			put_pixel(img, point_to_plot);

			point_to_plot.x = ipart_(interx) + 1;
			point_to_plot.y = y;
			point_to_plot.color = set_brightness(color, fpart_(interx));
			put_pixel(img, point_to_plot);
			interx += gradient;
		}
	}
}
