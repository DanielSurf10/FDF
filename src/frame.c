/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:42:02 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/22 19:01:32 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	manag_keys(t_fdf *fdf_data)
{
	if (mlx_is_key_down(fdf_data->mlx, MLX_KEY_W))
		fdf_data->camera.x_angle += 1;
	if (mlx_is_key_down(fdf_data->mlx, MLX_KEY_S))
		fdf_data->camera.x_angle -= 1;

	if (mlx_is_key_down(fdf_data->mlx, MLX_KEY_D))
		fdf_data->camera.y_angle += 1;
	if (mlx_is_key_down(fdf_data->mlx, MLX_KEY_A))
		fdf_data->camera.y_angle -= 1;

	if (mlx_is_key_down(fdf_data->mlx, MLX_KEY_E))
		fdf_data->camera.z_angle += 1;
	if (mlx_is_key_down(fdf_data->mlx, MLX_KEY_Q))
		fdf_data->camera.z_angle -= 1;

	if (mlx_is_key_down(fdf_data->mlx, MLX_KEY_UP))
		fdf_data->camera.z_factor += 1;
	if (mlx_is_key_down(fdf_data->mlx, MLX_KEY_DOWN))
		fdf_data->camera.z_factor -= 1;

	// Aqui irá ver se tem algum botão apertado e fazer alguma coisa
}

void	frame(void *param)
{
	t_fdf	*fdf_data;

	fdf_data = param;
	manag_keys(fdf_data);
	ft_bzero(fdf_data->images[RENDER]->pixels, WIDTH * HEIGHT * sizeof(int));
	render(fdf_data);
}
