/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:49:56 by cogata            #+#    #+#             */
/*   Updated: 2023/07/27 15:49:57 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_count_divider(long nb)
{
	long long	divider;

	if (nb == 0)
		return (1);
	divider = 1;
	while (nb > 0)
	{
		nb = nb / 10;
		divider = divider * 10;
	}
	divider = divider / 10;
	return (divider);
}

char	*ft_init_str(long nb, char *res, int count, int is_negative)
{
	int		i;
	long	divider;

	divider = ft_count_divider(nb);
	i = 0;
	if (is_negative == 1)
	{
		res[0] = '-';
		i++;
	}
	while (i < count)
	{
		res[i] = (nb / divider) + '0';
		nb = nb % divider;
		divider = divider / 10;
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_count_num(long nb)
{
	int	count;

	count = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		count;
	char	*res;
	int		is_negative;

	nb = n;
	is_negative = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		count = ft_count_num(nb) + 1;
		is_negative = 1;
	}
	else if (nb == 0)
		count = 1;
	else
		count = ft_count_num(nb);
	res = malloc((count + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_init_str(nb, res, count, is_negative);
	return (res);
}
