/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:40:05 by cogata            #+#    #+#             */
/*   Updated: 2024/01/04 16:22:13 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	error(char *err)
{
	printf("%s\n", err);
	exit(1);
}

void	free_and_message(t_map *map, char *str)
{
	free_matrix((void **)map->matrix);
	free(map);
	error(str);
}

void	free_matrix(void **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	check_fd(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		error("ERROR: invalid file.");
		return (-1);
	}
	return (fd);
}

uint32_t	put_alpha(uint32_t decimal)
{
	decimal = decimal << 8 | 0x000000FF;
	return (decimal);
}
