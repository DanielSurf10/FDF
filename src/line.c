// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   line.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/12/30 19:05:39 by danbarbo          #+#    #+#             */
// /*   Updated: 2023/12/30 19:19:15 by danbarbo         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */
//
#include "fdf.h"
//
// typedef struct s_rgb
// {
// 	int	red;
// 	int	blue;
// 	int	green;
// } rgb_color_p;
//
//
// inline void _dla_changebrightness(rgb_color_p from,
// 				  rgb_color_p to, float br)
// {
//   if ( br > 1.0 ) br = 1.0;
//   /* linear... Maybe something more complex could give better look */
//   to->red = br * (float)from->red;
//   to->green = br * (float)from->green;
//   to->blue = br * (float)from->blue;
// }
//
// #define plot_(X,Y,D) do{ rgb_color f_;				\
//   f_.red = r; f_.green = g; f_.blue = b;			\
//   _dla_plot(img, (X), (Y), &f_, (D)) ; }while(0)
//
// inline void _dla_plot(image img, int x, int y, rgb_color_p col, float br)
// {
//   rgb_color oc;
//   _dla_changebrightness(col, &oc, br);
//   put_pixel_clip(img, x, y, oc.red, oc.green, oc.blue);
// }
//
// #define ipart_(X) ((int)(X))
// #define round_(X) ((int)(((double)(X))+0.5))
// #define fpart_(X) (((double)(X))-(double)ipart_(X))
// #define rfpart_(X) (1.0-fpart_(X))
//
// #define swap_(a, b) do{ __typeof__(a) tmp;  tmp = a; a = b; b = tmp; }while(0)
// void draw_line_antialias(
//   image img,
//   unsigned int x1, unsigned int y1,
//   unsigned int x2, unsigned int y2,
//   color_component r,
//   color_component g,
//   color_component b )
// {
//   double dx = (double)x2 - (double)x1;
//   double dy = (double)y2 - (double)y1;
//   if ( fabs(dx) > fabs(dy) ) {
//     if ( x2 < x1 ) {
//       swap_(x1, x2);
//       swap_(y1, y2);
//     }
//     double gradient = dy / dx;
//     double xend = round_(x1);
//     double yend = y1 + gradient*(xend - x1);
//     double xgap = rfpart_(x1 + 0.5);
//     int xpxl1 = xend;
//     int ypxl1 = ipart_(yend);
//     plot_(xpxl1, ypxl1, rfpart_(yend)*xgap);
//     plot_(xpxl1, ypxl1+1, fpart_(yend)*xgap);
//     double intery = yend + gradient;
//
//     xend = round_(x2);
//     yend = y2 + gradient*(xend - x2);
//     xgap = fpart_(x2+0.5);
//     int xpxl2 = xend;
//     int ypxl2 = ipart_(yend);
//     plot_(xpxl2, ypxl2, rfpart_(yend) * xgap);
//     plot_(xpxl2, ypxl2 + 1, fpart_(yend) * xgap);
//
//     int x;
//     for(x=xpxl1+1; x < xpxl2; x++) {
//       plot_(x, ipart_(intery), rfpart_(intery));
//       plot_(x, ipart_(intery) + 1, fpart_(intery));
//       intery += gradient;
//     }
//   } else {
//     if ( y2 < y1 ) {
//       swap_(x1, x2);
//       swap_(y1, y2);
//     }
//     double gradient = dx / dy;
//     double yend = round_(y1);
//     double xend = x1 + gradient*(yend - y1);
//     double ygap = rfpart_(y1 + 0.5);
//     int ypxl1 = yend;
//     int xpxl1 = ipart_(xend);
//     plot_(xpxl1, ypxl1, rfpart_(xend)*ygap);
//     plot_(xpxl1 + 1, ypxl1, fpart_(xend)*ygap);
//     double interx = xend + gradient;
//
//     yend = round_(y2);
//     xend = x2 + gradient*(yend - y2);
//     ygap = fpart_(y2+0.5);
//     int ypxl2 = yend;
//     int xpxl2 = ipart_(xend);
//     plot_(xpxl2, ypxl2, rfpart_(xend) * ygap);
//     plot_(xpxl2 + 1, ypxl2, fpart_(xend) * ygap);
//
//     int y;
//     for(y=ypxl1+1; y < ypxl2; y++) {
//       plot_(ipart_(interx), y, rfpart_(interx));
//       plot_(ipart_(interx) + 1, y, fpart_(interx));
//       interx += gradient;
//     }
//   }
// }
// #undef swap_
// #undef plot_
// #undef ipart_
// #undef fpart_
// #undef round_
// #undef rfpart_

// swaps two numbers
void swap(int* a , int*b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// returns absolute value of number
float absolute(float x )
{
	if (x < 0) return -x;
	else return x;
}

//returns integer part of a floating point number
int iPartOfNumber(float x)
{
	return (int)x;
}

//rounds off a number
int roundNumber(float x)
{
	return iPartOfNumber(x + 0.5) ;
}

//returns fractional part of a number
float fPartOfNumber(float x)
{
	if (x>0) return x - iPartOfNumber(x);
	else return x - (iPartOfNumber(x)+1);

}

//returns 1 - fractional part of number
float rfPartOfNumber(float x)
{
	return 1 - fPartOfNumber(x);
}

uint32_t set_brightness(uint32_t color, float brightness)
{
	int	brightness_rgba;

	brightness_rgba = brightness * 255;
	return ((color & 0xFFFFFF00) | brightness_rgba);
}

void	draw_line(void *img, t_point *point_0, t_point *point_1)
{
// 	t_bres	aux;
//
// 	aux.dx = point_1->x - point_0->x;
// 	aux.dy = point_1->y - point_0->y;
// 	aux.abs_dx = abs(aux.dx);
// 	aux.abs_dy = abs(aux.dy);
// 	if (aux.abs_dx > aux.abs_dy)
// 		slope_lower_1(&aux, point_0, map);
// 	else
// 		slope_bigger_equal_1(&aux, point_0, map);
	int steep = absolute(point_1->y - point_0->y) > absolute(point_1->x - point_0->x);

	// swap the co-ordinates if slope > 1 or we
	// draw backwards
	if (steep)
	{
		swap(&point_0->x , &point_0->y);
		swap(&point_1->x , &point_1->y);
	}
	if (point_0->x > point_1->x)
	{
		swap(&point_0->x ,&point_1->x);
		swap(&point_0->y ,&point_1->y);
	}

	//compute the slope
	float dx = point_1->x-point_0->x;
	float dy = point_1->y-point_0->y;
	float gradient = dy/dx;
	if (dx == 0.0)
		gradient = 1;

	int xpxl1 = point_0->x;
	int xpxl2 = point_1->x;
	float intersectY = point_0->y;

	// main loop
	if (steep)
	{
		int x;
		for (x = xpxl1 ; x <=xpxl2 ; x++)
		{
			// pixel coverage is determined by fractional
			// part of y co-ordinate
			print_big_pixel(img, iPartOfNumber(intersectY), x,
						set_brightness(point_0->color, rfPartOfNumber(intersectY)));
			print_big_pixel(img, iPartOfNumber(intersectY) - 1, x,
						set_brightness(point_0->color, fPartOfNumber(intersectY)));
			intersectY += gradient;
		}
	}
	else
	{
		int x;
		for (x = xpxl1 ; x <=xpxl2 ; x++)
		{
			// pixel coverage is determined by fractional
			// part of y co-ordinate
			print_big_pixel(img, x, iPartOfNumber(intersectY),
						set_brightness(point_0->color, rfPartOfNumber(intersectY)));
			print_big_pixel(img, x, iPartOfNumber(intersectY) - 1,
						set_brightness(point_0->color, fPartOfNumber(intersectY)));
			intersectY += gradient;
		}
	}
}
