/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:04:58 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/06/10 18:58:37 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	frame_hook(void *param);
static void	ft_error_codam(void);
static void	del_and_create_img(t_fdf_ctl *mesh_data);

static void	ft_error_codam(void)
{
	char	*error;

	error = (char *) mlx_strerror(mlx_errno);
	ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}

static void	del_and_create_img(t_fdf_ctl *mesh_data)
{
	mlx_delete_image(mesh_data->mlx, mesh_data->img);
	mesh_data->img = mlx_new_image(mesh_data->mlx, 1280, 720);
	if (!mesh_data->img || \
		(mlx_image_to_window(mesh_data->mlx, mesh_data->img, 0, 0) < 0))
		ft_error_codam();
	ft_build_wireframe(mesh_data->mesh, mesh_data);
}

static void	frame_hook(void *param)
{
	t_fdf_ctl	*mesh_data;

	mesh_data = param;
	if (mlx_is_key_down(mesh_data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mesh_data->mlx);
	if (mlx_is_key_down(mesh_data->mlx, MLX_KEY_RIGHT))
		mesh_data->offset_x += 10;
	if (mlx_is_key_down(mesh_data->mlx, MLX_KEY_LEFT))
		mesh_data->offset_x -= 10;
	if (mlx_is_key_down(mesh_data->mlx, MLX_KEY_X))
		mesh_data->alpha += (PI / 180);
	if (mlx_is_key_down(mesh_data->mlx, MLX_KEY_Y))
		mesh_data->gamma += (PI / 180);
	if (mlx_is_key_down(mesh_data->mlx, MLX_KEY_Z))
		mesh_data->tetha += (PI / 180);
	if (mlx_is_key_down(mesh_data->mlx, MLX_KEY_F1))
		mesh_data->scale_factor += 0.2;
	if (mlx_is_key_down(mesh_data->mlx, MLX_KEY_F2) && \
		mesh_data->scale_factor > 0.4)
		mesh_data->scale_factor -= 0.2;
	del_and_create_img(mesh_data);
}

static void	terminate(t_fdf_ctl *mesh_data)
{
	mlx_delete_image(mesh_data->mlx, mesh_data->img);
	mlx_terminate(mesh_data->mlx);
	clear_mesh(&mesh_data->mesh);
}

int32_t	main(int argc, char **argv)
{
	t_mesh		*mesh;
	t_fdf_ctl	mesh_data;

	mesh = NULL;
	if (argc > 2)
		ft_error("Error: Too many arguments :(");
	else if (argc < 2)
		ft_error("Error: You forgot the map :(");
	init_fdf_data(&mesh_data);
	gnl_map(argv[1], &mesh_data, &mesh);
	mesh_data.mesh = mesh;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mesh_data.mlx = mlx_init(WIDTH, HEIGHT, "fdf @lsouza-r", true);
	if (!mesh_data.mlx)
		ft_error_codam();
	mesh_data.img = mlx_new_image(mesh_data.mlx, 1280, 720);
	if (!mesh_data.img || \
		(mlx_image_to_window(mesh_data.mlx, mesh_data.img, 0, 0) < 0))
		ft_error_codam();
	ft_build_wireframe(mesh_data.mesh, &mesh_data);
	mlx_loop_hook(mesh_data.mlx, frame_hook, &mesh_data);
	mlx_loop(mesh_data.mlx);
	terminate(&mesh_data);
	return (EXIT_SUCCESS);
}
