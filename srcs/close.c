/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 23:08:35 by cado-car          #+#    #+#             */
/*   Updated: 2024/01/01 22:41:23 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	close_coordinates(t_point **coordinates, int width);

void	close_all(t_fdf *fdf, int exit_code)
{
	close_coordinates(fdf->map->coordinates, fdf->map->max_x);
	free(fdf->map);
	mlx_destroy_image(fdf->mlx, fdf->image->image);
	free(fdf->image);
	free(fdf->cam);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	free(fdf);
	error(exit_code);
}

void	close_map(t_fdf *fdf, int exit_code)
{
	close_coordinates(fdf->map->coordinates, fdf->map->max_x);
	free(fdf->map);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf);
	error(exit_code);
}

static void	close_coordinates(t_point **coordinates, int width)
{
	int		i;

	i = 0;
	while (i < width)
	{
		free(coordinates[i]);
		i++;
	}
	free(coordinates);
}
