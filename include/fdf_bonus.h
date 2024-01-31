/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:06:07 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/31 17:26:04 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>
# include <math.h>
# include "MLX42.h"
# include "libft.h"

# define WIDTH 1280
# define HEIGHT 720

# define PI 3.14159
# define NUMBER_IMAGES 3
# define BUFFER_SIZE 4096
# define BACKGROUND_COLOR 0x89ABE3DB
# define BACKGROUND_STRING_COLOR 0xEA738DA0

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

enum e_projection
{
	ISOMETRIC = 0,
	TOP_DOWN,
	THREE_VIEWS
};

enum e_rotation_sense
{
	STOPED = 0,
	CLOCKWISE,
	COUNTERCLOCKWISE
};

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_line
{
	t_point	point_1;
	t_point	point_2;
}	t_line;

typedef struct s_bresenham
{
	int		delta_x;
	int		delta_y;
	int		slope_x;
	int		slope_y;
	int		error_1;
	int		error_2;
	t_point	delta;
	t_line	line;
	t_line	original_line;
}	t_bresenham;

typedef struct s_xioalin
{
	int		i;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		color;
	int		xpxl1;
	int		ypxl1;
	int		xpxl2;
	int		ypxl2;
	double	gradient;
	double	dx;
	double	dy;
	double	xend;
	double	yend;
	double	xgap;
	double	ygap;
	double	intery;
	double	interx;
	t_point	delta;
	t_point	point_to_plot;
	t_line	original_line;
}	t_xiaolin;

typedef struct s_camera
{
	int		x_offset;
	int		y_offset;
	double	x_angle;
	double	y_angle;
	double	z_angle;
	double	z_factor;
	double	scale;
	double	scale_width;
	double	scale_height;
	int		line_tracer;
	int		projection;
	int		auto_rotate_x;
	int		auto_rotate_y;
	int		auto_rotate_z;
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
	double		time_to_open;
}	t_fdf;

// Functions
// Main

int		create_map(t_fdf *fdf_data, char *file_path);
int		validate_map(char *file_string);
void	parse_map(t_map *map, char *file_string);
void	init_fdf(t_fdf *fdf_data);
void	create_images(t_fdf *fdf_data);
void	draw_menu(t_fdf *fdf_data);
void	frame(void *param);
void	render(t_fdf *fdf_data);
void	key_hook(mlx_key_data_t keydata, void *param);
void	manag_keys(t_fdf *fdf_data);
void	scale(t_fdf *fdf_data, t_point *point);
void	rotate_x(t_fdf *fdf_data, t_point *point);
void	rotate_y(t_fdf *fdf_data, t_point *point);
void	rotate_z(t_fdf *fdf_data, t_point *point);
void	move(t_fdf *fdf_data, t_point *point);
int		color_gradient(t_point current, t_point start, t_point end,
			t_point delta);
void	bresenham_algorithm(mlx_image_t *img, t_line line);
void	inicializate_x_greater(mlx_image_t *img, t_xiaolin *xiaolin);
void	inicializate_x_lesser(mlx_image_t *img, t_xiaolin *xiaolin);
void	xiaolin_algorithm(mlx_image_t *img, t_line line);

// Utils

int		ternary(int condition, int if_true, int if_false);
int		get_width(char *str);
int		get_height(char *str);
t_point	get_node_map(t_map *map, int x, int y);
void	set_node_map(t_map *map, t_point point, int x, int y);
void	put_pixel(mlx_image_t *img, t_point point);
int		get_max_z_value(t_map map);
t_point	create_point(int x, int y);

// Utils Xiaolin

int		set_brightness(int color, float brightness);
double	float_part(double x);
double	float_part(double x);
double	rev_float_part(double x);
void	swap(int *a, int *b);

#endif
