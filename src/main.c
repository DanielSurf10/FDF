/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:00:29 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/11 20:29:39 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void print_error(void)
{
	write(1, "Error\n", 7);
	exit(EXIT_FAILURE);
}

int	main(int argv, char *argc[])
{
	mlx_t*	mlx;

	if (argv != 2)
	{
		print_error();	// Argumentos errados
		exit(0);
	}


	// Isso aqui tem que ficar pra dps da verificação e leitura do mapa
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!mlx)
		print_error();
}
