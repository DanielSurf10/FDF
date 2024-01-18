/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:42:02 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/18 17:53:23 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	manag_keys(t_fdf *fdf_data)
{
	// Aqui irá ver se tem algum botão apertado e fazer alguma coisa
}

void	frame(void *param)
{
	t_fdf	*fdf_data;

	fdf_data = param;
	manag_keys(param);
	ft_bzero(fdf_data->images[RENDER]->pixels, WIDTH * HEIGHT * sizeof(int));
	render(param);
}
