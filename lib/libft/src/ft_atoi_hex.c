/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:26:32 by danbarbo          #+#    #+#             */
/*   Updated: 2024/01/15 23:42:39 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ishex(char c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	else if (c >= 'a' && c <= 'f')
		return (c - 87);
	else if (c >= 'A' && c <= 'F')
		return (c - 55);
	return (-1);
}

int	ft_atoi_hex(char *str)
{
	int	i;
	int	sign;
	int	decimal;
	int	num;

	i = 0;
	sign = 1;
	decimal = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (ft_strncmp(str + i, "0x", 2))
		i += 2;
	num = ishex(str[i]);
	while (num >= 0)
	{
		decimal = decimal * 16 + num;
		i++;
		num = ishex(str[i]);
	}
	return (sign * decimal);
}
