/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:54:03 by cogata            #+#    #+#             */
/*   Updated: 2024/01/07 23:40:03 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1280
# define HEIGHT 720

# ifndef M_PI
#  define M_PI 3.14159
# endif

# include "../lib/libft/libft.h"
# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

typedef struct s_matrix
{
	int			x;
	int			y;
	int			z;
	uint32_t	color;
}				t_matrix;

typedef struct s_position
{
	float		scale;
	float		z_factor;
	int			x_offset;
	int			y_offset;
	float		x_angle;
	float		y_angle;
	float		z_angle;
	char		projection;
}				t_position;

typedef struct s_map
{
	uint32_t	width;
	uint32_t	height;
	t_matrix	**matrix;
	t_position	position;
	mlx_t		*mlx;
	mlx_image_t	*mlx_image;
	mlx_image_t	*mlx_image_projection;		// First to render in Fourth quadrant
	mlx_image_t	*mlx_image_front;			// Second, first
	mlx_image_t	*mlx_image_left;			// Third, second
	mlx_image_t	*mlx_image_top;				// Fourth, third
	int			image_to_render;
	double		time;
	int			frame;
	int			line_render: 1;
	unsigned int	auto_transform_x : 2;
	unsigned int	auto_transform_y : 2;
	unsigned int	auto_transform_z : 2;
}				t_map;

typedef struct s_coordinate
{
	int			x;
	int			y;
	int			z;
	uint32_t	color;
}				t_coordinate;

typedef struct s_bres
{
	int			dx;
	int			dy;
	int			abs_dx;
	int			abs_dy;
	int			p;
}				t_bres;

void			check_args(int argc, char *map_name);
mlx_t			*init_mlx(void);
mlx_image_t		*init_image(mlx_t *mlx);
int				init_window(mlx_t *mlx, mlx_image_t *mlx_image);
void			init_each_line(int fd, uint32_t h, uint32_t width, t_map *map);
t_map			*initialize_matrix(char *map_name, uint32_t width,
					uint32_t height);
t_map			*init_map(char *map_name);
void			find_width(char *map_name, uint32_t *width);
void			find_height(char *map_name, uint32_t *height);
uint32_t		get_color(char *split_line);
void			check_width_vs_count(int width, int count);
void			check_each_line(int fd, uint32_t width, uint32_t height);
void			check_map(char *map_name, uint32_t width, uint32_t height);
void			find_initial_scale(t_map *map);
void			centralize(t_map *map);
void			find_z_factor(t_map *map);
void			init_position(t_map *map);
void			transform(t_coordinate *point_1, t_coordinate *point_2,
					t_map *map);
void			init_points(int x1, int y1, char type, t_map *map);
void			randomize(t_map *map);
void			scale(t_coordinate *point_1, t_coordinate *point_2, t_map *map);
void			rotation_in_x(t_coordinate *point_1, t_coordinate *point_2,
					t_map *map);
void			rotation_in_y(t_coordinate *point_1, t_coordinate *point_2,
					t_map *map);
void			rotation_in_z(t_coordinate *point_1, t_coordinate *point_2,
					t_map *map);
void			isometric(t_map *map);
void			oblique(t_coordinate *point_1, t_coordinate *point_2);
void			translate(t_coordinate *point_1, t_coordinate *point_2,
					t_map *map);
void			put_valid_pixel(t_map *map, int x, int y, uint32_t color);
void			check_delta_to_move_variable(int d, int *variable);
void			slope_lower_1(t_bres *aux, t_coordinate *point, t_map *map);
void			slope_bigger_equal_1(t_bres *aux, t_coordinate *point,
					t_map *map);
void			bresenham(t_coordinate *point_1, t_coordinate *point_2,
					t_map *map);
void			ft_hook(void *param);
void			rotate(t_map *map);
void			projection(t_map *map);
void			increase_descrease_z(t_map *map);
void			translate_zoom_close(t_map *map);
void			error(char *err);
void			free_and_message(t_map *map, char *str);
void			free_matrix(void **matrix);
int				check_fd(char *map_name);
uint32_t		put_alpha(uint32_t decimal);
void			key_hook(mlx_key_data_t keydata, void* param);


#endif
