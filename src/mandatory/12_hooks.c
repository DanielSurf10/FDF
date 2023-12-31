/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:58:05 by cogata            #+#    #+#             */
/*   Updated: 2023/11/16 13:58:12 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	ft_hook(void *param)
{
	t_map	*map;

	map = param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	mlx_delete_image(map->mlx, map->mlx_image);
	map->mlx_image = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(map->mlx, map->mlx_image, 0, 0);
	randomize(map);
}
