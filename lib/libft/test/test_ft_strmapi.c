/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:21:08 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/23 19:05:41 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));	// Prototype

char	change_char_1(unsigned int index, char c)
{
	(void) index;
	return (c);
}

MU_TEST(test_strmapi_change_1_receiving_a_returns_a)
{
	//ARRANGE
	char	*input = "a";
	char	*expected_result = "a";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_strmapi(input, &change_char_1);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST_SUITE(ft_strmapi_test_suite)
{
	MU_RUN_TEST(test_strmapi_change_1_receiving_a_returns_a);
}

int main(int argc, char *argv[]) {
	(void) argc;
	(void) argv;
	MU_RUN_SUITE(ft_strmapi_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
