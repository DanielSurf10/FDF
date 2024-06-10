/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:36:37 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/06/10 18:44:58 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include "MLX42/MLX42.h"
# include "libft.h"

# define WIDTH 1280
# define HEIGHT 720
# define PI 3.14159265358979323846
# define ANG_1 0.01745329
# define TURQUOISE 0x07EDEDFF
# define PINK 0xE5037EFF
# define YELLOW	0xEAE234FF

typedef struct s_mesh
{
	int				x;
	int				y;
	int				z;
	uint32_t		color_rgba;
	struct s_mesh	*next;
}				t_mesh;

typedef struct s_edge
{
	struct s_mesh	vertex_1;
	struct s_mesh	vertex_2;
}	t_edge;

typedef struct s_fdf_ctl
{
	int			max_z;
	int			min_z;
	int			width;
	int			height;
	int			max_x;
	int			max_y;
	t_mesh		*mesh;
	double		scale_factor;
	double		scale_x;
	double		scale_y;
	int			offset_x;
	int			offset_y;
	mlx_t		*mlx;
	mlx_image_t	*img;
	double		alpha;
	double		gamma;
	double		tetha;
}	t_fdf_ctl;

typedef struct s_bresenham
{
	int			delta_x;
	int			delta_y;
	int			sign_dx;
	int			sign_dy;
	int			error_1;
	int			error_2;
	uint32_t	color_rgba;
}	t_bresenham;

typedef struct s_cam
{
	double	scale_factor;
	double	scale_z;
	double	offset_x;
	double	offset_y;
	double	alpha;
	double	gamma;
	double	tetha;
}	t_cam;

void		ft_error(char *error);
void		fdf_file(const char *file_name);
void		gnl_map(const char *file_path, t_fdf_ctl *mesh_data, t_mesh **mesh);
t_mesh		*ft_new_point(int x, int y, char *z);
t_mesh		*ft_mesh_last(t_mesh *list);
void		ft_mesh_add_back(t_mesh **mesh, t_mesh *new_point);
void		add_line_data(t_mesh node_1, t_mesh node_2, t_bresenham *line_data);
void		ft_bresenham(t_mesh n_1, t_mesh n_2, t_fdf_ctl *mesh_data);
void		ft_build_wireframe(t_mesh *mesh, t_fdf_ctl *mesh_data);
void		fit_to_window(t_fdf_ctl *mesh_data);
void		ft_isometric(t_mesh *node_1, t_mesh *node_2);
void		scale(t_mesh *node_1, t_mesh *node_2, t_fdf_ctl *mesh_data);
void		translate(t_mesh *node_1, t_mesh *node_2, t_fdf_ctl *mesh_data);
void		rotate_x(t_mesh *node_1, t_mesh *node_2, t_fdf_ctl *mesh_data);
void		rotate_y(t_mesh *node_1, t_mesh *node_2, t_fdf_ctl *mesh_data);
void		rotate_z(t_mesh *node_1, t_mesh *node_2, t_fdf_ctl *mesh_data);
void		ft_draw_edge(t_mesh node_1, t_mesh node_2, t_fdf_ctl *mesh_data);
void		centralize(t_mesh *node_1, t_mesh *node_2, t_fdf_ctl *mesh_data);
void		init_fdf_data(t_fdf_ctl *mesh_data);
uint32_t	add_color(int z);
void		draw_vertical_line(t_mesh *current_node, t_fdf_ctl *mesh_data);
void		free_split(char **split);
void		clear_mesh(t_mesh **mesh);
#endif
