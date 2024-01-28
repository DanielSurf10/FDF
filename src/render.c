/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:47:30 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/27 21:58:52 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	transform_line(t_fdf *fdf_data, t_line *line)
// {
// 	scale(fdf_data, &(line->point_1));
// 	scale(fdf_data, &(line->point_2));
// 	rotate_z(fdf_data, &(line->point_1));
// 	rotate_z(fdf_data, &(line->point_2));
// 	rotate_x(fdf_data, &(line->point_1));
// 	rotate_x(fdf_data, &(line->point_2));
// 	rotate_y(fdf_data, &(line->point_1));
// 	rotate_y(fdf_data, &(line->point_2));
// 	move(fdf_data, &(line->point_1));
// 	move(fdf_data, &(line->point_2));
// }

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
	t_point	aux;
	// t_point	tmp_point_row;
	t_line	line;
	t_map	map;

	map = get_tranformed_map(fdf_data);
	aux.y = 0;
	while (aux.y < fdf_data->map.height)
	{
		// tmp_point_row = get_node_map(&(fdf_data->map), 0, aux.y);
		// transform_point(fdf_data, &(tmp_point_row));
		aux.x = 0;
		while (aux.x < fdf_data->map.width)
		{
			// line.point_1 = tmp_point_row;
			// if ((aux.x + 1) < fdf_data->map.width)
			// {
			// 	line.point_2 = get_node_map(&(fdf_data->map), aux.x + 1, aux.y);
			// 	transform_point(fdf_data, &(line.point_2));
			// 	tmp_point_row = line.point_2;
			// 	draw_line(fdf_data->images[RENDER], line, fdf_data->camera.line_tracer);
			// }
			// if ((aux.y + 1) < fdf_data->map.height)
			// {
			// 	line.point_2 = get_node_map(&(fdf_data->map), aux.x, aux.y + 1);
			// 	transform_point(fdf_data, &(line.point_2));
			// 	draw_line(fdf_data->images[RENDER], line, fdf_data->camera.line_tracer);
			// }

// 			if ((aux.x + 1) < fdf_data->map.width)
// 			{
// 				line.point_1 = get_node_map(&(fdf_data->map), aux.x, aux.y);
// 				line.point_2 = get_node_map(&(fdf_data->map), aux.x + 1, aux.y);
// 				transform_line(fdf_data, &line);
// 				draw_line(fdf_data->images[RENDER], line, fdf_data->camera.line_tracer);
// 			}
//
// 			if ((aux.y + 1) < fdf_data->map.height)
// 			{
// 				line.point_1 = get_node_map(&(fdf_data->map), aux.x, aux.y);
// 				line.point_2 = get_node_map(&(fdf_data->map), aux.x, aux.y + 1);
// 				transform_line(fdf_data, &line);
// 				draw_line(fdf_data->images[RENDER], line, fdf_data->camera.line_tracer);
// 			}

			if ((aux.x + 1) < fdf_data->map.width)
			{
				line.point_1 = get_node_map(&(map), aux.x, aux.y);
				line.point_2 = get_node_map(&(map), aux.x + 1, aux.y);
				draw_line(fdf_data->images[RENDER], line, fdf_data->camera.line_tracer);
			}

			if ((aux.y + 1) < fdf_data->map.height)
			{
				line.point_1 = get_node_map(&(map), aux.x, aux.y);
				line.point_2 = get_node_map(&(map), aux.x, aux.y + 1);
				draw_line(fdf_data->images[RENDER], line, fdf_data->camera.line_tracer);
			}
			aux.x++;
		}
		aux.y++;
	}

	free(map.map);

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
