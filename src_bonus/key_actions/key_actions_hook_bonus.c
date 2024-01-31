/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions_hook_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:50:42 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/31 16:57:46 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	change_rotation_state(int *rotate_state)
{
	if (*rotate_state == STOPED)
		*rotate_state = CLOCKWISE;
	else if (*rotate_state == CLOCKWISE)
		*rotate_state = COUNTERCLOCKWISE;
	else
		*rotate_state = STOPED;
}

static void	auto_rotation_keys(mlx_key_data_t keydata, t_fdf *fdf_data)
{
	if (keydata.key == MLX_KEY_Z)
		change_rotation_state(&fdf_data->camera.auto_rotate_x);
	if (keydata.key == MLX_KEY_X)
		change_rotation_state(&fdf_data->camera.auto_rotate_y);
	if (keydata.key == MLX_KEY_C)
		change_rotation_state(&fdf_data->camera.auto_rotate_z);
	if (keydata.key == MLX_KEY_V)
	{
		fdf_data->camera.auto_rotate_x = 0;
		fdf_data->camera.auto_rotate_y = 0;
		fdf_data->camera.auto_rotate_z = 0;
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf_data;

	fdf_data = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(fdf_data->mlx);
		if (keydata.key == MLX_KEY_0)
			fdf_data->camera.line_tracer = ternary(
					fdf_data->camera.line_tracer, XIAOLIN, BRESENHAM);
		if (keydata.key == MLX_KEY_R || keydata.key == MLX_KEY_F1
			|| keydata.key == MLX_KEY_F2)
		{
			init_fdf(fdf_data);
			if (keydata.key == MLX_KEY_F2)
			{
				fdf_data->camera.x_angle = 0;
				fdf_data->camera.y_angle = 0;
				fdf_data->camera.z_angle = 0;
				fdf_data->camera.projection = TOP_DOWN;
			}
		}
		auto_rotation_keys(keydata, fdf_data);
	}
}
