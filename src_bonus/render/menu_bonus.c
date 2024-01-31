/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:02:30 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/31 16:57:46 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	draw_header(t_fdf *fdf_data, int *x, int *y, int line_distance)
{
	mlx_put_string(fdf_data->mlx, "______  ______  ______ ", *x, *y);
	mlx_put_string(fdf_data->mlx, "|  ___| |  _  \\ |  ___|", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "| |_    | | | | | |_   ", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "|  _|   | | | | |  _|  ", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "| |     | |/ /  | |    ", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "\\_|     |___/   \\_|    ", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "------------------------ ", *x,
		*y += line_distance);
}

static void	body_1(t_fdf *fdf_data, int *x, int *y, int line_distance)
{
	mlx_put_string(fdf_data->mlx, "Move Up       == 'I'", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "Move Down     == 'K'", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "Move Left     == 'J'", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "Move Right    == 'L'", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "Rotate +X     == 'W'", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "Rotate -X     == 'S'", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "Rotate +Y     == 'E'", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "Rotate -Y     == 'Q'", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "Rotate +Z     == 'D'", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "Rotate -Z     == 'A'", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "Increase Z    == 'UP'", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "Decrease Z    == 'DOWN'", *x,
		*y += line_distance);
}

static void	body_2(t_fdf *fdf_data, int *x, int *y, int line_distance)
{
	mlx_put_string(fdf_data->mlx, "Zoom In       == '+'", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "Zoom Out      == '-'", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "Isometric     == 'F1'", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "Top-Down      == 'F2'", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "Reset         == 'R'", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "Change Line   == '0'", *x,
		*y += line_distance);
}

static void	body_3(t_fdf *fdf_data, int *x, int *y, int line_distance)
{
	mlx_put_string(fdf_data->mlx, "Auto Rotate:", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, " - Rotate X   == 'z'", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, " - Rotate Y   == 'x'", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, " - Rotate Z   == 'c'", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, " - Stop       == 'v'", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "Close         == 'ESC'", *x,
		*y += line_distance);
	mlx_put_string(fdf_data->mlx, "------------------------ ", *x,
		*y += line_distance);
}

void	draw_menu(t_fdf *fdf_data)
{
	int	start_y;
	int	start_x;
	int	line_distance;

	start_x = 7;
	start_y = 0;
	line_distance = 22;
	draw_header(fdf_data, &start_x, &start_y, line_distance);
	body_1(fdf_data, &start_x, &start_y, line_distance);
	body_2(fdf_data, &start_x, &start_y, line_distance);
	body_3(fdf_data, &start_x, &start_y, line_distance);
}
