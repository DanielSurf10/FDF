/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:21:08 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/19 13:52:11 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "libft.h"

void	*ft_calloc(size_t num_elem, size_t size);	// Prototype

MU_TEST(test_calloc_receiving_nelem_1_size_1)
{
	//ARRANGE
	int		num_elem = 1;
	int		size = 1;
	char	expected_result[num_elem * size];
	char	*actual_result;
	int		is_equal = 1;
	ft_bzero(expected_result, num_elem * size);

	//ACT
	actual_result = (char *) ft_calloc(num_elem, size);

	//ASSERT
	if (actual_result != NULL)
	{
		if (ft_memcmp(expected_result, actual_result, num_elem * size) == 0)
			is_equal = 0;
	}
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_calloc_receiving_nelem_2_size_2)
{
	//ARRANGE
	int		num_elem = 2;
	int		size = 2;
	char	expected_result[num_elem * size];
	char	*actual_result;
	int		is_equal = 1;
	ft_bzero(expected_result, num_elem * size);

	//ACT
	actual_result = (char *) ft_calloc(num_elem, size);

	//ASSERT
	if (actual_result != NULL)
	{
		if (ft_memcmp(expected_result, actual_result, num_elem * size) == 0)
			is_equal = 0;
	}
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_calloc_receiving_nelem_1000_size_16)
{
	//ARRANGE
	int		num_elem = 1000;
	int		size = 16;
	char	expected_result[num_elem * size];
	char	*actual_result;
	int		is_equal = 1;
	ft_bzero(expected_result, num_elem * size);

	//ACT
	actual_result = (char *) ft_calloc(num_elem, size);

	//ASSERT
	if (actual_result != NULL)
	{
		if (ft_memcmp(expected_result, actual_result, size) == 0)
			is_equal = 0;
	}
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_calloc_receiving_nelem_0_size_16)
{
	//ARRANGE
	int		num_elem = 0;
	int		size = 16;
	// char	expected_result[num_elem * size];
	char	*actual_result;
	int		is_equal = 1;
	// ft_bzero(expected_result, total_size);

	//ACT
	actual_result = (char *) ft_calloc(num_elem, size);

	//ASSERT
	if (actual_result != NULL)
		is_equal = 0;
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_calloc_overflow_receiving_nelem_size_t_max_size_16)
{
	//ARRANGE
	size_t		num_elem = -1;			// size_t max
	size_t		size = 16;
	// char	expected_result[num_elem * size];
	char	*actual_result;
	int		is_equal = 1;
	// ft_bzero(expected_result, total_size);

	//ACT
	actual_result = (char *) ft_calloc(num_elem, size);

	//ASSERT
	if (actual_result == NULL)
		is_equal = 0;
	mu_assert_int_eq(0, is_equal);
}

MU_TEST_SUITE(ft_calloc_test_suite)
{
	MU_RUN_TEST(test_calloc_receiving_nelem_1_size_1);
	MU_RUN_TEST(test_calloc_receiving_nelem_2_size_2);
	MU_RUN_TEST(test_calloc_receiving_nelem_1000_size_16);
	MU_RUN_TEST(test_calloc_receiving_nelem_0_size_16);
	MU_RUN_TEST(test_calloc_overflow_receiving_nelem_size_t_max_size_16);
}

int main(int argc, char *argv[]) {
	(void) argc;
	(void) argv;
	MU_RUN_SUITE(ft_calloc_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
