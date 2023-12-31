/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:21:08 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/21 14:29:56 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "libft.h"
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);	// Prototype

MU_TEST(test_substr_receiving_a_start_0_len_1_returns_a)
{
	//ARRANGE
	char	*input = "a";
	int		start = 0;
	int		len = 1;
	char	*expected_result = "a";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_substr(input, start, len);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_substr_receiving_abc_start_0_len_1_returns_a)
{
	//ARRANGE
	char	*input = "abc";
	int		start = 0;
	int		len = 1;
	char	*expected_result = "a";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_substr(input, start, len);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_substr_receiving_abc_start_0_len_3_returns_abc)
{
	//ARRANGE
	char	*input = "abc";
	int		start = 0;
	int		len = 3;
	char	*expected_result = "abc";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_substr(input, start, len);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_substr_receiving_abc_start_1_len_2_returns_bc)
{
	//ARRANGE
	char	*input = "abc";
	int		start = 1;
	int		len = 2;
	char	*expected_result = "bc";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_substr(input, start, len);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_substr_receiving_abcd_start_0_len_10_returns_abcd)
{
	//ARRANGE
	char	*input = "abcd";
	int		start = 0;
	int		len = 10;
	char	*expected_result = "abcd";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_substr(input, start, len);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_substr_receiving_abcd_start_0_len_0_returns_empty)
{
	//ARRANGE
	char	*input = "abcd";
	int		start = 0;
	int		len = 0;
	char	*expected_result = "";
	char	*actual_result;
	int		is_equal = 1;

	//ACT
	actual_result = ft_substr(input, start, len);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_substr_receiving_abcd_start_10_len_4_returns_empty)
{
	//ARRANGE
	char	*input = "abcd";
	int		start = 10;
	int		len = 4;
	char	*expected_result = "";
	char	*actual_result;
	int		is_equal = 1;

	//ACT
	actual_result = ft_substr(input, start, len);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_substr_receiving_abcd_start_10_len_0_returns_empty)
{
	//ARRANGE
	char	*input = "abcd";
	int		start = 10;
	int		len = 0;
	char	*expected_result = "";
	char	*actual_result;
	int		is_equal = 1;

	//ACT
	actual_result = ft_substr(input, start, len);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_substr_receiving_abcd1234_start_4_len_3_returns_d123)
{
	//ARRANGE
	char	*input = "abcd1234";
	int		start = 4;
	int		len = 4;
	char	*expected_result = "1234";
	char	*actual_result;
	int		is_equal = 1;

	//ACT
	actual_result = ft_substr(input, start, len);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_substr_receiving_abcd1234_start_8_len_3_returns_empty)
{
	//ARRANGE
	char	*input = "abcd1234";
	int		start = 8;
	int		len = 3;
	char	*expected_result = "";
	char	*actual_result;
	int		is_equal = 1;

	//ACT
	actual_result = ft_substr(input, start, len);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_substr_receiving_abcd1234_start_6_len_3_returns_34)
{
	//ARRANGE
	char	*input = "abcd1234";
	int		start = 6;
	int		len = 3;
	char	*expected_result = "34";
	char	*actual_result;
	int		is_equal = 1;

	//ACT
	actual_result = ft_substr(input, start, len);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_substr_receiving_abcd1234_start_6_len_5_returns_34)
{
	//ARRANGE
	char	*input = "abcd1234";
	int		start = 6;
	int		len = 5;
	char	*expected_result = "34";
	char	*actual_result;
	int		is_equal = 1;

	//ACT
	actual_result = ft_substr(input, start, len);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_substr_receiving_abcd1234_start_4_len_2_returns_12)
{
	//ARRANGE
	char	*input = "abcd1234";
	int		start = 4;
	int		len = 2;
	char	*expected_result = "12";
	char	*actual_result;
	int		is_equal = 1;

	//ACT
	actual_result = ft_substr(input, start, len);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST_SUITE(ft_substr_test_suite)
{
	MU_RUN_TEST(test_substr_receiving_a_start_0_len_1_returns_a);
	MU_RUN_TEST(test_substr_receiving_abc_start_0_len_1_returns_a);
	MU_RUN_TEST(test_substr_receiving_abc_start_0_len_3_returns_abc);
	MU_RUN_TEST(test_substr_receiving_abc_start_1_len_2_returns_bc);
	MU_RUN_TEST(test_substr_receiving_abcd_start_0_len_10_returns_abcd);
	MU_RUN_TEST(test_substr_receiving_abcd_start_0_len_0_returns_empty);
	MU_RUN_TEST(test_substr_receiving_abcd_start_10_len_4_returns_empty);
	MU_RUN_TEST(test_substr_receiving_abcd1234_start_4_len_3_returns_d123);
	MU_RUN_TEST(test_substr_receiving_abcd_start_10_len_0_returns_empty);
	MU_RUN_TEST(test_substr_receiving_abcd1234_start_8_len_3_returns_empty);
	MU_RUN_TEST(test_substr_receiving_abcd1234_start_6_len_3_returns_34);
	MU_RUN_TEST(test_substr_receiving_abcd1234_start_6_len_5_returns_34);
	MU_RUN_TEST(test_substr_receiving_abcd1234_start_4_len_2_returns_12);
}

int main(int argc, char *argv[]) {
	(void) argc;
	(void) argv;
	MU_RUN_SUITE(ft_substr_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
