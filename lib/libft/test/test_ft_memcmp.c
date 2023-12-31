/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:21:08 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/18 19:31:03 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n);	// Prototype

MU_TEST(test_memcmp_receiving_1_and_1_returns_0)
{
	//ARRANGE
	char	input_1[] = {1};
	char	input_2[] = {1};
	size_t	size = 1;
	int		expected_result = 0;
	int		actual_result;

	//ACT
	actual_result = ft_memcmp(input_1, input_2, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_memcmp_receiving_1_and_2_size_1_returns_minus_1)
{
	//ARRANGE
	char	input_1[] = {1};
	char	input_2[] = {2};
	size_t	size = 1;
	int		expected_result = -1;
	int		actual_result;

	//ACT
	actual_result = ft_memcmp(input_1, input_2, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_memcmp_receiving_2_and_1_size_1_returns_1)
{
	//ARRANGE
	char	input_1[] = {2};
	char	input_2[] = {1};
	size_t	size = 1;
	int		expected_result = 1;
	int		actual_result;

	//ACT
	actual_result = ft_memcmp(input_1, input_2, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_memcmp_receiving_11_and_11_size_1_returns_1)
{
	//ARRANGE
	char	input_1[] = {1, 1};
	char	input_2[] = {1, 1};
	size_t	size = 1;
	int		expected_result = 0;
	int		actual_result;

	//ACT
	actual_result = ft_memcmp(input_1, input_2, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_memcmp_receiving_11_and_12_size_2_returns_1)
{
	//ARRANGE
	char	input_1[] = {1, 1};
	char	input_2[] = {1, 2};
	size_t	size = 2;
	int		expected_result = -1;
	int		actual_result;

	//ACT
	actual_result = ft_memcmp(input_1, input_2, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_memcmp_receiving_12_and_11_size_2_returns_minus_1)
{
	//ARRANGE
	char	input_1[] = {1, 2};
	char	input_2[] = {1, 1};
	size_t	size = 2;
	int		expected_result = 1;
	int		actual_result;

	//ACT
	actual_result = ft_memcmp(input_1, input_2, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_memcmp_receiving_1234_and_1234_size_4_returns_0)
{
	//ARRANGE
	char	input_1[] = {1, 2, 3, 4};
	char	input_2[] = {1, 2, 3, 4};
	size_t	size = 4;
	int		expected_result = 0;
	int		actual_result;

	//ACT
	actual_result = ft_memcmp(input_1, input_2, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_memcmp_receiving_1324_and_1234_size_4_returns_0)
{
	//ARRANGE
	char	input_1[] = {1, 3, 2, 4};
	char	input_2[] = {1, 2, 3, 4};
	size_t	size = 4;
	int		expected_result = 1;
	int		actual_result;

	//ACT
	actual_result = ft_memcmp(input_1, input_2, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_memcmp_receiving_1243_and_1234_size_2_returns_0)
{
	//ARRANGE
	char	input_1[] = {1, 2, 4, 3};
	char	input_2[] = {1, 2, 3, 4};
	size_t	size = 2;
	int		expected_result = 0;
	int		actual_result;

	//ACT
	actual_result = ft_memcmp(input_1, input_2, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_memcmp_receiving_1234_and_1234_size_0_returns_0)
{
	//ARRANGE
	char	input_1[] = {1, 2, 4, 3};
	char	input_2[] = {1, 2, 3, 4};
	size_t	size = 0;
	int		expected_result = 0;
	int		actual_result;

	//ACT
	actual_result = ft_memcmp(input_1, input_2, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_memcmp_test_suite)
{
	MU_RUN_TEST(test_memcmp_receiving_1_and_1_returns_0);
	MU_RUN_TEST(test_memcmp_receiving_1_and_2_size_1_returns_minus_1);
	MU_RUN_TEST(test_memcmp_receiving_2_and_1_size_1_returns_1);
	MU_RUN_TEST(test_memcmp_receiving_11_and_11_size_1_returns_1);
	MU_RUN_TEST(test_memcmp_receiving_11_and_12_size_2_returns_1);
	MU_RUN_TEST(test_memcmp_receiving_12_and_11_size_2_returns_minus_1);
	MU_RUN_TEST(test_memcmp_receiving_1234_and_1234_size_4_returns_0);
	MU_RUN_TEST(test_memcmp_receiving_1324_and_1234_size_4_returns_0);
	MU_RUN_TEST(test_memcmp_receiving_1243_and_1234_size_2_returns_0);
	MU_RUN_TEST(test_memcmp_receiving_1234_and_1234_size_0_returns_0);
}

int main(int argc, char *argv[]) {
	(void) argc;
	(void) argv;
	MU_RUN_SUITE(ft_memcmp_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
