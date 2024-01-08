/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_hooks_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:39:56 by cogata            #+#    #+#             */
/*   Updated: 2024/01/08 01:33:17 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	is_auto_on(t_map *map)
{
	if (map->auto_transform_x != 0
		|| map->auto_transform_y != 0
		|| map->auto_transform_z != 0)
		return (1);
	return (0);
}

void	rotate(t_map *map)		// Algumas condiçõs a mais para garantir que não gire errado quando tiver no top view
{
	if ((mlx_is_key_down(map->mlx, MLX_KEY_W) && !is_auto_on(map) && map->position.projection != '3')
		|| map->auto_transform_x == 1 && map->position.projection != '3')
		map->position.x_angle += 0.7;
	if ((mlx_is_key_down(map->mlx, MLX_KEY_S) && !is_auto_on(map) && map->position.projection != '3')
		|| map->auto_transform_x == 2 && map->position.projection != '3')
		map->position.x_angle -= 0.7;
	if ((mlx_is_key_down(map->mlx, MLX_KEY_E) && !is_auto_on(map) && map->position.projection != '3')
		|| map->auto_transform_y == 1 && map->position.projection != '3')
		map->position.y_angle += 0.7;
	if ((mlx_is_key_down(map->mlx, MLX_KEY_Q) && !is_auto_on(map) && map->position.projection != '3')
		|| map->auto_transform_y == 2 && map->position.projection != '3')
		map->position.y_angle -= 0.7;
	if ((mlx_is_key_down(map->mlx, MLX_KEY_D) && !is_auto_on(map))
		|| map->auto_transform_z == 1)
		map->position.z_angle += 0.7;
	if ((mlx_is_key_down(map->mlx, MLX_KEY_A) && !is_auto_on(map))
		|| map->auto_transform_z == 2)
		map->position.z_angle -= 0.7;
}

void	projection(t_map *map)
{
	// if (mlx_is_key_down(map->mlx, MLX_KEY_F1))
	// 	map->position.projection = '1';
	// if (mlx_is_key_down(map->mlx, MLX_KEY_F2) || mlx_is_key_down(map->mlx, MLX_KEY_F3))
	// {
	// 	if (mlx_is_key_down(map->mlx, MLX_KEY_F2))
	// 		map->position.projection = '2';
	// 	else if (mlx_is_key_down(map->mlx, MLX_KEY_F3))
	// 		map->position.projection = '3';
	// 	map->position.x_angle = 0;
	// 	map->position.y_angle = 0;
	// 	map->position.z_angle = 0;
	// }
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

	if (mlx_is_key_down(map->mlx, MLX_KEY_UP) || mlx_is_key_down(map->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(map->mlx, MLX_KEY_LEFT) || mlx_is_key_down(map->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(map->mlx, MLX_KEY_EQUAL) || mlx_is_key_down(map->mlx, MLX_KEY_MINUS))
	{
		ft_bzero(map->mlx_image_projection->pixels, WIDTH * HEIGHT * sizeof(int32_t));
		ft_bzero(map->mlx_image_front->pixels, WIDTH * HEIGHT * sizeof(int32_t));
		ft_bzero(map->mlx_image_left->pixels, WIDTH * HEIGHT * sizeof(int32_t));
		ft_bzero(map->mlx_image_top->pixels, WIDTH * HEIGHT * sizeof(int32_t));
	}
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
		// if ((map->auto_transform_z) == 2)
		// 	map->auto_transform_z = 2;
		// else
		// 	map->auto_transform_z += 1;

	if (keydata.key == MLX_KEY_V && keydata.action == MLX_PRESS)
	{
		map->auto_transform_x = 0;
		map->auto_transform_y = 0;
		map->auto_transform_z = 0;
	}
	if (keydata.key == MLX_KEY_F1 && keydata.action == MLX_PRESS)
		map->position.projection = '1';
	if ((keydata.key == MLX_KEY_F2 || keydata.key == MLX_KEY_F3)
		&& keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_F2)
			map->position.projection = '2';
		else if (keydata.key == MLX_KEY_F3)
			map->position.projection = '3';
		map->position.x_angle = 0;
		map->position.y_angle = 0;
		map->position.z_angle = 0;
	}

	if ((keydata.key == MLX_KEY_F1 || keydata.key == MLX_KEY_F2 || keydata.key == MLX_KEY_F3)
		&& keydata.action == MLX_PRESS)
	{
		map->mlx_image->enabled = 1;
		map->mlx_image_front->enabled = 0;
		map->mlx_image_left->enabled = 0;
		map->mlx_image_top->enabled = 0;
		map->mlx_image_projection->enabled = 0;
	}

	if (keydata.key == MLX_KEY_F4 && keydata.action == MLX_PRESS)
	{
		map->position.projection = '4';
		map->mlx_image->enabled = 0;
		map->mlx_image_front->enabled = 1;
		map->mlx_image_left->enabled = 1;
		map->mlx_image_top->enabled = 1;
		map->mlx_image_projection->enabled = 1;
		if (map->position.projection != '4')
			map->position.y_offset += 200;
	}

	// if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_PRESS)
	// 	map->position.scale *= 1.05;
	// if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS)
	// 	map->position.scale /= 1.05;
}

void	ft_hook(void *param)
{
	double	start;
	double	old_start;
	double	count_time;
	double	end;
	double	delta_time;
	double	in_while_time;
	t_map	*map;

	map = param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_F9))
	{
		printf("1 - %f %f %f\n", map->position.x_angle, map->position.y_angle, map->position.z_angle);
		printf("2 - %d %d %f\n", map->position.x_offset, map->position.y_offset, map->position.z_factor);
	}

	translate_zoom_close(map);
	rotate(map);
	projection(map);
	increase_descrease_z(map);
	ft_bzero(map->mlx_image->pixels, WIDTH * HEIGHT * sizeof(int32_t));
	// randomize(map);
	if (map->position.projection == '4')	// Talvez seja melhor colocar na mesma imagem, pode ser mais difícil, mas não deve ficar pisando ao movimentar
	{
		if (map->frame == 0)
		{
			map->image_to_render = 0;
			map->position.x_angle = 60;
			map->position.y_angle = 0;
			map->position.z_angle = 45;
			randomize(map);
		}

		else if (map->frame == 1)
		{
			map->image_to_render = 1;
			map->position.x_angle = 90;
			map->position.y_angle = 0;
			map->position.z_angle = 0;
			randomize(map);
		}

		else if (map->frame == 2)
		{
			map->image_to_render = 2;
			map->position.x_angle = 90;
			map->position.y_angle = 0;
			map->position.z_angle = 270;
			randomize(map);
		}

		else if (map->frame == 3)
		{
			map->image_to_render = 3;
			map->position.x_angle = 0;
			map->position.y_angle = 0;
			map->position.z_angle = 0;
			randomize(map);
		}

		map->frame += 1;
		if (map->frame == 4)
			map->frame = 0;
	}
	else
	{
		ft_bzero(map->mlx_image->pixels, WIDTH * HEIGHT * sizeof(int32_t));
		randomize(map);
	}
}
