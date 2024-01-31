/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:25:44 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/31 16:57:46 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static char	*ft_read_all(int fd)
{
	int		chars_readed;
	char	*temp_buffer;
	char	*file_string;
	char	*aux;

	chars_readed = 1;
	temp_buffer = (char *) malloc((BUFFER_SIZE + 1));
	file_string = ft_strdup("");
	while (chars_readed > 0)
	{
		chars_readed = read(fd, temp_buffer, BUFFER_SIZE);
		temp_buffer[chars_readed] = '\0';
		aux = file_string;
		file_string = ft_strjoin(file_string, temp_buffer);
		free(aux);
	}
	free(temp_buffer);
	return (file_string);
}

int	create_map(t_fdf *fdf_data, char *file_path)
{
	int		fd;
	int		return_code;
	char	*file_string;

	fd = open(file_path, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (FILE_ERROR);
	ft_putendl_fd("Reading file", 1);
	file_string = ft_read_all(fd);
	ft_putendl_fd("Validating file", 1);
	return_code = validate_map(file_string);
	if (return_code == SUCCESS)
	{
		ft_putendl_fd("Parsing map", 1);
		parse_map(&(fdf_data->map), file_string);
		ft_putendl_fd("Rendering", 1);
	}
	free(file_string);
	return (return_code);
}
