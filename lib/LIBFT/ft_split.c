/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:57:56 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/06/10 18:06:35 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_substr(char const *s, char c)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

size_t	ft_substr_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static char	*put_str_in_array(const char *s, size_t len)
{
	char	*sub_str;
	size_t	i;

	sub_str = (char *) malloc((len + 1) * sizeof(char));
	if (!sub_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_str[i] = s[i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

char	**ft_split(char const *s, char c)
{
	char	**split_str;
	size_t	substr_len;
	int		i;
	int		iter_substr;
	int		total_substr;

	total_substr = count_substr(s, c);
	split_str = (char **) ft_calloc((total_substr + 1), sizeof(char *));
	if (!split_str)
		return (NULL);
	i = 0;
	iter_substr = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && iter_substr < total_substr)
		{
			substr_len = ft_substr_len(s + i, c);
			split_str[iter_substr] = put_str_in_array(&s[i], substr_len);
			iter_substr++;
			i = i + substr_len;
		}
	}
	return (split_str);
}
