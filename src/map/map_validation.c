/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:36:39 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/24 20:08:32 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	validate_map(char *file_string)
{
	int		i;
	int		width;
	char	**string_split;

	i = 0;
	width = get_width(file_string);
	if (width < 2)
		return (FILE_ERROR);
	string_split = ft_split(file_string, '\n');
	while (string_split[i])
	{
		if (get_width(string_split[i]) != width)
		{
			ft_free_split(string_split);
			return (FILE_ERROR);
		}
		i++;
	}
	ft_free_split(string_split);
	if (i < 2)
		return (FILE_ERROR);
	return (SUCCESS);
}
