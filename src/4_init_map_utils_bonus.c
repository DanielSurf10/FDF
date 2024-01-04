/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_init_map_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:39:05 by cogata            #+#    #+#             */
/*   Updated: 2024/01/04 16:22:13 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_width(char *map_name, uint32_t *width)
{
	int		i;
	int		fd;
	char	*gnl_line;
	char	**split_line;

	fd = check_fd(map_name);
	*width = 0;
	gnl_line = get_next_line(fd);
	split_line = ft_split(gnl_line, ' ');
	i = 0;
	while (split_line[i] != NULL)
	{
		*width += 1;
		i++;
	}
	if (gnl_line != NULL)
		free(gnl_line);
	free_matrix((void **)split_line);
	get_next_line(-1);
	close(fd);
}

void	find_height(char *map_name, uint32_t *height)
{
	int		fd;
	char	*gnl_line;

	fd = check_fd(map_name);
	*height = 0;
	gnl_line = get_next_line(fd);
	while (gnl_line != NULL)
	{
		*height += 1;
		free(gnl_line);
		gnl_line = get_next_line(fd);
	}
	get_next_line(-1);
	close(fd);
}

uint32_t	get_color(char *split_line)
{
	char		*str_color;
	uint32_t	color;

	str_color = ft_strchr(split_line, ',');
	if (str_color != NULL)
		color = put_alpha((uint32_t)ft_atoi_base(&str_color[3]));
	else
		color = 0xFFFFFFFF;
	return (color);
}
