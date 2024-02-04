/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:29:35 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/31 16:57:46 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	ternary(int condition, int if_true, int if_false)
{
	if (condition)
		return (if_true);
	return (if_false);
}

void	put_pixel(mlx_image_t *img, t_point point)
{
	if (point.x >= 0 && point.x < WIDTH && point.y >= 0 && point.y < HEIGHT)
		mlx_put_pixel(img, point.x, point.y, point.color);
}

t_point	create_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}