/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:04:25 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/17 18:14:04 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include <stdlib.h>

int		ft_atoi(const char *c);

MU_TEST(test_atoi_convert_1_char_to_1_integer)
{
	// ARRANGE
	char *c = "1";
	int expected_result = 1;
	char actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_42_char_to_42_integer)
{
	// ARRANGE
	char *c = "42";
	int expected_result = 42;
	char actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_2_char_to_2_integer)
{
	// ARRANGE
	char *c = "2";
	int expected_result = 2;
	char actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_1042_char_to_1042_integer)
{
	// ARRANGE
	char *c = "1042";
	int expected_result = 1042;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_minus_1_char_to_minus_1_integer)
{
	// ARRANGE
	char *c = "-1";
	int expected_result = -1;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_minus_1042_char_to_minus_1042_integer)
{
	// ARRANGE
	char *c = "-1042";
	int expected_result = -1042;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_minus_42_char_to_minus_42_integer)
{
	// ARRANGE
	char *c = "-42 ";
	int expected_result = -42;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_minus_minus_42_char_to_0_integer)
{
	// ARRANGE
	char *c = "--42";
	int expected_result = 0;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_1042e2_char_to_1042_integer)
{
	// ARRANGE
	char *c = "1042e2";
	int expected_result = 1042;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_minus_space_char_to_0_integer)
{
	// ARRANGE
	char *c = "- ";
	int expected_result = 0;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_space_42_char_to_42_integer)
{
	// ARRANGE
	char *c = " 42";
	int expected_result = 42;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_space_letters_42_char_to_0_integer)
{
	// ARRANGE
	char *c = "r42";
	int expected_result = 0;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_space_many_letters_42_char_to_0_integer)
{
	// ARRANGE
	char *c = "dsddsdr42";
	int expected_result = 0;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_plus_42_char_to_42_integer)
{
	// ARRANGE
	char *c = "+42";
	int expected_result = 42;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_plus_plus_42_char_to_0_integer)
{
	// ARRANGE
	char *c = "++42";
	int expected_result = 0;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_042_char_to_42_integer)
{
	// ARRANGE
	char *c = "042";
	int expected_result = 42;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_0042_char_to_42_integer)
{
	// ARRANGE
	char *c = "0042";
	int expected_result = 42;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_plus_minus_42_char_to_0_integer)
{
	// ARRANGE
	char *c = "+-42";
	int expected_result = 0;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_plus_42_plus_5_char_to_42_integer)
{
	// ARRANGE
	char *c = "+42+5";
	int expected_result = 42;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_int_max_char_to_int_max_integer)
{
	// ARRANGE
	char *c = "2147483647";
	int expected_result = 2147483647;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_int_max_plus_one_char_to_int_min_integer)
{
	// ARRANGE
	char *c = "2147483648";
	int expected_result = -2147483648;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_empty_string_char_to_0_integer)
{
	// ARRANGE
	char *c = "";
	int expected_result = 0;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_null_string_char_to_0_integer)
{
	// ARRANGE
	char *c = 0;
	int expected_result = 0;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_plus_sign_and_space_char_to_0_integer)
{
	// ARRANGE
	char *c = "\t\v\f\r\n \f+\t\v\f\r\n \f1234";
	int expected_result = 0;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_atoi_test_suite)
{
	MU_RUN_TEST(test_atoi_convert_1_char_to_1_integer);
	MU_RUN_TEST(test_atoi_convert_2_char_to_2_integer);
	MU_RUN_TEST(test_atoi_convert_42_char_to_42_integer);
	MU_RUN_TEST(test_atoi_convert_1042_char_to_1042_integer);
	MU_RUN_TEST(test_atoi_convert_minus_1_char_to_minus_1_integer);
	MU_RUN_TEST(test_atoi_convert_minus_1042_char_to_minus_1042_integer);
	MU_RUN_TEST(test_atoi_convert_minus_42_char_to_minus_42_integer);
	MU_RUN_TEST(test_atoi_convert_minus_minus_42_char_to_0_integer);
	MU_RUN_TEST(test_atoi_convert_1042e2_char_to_1042_integer);
	MU_RUN_TEST(test_atoi_convert_minus_space_char_to_0_integer);
	MU_RUN_TEST(test_atoi_convert_space_42_char_to_42_integer);
	MU_RUN_TEST(test_atoi_convert_plus_42_char_to_42_integer);
	MU_RUN_TEST(test_atoi_convert_space_letters_42_char_to_0_integer);
	MU_RUN_TEST(test_atoi_convert_space_many_letters_42_char_to_0_integer);
	MU_RUN_TEST(test_atoi_convert_plus_plus_42_char_to_0_integer);
	MU_RUN_TEST(test_atoi_convert_042_char_to_42_integer);
	MU_RUN_TEST(test_atoi_convert_0042_char_to_42_integer);
	MU_RUN_TEST(test_atoi_convert_plus_minus_42_char_to_0_integer);
	MU_RUN_TEST(test_atoi_convert_plus_42_plus_5_char_to_42_integer);
	MU_RUN_TEST(test_atoi_convert_int_max_char_to_int_max_integer);
	MU_RUN_TEST(test_atoi_convert_int_max_plus_one_char_to_int_min_integer);
	MU_RUN_TEST(test_atoi_convert_empty_string_char_to_0_integer);
	MU_RUN_TEST(test_atoi_convert_null_string_char_to_0_integer);
	MU_RUN_TEST(test_atoi_convert_plus_sign_and_space_char_to_0_integer);
}

int main(int argc, char *argv[]) {
	(void) argc;
	(void) argv;
	MU_RUN_SUITE(ft_atoi_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
