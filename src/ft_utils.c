/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:23:37 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/06/10 18:44:33 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mesh	*ft_mesh_last(t_mesh *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}

void	ft_mesh_add_back(t_mesh **mesh, t_mesh *new_point)
{
	t_mesh	*last_point;

	if (!*mesh)
	{
		*mesh = new_point;
		return ;
	}
	last_point = ft_mesh_last(*mesh);
	last_point->next = new_point;
}

t_mesh	*ft_new_point(int x, int y, char *z)
{
	t_mesh	*new_point;

	new_point = malloc(sizeof(t_mesh));
	if (!new_point)
		return (NULL);
	new_point->x = x;
	new_point->y = y;
	new_point->z = ft_atoi(z);
	new_point->color_rgba = add_color(new_point->z);
	new_point->next = NULL;
	return (new_point);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	clear_mesh(t_mesh **mesh)
{
	t_mesh	*tmp;

	while (*mesh)
	{
		tmp = (*mesh)->next;
		free(*mesh);
		*mesh = tmp;
	}
}
