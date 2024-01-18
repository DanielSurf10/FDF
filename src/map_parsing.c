/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:13:12 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/18 14:47:04 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	get_z_and_color(t_map *map, char *file_string, t_point point,
// 			t_point *to_place_in_map)
// {
// 	int		i;
// 	int		line;
// 	int		row;
// 	char	*current_line;
//
// 	i = 0;
// 	line = 0;
// 	row = 0;
// 	current_line = file_string;
// 	while (line++ < point.y)
// 		current_line = ft_strchr(current_line, '\n') + 1;
// 	while (row++ < point.x)
// 	{
// 		// while (current_line[i] == ' ')
// 		// 	i++;
// 		while (current_line[i] != ' ')
// 			i++;
// 		while (current_line[i] == ' ')
// 			i++;
// 	}
// 	ft_atoi_z_and_color(current_line + i, to_place_in_map);
// 	// printf("i antigo: %d\n", i);
// 	// printf("%s\n", current_line + i);
// 	// while (ft_isdigit(current_line[i]))
// 	// {
// 	// 	printf("|%c|\n", current_line[i]);
// 	// 	i++;
// 	// }
//
// 	// printf("res strncmp: %d\ni: %i\n", ft_strncmp(current_line + i, ",0x", 3), i);
// 	// if (current_line[i] && ft_strncmp(current_line + i, ",0x", 3) == 0)
// 	// 	i += 3;
// // 	if (current_line[i] == ',')
// // 		i += 3;
// //
// // 	to_place_in_map->color.color_int = ft_atoi_hex(current_line + i) << 8;
// //
// // 	printf("i dps: %i\n", i);
// // 	printf("%s\n", current_line + i);
// // 	printf("%i\n", to_place_in_map->color.color_int);
// // 	puts("------------------------");
// }

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
			to_place_in_map.color.color_int = get_color(split_rows[aux.x]);
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
