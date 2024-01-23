/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:21:00 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/23 00:27:02 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (!distance)
		return (1.0);
	return (placement / distance);
}

static int	get_light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

t_color	get_color_gradient(t_point current, t_point start, t_point end, t_point delta)
{
	int		r;
	int		g;
	int		b;
	double	percentage;
	t_color	color;

	if (current.color.color_int == end.color.color_int)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	color.color_struct.r = get_light(start.color.color_struct.r, end.color.color_struct.r, percentage);
	color.color_struct.g = get_light(start.color.color_struct.g, end.color.color_struct.g, percentage);
	color.color_struct.b = get_light(start.color.color_struct.b, end.color.color_struct.b, percentage);
	color.color_struct.a = get_light(start.color.color_struct.b, end.color.color_struct.b, percentage);
	return (color);
}
