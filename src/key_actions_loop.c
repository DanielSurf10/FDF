/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:50:15 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/27 20:33:01 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	auto_off(t_fdf *fdf_data)
{
	return (!(fdf_data->camera.auto_rotate_x
			|| fdf_data->camera.auto_rotate_y
			|| fdf_data->camera.auto_rotate_z));
}

static void	rotation_keys(t_fdf *fdf_data)
{
	if (fdf_data->camera.projection != TOP_DOWN)
	{
		if ((mlx_is_key_down(fdf_data->mlx, MLX_KEY_W) && auto_off(fdf_data))
			|| fdf_data->camera.auto_rotate_x == CLOCKWISE)
			fdf_data->camera.x_angle += 1;
		if ((mlx_is_key_down(fdf_data->mlx, MLX_KEY_S) && auto_off(fdf_data))
			|| fdf_data->camera.auto_rotate_x == COUNTERCLOCKWISE)
			fdf_data->camera.x_angle -= 1;
		if ((mlx_is_key_down(fdf_data->mlx, MLX_KEY_E) && auto_off(fdf_data))
			|| fdf_data->camera.auto_rotate_y == CLOCKWISE)
			fdf_data->camera.y_angle += 1;
		if ((mlx_is_key_down(fdf_data->mlx, MLX_KEY_Q) && auto_off(fdf_data))
			|| fdf_data->camera.auto_rotate_y == COUNTERCLOCKWISE)
			fdf_data->camera.y_angle -= 1;
	}
	if ((mlx_is_key_down(fdf_data->mlx, MLX_KEY_D) && auto_off(fdf_data))
		|| fdf_data->camera.auto_rotate_z == CLOCKWISE)
		fdf_data->camera.z_angle += 1;
	if ((mlx_is_key_down(fdf_data->mlx, MLX_KEY_A) && auto_off(fdf_data))
		|| fdf_data->camera.auto_rotate_z == COUNTERCLOCKWISE)
		fdf_data->camera.z_angle -= 1;
}

static void	scale_keys(t_fdf *fdf_data)
{
	if (mlx_is_key_down(fdf_data->mlx, MLX_KEY_UP)
		&& fdf_data->camera.z_factor
		< ternary(fdf_data->map.max_z < 100, 20, 5))
		fdf_data->camera.z_factor += 0.2;
	if (mlx_is_key_down(fdf_data->mlx, MLX_KEY_DOWN)
		&& fdf_data->camera.z_factor
		> ternary(fdf_data->map.max_z < 100, -20, -5))
		fdf_data->camera.z_factor -= 0.2;
	if (mlx_is_key_down(fdf_data->mlx, MLX_KEY_EQUAL))
		fdf_data->camera.scale += 0.01;
	if (mlx_is_key_down(fdf_data->mlx, MLX_KEY_MINUS)
		&& fdf_data->camera.scale > 0)
		fdf_data->camera.scale -= 0.01;
}

static void	move_keys(t_fdf *fdf_data)
{
	if (mlx_is_key_down(fdf_data->mlx, MLX_KEY_I))
		fdf_data->camera.y_offset -= 5;
	if (mlx_is_key_down(fdf_data->mlx, MLX_KEY_K))
		fdf_data->camera.y_offset += 5;
	if (mlx_is_key_down(fdf_data->mlx, MLX_KEY_J))
		fdf_data->camera.x_offset -= 5;
	if (mlx_is_key_down(fdf_data->mlx, MLX_KEY_L))
		fdf_data->camera.x_offset += 5;
}

void	manag_keys(t_fdf *fdf_data)
{
	rotation_keys(fdf_data);
	scale_keys(fdf_data);
	move_keys(fdf_data);
}
