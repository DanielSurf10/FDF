/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:31:02 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/13 20:01:07 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include <stdlib.h>

char	*ft_strdup(const char *s);		// Prototype

MU_TEST(test_strdup_receiving_a_returns_a)
{
	//ARRANGE
	char	*input = "a";
	char	*dup;
	int		expected_result = 0;
	int		actual_result;

	//ACT
	dup = ft_strdup(input);
	actual_result = strcmp(input, dup);
	free(dup);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_strdup_receiving_b_returns_b)
{
	//ARRANGE
	char	*input = "b";
	char	*dup;
	int		expected_result = 0;
	int		actual_result;

	//ACT
	dup = ft_strdup(input);
	actual_result = strcmp(input, dup);
	free(dup);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_strdup_receiving_null_char_returns_null_char)
{
	//ARRANGE
	char	*input = "";
	char	*dup;
	int		expected_result = 0;
	int		actual_result;

	//ACT
	dup = ft_strdup(input);
	actual_result = strcmp(input, dup);
	free(dup);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_strdup_receiving_batata_returns_batata)
{
	//ARRANGE
	char	*input = "batata";
	char	*dup;
	int		expected_result = 0;
	int		actual_result;

	//ACT
	dup = ft_strdup(input);
	actual_result = strcmp(input, dup);
	free(dup);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_strdup_receiving_12345_returns_12345)
{
	//ARRANGE
	char	*input = "12345";
	char	*dup;
	int		expected_result = 0;
	int		actual_result;

	//ACT
	dup = ft_strdup(input);
	actual_result = strcmp(input, dup);
	free(dup);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_strdup_test_suite)
{
	MU_RUN_TEST(test_strdup_receiving_a_returns_a);
	MU_RUN_TEST(test_strdup_receiving_b_returns_b);
	MU_RUN_TEST(test_strdup_receiving_null_char_returns_null_char);
	MU_RUN_TEST(test_strdup_receiving_batata_returns_batata);
	MU_RUN_TEST(test_strdup_receiving_12345_returns_12345);
}

int	main(int argc, char *argv[]) {
	(void) argc;
	(void) argv;
	MU_RUN_SUITE(ft_strdup_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
