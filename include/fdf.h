/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:06:07 by danbarbo          #+#    #+#             */
/*   Updated: 2023/12/30 22:57:28 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include "MLX42.h"

# define WIDTH 1024
# define HEIGHT 1024

typedef struct s_point
{
	int			x;
	int			y;
	uint32_t	color;
}	t_point;

void	draw_line(void *img, t_point *point_0, t_point *point_1);
void	print_big_pixel(void *img, int x, int y, uint32_t color);


#endif
