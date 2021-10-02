/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:36:00 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/01 23:19:54 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
static void	isometric(t_point *point);

void	project(t_fdf *fdf, int max_x, int max_y)
{
	int	x;
	int	y;

	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			if (fdf->cam->projection == ISOMETRIC)
				isometric(&fdf->image->coordinates[x][y]);
			x++;
		}
		y++;
	}
}

static void	isometric(t_point *point)
{
	point->x = (point->x - point->y) * cos(ANG_30);
	point->y = (point->x + point->y) * sin(ANG_30) - point->z;
}
