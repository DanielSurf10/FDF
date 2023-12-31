/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:21:08 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/17 20:23:06 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size);	// Prototype

MU_TEST(test_strlcpy_receiving_a_returns_a)
{
	//ARRANGE
	char	*input = "a";
	char	*expected = "a";
	int		ret_expected = 1;
	int		size = 2;
	char	result[20];
	int		ret_result;
	int		is_equal = 1;

	//ACT
	ret_result = ft_strlcpy(result, input, size);
	if (strcmp(expected, result) == 0 && ret_expected == ret_result)
		is_equal = 0;

	//ASSERT
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strlcpy_receiving_abc_size_4_returns_abc)
{
	//ARRANGE
	char	*input = "abc";
	char	*expected = "abc";
	int		ret_expected = 3;
	int		size = 4;
	char	result[20];
	int		ret_result;
	int		is_equal = 1;

	//ACT
	ret_result = ft_strlcpy(result, input, size);
	if (strcmp(expected, result) == 0 && ret_expected == ret_result)
		is_equal = 0;

	//ASSERT
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strlcpy_receiving_abc1234_size_4_returns_abc)
{
	//ARRANGE
	char	*input = "abc1234";
	char	*expected = "abc";
	int		ret_expected = 7;
	int		size = 4;
	char	result[20];
	int		ret_result;
	int		is_equal = 1;

	//ACT
	ret_result = ft_strlcpy(result, input, size);
	if (strcmp(expected, result) == 0 && ret_expected == ret_result)
		is_equal = 0;

	//ASSERT
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strlcpy_receiving_abc1234_size_9_returns_abc1234)
{
	//ARRANGE
	char	*input = "abc1234";
	char	*expected = "abc1234";
	int		ret_expected = 7;
	int		size = 9;
	char	result[20];
	int		ret_result;
	int		is_equal = 1;

	//ACT
	ret_result = ft_strlcpy(result, input, size);
	if (strcmp(expected, result) == 0 && ret_expected == ret_result)
		is_equal = 0;

	//ASSERT
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strlcpy_receiving_abc1234_size_0_returns_empty)
{
	//ARRANGE
	char	*input = "abc1234";
	// char	*expected = "";
	int		ret_expected = 7;
	int		size = 0;
	char	result[20];
	int		ret_result;
	int		is_equal = 1;
	int		i = 0;

	//ACT
	memset(result, 0, 20);
	ret_result = ft_strlcpy(result, input, size);

	//ASSERT
	if (ret_expected == ret_result)
		is_equal = 0;
	while (i < 20)
	{
		if (result[i] != 0)
			is_equal = 1;		// Não está igual
		i++;
	}
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strlcpy_receiving_empty_size_9_returns_empty)
{
	//ARRANGE
	char	*input = "";
	char	*expected = "";
	int		ret_expected = 9;
	int		size = 9;
	char	result[20];
	int		ret_result;
	int		is_equal = 1;
	int		i = 0;

	//ACT
	memset(result, 0, 20);
	ret_result = ft_strlcpy(result, input, size);

	//ASSERT
	if (ret_expected == ret_result)
		is_equal = 0;
	while (i < 20)
	{
		if (result[i] != 0)
			is_equal = 1;		// Não está igual
		i++;
	}
	is_equal = strcmp(expected, result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strlcpy_receiving_empty_size_0_returns_empty)
{
	//ARRANGE
	char	*input = "";
	char	*expected = "";
	int		ret_expected = 0;
	int		size = 0;
	char	result[20];
	int		ret_result;
	int		is_equal = 1;
	int		i = 0;

	//ACT
	memset(result, 0, 20);
	ret_result = ft_strlcpy(result, input, size);

	//ASSERT
	if (ret_expected == ret_result)
		is_equal = 0;
	while (i < 20)
	{
		if (result[i] != 0)
			is_equal = 1;		// Não está igual
		i++;
	}
	is_equal = strcmp(expected, result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST_SUITE(ft_strlcpy_test_suite)
{
	MU_RUN_TEST(test_strlcpy_receiving_a_returns_a);
	MU_RUN_TEST(test_strlcpy_receiving_abc_size_4_returns_abc);
	MU_RUN_TEST(test_strlcpy_receiving_abc1234_size_4_returns_abc);
	MU_RUN_TEST(test_strlcpy_receiving_abc1234_size_9_returns_abc1234);
	MU_RUN_TEST(test_strlcpy_receiving_abc1234_size_0_returns_empty);
	MU_RUN_TEST(test_strlcpy_receiving_empty_size_9_returns_empty);
	MU_RUN_TEST(test_strlcpy_receiving_empty_size_0_returns_empty);
}

int main(int argc, char *argv[]) {
	(void) argc;
	(void) argv;
	MU_RUN_SUITE(ft_strlcpy_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
