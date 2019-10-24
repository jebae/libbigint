/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_strassen_mul_bi_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:01:28 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:01:29 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

static int	copy_arr(t_bigint *arr, t_bigint **copy, size_t size)
{
	size_t		i;

	if ((*copy = ft_memalloc(sizeof(t_bigint) * size)) == NULL)
		return (BI_FAIL);
	i = 0;
	while (i < size)
	{
		(*copy)[i] = arr[i];
		i++;
	}
	return (BI_SUCCESS);
}

size_t		bi_strassen_mul_get_block_length(t_bigint *a, t_bigint *b)
{
	size_t			length;
	size_t			min;

	length = 32;
	min = bi_max_bit(a) + bi_max_bit(b);
	min = min / BI_UNIT_BITS + ((min % BI_UNIT_BITS) ? 1 : 0);
	while (length < min)
		length <<= 1;
	return (length);
}

int			bi_strassen_mul_shuffle_order(t_bigint *arr, size_t size)
{
	size_t		num_bits;
	size_t		i;
	t_bigint	*copy;

	if (size == 0)
		return (BI_SUCCESS);
	if (copy_arr(arr, &copy, size) == BI_FAIL)
		return (BI_FAIL);
	num_bits = ft_int_log2(size);
	i = 0;
	while (i < size)
	{
		arr[i] = copy[ft_bit_reverse(i, num_bits)];
		arr[i].sign = BI_SIGN_POSITIVE;
		i++;
	}
	ft_memdel((void **)&copy);
	return (BI_SUCCESS);
}

int			bi_strassen_mul_pointwise_prod(
	t_bigint *a_arr,
	t_bigint *b_arr,
	size_t n
)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		if (bi_mul_bi(a_arr + i, b_arr + i, a_arr + i) == BI_FAIL)
			return (BI_FAIL);
		if (bi_mod_n_pow_of_2_plus_1(a_arr + i, n, a_arr + i) == BI_FAIL)
			return (BI_FAIL);
		i++;
	}
	return (BI_SUCCESS);
}

void		bi_strassen_invsere_array(t_bigint *arr, size_t n)
{
	t_bigint	temp;
	size_t		i;

	i = 1;
	while (i < (n >> 1))
	{
		temp = arr[i];
		arr[i] = arr[n - i];
		arr[n - i] = temp;
		i++;
	}
}
