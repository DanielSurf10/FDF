/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:00:29 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/22 17:57:55 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void print_error(int error)
{
	if (error == INVALID_ARGUMENTS_ERROR)
		ft_putendl_fd("Wrong usage. Expected './fdf <file_path>'.", 1);
	else if (error == FILE_ERROR)
		ft_putendl_fd("File error. Invalid File.", 1);
	exit(EXIT_FAILURE);
}

int	main(int argv, char *argc[])
{
	int		return_code;
	t_fdf	fdf_data;

	if (argv != 2)
		print_error(INVALID_ARGUMENTS_ERROR);
	return_code = create_map(&fdf_data, argc[1]);
	if (return_code == FILE_ERROR)
		print_error(FILE_ERROR);

	// Isso aqui tem que ficar pra dps da verificação e leitura do mapa
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	fdf_data.mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	// if (!mlx)
	// 	print_error();

	fdf_data.camera.x_angle = 60;
	fdf_data.camera.y_angle = 0;
	fdf_data.camera.z_angle = 45;
	fdf_data.camera.x_offset = 0;
	fdf_data.camera.y_offset = 0;
	fdf_data.camera.z_factor = 1;		// É 1 pq é 100% do z
	fdf_data.camera.scale_width = WIDTH / fdf_data.map.width;
	fdf_data.camera.scale_height = HEIGHT / fdf_data.map.height;
	fdf_data.camera.line_tracer = XIAOLIN;

	// Colocar os hooks

	// Crias as imagens
	fdf_data.images[RENDER] = mlx_new_image(fdf_data.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(fdf_data.mlx, fdf_data.images[RENDER], 0, 0);

	// mlx_key_hook(fdf_data.mlx, key_hook, &fdf_data);
	mlx_loop_hook(fdf_data.mlx, frame, &fdf_data);

	// mlx_loop
	mlx_loop(fdf_data.mlx);

	// Apagar tudo, destruir as imagens e fechar a janela
	mlx_terminate(fdf_data.mlx);
	// delete_images(fdf_data.images);

	return (0);
}
