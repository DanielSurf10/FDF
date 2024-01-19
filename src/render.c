/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:47:30 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/19 18:35:34 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line(mlx_image_t *img, t_line line)
{

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
				transform_line(fdf_data, &line);
				draw_line(fdf_data->images[RENDER], line);
			}

			if ((aux.y + 1) < fdf_data->map.height)
			{
				line.point_2 = get_node_map(&(fdf_data->mlx), aux.x, aux.y + 1);
				transform_line(fdf_data, &line);
				draw_line(fdf_data->images[RENDER], line);
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
