/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:21:08 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/21 17:01:04 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strtrim(char const *str, char const *set);	// Prototype

MU_TEST(test_strtrim_receiving_str_a_set_empty_returns_a)
{
	//ARRANGE
	char	*input = "a";
	char	*set = "";
	char	*expected_result = "a";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_strtrim(input, set);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strtrim_receiving_str_a_set_space_returns_a)
{
	//ARRANGE
	char	*input = "a";
	char	*set = " ";
	char	*expected_result = "a";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_strtrim(input, set);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strtrim_receiving_str_za_set_z_returns_a)
{
	//ARRANGE
	char	*input = "za";
	char	*set = "z";
	char	*expected_result = "a";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_strtrim(input, set);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strtrim_receiving_str_zzzza_set_z_returns_a)
{
	//ARRANGE
	char	*input = "zzzza";
	char	*set = "z";
	char	*expected_result = "a";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_strtrim(input, set);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strtrim_receiving_str_abacaBomdia_set_abc_returns_Bomdi)
{
	//ARRANGE
	char	*input = "abacaBomdia";
	char	*set = "abc";
	char	*expected_result = "Bomdi";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_strtrim(input, set);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strtrim_receiving_str_az_set_z_returns_a)
{
	//ARRANGE
	char	*input = "az";
	char	*set = "z";
	char	*expected_result = "a";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_strtrim(input, set);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strtrim_receiving_str_azzzzz_set_z_returns_a)
{
	//ARRANGE
	char	*input = "azzzzz";
	char	*set = "z";
	char	*expected_result = "a";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_strtrim(input, set);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strtrim_receiving_str_zaz_set_z_returns_a)
{
	//ARRANGE
	char	*input = "zaz";
	char	*set = "z";
	char	*expected_result = "a";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_strtrim(input, set);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strtrim_receiving_str_zzzzz_set_z_returns_empty)
{
	//ARRANGE
	char	*input = "zzzzz";
	char	*set = "z";
	char	*expected_result = "";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = ft_strtrim(input, set);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST_SUITE(ft_strtrim_test_suite)
{
	MU_RUN_TEST(test_strtrim_receiving_str_a_set_empty_returns_a);
	MU_RUN_TEST(test_strtrim_receiving_str_a_set_space_returns_a);
	MU_RUN_TEST(test_strtrim_receiving_str_za_set_z_returns_a);
	MU_RUN_TEST(test_strtrim_receiving_str_zzzza_set_z_returns_a);
	MU_RUN_TEST(test_strtrim_receiving_str_abacaBomdia_set_abc_returns_Bomdi);
	MU_RUN_TEST(test_strtrim_receiving_str_az_set_z_returns_a);
	MU_RUN_TEST(test_strtrim_receiving_str_azzzzz_set_z_returns_a);
	MU_RUN_TEST(test_strtrim_receiving_str_zaz_set_z_returns_a);
	MU_RUN_TEST(test_strtrim_receiving_str_zzzzz_set_z_returns_empty);
}

int main(int argc, char *argv[]) {
	(void) argc;
	(void) argv;
	MU_RUN_SUITE(ft_strtrim_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
