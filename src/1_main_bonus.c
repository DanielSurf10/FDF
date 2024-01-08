/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:38:49 by cogata            #+#    #+#             */
/*   Updated: 2024/01/08 00:28:01 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	close_window(mlx_key_data_t keydata, void* param)
// {
// 	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
// 		mlx_close_window(param);
// }

int32_t	main(int32_t argc, char *argv[])
{
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	*mlx_image;

	check_args(argc, argv[1]);
	map = init_map(argv[1]);
	mlx = init_mlx();
	map->mlx = mlx;

	map->mlx_image = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	map->mlx_image_front = mlx_new_image(map->mlx, WIDTH / 2, HEIGHT / 2);
	map->mlx_image_left = mlx_new_image(map->mlx, WIDTH / 2, HEIGHT / 2);
	map->mlx_image_top = mlx_new_image(map->mlx, WIDTH / 2, HEIGHT / 2);
	map->mlx_image_projection = mlx_new_image(map->mlx, WIDTH / 2, HEIGHT / 2);

	init_position(map);
	randomize(map);

	mlx_image_to_window(mlx, map->mlx_image, 0, 0);
	mlx_image_to_window(mlx, map->mlx_image_front, 0, 0);
	mlx_image_to_window(mlx, map->mlx_image_left, WIDTH / 2, 0);
	mlx_image_to_window(mlx, map->mlx_image_top, 0, HEIGHT / 2);
	mlx_image_to_window(mlx, map->mlx_image_projection, WIDTH / 2, HEIGHT / 2);
	mlx_set_instance_depth(map->mlx_image->instances, 1);
	mlx_set_instance_depth(map->mlx_image_front->instances, 0);
	mlx_set_instance_depth(map->mlx_image_left->instances, 0);
	mlx_set_instance_depth(map->mlx_image_top->instances, 0);
	mlx_set_instance_depth(map->mlx_image_projection->instances, 0);

	map->mlx_image_front->enabled = 0;
	map->mlx_image_left->enabled = 0;
	map->mlx_image_top->enabled = 0;
	map->mlx_image_projection->enabled = 0;
	// map->mlx_image = 0;

	// memset(map->mlx_image_front->pixels, 0xAF, (WIDTH / 2) * (HEIGHT / 2) * sizeof(int32_t));
	// memset(map->mlx_image_left->pixels, 0xFF, (WIDTH / 2) * (HEIGHT / 2) * sizeof(int32_t));
	// memset(map->mlx_image_top->pixels, 0x0A, (WIDTH / 2) * (HEIGHT / 2) * sizeof(int32_t));
	// memset(map->mlx_image_projection->pixels, 0xC5, (WIDTH / 2) * (HEIGHT / 2) * sizeof(int32_t));

	// mlx_key_hook(mlx, close_window, mlx);
	mlx_key_hook(mlx, key_hook, map);
	mlx_loop_hook(mlx, ft_hook, map);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_and_message(map, "Program finished.");
	return (EXIT_SUCCESS);
}
