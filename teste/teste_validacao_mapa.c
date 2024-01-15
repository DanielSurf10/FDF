/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_validacao_mapa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:13:09 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/15 18:18:47 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void print_error(char *error)
{
	ft_putendl_fd(error, 1);
	exit(EXIT_FAILURE);
}

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

static int	validate_width_map(char *file_string, int width)
{
	int		str_lenght;
	int		width_test;
	char	*tmp_string;

	tmp_string = file_string;
	str_lenght = ft_strlen(file_string);
	while (tmp_string)
	{
		if (tmp_string[0] == '\0' && *(tmp_string - 1) == '\n')
			break ;
		width_test = get_width(tmp_string);
		printf("%d\n", width_test);
		if (width_test != width)
			return (DESPROPORCIONAL_MAP_ERROR);
		tmp_string = ft_strchr(tmp_string, '\n');
		if (tmp_string)
			tmp_string += 1;
	}
	return (SUCCESS);
}

static int	parse_map(t_map *map, char *file_string)
{
	int	return_code;

	map->width = get_width(file_string);
	map->height = get_height(file_string);
	if (map->width < 2 || map->height < 2)
		return (DESPROPORCIONAL_MAP_ERROR);
	return_code = validate_width_map(file_string, map->width);
	return (return_code);
}

int	main(int argv, char *argc[])
{
	int		fd;
	int		return_code;
	char	*file_string;
	t_map	map;

	if (argv != 2)
		print_error("Falta o caminho do arquivo.");	// Argumentos errados

	fd = open(argc[1], O_RDONLY);
	if (fd < 0)
		print_error("Arquivo inválido.");

	fd = open(argc[1], O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
		print_error(ERROR_FILE_MSG);
	file_string = ft_read_all(fd);
	if (ft_strlen(file_string) == 0)
	{
		free(file_string);
		print_error(ERROR_FILE_MSG);
	}
	return_code = parse_map(&map, file_string);
	if (return_code == DESPROPORCIONAL_MAP_ERROR)
		print_error("Outro erro");
	printf("Tudo certo: %d %d\n", map.width, map.height);
	free(file_string);


	return (0);
}
