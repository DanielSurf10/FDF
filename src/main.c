/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:00:29 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/15 22:19:34 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void print_error(char *error)
{
	ft_putendl_fd(error, 1);
	exit(EXIT_FAILURE);
}

int	main(int argv, char *argc[])
{
	int		return_code;
	t_fdf	fdf_data;


	if (argv != 2)
		print_error(ERROR_INVALID_ARGUMENTS_MSG);	// Argumentos errados

	return_code = create_map(&fdf_data, argc[1]);
	if (return_code == FILE_ERROR)
		print_error(ERROR_FILE_MSG);
	if (return_code == DESPROPORCIONAL_MAP_ERROR)
		print_error("Algum erro");

	// Isso aqui tem que ficar pra dps da verificação e leitura do mapa
	// mlx_set_setting(MLX_STRETCH_IMAGE, true);
	// fdf_data.mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	// if (!mlx)
	// 	print_error();
}
