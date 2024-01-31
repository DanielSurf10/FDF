/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:47:30 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/31 16:57:46 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	transform_point(t_fdf *fdf_data, t_point *point)
{
	scale(fdf_data, point);
	rotate_z(fdf_data, point);
	rotate_x(fdf_data, point);
	rotate_y(fdf_data, point);
	move(fdf_data, point);
}

static void	draw_line(mlx_image_t *img, t_line line, int line_algorithm)
{
	if (line_algorithm == XIAOLIN)
		xiaolin_algorithm(img, line);
	else
		bresenham_algorithm(img, line);
}

static void	draw_row(t_fdf *fdf_data, t_map map, int line_pos)
{
	int		x;
	t_line	line;

	x = 0;
	while (x < fdf_data->map.width)
	{
		if ((x + 1) < fdf_data->map.width)
		{
			line.point_1 = get_node_map(&(map), x, line_pos);
			line.point_2 = get_node_map(&(map), x + 1, line_pos);
			draw_line(fdf_data->images[RENDER], line,
				fdf_data->camera.line_tracer);
		}
		if ((line_pos + 1) < fdf_data->map.height)
		{
			line.point_1 = get_node_map(&(map), x, line_pos);
			line.point_2 = get_node_map(&(map), x, line_pos + 1);
			draw_line(fdf_data->images[RENDER], line,
				fdf_data->camera.line_tracer);
		}
		x++;
	}
}

static t_map	get_tranformed_map(t_fdf *fdf_data)
{
	t_point	aux;
	t_point	point;
	t_point	*points_array;
	t_map	map;

	aux.y = 0;
	map.width = fdf_data->map.width;
	map.height = fdf_data->map.height;
	points_array = malloc(map.width * map.height * sizeof(t_point));
	map.map = points_array;
	while (aux.y < map.height)
	{
		aux.x = 0;
		while (aux.x < map.width)
		{
			point = get_node_map(&(fdf_data->map), aux.x, aux.y);
			transform_point(fdf_data, &point);
			set_node_map(&map, point, aux.x, aux.y);
			aux.x++;
		}
		aux.y++;
	}
	return (map);
}

void	render(t_fdf *fdf_data)
{
	int		line;
	t_map	map;

	map = get_tranformed_map(fdf_data);
	line = 0;
	while (line < fdf_data->map.height)
	{
		draw_row(fdf_data, map, line);
		line++;
	}
	free(map.map);
}
