/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:18:12 by cogata            #+#    #+#             */
/*   Updated: 2023/07/27 14:18:13 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_start(char const *s1, char const *set)
{
	size_t	i;
	char	*result;

	i = 0;
	result = ft_strchr(set, s1[0]);
	if (result == 0)
		return (0);
	while (ft_strchr(set, s1[i]) != 0 && s1[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_end(char const *s1, char const *set, size_t len)
{
	char	*result;

	result = ft_strchr(set, s1[len - 1]);
	if (result == 0)
		return (len - 1);
	while (result != 0)
	{
		result = ft_strchr(set, s1[len - 1]);
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;
	size_t	i;
	char	*res;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	start = ft_start(s1, set);
	if (start == len)
		return (ft_strdup(""));
	end = ft_end(s1, set, len);
	res = malloc(end - start + 2);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (start + i < end + 1)
	{
		res[i] = s1[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
