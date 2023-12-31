/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_hooks_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:39:56 by cogata            #+#    #+#             */
/*   Updated: 2023/12/31 14:56:50 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf_bonus.h"

void	rotate(t_map *map)
{
	if (mlx_is_key_down(map->mlx, MLX_KEY_A))
		map->position.x_angle += 2;
	if (mlx_is_key_down(map->mlx, MLX_KEY_D))
		map->position.x_angle -= 2;
	if (mlx_is_key_down(map->mlx, MLX_KEY_W))
		map->position.y_angle += 2;
	if (mlx_is_key_down(map->mlx, MLX_KEY_S))
		map->position.y_angle -= 2;
	if (mlx_is_key_down(map->mlx, MLX_KEY_K))
		map->position.z_angle += 2;
	if (mlx_is_key_down(map->mlx, MLX_KEY_J))
		map->position.z_angle -= 2;
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

void	ft_hook(void *param)
{
	t_map	*map;

	map = param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_F10))
		map->line_render = map->line_render == 0 ? 1 : 0;
	translate_zoom_close(map);
	rotate(map);
	projection(map);
	increase_descrease_z(map);
	mlx_delete_image(map->mlx, map->mlx_image);
	map->mlx_image = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(map->mlx, map->mlx_image, 0, 0);
	randomize(map);
}
