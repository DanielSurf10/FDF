/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:50:02 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/06/10 18:54:43 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *error)
{
	int	i;

	i = 0;
	if (errno)
		perror("Error");
	else
	{
		while (error[i] != '\0')
		{
			write(2, &error[i], 1);
			i++;
		}
		write(2, "\n", 1);
	}
	if (read(3, NULL, 0) == 0)
		close(3);
	get_next_line(-1);
	exit(EXIT_FAILURE);
}
