/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:37:23 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/06/10 19:05:45 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_all(char **splitted, char *line, t_mesh **mesh)
{
	free_split(splitted);
	free(line);
	clear_mesh(mesh);
}

static void	build_mesh(char *line, t_fdf_ctl **fdf_data, int y, t_mesh **mesh)
{
	char	**splitted;
	int		x;

	splitted = ft_split(line, ' ');
	x = 0;
	while (splitted[x] != NULL)
	{
		ft_mesh_add_back(mesh, ft_new_point(x, y, splitted[x]));
		if (ft_atoi(splitted[x]) > (*fdf_data)->max_z)
			(*fdf_data)->max_z = ft_atoi(splitted[x]);
		if (ft_atoi(splitted[x]) < (*fdf_data)->min_z)
			(*fdf_data)->min_z = ft_atoi(splitted[x]);
		x++;
	}
	if (y == 0)
		(*fdf_data)->width = x;
	else if ((*fdf_data)->width != x)
	{
		free_all(splitted, line, mesh);
		ft_error("Error: All lines must have the same number of points. ");
	}
	else
		(*fdf_data)->width = x;
	free_split(splitted);
}

void	fdf_file(const char *file_name)
{
	int	str_len;

	str_len = ft_strlen(file_name);
	if (ft_strncmp(&file_name[str_len - 4], ".fdf", 4) != 0)
		ft_error("File is not fdf type.");
}

void	gnl_map(const char *file_path, t_fdf_ctl *mesh_data, t_mesh **mesh)
{
	int		fd;
	char	*line;
	int		y;

	fdf_file(file_path);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		ft_error("Failed to open the map.");
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		build_mesh(line, &mesh_data, y++, mesh);
		free (line);
		line = get_next_line(fd);
	}
	if (y < 2)
	{
		clear_mesh(mesh);
		ft_error("Error: The map needs at least two lines.");
	}
	else
		mesh_data->height = y;
	close(fd);
	fit_to_window(mesh_data);
}
