/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:47:30 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/23 15:51:38 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ternary(int condition, int if_true, int if_false)
{
	if (condition)
		return (if_true);
	return (if_false);
}

static void	put_pixel(mlx_image_t *img, t_point point)
{
	if (point.x >= 0 && point.x < WIDTH && point.y >= 0 && point.y < HEIGHT)
		mlx_put_pixel(img, point.x, point.y, point.color.color_int);
}

static void	draw_line(mlx_image_t *img, t_line line)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	error;
	int	e2;

	int	x0 = line.point_1.x;
	int	y0 = line.point_1.y;
	int	x1 = line.point_2.x;
	int	y1 = line.point_2.y;
	t_point	aux;
	t_point	delta;

	delta.x = abs(line.point_2.x - line.point_1.x);
	delta.y = abs(line.point_2.y - line.point_1.y);
	dx = abs(x1 - x0);
	dy = -abs(y1 - y0);
	sx = ternary(x0 < x1, 1, -1);
	sy = ternary(y0 < y1, 1, -1);
	error = dx + dy;
	while (1)
	{
		aux.x = x0;
		aux.y = y0;
		aux.color = get_color_gradient(aux, line.point_1, line.point_2, delta);
		aux.color.color_struct.a = -1;

		put_pixel(img, aux);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * error;
		if (e2 >= dy)
		{
			if (x0 == x1)
				break ;
			error += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			if (y0 == y1)
				break ;
			error += dx;
			y0 += sy;
		}
	}
}

void	render(t_fdf *fdf_data)
{
	t_point	aux;
	t_point	tmp_point_row;
	t_line	line;

	aux.y = 0;
	while (aux.y < fdf_data->map.height)
	{
		tmp_point_row = get_node_map(&(fdf_data->map), 0, aux.y);
		transform_point(fdf_data, &(tmp_point_row));
		aux.x = 0;
		while (aux.x < fdf_data->map.width)
		{
			// line.point_1 = tmp_point_row;				// Esse negocio tá bugado
			// if ((aux.x + 1) < fdf_data->map.width)
			// {
			// 	line.point_2 = get_node_map(&(fdf_data->map), aux.x + 1, aux.y);
			// 	transform_point(fdf_data, &(line.point_2));
			// 	tmp_point_row = line.point_2;
			// 	draw_line(fdf_data->images[RENDER], line);
			// }
			// if ((aux.y + 1) < fdf_data->map.height)
			// {
			// 	line.point_2 = get_node_map(&(fdf_data->map), aux.x, aux.y + 1);
			// 	transform_point(fdf_data, &(line.point_2));
			// 	draw_line(fdf_data->images[RENDER], line);
			// }

			if ((aux.x + 1) < fdf_data->map.width)
			{
				line.point_1 = get_node_map(&(fdf_data->map), aux.x, aux.y);
				line.point_2 = get_node_map(&(fdf_data->map), aux.x + 1, aux.y);
				line.point_1.z *= fdf_data->camera.z_factor;
				line.point_2.z *= fdf_data->camera.z_factor;
				transform_line(fdf_data, &line);
				draw_line(fdf_data->images[RENDER], line);
			}

			if ((aux.y + 1) < fdf_data->map.height)
			{
				line.point_1 = get_node_map(&(fdf_data->map), aux.x, aux.y);
				line.point_2 = get_node_map(&(fdf_data->map), aux.x, aux.y + 1);
				line.point_1.z *= fdf_data->camera.z_factor;
				line.point_2.z *= fdf_data->camera.z_factor;
				transform_line(fdf_data, &line);
				draw_line(fdf_data->images[RENDER], line);
			}
			aux.x++;
		}
		aux.y++;
	}



	// while (h < map->height)
	// {
	// 	w = 0;
	// 	while (w < map->width)
	// 	{
	// 		if ((w + 1) < map->width)
	// 			init_points(w, h, 'w', map);
	// 		if ((h + 1) < map->height)
	// 			init_points(w, h, 'h', map);
	// 		w++;
	// 	}
	// 	h++;
	// }
}
