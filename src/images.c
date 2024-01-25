/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:11:32 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/25 14:47:38 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_images_in_window(t_fdf *fdf_data)
{
	mlx_image_to_window(fdf_data->mlx, fdf_data->images[BACKGROUND], 0, 0);
	mlx_image_to_window(fdf_data->mlx, fdf_data->images[RENDER], 0, 0);
	mlx_image_to_window(fdf_data->mlx, fdf_data->images[STRING], 0, 0);
	mlx_set_instance_depth(fdf_data->images[BACKGROUND]->instances, 0);
	mlx_set_instance_depth(fdf_data->images[RENDER]->instances, 1);
	mlx_set_instance_depth(fdf_data->images[STRING]->instances, 2);

	// mlx_put_string(fdf_data->mlx, "-----------------------------", 20, 160);
	// mlx_put_string(fdf_data->mlx, "Increase Scale Z == 'J'", 30, 200);
	// mlx_put_string(fdf_data->mlx, "Decrease Scale Z == 'K'", 30, 240);
	// mlx_put_string(fdf_data->mlx, "Zoom In == '+'", 30, 280);
	// mlx_put_string(fdf_data->mlx, "Zoom Out == '-'", 30, 320);
	// mlx_put_string(fdf_data->mlx, "Move Up == 'W'", 30, 360);
	// mlx_put_string(fdf_data->mlx, "Move Down == 'S'", 30, 400);
	// mlx_put_string(fdf_data->mlx, "Move Left == 'A'", 30, 440);
	// mlx_put_string(fdf_data->mlx, "Move Right == 'D'", 30, 480);
	// mlx_put_string(fdf_data->mlx, "Rotate Asis+X == 'RIGHT'", 30, 520);
	// mlx_put_string(fdf_data->mlx, "Rotate Asis-X == 'LEFT'", 30, 560);
	// mlx_put_string(fdf_data->mlx, "Rotate Asis+Y == 'UP'", 30, 600);
	// mlx_put_string(fdf_data->mlx, "Rotate Asis-Y == 'DOWN'", 30, 640);
	// mlx_put_string(fdf_data->mlx, "Rotate Asis-Z == 'Q'", 30, 680);
	// mlx_put_string(fdf_data->mlx, "Rotate Asis+Z == 'E'", 30, 720);
	// mlx_put_string(fdf_data->mlx, "Top-Down == '2' || Reset == 'R'", 30, 760);
	// mlx_put_string(fdf_data->mlx, "Change Color == 'C'", 30, 800);
	// mlx_put_string(fdf_data->mlx, "Change Type LINE B/X == 'Y'", 30, 840);
	// mlx_put_string(fdf_data->mlx, "Auto Rotate ON/OFF == '1'", 30, 880);
	// mlx_put_string(fdf_data->mlx, "For Fun == 'F'", 30, 920);
	// mlx_put_string(fdf_data->mlx, "CLOSE PROGRAM == 'ESC'", 30, 950);
}

static void	set_background(t_fdf *fdf_data)
{
	t_point	i;

	i.x = -1;
	i.color.color_int = BACKGROUND_COLOR;
	while (++i.x < WIDTH)
	{
		i.y = -1;
		while (++i.y < HEIGHT)
			put_pixel(fdf_data->images[BACKGROUND], i);
	}
	i.x = -1;
	i.color.color_int = BACKGROUND_STRING_COLOR;
	while (++i.x < WIDTH / 5)
	{
		i.y = -1;
		while (++i.y < HEIGHT)
			put_pixel(fdf_data->images[STRING], i);
	}
}

void	create_images(t_fdf *fdf_data)
{
	fdf_data->images[BACKGROUND] = mlx_new_image(fdf_data->mlx, WIDTH, HEIGHT);
	fdf_data->images[RENDER] = mlx_new_image(fdf_data->mlx, WIDTH, HEIGHT);
	fdf_data->images[STRING] = mlx_new_image(fdf_data->mlx, WIDTH, HEIGHT);
	put_images_in_window(fdf_data);
	set_background(fdf_data);
}
