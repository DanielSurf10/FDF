/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:21:08 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/29 21:35:26 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "libft.h"
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c);	// Prototype

MU_TEST(test_strrchr_receiving_str_a_char_a_returns_a)
{
	//ARRANGE
	char	*input_str = "a";
	char	input_char = 'a';
	char	*expected = "a";
	char	*result;
	int		is_equal = 1;

	//ACT
	result = ft_strrchr(input_str, input_char);
	is_equal = strcmp(expected, result);

	//ASSERT
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strrchr_receiving_str_cba_char_a_returns_a)
{
	//ARRANGE
	char	*input_str = "cba";
	char	input_char = 'a';
	char	*expected = "a";
	char	*result;
	int		is_equal = 1;

	//ACT
	result = ft_strrchr(input_str, input_char);
	is_equal = strcmp(expected, result);

	//ASSERT
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strrchr_receiving_str_cba_char_b_returns_ba)
{
	//ARRANGE
	char	*input_str = "cba";
	char	input_char = 'b';
	char	*expected = "ba";
	char	*result;
	int		is_equal = 1;

	//ACT
	result = ft_strrchr(input_str, input_char);
	is_equal = strcmp(expected, result);

	//ASSERT
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strrchr_receiving_str_abcd_char_t_returns_null)
{
	//ARRANGE
	char	*input_str = "abcd";
	char	input_char = 't';
	char	*expected = NULL;
	char	*result;
	int		is_equal = 1;

	//ACT
	result = ft_strrchr(input_str, input_char);
	is_equal = result == expected ? 0 : 1;

	//ASSERT
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strrchr_receiving_str_abcd_char_null_char_returns_null_char)
{
	//ARRANGE
	char	*input_str = "abcd";
	char	input_char = '\0';
	char	*expected = strrchr(input_str, '\0');
	char	*result;
	int		is_equal = 1;

	//ACT
	result = ft_strrchr(input_str, input_char);
	if (result != NULL)
		is_equal = strcmp(expected, result);

	//ASSERT
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_strrchr_receiving_str_abcd_char_1024_char_returns_null_char)
{
	//ARRANGE
	char	*input_str = "abcd";
	int		input_char = 1024;
	// char	*expected = "";
	char	*result;
	int		is_equal = 1;

	//ACT
	result = ft_strrchr(input_str, input_char);
	if (&input_str[ft_strlen(input_str)] == result)
		is_equal = 0;
	else
		is_equal = 1;
	// is_equal = strcmp(expected, result);

	//ASSERT
	mu_assert_int_eq(0, is_equal);
}

MU_TEST_SUITE(ft_strrchr_test_suite)
{
	MU_RUN_TEST(test_strrchr_receiving_str_a_char_a_returns_a);
	MU_RUN_TEST(test_strrchr_receiving_str_cba_char_a_returns_a);
	MU_RUN_TEST(test_strrchr_receiving_str_cba_char_b_returns_ba);
	MU_RUN_TEST(test_strrchr_receiving_str_abcd_char_t_returns_null);
	MU_RUN_TEST(test_strrchr_receiving_str_abcd_char_null_char_returns_null_char);
	MU_RUN_TEST(test_strrchr_receiving_str_abcd_char_1024_char_returns_null_char);
}

int main(int argc, char *argv[]) {
	(void) argc;
	(void) argv;
	MU_RUN_SUITE(ft_strrchr_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
