/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:21:08 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/26 18:27:49 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "libft.h"

char	**ft_split(char const *s, char c);	// Prototype

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (s1[i] != s2[i])
		return (1);
	return (0);
}

void	free_split(char **split)
{
	int	i = 0;

	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split[i]);
	free(split);
}

MU_TEST(test_split_receiving_bom_sep_1_bom)
{
	//ARRANGE
	char	*input = "bom";
	char	sep = '1';
	char	**expected_result = malloc(sizeof(char *) * 10);
	char	**actual_result;
	int		is_equal;
	int		i = 0;
	expected_result[0] = "bom";
	expected_result[1] = NULL;

	//ACT
	actual_result = ft_split((char *) input, sep);

	//ASSERT
	while (expected_result[i] != NULL && ft_strcmp(expected_result[i], actual_result[i]) == 0)
		i++;
	if (expected_result[i] == NULL)
		is_equal = 0;
	else
		is_equal = 1;
	free_split(actual_result);
	free(expected_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_split_receiving_1bom_sep_1_bom)
{
	//ARRANGE
	char	*input = "1bom";
	char	sep = '1';
	char	**expected_result = malloc(sizeof(char *) * 10);
	char	**actual_result;
	int		is_equal;
	int		i = 0;
	expected_result[0] = "bom";
	expected_result[1] = NULL;

	//ACT
	actual_result = ft_split((char *) input, sep);

	//ASSERT
	while (expected_result[i] != NULL && ft_strcmp(expected_result[i], actual_result[i]) == 0)
		i++;
	if (expected_result[i] == NULL)
		is_equal = 0;
	else
		is_equal = 1;
	free_split(actual_result);
	free(expected_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_split_receiving_111bom_sep_1_bom)
{
	//ARRANGE
	char	*input = "111bom";
	char	sep = '1';
	char	**expected_result = malloc(sizeof(char *) * 10);
	char	**actual_result;
	int		is_equal;
	int		i = 0;
	expected_result[0] = "bom";
	expected_result[1] = NULL;

	//ACT
	actual_result = ft_split((char *) input, sep);

	//ASSERT
	while (expected_result[i] != NULL && ft_strcmp(expected_result[i], actual_result[i]) == 0)
		i++;
	if (expected_result[i] == NULL)
		is_equal = 0;
	else
		is_equal = 1;
	free_split(actual_result);
	free(expected_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_split_receiving_bom1_sep_1_bom)
{
	//ARRANGE
	char	*input = "bom1";
	char	sep = '1';
	char	**expected_result = malloc(sizeof(char *) * 10);
	char	**actual_result;
	int		is_equal;
	int		i = 0;
	expected_result[0] = "bom";
	expected_result[1] = NULL;

	//ACT
	actual_result = ft_split((char *) input, sep);

	//ASSERT
	while (expected_result[i] != NULL && ft_strcmp(expected_result[i], actual_result[i]) == 0)
		i++;
	if (expected_result[i] == NULL)
		is_equal = 0;
	else
		is_equal = 1;
	free_split(actual_result);
	free(expected_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_split_receiving_bom111_sep_1_bom)
{
	//ARRANGE
	char	*input = "bom111";
	char	sep = '1';
	char	**expected_result = malloc(sizeof(char *) * 10);
	char	**actual_result;
	int		is_equal;
	int		i = 0;
	expected_result[0] = "bom";
	expected_result[1] = NULL;

	//ACT
	actual_result = ft_split((char *) input, sep);

	//ASSERT
	while (expected_result[i] != NULL && ft_strcmp(expected_result[i], actual_result[i]) == 0)
		i++;
	if (expected_result[i] == NULL)
		is_equal = 0;
	else
		is_equal = 1;
	free_split(actual_result);
	free(expected_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_split_receiving_1bom1_sep_1_bom)
{
	//ARRANGE
	char	*input = "1bom1";
	char	sep = '1';
	char	**expected_result = malloc(sizeof(char *) * 10);
	char	**actual_result;
	int		is_equal;
	int		i = 0;
	expected_result[0] = "bom";
	expected_result[1] = NULL;

	//ACT
	actual_result = ft_split((char *) input, sep);

	//ASSERT
	while (expected_result[i] != NULL && ft_strcmp(expected_result[i], actual_result[i]) == 0)
		i++;
	if (expected_result[i] == NULL)
		is_equal = 0;
	else
		is_equal = 1;
	free_split(actual_result);
	free(expected_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_split_receiving_111bom111_sep_1_bom)
{
	//ARRANGE
	char	*input = "111bom111";
	char	sep = '1';
	char	**expected_result = malloc(sizeof(char *) * 10);
	char	**actual_result;
	int		is_equal;
	int		i = 0;
	expected_result[0] = "bom";
	expected_result[1] = NULL;

	//ACT
	actual_result = ft_split((char *) input, sep);

	//ASSERT
	while (expected_result[i] != NULL && ft_strcmp(expected_result[i], actual_result[i]) == 0)
		i++;
	if (expected_result[i] == NULL)
		is_equal = 0;
	else
		is_equal = 1;
	free_split(actual_result);
	free(expected_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_split_receiving_bom1dia_sep_1_bom_dia)
{
	//ARRANGE
	char	*input = "bom1dia";
	char	sep = '1';
	char	**expected_result = malloc(sizeof(char *) * 10);
	char	**actual_result;
	int		is_equal;
	int		i = 0;
	expected_result[0] = "bom";
	expected_result[1] = "dia";
	expected_result[2] = NULL;

	//ACT
	actual_result = ft_split((char *) input, sep);

	//ASSERT
	while (expected_result[i] != NULL && ft_strcmp(expected_result[i], actual_result[i]) == 0)
		i++;
	if (expected_result[i] == NULL)
		is_equal = 0;
	else
		is_equal = 1;
	free_split(actual_result);
	free(expected_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_split_receiving_bom1111dia_sep_1_bom_dia)
{
	//ARRANGE
	char	*input = "bom111dia";
	char	sep = '1';
	char	**expected_result = malloc(sizeof(char *) * 10);
	char	**actual_result;
	int		is_equal;
	int		i = 0;
	expected_result[0] = "bom";
	expected_result[1] = "dia";
	expected_result[2] = NULL;

	//ACT
	actual_result = ft_split((char *) input, sep);

	//ASSERT
	while (expected_result[i] != NULL && ft_strcmp(expected_result[i], actual_result[i]) == 0)
		i++;
	if (expected_result[i] == NULL)
		is_equal = 0;
	else
		is_equal = 1;
	free_split(actual_result);
	free(expected_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_split_receiving_1bom1111dia1_sep_1_bom_dia)
{
	//ARRANGE
	char	*input = "bom111dia";
	char	sep = '1';
	char	**expected_result = malloc(sizeof(char *) * 10);
	char	**actual_result;
	int		is_equal;
	int		i = 0;
	expected_result[0] = "bom";
	expected_result[1] = "dia";
	expected_result[2] = NULL;

	//ACT
	actual_result = ft_split((char *) input, sep);

	//ASSERT
	while (expected_result[i] != NULL && ft_strcmp(expected_result[i], actual_result[i]) == 0)
		i++;
	if (expected_result[i] == NULL)
		is_equal = 0;
	else
		is_equal = 1;
	free_split(actual_result);
	free(expected_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_split_receiving_111bom1111dia111_sep_1_bom_dia)
{
	//ARRANGE
	char	*input = "bom111dia";
	char	sep = '1';
	char	**expected_result = malloc(sizeof(char *) * 10);
	char	**actual_result;
	int		is_equal;
	int		i = 0;
	expected_result[0] = "bom";
	expected_result[1] = "dia";
	expected_result[2] = NULL;

	//ACT
	actual_result = ft_split((char *) input, sep);

	//ASSERT
	while (expected_result[i] != NULL && ft_strcmp(expected_result[i], actual_result[i]) == 0)
		i++;
	if (expected_result[i] == NULL)
		is_equal = 0;
	else
		is_equal = 1;
	free_split(actual_result);
	free(expected_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_split_receiving_11111_sep_1_null)
{
	//ARRANGE
	char	*input = "11111";
	char	sep = '1';
	char	**expected_result = malloc(sizeof(char *) * 10);
	char	**actual_result;
	int		is_equal;
	int		i = 0;
	expected_result[0] = NULL;

	//ACT
	actual_result = ft_split((char *) input, sep);

	//ASSERT
	if (actual_result[i] == NULL)
		is_equal = 0;
	else
		is_equal = 1;
	free_split(actual_result);
	free(expected_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_split_receiving_empty_sep_1_null)
{
	//ARRANGE
	char	*input = "";
	char	sep = '1';
	char	**expected_result = malloc(sizeof(char *) * 10);
	char	**actual_result;
	int		is_equal;
	int		i = 0;
	expected_result[0] = NULL;

	//ACT
	actual_result = ft_split((char *) input, sep);

	//ASSERT
	if (actual_result[i] == NULL)
		is_equal = 0;
	else
		is_equal = 1;
	free_split(actual_result);
	free(expected_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_split_receiving_11bom11dia11tudo11bem11_sep_1_bom_dia)
{
	//ARRANGE
	char	*input = "11bom11dia11tudo11bem11";
	char	sep = '1';
	char	**expected_result = malloc(sizeof(char *) * 10);
	char	**actual_result;
	int		is_equal;
	int		i = 0;
	expected_result[0] = "bom";
	expected_result[1] = "dia";
	expected_result[2] = "tudo";
	expected_result[3] = "bem";
	expected_result[4] = NULL;

	//ACT
	actual_result = ft_split((char *) input, sep);

	//ASSERT
	while (expected_result[i] != NULL && ft_strcmp(expected_result[i], actual_result[i]) == 0)
		i++;
	if (expected_result[i] == NULL)
		is_equal = 0;
	else
		is_equal = 1;
	free_split(actual_result);
	free(expected_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_split_receiving_bom1dia111tudo1111bem_sep_1_bom_dia)
{
	//ARRANGE
	char	*input = "11bom11dia11tudo11bem11";
	char	sep = '1';
	char	**expected_result = malloc(sizeof(char *) * 10);
	char	**actual_result;
	int		is_equal;
	int		i = 0;
	expected_result[0] = "bom";
	expected_result[1] = "dia";
	expected_result[2] = "tudo";
	expected_result[3] = "bem";
	expected_result[4] = NULL;

	//ACT
	actual_result = ft_split((char *) input, sep);

	//ASSERT
	while (expected_result[i] != NULL && ft_strcmp(expected_result[i], actual_result[i]) == 0)
		i++;
	if (expected_result[i] == NULL)
		is_equal = 0;
	else
		is_equal = 1;
	free_split(actual_result);
	free(expected_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_split_um_teste_maluco)
{
	//ARRANGE
	char	*input = "^^^1^^2a,^^^^3^^^^--h^^^^";
	char	sep = '^';
	char	**expected_result = malloc(sizeof(char *) * 10);
	char	**actual_result;
	int		is_equal;
	int		i = 0;
	expected_result[0] = "1";
	expected_result[1] = "2a,";
	expected_result[2] = "3";
	expected_result[3] = "--h";
	expected_result[4] = NULL;

	//ACT
	actual_result = ft_split((char *) input, sep);

	//ASSERT
	while (expected_result[i] != NULL && ft_strcmp(expected_result[i], actual_result[i]) == 0)
		i++;
	if (expected_result[i] == NULL)
		is_equal = 0;
	else
		is_equal = 1;
	free_split(actual_result);
	free(expected_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST_SUITE(ft_split_test_suite)
{
	MU_RUN_TEST(test_split_receiving_bom_sep_1_bom);
	MU_RUN_TEST(test_split_receiving_1bom_sep_1_bom);
	MU_RUN_TEST(test_split_receiving_111bom_sep_1_bom);
	MU_RUN_TEST(test_split_receiving_bom1_sep_1_bom);
	MU_RUN_TEST(test_split_receiving_bom111_sep_1_bom);
	MU_RUN_TEST(test_split_receiving_1bom1_sep_1_bom);
	MU_RUN_TEST(test_split_receiving_111bom111_sep_1_bom);
	MU_RUN_TEST(test_split_receiving_bom1dia_sep_1_bom_dia);
	MU_RUN_TEST(test_split_receiving_bom1111dia_sep_1_bom_dia);
	MU_RUN_TEST(test_split_receiving_1bom1111dia1_sep_1_bom_dia);
	MU_RUN_TEST(test_split_receiving_111bom1111dia111_sep_1_bom_dia);
	MU_RUN_TEST(test_split_receiving_11111_sep_1_null);
	MU_RUN_TEST(test_split_receiving_empty_sep_1_null);
	MU_RUN_TEST(test_split_receiving_11bom11dia11tudo11bem11_sep_1_bom_dia);
	MU_RUN_TEST(test_split_receiving_bom1dia111tudo1111bem_sep_1_bom_dia);
	MU_RUN_TEST(test_split_um_teste_maluco);
}

int main(int argc, char *argv[]) {
	(void) argc;
	(void) argv;
	MU_RUN_SUITE(ft_split_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
