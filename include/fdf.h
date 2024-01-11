/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:06:07 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/11 19:32:06 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// PARA TIRAR DPS
# include <stdio.h>
# include <string.h>


# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include "MLX42.h"

# define WIDTH 1024
# define HEIGHT 1024

# define NUMBER_IMAGES 3

typedef struct	fdf
{
	void		*mlx;
	mlx_image	*images[NUMBER_IMAGES];
};


typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	uint32_t	color;
}	t_point;

// typedef struct s_keys
// {
// 	int	key_p : 1;		// Botão de mudar a perspectiva
// 	int	key_line : 1;	// Botão para mudar o algoritmo de fazer a linha
// } t_keys;

void	draw_line(void *img, t_point *point_0, t_point *point_1);
void	print_big_pixel(void *img, int x, int y, uint32_t color);


#endif
