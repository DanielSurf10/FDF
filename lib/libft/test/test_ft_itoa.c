/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:21:08 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/20 15:05:24 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "libft.h"

char	*ft_itoa(int n);	// Prototype

MU_TEST(test_itoa_receiving_1_returns_1)
{
	//ARRANGE
	int		input = 1;
	char	*expected_result = "1";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_itoa(input);

	//ASSERT
	is_equal = ft_strncmp(expected_result, actual_result, ft_strlen(expected_result));
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_itoa_receiving_2_returns_2)
{
	//ARRANGE
	int		input = 2;
	char	*expected_result = "2";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_itoa(input);

	//ASSERT
	is_equal = ft_strncmp(expected_result, actual_result, ft_strlen(expected_result));
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_itoa_receiving_0_returns_0)
{
	//ARRANGE
	int		input = 0;
	char	*expected_result = "0";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_itoa(input);

	//ASSERT
	is_equal = ft_strncmp(expected_result, actual_result, ft_strlen(expected_result));
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_itoa_receiving_9_returns_9)
{
	//ARRANGE
	int		input = 9;
	char	*expected_result = "9";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_itoa(input);

	//ASSERT
	is_equal = ft_strncmp(expected_result, actual_result, ft_strlen(expected_result));
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_itoa_receiving_42_returns_42)
{
	//ARRANGE
	int		input = 42;
	char	*expected_result = "42";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_itoa(input);

	//ASSERT
	is_equal = ft_strncmp(expected_result, actual_result, ft_strlen(expected_result));
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_itoa_receiving_1042_returns_1042)
{
	//ARRANGE
	int		input = 1042;
	char	*expected_result = "1042";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_itoa(input);

	//ASSERT
	is_equal = ft_strncmp(expected_result, actual_result, ft_strlen(expected_result));
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_itoa_receiving_minus_2_returns_minus_2)
{
	//ARRANGE
	int		input = -2;
	char	*expected_result = "-2";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_itoa(input);

	//ASSERT
	is_equal = ft_strncmp(expected_result, actual_result, ft_strlen(expected_result));
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_itoa_receiving_minus_1042_returns_minus_1042)
{
	//ARRANGE
	int		input = -1042;
	char	*expected_result = "-1042";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_itoa(input);

	//ASSERT
	is_equal = ft_strncmp(expected_result, actual_result, ft_strlen(expected_result));
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_itoa_receiving_int_max_returns_int_max)
{
	//ARRANGE
	int		input = 2147483647;
	char	*expected_result = "2147483647";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_itoa(input);

	//ASSERT
	is_equal = ft_strncmp(expected_result, actual_result, ft_strlen(expected_result));
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_itoa_receiving_minus_int_max_returns_minus_int_max)
{
	//ARRANGE
	int		input = -2147483648;
	char	*expected_result = "-2147483648";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_itoa(input);

	//ASSERT
	is_equal = ft_strncmp(expected_result, actual_result, ft_strlen(expected_result));
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST_SUITE(ft_itoa_test_suite)
{
	MU_RUN_TEST(test_itoa_receiving_1_returns_1);
	MU_RUN_TEST(test_itoa_receiving_2_returns_2);
	MU_RUN_TEST(test_itoa_receiving_0_returns_0);
	MU_RUN_TEST(test_itoa_receiving_9_returns_9);
	MU_RUN_TEST(test_itoa_receiving_42_returns_42);
	MU_RUN_TEST(test_itoa_receiving_1042_returns_1042);
	MU_RUN_TEST(test_itoa_receiving_minus_2_returns_minus_2);
	MU_RUN_TEST(test_itoa_receiving_minus_1042_returns_minus_1042);
	MU_RUN_TEST(test_itoa_receiving_int_max_returns_int_max);
	MU_RUN_TEST(test_itoa_receiving_minus_int_max_returns_minus_int_max);
}

int main(int argc, char *argv[]) {
	(void) argc;
	(void) argv;
	MU_RUN_SUITE(ft_itoa_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
