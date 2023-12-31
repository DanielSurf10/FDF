/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:21:08 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/20 20:46:26 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "libft.h"
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2);	// Prototype

MU_TEST(test_strjoin_receiving_a_and_empty_returns_a)
{
	//ARRANGE
	char	*input_s1 = "a";
	char	*input_s2 = "";
	char	*expected_result = "a";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_strjoin(input_s1, input_s2);

	//ASSERT
	is_equal = ft_strncmp(expected_result, actual_result, ft_strlen(expected_result));
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strjoin_receiving_empty_and_a_returns_a)
{
	//ARRANGE
	char	*input_s1 = "";
	char	*input_s2 = "a";
	char	*expected_result = "a";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_strjoin(input_s1, input_s2);

	//ASSERT
	is_equal = ft_strncmp(expected_result, actual_result, ft_strlen(expected_result));
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strjoin_receiving_a_and_a_returns_aa)
{
	//ARRANGE
	char	*input_s1 = "a";
	char	*input_s2 = "a";
	char	*expected_result = "aa";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_strjoin(input_s1, input_s2);

	//ASSERT
	is_equal = ft_strncmp(expected_result, actual_result, ft_strlen(expected_result));
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strjoin_receiving_ab_and_c_returns_abc)
{
	//ARRANGE
	char	*input_s1 = "ab";
	char	*input_s2 = "c";
	char	*expected_result = "abc";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_strjoin(input_s1, input_s2);

	//ASSERT
	is_equal = ft_strncmp(expected_result, actual_result, ft_strlen(expected_result));
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strjoin_receiving_bom_and_dia_returns_bomdia)
{
	//ARRANGE
	char	*input_s1 = "bom";
	char	*input_s2 = "dia";
	char	*expected_result = "bomdia";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_strjoin(input_s1, input_s2);

	//ASSERT
	is_equal = ft_strncmp(expected_result, actual_result, ft_strlen(expected_result));
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strjoin_receiving_null_and_dia_returns_dia)
{
	//ARRANGE
	char	*input_s1 = 0;
	char	*input_s2 = "dia";
	char	*expected_result = "dia";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_strjoin(input_s1, input_s2);

	//ASSERT
	is_equal = ft_strncmp(expected_result, actual_result, ft_strlen(expected_result));
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strjoin_receiving_bom_and_null_returns_bom)
{
	//ARRANGE
	char	*input_s1 = "bom";
	char	*input_s2 = 0;
	char	*expected_result = "bom";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_strjoin(input_s1, input_s2);

	//ASSERT
	is_equal = ft_strncmp(expected_result, actual_result, ft_strlen(expected_result));
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strjoin_receiving_empty_and_empty_returns_empty)
{
	//ARRANGE
	char	*input_s1 = "";
	char	*input_s2 = "";
	char	*expected_result = "";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_strjoin(input_s1, input_s2);

	//ASSERT
	is_equal = ft_strncmp(expected_result, actual_result, ft_strlen(expected_result));
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strjoin_receiving_null_and_null_returns_null)
{
	//ARRANGE
	char	*input_s1 = 0;
	char	*input_s2 = 0;
	char	*expected_result = "";
	char	*actual_result;
	int		is_equal = 1;

	//ACT
	actual_result = ft_strjoin(input_s1, input_s2);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST_SUITE(ft_strjoin_test_suite)
{
	MU_RUN_TEST(test_strjoin_receiving_a_and_empty_returns_a);
	MU_RUN_TEST(test_strjoin_receiving_empty_and_a_returns_a);
	MU_RUN_TEST(test_strjoin_receiving_a_and_a_returns_aa);
	MU_RUN_TEST(test_strjoin_receiving_ab_and_c_returns_abc);
	MU_RUN_TEST(test_strjoin_receiving_bom_and_dia_returns_bomdia);
	MU_RUN_TEST(test_strjoin_receiving_null_and_dia_returns_dia);
	MU_RUN_TEST(test_strjoin_receiving_bom_and_null_returns_bom);
	MU_RUN_TEST(test_strjoin_receiving_empty_and_empty_returns_empty);
	MU_RUN_TEST(test_strjoin_receiving_null_and_null_returns_null);
}

int main(int argc, char *argv[]) {
	(void) argc;
	(void) argv;
	MU_RUN_SUITE(ft_strjoin_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
