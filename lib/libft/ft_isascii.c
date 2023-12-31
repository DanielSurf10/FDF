/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:46:29 by cogata            #+#    #+#             */
/*   Updated: 2023/12/23 15:08:10 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(unsigned int c)
{
	if (c <= 127)
	{
		return (1);
	}
	return (0);
}