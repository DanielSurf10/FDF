/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:06:07 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/19 18:36:42 by danbarbo         ###   ########.fr       */
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
# include <fcntl.h>
# include <math.h>
# include "MLX42.h"
# include "libft.h"

# define WIDTH 1024
# define HEIGHT 1024

# define NUMBER_IMAGES 3
# define BUFFER_SIZE 50
# define PI 3.14159

// # define ERROR_INVALID_ARGUMENTS_MSG "Wrong usage. \
// Expected './fdf <file_path>'."
//
// # define ERROR_FILE_MSG "File error. \
// Invalid File."

enum e_errors
{
	SUCCESS = 0,
	INVALID_ARGUMENTS_ERROR,
	FILE_ERROR
};

enum e_images
{
	BACKGROUND = 0,
	RENDER,
	STRING
};

enum e_line_tracer
{
	XIAOLIN = 0,
	BRESENHAM
};

typedef struct s_color_rgba
{
	int	r:8;
	int	g:8;
	int	b:8;
	int	a:8;
}	t_color_rgba;

typedef union u_color
{
	int				color_int;
	t_color_rgba	color_struct;
}	t_color;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	t_color		color;
}	t_point;

typedef struct s_line
{
	t_point	point_1;
	t_point	point_2;
}	t_line;

typedef struct s_camera
{
	int	x_offset;
	int	y_offset;
	int	x_angle;
	int	y_angle;
	int	z_angle;
	int	z_factor;
	int	scale_width;
	int	scale_height;
	int	line_tracer;
}	t_camera;

typedef struct s_map
{
	int		width;
	int		height;
	int		max_z;				// Não sei se isso é necessário
	t_point	*map;
}	t_map;

typedef struct s_fdf
{
	void		*mlx;
	mlx_image_t	*images[NUMBER_IMAGES];
	t_camera	camera;
	t_map		map;
}	t_fdf;

// typedef struct s_keys
// {
// 	int	key_p : 1;		// Botão de mudar a perspectiva
// 	int	key_line : 1;	// Botão para mudar o algoritmo de fazer a linha
// } t_keys;

void	draw_line(void *img, t_point *point_0, t_point *point_1);
void	print_big_pixel(void *img, int x, int y, uint32_t color);


// Functions
// Main

int		create_map(t_fdf *fdf_data, char *file_path);
int		validate_map(char *file_string);
void	parse_map(t_map *map, char *file_string);
void	frame(void *param);
void	render(t_fdf *fdf_data);
void	transform_line(t_fdf *fdf_data, t_line *line);


// Utils

int		get_height(char *str);
int		get_width(char *str);
t_point	get_node_map(t_map *map, int x, int y);
void	set_node_map(t_map *map, t_point point, int x, int y);
// char	*ft_read_all(int fd);



#endif
