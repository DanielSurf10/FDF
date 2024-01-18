/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:47:30 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/18 19:35:33 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	transform_line(t_fdf *fdf_data, t_line line)
{
	point_1->x *= map->position.scale;
	point_1->y *= map->position.scale;
	point_2->x *= map->position.scale;
	point_2->y *= map->position.scale;
}

void	render(t_fdf *fdf_data)
{
	t_point	aux;
	t_line	line;

	aux.y = 0;
	while (aux.y < fdf_data->map.height)
	{
		aux.x = 0;
		while (aux.x < fdf_data->map.width)
		{
			line.point_1 = get_node_map(&(fdf_data->mlx), aux.x, aux.y);
			if ((aux.x + 1) < fdf_data->map.width)
			{
				line.point_2 = get_node_map(&(fdf_data->mlx), aux.x + 1, aux.y);
				transform_line(fdf_data, line);
				draw_line(fdf_data->images[RENDER], &(line.point_1), &(line.point_2));
			}


			if ((aux.y + 1) < fdf_data->map.height)
			{
				line.point_2 = get_node_map(&(fdf_data->mlx), aux.x, aux.y + 1);
				transform_line(fdf_data, line);
				draw_line(fdf_data->images[RENDER], &(line.point_1), &(line.point_2));
			}
			aux.x++;
		}
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
