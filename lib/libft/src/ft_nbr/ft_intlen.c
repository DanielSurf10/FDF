/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:37:18 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/09/27 16:06:51 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_intlen(int n)
{
	int	cnt;

	cnt = !n;
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}
