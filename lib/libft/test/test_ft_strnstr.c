/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:21:08 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/28 21:40:45 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t n);	// Prototype

MU_TEST(test_strnstr_receiving_bomdia_dia_size_6_returns_dia)
{
	//ARRANGE
	char	*input = "bomdia";
	char	*to_find = "dia";
	char	*expected_result = "dia";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_strnstr(input, to_find, 6);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	mu_assert_int_eq(is_equal, 0);
}

MU_TEST(test_strnstr_receiving_bomdia_dia_size_minus_1_returns_dia)
{
	//ARRANGE
	char	*input = "bomdia";
	char	*to_find = "dia";
	char	*expected_result = "dia";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_strnstr(input, to_find, -1);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	mu_assert_int_eq(is_equal, 0);
}

MU_TEST(test_strnstr_receiving_aaabcabcd_abcd_size_9_returns_abcd)
{
	//ARRANGE
	char	*input = "aaabcabcd";
	char	*to_find = "abcd";
	char	*expected_result = "abcd";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_strnstr(input, to_find, 9);

	//ASSERT
	is_equal = ft_strncmp(expected_result, actual_result, -1);
	mu_assert_int_eq(is_equal, 0);
}

MU_TEST_SUITE(ft_strnstr_test_suite)
{
	MU_RUN_TEST(test_strnstr_receiving_bomdia_dia_size_6_returns_dia);
	MU_RUN_TEST(test_strnstr_receiving_bomdia_dia_size_minus_1_returns_dia);
	MU_RUN_TEST(test_strnstr_receiving_aaabcabcd_abcd_size_9_returns_abcd);
}

int main(int argc, char *argv[]) {
	(void) argc;
	(void) argv;
	MU_RUN_SUITE(ft_strnstr_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
