/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_init_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:39:00 by cogata            #+#    #+#             */
/*   Updated: 2023/12/31 14:50:03 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf_bonus.h"

void	init_each_line(int fd, uint32_t h, uint32_t width, t_map *map)
{
	uint32_t	w;
	char		*gnl_line;
	char		**split_line;

	gnl_line = get_next_line(fd);
	split_line = ft_split(gnl_line, ' ');
	map->matrix[h] = (t_matrix *)malloc(sizeof(t_matrix) * width);
	if (map->matrix[h] == NULL)
	{
		free_matrix((void **)map->matrix);
		free(map);
	}
	w = 0;
	while (w < width)
	{
		map->matrix[h][w].x = w;
		map->matrix[h][w].y = h;
		map->matrix[h][w].z = ft_atoi(split_line[w]);
		map->matrix[h][w].color = get_color(split_line[w]);
		w++;
	}
	free(gnl_line);
	free_matrix((void **)split_line);
}

t_map	*initialize_matrix(char *map_name, uint32_t width, uint32_t height)
{
	int			fd;
	uint32_t	h;
	t_map		*map;

	fd = check_fd(map_name);
	map = (t_map *)malloc(sizeof(t_map) * 1);
	if (map == NULL)
		return (NULL);
	map->matrix = (t_matrix **)malloc(sizeof(t_matrix *) * (height + 1));
	if (map->matrix == NULL)
	{
		free(map);
		return (NULL);
	}
	h = 0;
	while (h < height)
	{
		init_each_line(fd, h, width, map);
		h++;
	}
	map->matrix[h] = NULL;
	get_next_line(-1);
	close(fd);
	return (map);
}

t_map	*init_map(char *map_name)
{
	uint32_t	width;
	uint32_t	height;
	t_map		*map;

	map = NULL;
	find_width(map_name, &width);
	find_height(map_name, &height);
	check_map(map_name, width, height);
	map = initialize_matrix(map_name, width, height);
	map->width = width;
	map->height = height;
	map->line_render = 0;
	return (map);
}
