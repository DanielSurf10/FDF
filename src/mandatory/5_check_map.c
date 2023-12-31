/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_check_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:04:25 by cogata            #+#    #+#             */
/*   Updated: 2023/11/16 14:04:28 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	check_width_vs_count(int width, int count)
{
	if (count != width)
	{
		get_next_line(-1);
		error("ERROR: invalid map. It is not rectangular.");
	}
}

void	check_each_line(int fd, uint32_t width, uint32_t height)
{
	uint32_t	h;
	int			i;
	int			count;
	char		*gnl_line;
	char		**split_line;

	h = 0;
	while (h++ < height)
	{
		gnl_line = get_next_line(fd);
		split_line = ft_split(gnl_line, ' ');
		count = 0;
		i = 0;
		while (split_line[i++])
		{
			if (ft_strncmp(split_line[count], "\n", 2) != 0)
				count++;
		}
		free(gnl_line);
		free_matrix((void **)split_line);
		check_width_vs_count(width, count);
	}
}

void	check_map(char *map_name, uint32_t width, uint32_t height)
{
	int	fd;

	if (height < 2 || width < 2)
		error("ERROR: invalid map size.");
	fd = check_fd(map_name);
	check_each_line(fd, width, height);
	close(fd);
}
