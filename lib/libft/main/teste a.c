#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
#include "libft.h"

// void	print_memory(int *s, int n)
// {
// 	for (int i = 0; i < n; i++) {
// 		if (s[i] >= 0 && s[i] <= 0)
// 			printf("%i", s[i]);
// 		else
// 			printf(".");
// 	}
// 	puts("");
// }

void	del(void *a)
{
	free(a);
}

void	*faz_algo(void *a)
{
	return (ft_strdup((char *) a));
}

int main()
{
	// char *src = NULL;
	// char *d1 = strchr(src, '\0');
	// char *d2 = ft_strchr(src, '\0');

	// printf("%s\n", d1);
	// printf("%s\n", d2);

	// int a = ft_atoi("   +42a54   ");

	// char a[] = {1};
	// char b[] = {2};

	// printf("%i\n", memcmp(a, b, 1));

	// char a[20] = "Bom dia, ";
	// char b[] = "Batata!";
	// size_t ret = ft_strlcat(a, b, 15);

	// printf("%zu %s\n", ret, a);

	// char a[20];

	// memset(a, 'a', 20);

	// memmove(a, a + 2, )

	// printf("%lu\n", sizeof(int));

	t_list	*lst = NULL;
	t_list	*map_lst = NULL;
	t_list	*aux;

	aux = ft_lstnew(ft_strdup("oi"));
	ft_lstadd_back(&lst, aux);
	aux = ft_lstnew(ft_strdup("tudo"));
	ft_lstadd_back(&lst, aux);
	aux = ft_lstnew(ft_strdup("bemm?"));
	ft_lstadd_back(&lst, aux);
	aux = ft_lstnew(ft_strdup("?????"));
	ft_lstadd_back(&lst, aux);

	map_lst = ft_lstmap(lst, &faz_algo, &del);

	printf("%s\n", (char *) map_lst->content);
	printf("%s\n", (char *) map_lst->next->content);
	printf("%s\n", (char *) map_lst->next->next->content);

	ft_lstclear(&lst, &del);
	ft_lstclear(&map_lst, &del);

// 	char haystack[30] = "aaabcabcd";
// 	char needle[10] = "abcd";
//
// 	char *a = ft_strnstr(haystack, "abcd", 10);
// 	printf("%s\n",a);

	return (0);
}
