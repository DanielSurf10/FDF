/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:00:29 by danbarbo          #+#    #+#             */
/*   Updated: 2024/02/04 20:03:41 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_error(int error)
{
	if (error == INVALID_ARGUMENTS_ERROR)
		ft_putendl_fd("Wrong usage. Expected './fdf <file_path>'.", 1);
	else if (error == FILE_ERROR)
		ft_putendl_fd("File error. Invalid File.", 1);
	exit(EXIT_FAILURE);
}

static void	set_icon(t_fdf *fdf_data, char *path_to_icon)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path_to_icon);
	mlx_set_icon(fdf_data->mlx, texture);
	mlx_delete_texture(texture);
}

void	init_fdf(t_fdf *fdf_data)
{
	fdf_data->camera.x_angle = 60;
	fdf_data->camera.y_angle = 0;
	fdf_data->camera.z_angle = 45;
	fdf_data->camera.x_offset = WIDTH / 2;
	fdf_data->camera.y_offset = HEIGHT / 2;
	fdf_data->map.max_z = get_max_z_value(fdf_data->map);
	if (fdf_data->map.max_z < 100 && fdf_data->map.max_z != 0)
		fdf_data->camera.z_factor = (100.0 / fdf_data->map.max_z);
	else if (fdf_data->map.max_z > 200)
		fdf_data->camera.z_factor = (200.0 / fdf_data->map.max_z);
	else
		fdf_data->camera.z_factor = 1;
	fdf_data->camera.scale = 0.7;
	fdf_data->camera.scale_height = WIDTH / hypot((double) fdf_data->map.width,
			(double) fdf_data->map.height);
	fdf_data->camera.scale_width = WIDTH / hypot((double) fdf_data->map.width,
			(double) fdf_data->map.height);
	if (fdf_data->map.width > 100 || fdf_data->map.height > 200)
		fdf_data->camera.line_tracer = BRESENHAM;
	else
		fdf_data->camera.line_tracer = XIAOLIN;
	fdf_data->camera.projection = ISOMETRIC;
	fdf_data->camera.auto_rotate_x = STOPED;
	fdf_data->camera.auto_rotate_y = STOPED;
	fdf_data->camera.auto_rotate_z = STOPED;
}

static void	delete_images(t_fdf *fdf_data)
{
	mlx_delete_image(fdf_data->mlx, fdf_data->images[BACKGROUND]);
	mlx_delete_image(fdf_data->mlx, fdf_data->images[RENDER]);
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
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	fdf_data.mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	set_icon(&fdf_data, "src/icon.png");
	init_fdf(&fdf_data);
	create_images(&fdf_data);
	mlx_key_hook(fdf_data.mlx, key_hook, &fdf_data);
	mlx_loop_hook(fdf_data.mlx, frame, &fdf_data);
	mlx_loop(fdf_data.mlx);
	delete_images(&fdf_data);
	free(fdf_data.map.map);
	mlx_terminate(fdf_data.mlx);
	ft_putendl_fd("Finishing", 1);
	return (0);
}
