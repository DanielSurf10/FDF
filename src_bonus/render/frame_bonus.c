/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:42:02 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/31 16:57:46 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	frame(void *param)
{
	t_fdf	*fdf_data;

	fdf_data = param;
	manag_keys(fdf_data);
	ft_bzero(fdf_data->images[RENDER]->pixels, WIDTH * HEIGHT * sizeof(int));
	render(fdf_data);
}