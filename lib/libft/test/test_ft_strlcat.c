/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:21:08 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/18 19:39:14 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size);	// Prototype

MU_TEST(test_strlcat_receiving_src_empty_dst_a_size_2_returns_a)
{
	//ARRANGE
	char	*input_src = "";
	char	*input_dst = "a";
	char	*expected = "a";
	int		size = 2;
	char	result[20];
	int		expected_ret = 1;
	int		ret;
	int		is_equal = 1;

	//ACT
	ft_strlcpy(result, input_dst, ft_strlen(input_dst) + 1);
	ret = ft_strlcat(result, input_src, size);
	if (strcmp(expected, result) == 0 && ret == expected_ret)
		is_equal = 0;

	//ASSERT
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strlcat_receiving_src_a_dst_empty_size_2_returns_a)
{
	//ARRANGE
	char	*input_src = "a";
	char	*input_dst = "";
	char	*expected = "a";
	int		size = 2;
	char	result[20];
	int		expected_ret = 1;
	int		ret;
	int		is_equal = 1;

	//ACT
	ft_strlcpy(result, input_dst, ft_strlen(input_dst) + 1);
	ret = ft_strlcat(result, input_src, size);
	if (strcmp(expected, result) == 0 && ret == expected_ret)
		is_equal = 0;

	//ASSERT
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strlcat_receiving_src_abc_dst_1234_size_5_returns_a)
{
	//ARRANGE
	char	*input_src = "1234";
	char	*input_dst = "abc";
	char	*expected = "abc1";
	int		size = 5;
	char	result[20];
	int		expected_ret = 7;
	int		ret;
	int		is_equal = 1;

	//ACT
	ft_strlcpy(result, input_dst, ft_strlen(input_dst) + 1);
	ret = ft_strlcat(result, input_src, size);
	if (strcmp(expected, result) == 0 && ret == expected_ret)
		is_equal = 0;

	//ASSERT
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strlcat_receiving_src_abc_dst_1234_size_3_returns_a)
{
	//ARRANGE
	char	*input_src = "1234";
	char	*input_dst = "abc";
	char	*expected = "abc";
	int		size = 3;
	char	result[20];
	int		expected_ret = 7;
	int		ret;
	int		is_equal = 1;

	//ACT
	ft_strlcpy(result, input_dst, ft_strlen(input_dst) + 1);
	ret = ft_strlcat(result, input_src, size);
	if (strcmp(expected, result) == 0 && ret == expected_ret)
		is_equal = 0;

	//ASSERT
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strlcat_receiving_src_abc_dst_1234_size_9_returns_a)
{
	//ARRANGE
	char	*input_src = "1234";
	char	*input_dst = "abc";
	char	*expected = "abc1234";
	int		size = 9;
	char	result[20];
	int		expected_ret = 7;
	int		ret;
	int		is_equal = 1;

	//ACT
	ft_strlcpy(result, input_dst, ft_strlen(input_dst) + 1);
	ret = ft_strlcat(result, input_src, size);
	if (strcmp(expected, result) == 0 && ret == expected_ret)
		is_equal = 0;

	//ASSERT
	mu_assert_int_eq(0, is_equal);
}

MU_TEST_SUITE(ft_strcat_test_suite)
{
	MU_RUN_TEST(test_strlcat_receiving_src_empty_dst_a_size_2_returns_a);
	MU_RUN_TEST(test_strlcat_receiving_src_a_dst_empty_size_2_returns_a);
	MU_RUN_TEST(test_strlcat_receiving_src_abc_dst_1234_size_5_returns_a);
	MU_RUN_TEST(test_strlcat_receiving_src_abc_dst_1234_size_3_returns_a);
	MU_RUN_TEST(test_strlcat_receiving_src_abc_dst_1234_size_9_returns_a);
}

int main(int argc, char *argv[]) {
	(void) argc;
	(void) argv;
	MU_RUN_SUITE(ft_strcat_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
