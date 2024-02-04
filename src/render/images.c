/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:11:32 by danbarbo          #+#    #+#             */
/*   Updated: 2024/02/04 20:03:30 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_images_in_window(t_fdf *fdf_data)
{
	mlx_image_to_window(fdf_data->mlx, fdf_data->images[BACKGROUND], 0, 0);
	mlx_image_to_window(fdf_data->mlx, fdf_data->images[RENDER], 0, 0);
	mlx_set_instance_depth(fdf_data->images[BACKGROUND]->instances, 0);
	mlx_set_instance_depth(fdf_data->images[RENDER]->instances, 1);
}

static void	set_background(t_fdf *fdf_data)
{
	t_point	i;

	i.x = -1;
	i.color = BACKGROUND_COLOR;
	while (++i.x < WIDTH)
	{
		i.y = -1;
		while (++i.y < HEIGHT)
			put_pixel(fdf_data->images[BACKGROUND], i);
	}
}

void	create_images(t_fdf *fdf_data)
{
	fdf_data->images[BACKGROUND] = mlx_new_image(fdf_data->mlx, WIDTH, HEIGHT);
	fdf_data->images[RENDER] = mlx_new_image(fdf_data->mlx, WIDTH, HEIGHT);
	put_images_in_window(fdf_data);
	set_background(fdf_data);
}
