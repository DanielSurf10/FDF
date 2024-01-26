/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:50:15 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/26 19:17:49 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_auto_on(t_fdf *fdf_data)
{
	return (fdf_data->camera.auto_rotate_x
		|| fdf_data->camera.auto_rotate_y
		|| fdf_data->camera.auto_rotate_z);
}

static void	rotation_keys(t_fdf *fdf_data)
{
	if (fdf_data->camera.projection != TOP_DOWN)
	{
		if ((mlx_is_key_down(fdf_data->mlx, MLX_KEY_W)
			&& !is_auto_on(fdf_data))
			|| fdf_data->camera.auto_rotate_x == CLOCKWISE)
			fdf_data->camera.x_angle += 1;
		if ((mlx_is_key_down(fdf_data->mlx, MLX_KEY_S)
			&& !is_auto_on(fdf_data))
			|| fdf_data->camera.auto_rotate_x == COUNTERCLOCKWISE)
			fdf_data->camera.x_angle -= 1;
		if ((mlx_is_key_down(fdf_data->mlx, MLX_KEY_E)
			&& !is_auto_on(fdf_data))
			|| fdf_data->camera.auto_rotate_y == COUNTERCLOCKWISE)
			fdf_data->camera.y_angle += 1;
		if ((mlx_is_key_down(fdf_data->mlx, MLX_KEY_Q)
			&& !is_auto_on(fdf_data))
			|| fdf_data->camera.auto_rotate_y == COUNTERCLOCKWISE)
			fdf_data->camera.y_angle -= 1;
	}
	if (mlx_is_key_down(fdf_data->mlx, MLX_KEY_D))
		fdf_data->camera.z_angle += 1;
	if (mlx_is_key_down(fdf_data->mlx, MLX_KEY_A))
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
