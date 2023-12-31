/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   11_bresenham.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: danbarbo <danbarbo@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/11/16 13:58:02 by cogata			#+#	#+#			 */
/*   Updated: 2023/12/30 13:57:18 by danbarbo		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../include/fdf.h"
#include <stdio.h>

void	put_valid_pixel(t_map *map, int x, int y, uint32_t color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		mlx_put_pixel(map->mlx_image, x, y, color);
}

void	check_delta_to_move_variable(int d, int *variable)
{
	if (d < 0)
		*variable = *variable - 1;
	else
		*variable = *variable + 1;
}

void	slope_lower_1(t_bres *aux, t_coordinate *point, t_map *map)
{
	int			x;
	int			y;
	uint32_t	color;
	int			i;

	x = point->x;
	y = point->y;
	color = point->color;
	aux->p = 2 * aux->dy - aux->dx;
	i = 0;
	while (i < aux->abs_dx)
	{
		check_delta_to_move_variable(aux->dx, &x);
		if (aux->p < 0)
			aux->p = aux->p + 2 * aux->abs_dy;
		else
		{
			check_delta_to_move_variable(aux->dy, &y);
			aux->p = aux->p + (2 * aux->abs_dy - 2 * aux->abs_dx);
		}
		put_valid_pixel(map, x, y, color);
		i++;
	}
}

void	slope_bigger_equal_1(t_bres *aux, t_coordinate *point, t_map *map)
{
	int			x;
	int			y;
	uint32_t	color;
	int			i;

	x = point->x;
	y = point->y;
	color = point->color;
	aux->p = 2 * aux->dx - aux->dy;
	i = 0;
	while (i < aux->abs_dy)
	{
		check_delta_to_move_variable(aux->dy, &y);
		if (aux->p < 0)
			aux->p = aux->p + 2 * aux->abs_dx;
		else
		{
			check_delta_to_move_variable(aux->dx, &x);
			aux->p = aux->p + (2 * aux->abs_dx - 2 * aux->abs_dy);
		}
		put_valid_pixel(map, x, y, color);
		i++;
	}
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
	return (0xFFFFFF00 | brightness_rgba);
}

void	bresenham(t_coordinate *point_0, t_coordinate *point_1, t_map *map)
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
			put_valid_pixel(map, iPartOfNumber(intersectY), x,
						set_brightness(point_0->color, rfPartOfNumber(intersectY)));
			put_valid_pixel(map, iPartOfNumber(intersectY) - 1, x,
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
			put_valid_pixel(map, x, iPartOfNumber(intersectY),
						set_brightness(point_0->color, rfPartOfNumber(intersectY)));
			put_valid_pixel(map, x, iPartOfNumber(intersectY) - 1,
						set_brightness(point_0->color, fPartOfNumber(intersectY)));
			intersectY += gradient;
		}
	}
}
