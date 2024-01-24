/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:06:07 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/24 20:06:22 by danbarbo         ###   ########.fr       */
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

# define WIDTH 1280
# define HEIGHT 720

# define NUMBER_IMAGES 3
# define BUFFER_SIZE 4096
# define PI 3.14159

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
	int		x;
	int		y;
	int		z;
	t_color	color;
}	t_point;

typedef struct s_line
{
	t_point	point_1;
	t_point	point_2;
}	t_line;

typedef struct s_camera
{
	int		x_offset;
	int		y_offset;
	double	x_angle;
	double	y_angle;
	double	z_angle;
	double	z_factor;
	double	scale;
	int		scale_width;
	int		scale_height;
	int		line_tracer;
}	t_camera;

typedef struct s_map
{
	int		width;
	int		height;
	int		max_z;
	t_point	*map;
}	t_map;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*images[NUMBER_IMAGES];
	t_camera	camera;
	t_map		map;
}	t_fdf;

// Functions
// Main

int		create_map(t_fdf *fdf_data, char *file_path);
int		validate_map(char *file_string);
void	parse_map(t_map *map, char *file_string);
void	frame(void *param);
void	render(t_fdf *fdf_data);
void	key_hook(mlx_key_data_t keydata, void* param);
void	manag_keys(t_fdf *fdf_data);
void	transform_line(t_fdf *fdf_data, t_line *line);
void	transform_point(t_fdf *fdf_data, t_point *point);
t_color	get_color_gradient(t_point current, t_point start, t_point end, t_point delta);
void	bresenham_algorithm(mlx_image_t *img, t_line line);
void	xiaolin_algorithm(mlx_image_t *img, t_line line);

// Utils

int		get_height(char *str);
int		get_width(char *str);
t_point	get_node_map(t_map *map, int x, int y);
void	set_node_map(t_map *map, t_point point, int x, int y);
// char	*ft_read_all(int fd);
int		ternary(int condition, int if_true, int if_false);
void	put_pixel(mlx_image_t *img, t_point point);
int		get_max_z_value(t_map map);

#endif
