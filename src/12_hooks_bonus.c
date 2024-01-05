/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_hooks_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:39:56 by cogata            #+#    #+#             */
/*   Updated: 2024/01/05 17:46:41 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	rotate(t_map *map)
{
	if ((mlx_is_key_down(map->mlx, MLX_KEY_W) && (map->auto_transform_x & 2) == 0)
		|| map->auto_transform_x == 1)
		map->position.x_angle += 0.7;
	else if ((mlx_is_key_down(map->mlx, MLX_KEY_S) && (map->auto_transform_x & 2) == 0)
		|| map->auto_transform_x == 2)
		map->position.x_angle -= 0.7;
	if ((mlx_is_key_down(map->mlx, MLX_KEY_E) && (map->auto_transform_y & 2) == 0)
		|| map->auto_transform_y == 1)
		map->position.y_angle += 0.7;
	if ((mlx_is_key_down(map->mlx, MLX_KEY_Q) && (map->auto_transform_y & 2) == 0)
		|| map->auto_transform_y == 2)
		map->position.y_angle -= 0.7;
	if ((mlx_is_key_down(map->mlx, MLX_KEY_D) && (map->auto_transform_z & 2) == 0)
		|| map->auto_transform_z == 1)
		map->position.z_angle += 0.7;
	if ((mlx_is_key_down(map->mlx, MLX_KEY_A) && (map->auto_transform_z & 2) == 0)
		|| map->auto_transform_z == 2)
		map->position.z_angle -= 0.7;

}

void	projection(t_map *map)
{
	if (mlx_is_key_down(map->mlx, MLX_KEY_F1))
		map->position.projection = '1';
	if (mlx_is_key_down(map->mlx, MLX_KEY_F2))
	{
		map->position.projection = '2';
		map->position.x_angle = 0;
		map->position.y_angle = 0;
		map->position.z_angle = 0;
	}
}

void	increase_descrease_z(t_map *map)
{
	if (mlx_is_key_down(map->mlx, MLX_KEY_KP_MULTIPLY))
		map->position.z_factor *= 1.1;
	if (mlx_is_key_down(map->mlx, MLX_KEY_KP_DIVIDE))
		map->position.z_factor /= 1.1;
}

void	translate_zoom_close(t_map *map)
{
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
		map->position.y_offset -= 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
		map->position.y_offset += 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
		map->position.x_offset -= 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		map->position.x_offset += 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_EQUAL))
		map->position.scale *= 1.05;
	if (mlx_is_key_down(map->mlx, MLX_KEY_MINUS))
		map->position.scale /= 1.05;
}

void	key_hook(mlx_key_data_t keydata, void* param)
{
	t_map	*map;

	map = param;
	if (keydata.key == MLX_KEY_F10 && keydata.action == MLX_PRESS)
		map->line_render = map->line_render == 0 ? 1 : 0;

	if (keydata.key == MLX_KEY_Z && keydata.action == MLX_PRESS)
		map->auto_transform_x += ((map->auto_transform_x) == 2 ? 2 : 1);

	if (keydata.key == MLX_KEY_X && keydata.action == MLX_PRESS)
		map->auto_transform_y += ((map->auto_transform_y) == 2 ? 2 : 1);

	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		map->auto_transform_z += ((map->auto_transform_z) == 2 ? 2 : 1);
		// if ((map->auto_transform_z & 2) == 2)
		// 	map->auto_transform_z = 0;
		// else
		// 	map->auto_transform_z++;


}

void	ft_hook(void *param)
{
	double	start;
	double	count_time;
	double	end;
	double	delta_time;
	t_map	*map;

	map = param;
	start = mlx_get_time();

	// if (map->frame == 1)
	// {
	// 	map->position.z_angle += 0.3;
	// 	map->position.y_angle += 0.5;
	// 	map->frame = 0;
	// }

	// if (mlx_is_key_down(map->mlx, MLX_KEY_F10) && (map->line_render & 2) == 0)
	// 	map->line_render = map->line_render == 0 ? 1 : 0;
	// if (mlx_is_key_down(map->mlx, MLX_KEY_F10))
	// 	map->line_render = map->line_render | 2;
	// else
	// 	map->line_render = map->line_render & 1;

	if (mlx_is_key_down(map->mlx, MLX_KEY_F9))
	{
		printf("1 - %f %f %f\n", map->position.x_angle, map->position.y_angle, map->position.z_angle);
		printf("2 - %d %d %f\n", map->position.x_offset, map->position.y_offset, map->position.z_factor);
	}

	translate_zoom_close(map);
	rotate(map);
	projection(map);
	increase_descrease_z(map);
	mlx_delete_image(map->mlx, map->mlx_image);
	map->mlx_image = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(map->mlx, map->mlx_image, 0, 0);
	randomize(map);

	map->frame += 1;

	end = mlx_get_time();
	delta_time = end - start;

	count_time = mlx_get_time();
	while (delta_time <= ((1000.0 / 60) / 1000.0))
	{
		// count_time++;
		end = mlx_get_time();
		delta_time = end - start;
	}

	// printf("%f %f\n", mlx_get_time() - count_time, map->mlx->delta_time);
	printf("%u %u %u\n", map->auto_transform_x, map->auto_transform_y, map->auto_transform_z);
}
