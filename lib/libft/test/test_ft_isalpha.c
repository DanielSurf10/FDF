/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:04:23 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/13 19:36:46 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

int	ft_isalpha(int c);

MU_TEST(test_isalpha_receiving_A_returns_true)
{
	//ARRANGE
	char	input = 'A';
	int		expected_result = 1;
	int		actual_result;

	//ACT
	actual_result = ft_isalpha(input);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isalpha_receiving_B_returns_true)
{
	//ARRANGE
	char	input = 'B';
	int		expected_result = 1;
	int		actual_result;

	//ACT
	actual_result = ft_isalpha(input);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isalpha_receiving_a_returns_true)
{
	//ARRANGE
	char	input = 'a';
	int		expected_result = 1;
	int		actual_result;

	//ACT
	actual_result = ft_isalpha(input);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isalpha_receiving_z_returns_true)
{
	//ARRANGE
	char	input = 'z';
	int		expected_result = 1;
	int		actual_result;

	//ACT
	actual_result = ft_isalpha(input);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isalpha_receiving_char_1_returns_false)
{
	//ARRANGE
	char	input = '1';
	int		expected_result = 0;
	int		actual_result;

	//ACT
	actual_result = ft_isalpha(input);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isalpha_receiving_char_0_returns_false)
{
	//ARRANGE
	char	input = '0';
	int		expected_result = 0;
	int		actual_result;

	//ACT
	actual_result = ft_isalpha(input);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isalpha_receiving_int_0_returns_false)
{
	//ARRANGE
	char	input = 0;
	int		expected_result = 0;
	int		actual_result;

	//ACT
	actual_result = ft_isalpha(input);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isalpha_receiving_int_128_returns_false)
{
	//ARRANGE
	int	input = 128;
	int	expected_result = 0;
	int	actual_result;

	//ACT
	actual_result = ft_isalpha(input);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isalpha_receiving_int_max_returns_false)
{
	//ARRANGE
	int	input = 2147483647;
	int	expected_result = 0;
	int	actual_result;

	//ACT
	actual_result = ft_isalpha(input);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_isalpha_test_suite)
{
	MU_RUN_TEST(test_isalpha_receiving_A_returns_true);
	MU_RUN_TEST(test_isalpha_receiving_B_returns_true);
	MU_RUN_TEST(test_isalpha_receiving_a_returns_true);
	MU_RUN_TEST(test_isalpha_receiving_z_returns_true);
	MU_RUN_TEST(test_isalpha_receiving_char_1_returns_false);
	MU_RUN_TEST(test_isalpha_receiving_char_0_returns_false);
	MU_RUN_TEST(test_isalpha_receiving_int_0_returns_false);
	MU_RUN_TEST(test_isalpha_receiving_int_128_returns_false);
	MU_RUN_TEST(test_isalpha_receiving_int_max_returns_false);
}

int main(int argc, char *argv[]) {
	(void) argc;
	(void) argv;
	MU_RUN_SUITE(ft_isalpha_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
