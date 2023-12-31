/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:29:13 by cogata            #+#    #+#             */
/*   Updated: 2023/07/21 15:29:14 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			size;
	unsigned char	u;

	u = (unsigned char)c;
	size = ft_strlen(s);
	while (size + 1 > 0)
	{
		if (s[size] == u)
			return ((char *)&s[size]);
		size--;
	}
	return (0);
}
