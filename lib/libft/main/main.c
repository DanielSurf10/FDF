/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:02:40 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/18 18:11:48 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#include "libft.h"

void	print_header(char *str)
{
	printf("\n\n%s\n", str);
}

void	print_memory(char *title, char *s, int n)
{
	printf("%s", title);
	for (int i = 0; i < n; i++) {
		if (s[i] >= 32 && s[i] <= 126)
			printf("%c", s[i]);
		else
			printf(".");
	}
	puts("");
}

int main() {


	// FT_MEMSET
	print_header("FT_MEMSET");

	char	s1_memset[] = {"Bom diaa, tudo bem?"};
	char	s2_memset[] = {"Bom diaa, tudo bem?"};
	int		size_memset = 20;

	print_memory("String		= ", s1_memset, size_memset);
	print_memory("ft_memset	= ", (char *) ft_memset(s1_memset, '5', 5), size_memset);
	print_memory("memset		= ", (char *) memset(s2_memset, '5', 5), size_memset);
	// print_memory("memset		= ", (char *) memset(s2_memset, '5', 0), size_memset);	// Dá warning


	// FT_BZERO
	print_header("FT_BZERO");

	char	s1_bzero[] = {"Bom diaa, tudo bem?"};
	char	s2_bzero[] = {"Bom diaa, tudo bem?"};
	int		size_bzero = 20;

	print_memory("String		= ", s1_bzero, size_bzero);
	ft_bzero(s1_bzero, 5);
	bzero(s2_bzero, 5);

	print_memory("bzero		= ", s1_bzero, size_bzero);
	print_memory("ft_bzero	= ", s2_bzero, size_bzero);


	// FT_MEMCPY
	print_header("FT_MEMCPY");

	char	src_memcpy[] = {"Bom diaa, tudo bem?"};
	char	dest1_memcpy[10];
	char	dest2_memcpy[10];
	int		size_memcpy = 10;
	dest1_memcpy[7] = '\0';
	dest2_memcpy[7] = '\0';

	ft_memcpy(dest1_memcpy, src_memcpy, 7);
	memcpy(dest2_memcpy, src_memcpy, 7);

	print_memory("String		= ", src_memcpy, 20);
	print_memory("ft_memcpy	= ", dest1_memcpy, size_memcpy);
	print_memory("memcpy		= ", dest2_memcpy, size_memcpy);


	// FT_MEMMOVE
	print_header("FT_MEMMOVE");

	char	src1_memmove[15] = {"Bom dia"};
	char	*dest_maior_memmove = src1_memmove + 1;
	char	*dest_menor_memmove = src1_memmove - 2;

	ft_memmove(dest_maior_memmove, src1_memmove, 15);
	print_memory("ft_memmove	= ", src1_memmove, 15);
	ft_memmove(dest_menor_memmove, src1_memmove, 15);
	print_memory("ft_memmove	= ", src1_memmove, 15);


	// FT_MEMCHR
	print_header("FT_MEMCHR");

	char	s1_memchr[] = {"Bom dia!"};

	printf("ft_memchr	= %s\n", (char *) ft_memchr(s1_memchr, 'm', 9));
	printf("memchr		= %s\n", (char *) memchr(s1_memchr, 'm', 9));

	return (0);
}
