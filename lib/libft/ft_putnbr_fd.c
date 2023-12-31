/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:24:45 by cogata            #+#    #+#             */
/*   Updated: 2023/07/28 14:24:48 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_logic_putnbr(int fd, long nb)
{
	char	c;

	if (nb > 9)
	{
		ft_logic_putnbr(fd, nb / 10);
		c = nb % 10 + '0';
		write(fd, &c, 1);
	}
	else
	{
		c = nb + '0';
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (fd > 0)
	{
		if (nb < 0)
		{
			write(fd, "-", 1);
			nb = nb * (-1);
			ft_logic_putnbr(fd, nb);
		}
		else
			ft_logic_putnbr(fd, nb);
	}
}
