/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:38:49 by cogata            #+#    #+#             */
/*   Updated: 2024/01/04 16:22:13 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_window(mlx_key_data_t keydata, void* param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(param);

	// if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
	// 	mlx_close_window(map->mlx);
}

int32_t	main(int32_t argc, char *argv[])
{
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	*mlx_image;

	check_args(argc, argv[1]);
	map = init_map(argv[1]);
	if (map == NULL)
		error("ERROR: map init failed.");
	mlx = init_mlx();
	if (mlx == NULL)
		free_and_message(map, "ERROR: mlx init failed.");
	mlx_image = init_image(mlx);
	if (mlx_image == NULL)
		free_and_message(map, "ERROR: mlx image init failed.");
	map->mlx = mlx;
	map->mlx_image = mlx_image;
	init_position(map);
	randomize(map);
	if (init_window(mlx, mlx_image) == -1)
		free_and_message(map, "ERROR: mlx window init failed.");
	mlx_key_hook(mlx, close_window, mlx);
	mlx_loop_hook(mlx, ft_hook, map);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_and_message(map, "Program finished.");
	return (EXIT_SUCCESS);
}
