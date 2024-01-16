/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:36:39 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/16 19:50:22 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Essa função verifica se todas as linhas tem o mesmo tamanho
static int	validate_width_map(t_map *map, char *file_string)
{
	// int		str_lenght;
	// int		width_map;
	int		width_test;
	char	*tmp_string;
	char	*split_line;

	tmp_string = file_string;
	map->width = get_width(file_string);
	if (ft_strlen(file_string) == 0)
		return (FILE_ERROR);
	split_line = ft_split(file_string, '\n');
	// str_lenght = ft_strlen(file_string);
	while (tmp_string)
	{
		if (tmp_string[0] == '\0' && *(tmp_string - 1) == '\n')
			break ;
		width_test = get_width(tmp_string);
		if (width_test != width_map)
			return (DESPROPORCIONAL_MAP_ERROR);
		tmp_string = ft_strchr(tmp_string, '\n');
		if (tmp_string)
			tmp_string += 1;
	}

	return (SUCCESS);
}

int	validate_map(char *file_string)
{
	int		i;
	int		is_valid;
	int		width;
	char	**string_split;

	i = 0;
	is_valid = 1;
	if (ft_strlen(file_string) == 0)
		return (FILE_ERROR);			// Arquivo está vazio
	width = get_width(file_string);
	string_split = ft_split(file_string, '\n');
	while (string_split[i])
	{

	}
}
