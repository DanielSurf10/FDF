/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:13:12 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/16 16:13:58 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static void	get_z_and_color(t_map *map, char *file_string, t_point point,
			t_point *to_place_in_map)
{
	int		i;
	int		line;
	int		row;
	char	*current_line;

	i = 0;
	line = 0;
	row = 0;
	current_line = file_string;
	while (line++ < point.y)
		current_line = ft_strchr(current_line, '\n') + 1;
	while (row++ < point.x)
	{
		// while (current_line[i] == ' ')
		// 	i++;
		while (current_line[i] != ' ')
			i++;
		while (current_line[i] == ' ')
			i++;
	}
	ft_atoi_z_and_color(current_line + i, to_place_in_map);
	// printf("i antigo: %d\n", i);
	// printf("%s\n", current_line + i);
	// while (ft_isdigit(current_line[i]))
	// {
	// 	printf("|%c|\n", current_line[i]);
	// 	i++;
	// }

	// printf("res strncmp: %d\ni: %i\n", ft_strncmp(current_line + i, ",0x", 3), i);
	// if (current_line[i] && ft_strncmp(current_line + i, ",0x", 3) == 0)
	// 	i += 3;
// 	if (current_line[i] == ',')
// 		i += 3;
//
// 	to_place_in_map->color.color_int = ft_atoi_hex(current_line + i) << 8;
//
// 	printf("i dps: %i\n", i);
// 	printf("%s\n", current_line + i);
// 	printf("%i\n", to_place_in_map->color.color_int);
// 	puts("------------------------");
}

static int	inicializate_map(t_map *map, char *file_string)
{
	t_point	aux;
	t_point	to_place_in_map;

	aux.y = 0;
	map->map = malloc(map->width * map->height * sizeof(t_point));
	while (aux.y < map->height)
	{
		aux.x = 0;
		while (aux.x < map->width)
		{
			to_place_in_map.x = aux.x - (map->width / 2);
			to_place_in_map.y = aux.y - (map->height / 2);
			get_z_and_color(map, file_string, aux, &to_place_in_map);
			// printf("%5d ", to_place_in_map.color.color_int);

			set_node_map(map, to_place_in_map, aux.x, aux.y);
			aux.x += 1;
		}
		puts("");
		aux.y += 1;
	}
	return (SUCCESS);
}

int	parse_map(t_map *map, char *file_string)
{
	int	return_code;

	map->width = get_width(file_string);
	map->height = get_height(file_string);
	if (map->width < 2 || map->height < 2)
		return (DESPROPORCIONAL_MAP_ERROR);
	return_code = validate_width_map(file_string, map->width);
	if (return_code != SUCCESS)
		return (return_code);
	return_code = inicializate_map(map, file_string);
	return (return_code);
}
