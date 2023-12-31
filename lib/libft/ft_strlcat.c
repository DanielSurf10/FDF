/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:55:09 by cogata            #+#    #+#             */
/*   Updated: 2023/07/21 11:55:10 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	total_len;
	int		i;

	if (dst != 0)
		dest_len = ft_strlen(dst);
	else
		dest_len = 0;
	src_len = ft_strlen(src);
	total_len = src_len + dest_len;
	i = 0;
	if (size > dest_len)
	{
		while (dest_len < size - 1 && src[i] != '\0')
		{
			dst[dest_len] = src[i];
			dest_len++;
			i++;
		}
		dst[dest_len] = '\0';
		return (total_len);
	}
	return (src_len + size);
}
