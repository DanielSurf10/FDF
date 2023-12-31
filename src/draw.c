/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:31:38 by dpoveda-          #+#    #+#             */
/*   Updated: 2023/12/30 15:47:56 by danbarbo         ###   ########.fr       */
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

uint32_t get_brightness(uint32_t color, float brightness)
{
	int	brightness_rgba;

	brightness_rgba = brightness * 255;
	// printf("%d\n", brightness_rgba);
	return ((color & 0xFFFFFF00) | brightness_rgba);
}

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
		int steep = absolute(point_1.y - point_0.y) > absolute(point_1.x - point_0.x);

		// swap the co-ordinates if slope > 1 or we
		// draw backwards
		if (steep)
		{
			swap(&point_0.x , &point_0.y);
			swap(&point_1.x , &point_1.y);
		}
		if (point_0.x > point_1.x)
		{
			swap(&point_0.x ,&point_1.x);
			swap(&point_0.y ,&point_1.y);
		}

		//compute the slope
		float dx = point_1.x-point_0.x;
		float dy = point_1.y-point_0.y;
		float gradient = dy/dx;
		if (dx == 0.0)
			gradient = 1;

		int xpxl1 = point_0.x;
		int xpxl2 = point_1.x;
		float intersectY = point_0.y;

		// main loop
		if (steep)
		{
			int x;
			for (x = xpxl1 ; x <=xpxl2 ; x++)
			{
				// pixel coverage is determined by fractional
				// part of y co-ordinate
				cur.x = iPartOfNumber(intersectY);
				cur.y = x;
				// cur.color = get_color(cur, point_0, point_1, delta);
				cur.color = point_0.color;
				img_pixel_put(vars, cur.x, cur.y,
							get_brightness(cur.color, rfPartOfNumber(intersectY)));
				cur.x = iPartOfNumber(intersectY) - 1;
				cur.y = x;
				// cur.color = get_color(cur, point_0, point_1, delta);
				cur.color = point_0.color;
				img_pixel_put(vars, cur.x, cur.y,
							get_brightness(cur.color, fPartOfNumber(intersectY)));
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
				cur.x = x;
				cur.y =iPartOfNumber(intersectY);
				// cur.color = get_color(cur, point_0, point_1, delta);
				cur.color = point_0.color;
				img_pixel_put(vars, cur.x, cur.y,
							get_brightness(cur.color, rfPartOfNumber(intersectY)));
				cur.x = x;
				cur.y = iPartOfNumber(intersectY) - 1;
				// cur.color = get_color(cur, point_0, point_1, delta);
				cur.color = point_0.color;
				img_pixel_put(vars, cur.x, cur.y,
							get_brightness(cur.color, fPartOfNumber(intersectY)));
				intersectY += gradient;
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
