/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:31:38 by dpoveda-          #+#    #+#             */
/*   Updated: 2024/01/01 18:05:58 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft/ft_mem.h>
#include <mlx.h>
#include <math.h>
#include <stdint.h>

static void	draw_menu(t_vars *vars)
{
	int		y;
	void	*mlx;
	void	*win;

	mlx = vars->mlx;
	win = vars->win;
	y = 0;
	mlx_string_put(mlx, win, 15, y += 15, WHITE, "Controls:");
	mlx_string_put(mlx, win, 15, y += 50, WHITE, "Reset: R");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Move: W, A, S, D");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Zoom: Arrows");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Flattening: + / -");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Rotate:");
	mlx_string_put(mlx, win, 30, y += 25, WHITE, "  x (+ / -): U / J");
	mlx_string_put(mlx, win, 30, y += 25, WHITE, "  y (+ / -): I / K");
	mlx_string_put(mlx, win, 30, y += 25, WHITE, "  z (+ / -): O / L");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Toggle Perspective: P");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "(Isometric and Parallel)");
}

static int	ft_abs(int a)
{
	if (a < 0)
		return (-(a));
	return (a);
}

static void	initialise_bresenham(t_point *start, t_point *end,
	t_point *delta, t_point *sign)
{
	delta->x = ft_abs(end->x - start->x);
	delta->y = ft_abs(end->y - start->y);
	sign->x = -1;
	sign->y = -1;
	if (start->x < end->x)
		sign->x = 1;
	if (start->y < end->y)
		sign->y = 1;
}

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
	// printf("%d\n", brightness_rgba);
	return ((color << 8) | brightness_rgba);
}

t_point	new_point_aux(int x, int y)
{
	t_point	out;

	out.x = x;
	out.y = y;
	out.z = 0;
	return (out);
}

#define ipart_(X) ((int)(X))
#define round_(X) ((int)(((double)(X))+0.5))
#define fpart_(X) (((double)(X))-(double)ipart_(X))
#define rfpart_(X) (1.0-fpart_(X))
#define swap_(a, b) do{ __typeof__(a) tmp;	tmp = a; a = b; b = tmp; }while(0)

static void	bresenham(t_vars *vars, t_point point_0, t_point point_1)
{
	t_point	cur;
	t_point	sign;
	t_point	delta;
	int		line;
	int		tmp;

	initialise_bresenham(&point_0, &point_1, &delta, &sign);
	if (vars->line_tracer == 0)
	{
		line = delta.x - delta.y;
		cur = point_0;
		while (cur.x != point_1.x || cur.y != point_1.y)
		{
			img_pixel_put(vars, cur.x, cur.y, get_color(cur, point_0, point_1, delta));
			tmp = line * 2;
			if (tmp > -delta.y)
			{
				line -= delta.y;
				cur.x += sign.x;
			}
			if (tmp < delta.x)
			{
				line += delta.x;
				cur.y += sign.y;
			}
		}
	}
	else
	{
// 		int steep = absolute(point_1.y - point_0.y) > absolute(point_1.x - point_0.x);
//
// 		// swap the co-ordinates if slope > 1 or we
// 		// draw backwards
// 		if (steep)
// 		{
// 			swap(&point_0.x , &point_0.y);
// 			swap(&point_1.x , &point_1.y);
// 		}
// 		if (point_0.x > point_1.x)
// 		{
// 			swap(&point_0.x ,&point_1.x);
// 			swap(&point_0.y ,&point_1.y);
// 		}
//
// 		//compute the slope
// 		float dx = point_1.x-point_0.x;
// 		float dy = point_1.y-point_0.y;
// 		float gradient = dy/dx;
// 		if (dx == 0.0)
// 			gradient = 1;
//
// 		int xpxl1 = point_0.x;
// 		int xpxl2 = point_1.x;
// 		float intersectY = point_0.y;
//
// 		// main loop
// 		if (steep)
// 		{
// 			int x;
// 			for (x = xpxl1 ; x <=xpxl2 ; x++)
// 			{
// 				// pixel coverage is determined by fractional
// 				// part of y co-ordinate
// 				cur.x = iPartOfNumber(intersectY);
// 				cur.y = x;
// 				// cur.color = get_color(cur, point_0, point_1, delta);
// 				cur.color = point_0.color;
// 				img_pixel_put(vars, cur.x, cur.y,
// 							get_brightness(cur.color, rfPartOfNumber(intersectY)));
// 				cur.x = iPartOfNumber(intersectY) - 1;
// 				cur.y = x;
// 				// cur.color = get_color(cur, point_0, point_1, delta);
// 				cur.color = point_0.color;
// 				img_pixel_put(vars, cur.x, cur.y,
// 							get_brightness(cur.color, fPartOfNumber(intersectY)));
// 				intersectY += gradient;
// 			}
// 		}
// 		else
// 		{
// 			int x;
// 			for (x = xpxl1 ; x <=xpxl2 ; x++)
// 			{
// 				// pixel coverage is determined by fractional
// 				// part of y co-ordinate
// 				cur.x = x;
// 				cur.y =iPartOfNumber(intersectY);
// 				// cur.color = get_color(cur, point_0, point_1, delta);
// 				cur.color = point_0.color;
// 				img_pixel_put(vars, cur.x, cur.y,
// 							get_brightness(cur.color, rfPartOfNumber(intersectY)));
// 				cur.x = x;
// 				cur.y = iPartOfNumber(intersectY) - 1;
// 				// cur.color = get_color(cur, point_0, point_1, delta);
// 				cur.color = point_0.color;
// 				img_pixel_put(vars, cur.x, cur.y,
// 							get_brightness(cur.color, fPartOfNumber(intersectY)));
// 				intersectY += gradient;
// 			}
// 		}

		int		x1 = point_0.x;
		int		x2 = point_1.x;
		int		y1 = point_0.y;
		int		y2 = point_1.y;
		t_point	cur;

		double dx = (double)x2 - (double)x1;
		double dy = (double)y2 - (double)y1;

		if ( absolute(dx) > absolute(dy) ) {
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


			cur = new_point_aux(xpxl1, ypxl1);
			cur.color = set_brightness(get_color(cur, point_0, point_1, delta), rfpart_(yend)*xgap);
			img_pixel_put(vars, xpxl1, ypxl1, cur.color);

			cur = new_point_aux(xpxl1, ypxl1 + 1);
			cur.color = set_brightness(get_color(cur, point_0, point_1, delta), rfpart_(yend)*xgap);
			img_pixel_put(vars, xpxl1, ypxl1 + 1, cur.color);


			double intery = yend + gradient;

			xend = round_(x2);
			yend = y2 + gradient*(xend - x2);
			xgap = fpart_(x2+0.5);
			int xpxl2 = xend;
			int ypxl2 = ipart_(yend);

			cur = new_point_aux(xpxl2, ypxl2);
			cur.color = set_brightness(get_color(cur, point_0, point_1, delta), rfpart_(yend)*xgap);
			img_pixel_put(vars, xpxl2, ypxl2, cur.color);

			cur = new_point_aux(xpxl2, ypxl2 + 1);
			cur.color = set_brightness(get_color(cur, point_0, point_1, delta), rfpart_(yend)*xgap);
			img_pixel_put(vars, xpxl2, ypxl2 + 1, cur.color);

			int x;
			for(x=xpxl1+1; x < xpxl2; x++) {

				cur = new_point_aux(x, ipart_(intery));
				cur.color = set_brightness(get_color(cur, point_0, point_1, delta), rfpart_(intery));
				img_pixel_put(vars, x, ipart_(intery), cur.color);

				cur = new_point_aux(x, ipart_(intery) + 1);
				cur.color = set_brightness(get_color(cur, point_0, point_1, delta), fpart_(intery));
				img_pixel_put(vars, x, ipart_(intery) + 1, cur.color);


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

			cur = new_point_aux(xpxl1, ypxl1);
			cur.color = set_brightness(get_color(cur, point_0, point_1, delta), rfpart_(xend)*ygap);
			img_pixel_put(vars, xpxl1, ypxl1, cur.color);

			cur = new_point_aux(xpxl1 + 1, ypxl1);
			cur.color = set_brightness(get_color(cur, point_0, point_1, delta), fpart_(xend)*ygap);
			img_pixel_put(vars, xpxl1 + 1, ypxl1, cur.color);
			double interx = xend + gradient;

			yend = round_(y2);
			xend = x2 + gradient*(yend - y2);
			ygap = fpart_(y2+0.5);
			int ypxl2 = yend;
			int xpxl2 = ipart_(xend);

			cur = new_point_aux(xpxl2, ypxl2);
			cur.color = set_brightness(get_color(cur, point_0, point_1, delta), rfpart_(xend) * ygap);
			img_pixel_put(vars, xpxl2, ypxl2, cur.color);

			cur = new_point_aux(xpxl2 + 1, ypxl2);
			cur.color = set_brightness(get_color(cur, point_0, point_1, delta), fpart_(xend) * ygap);
			img_pixel_put(vars, xpxl2 + 1, ypxl2, cur.color);

			int y;
			for(y=ypxl1+1; y < ypxl2; y++) {

				cur = new_point_aux(ipart_(interx), y);
				cur.color = set_brightness(get_color(cur, point_0, point_1, delta), rfpart_(interx));
				img_pixel_put(vars, ipart_(interx), y, cur.color);

				cur = new_point_aux(ipart_(interx) + 1, y);
				cur.color = set_brightness(get_color(cur, point_0, point_1, delta), fpart_(interx));
				img_pixel_put(vars, ipart_(interx) + 1, y, cur.color);
				interx += gradient;
			}
		}
	}
}

void	draw(t_vars *vars)
{
	int	x;
	int	y;

	ft_bzero(vars->img->addr, WIN_H * WIN_W * (vars->img->bpp / 8));
	if (vars->zoom)
	{
		y = -1;
		while (++y < vars->map->h)
		{
			x = -1;
			while (++x < vars->map->w)
			{
				if (x < vars->map->w - 1)
					bresenham(vars,
						get_coords(vars, new_point(x, y, vars)),
						get_coords(vars, new_point(x + 1, y, vars)));
				if (y < vars->map->h - 1)
					bresenham(vars,
						get_coords(vars, new_point(x, y, vars)),
						get_coords(vars, new_point(x, y + 1, vars)));
			}
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	draw_menu(vars);
}
