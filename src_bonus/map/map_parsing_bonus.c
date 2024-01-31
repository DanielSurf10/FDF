/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:13:12 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/31 16:57:46 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	get_color(char *str)
{
	int		num_int;
	char	*num_char;

	num_char = ft_strnstr(str, "0x", ft_strlen(str));
	if (!num_char)
		return (0xFFFFFFFF);
	num_int = (ft_atoi_hex(num_char) << 8) | 0xFF;
	return (num_int);
}

static void	inicializate_map(t_map *map, char *file_string)
{
	t_point	aux;
	t_point	to_place_in_map;
	char	**split_lines;
	char	**split_rows;

	aux.y = 0;
	split_lines = ft_split(file_string, '\n');
	while (aux.y < map->height)
	{
		aux.x = 0;
		split_rows = ft_split(split_lines[aux.y], ' ');
		while (aux.x < map->width)
		{
			to_place_in_map.x = aux.x - (map->width / 2);
			to_place_in_map.y = aux.y - (map->height / 2);
			to_place_in_map.z = ft_atoi(split_rows[aux.x]);
			to_place_in_map.color = get_color(split_rows[aux.x]);
			set_node_map(map, to_place_in_map, aux.x, aux.y);
			aux.x += 1;
		}
		ft_free_split(split_rows);
		aux.y += 1;
	}
	ft_free_split(split_lines);
}

void	parse_map(t_map *map, char *file_string)
{
	map->width = get_width(file_string);
	map->height = get_height(file_string);
	map->map = malloc(map->width * map->height * sizeof(t_point));
	inicializate_map(map, file_string);
}
