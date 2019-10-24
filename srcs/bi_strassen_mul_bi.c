/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_strassen_mul_bi.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:01:26 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:01:26 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

static int		handle_return(
	t_bigint *a_arr,
	t_bigint *b_arr,
	size_t n,
	int ret
)
{
	bi_del_bi_array(a_arr, n);
	bi_del_bi_array(b_arr, n);
	return (ret);
}

static int		fft_loop_by_level(
	t_bigint *arr,
	size_t n,
	t_bi_strassen_mul_fft_vars *v
)
{
	size_t		j;
	size_t		k;
	size_t		e;

	j = 0;
	e = 0;
	while (j < v->m2)
	{
		k = j;
		while (k < n)
		{
			if (bi_left_shift(arr + k + v->m2, e, &(v->t)) == BI_FAIL ||
				bi_sub_bi(arr + k, &(v->t), arr + k + v->m2) == BI_FAIL ||
				bi_add_bi(arr + k, &(v->t), arr + k) == BI_FAIL ||
				bi_mod_n_pow_of_2_plus_1(arr + k, n, arr + k) == BI_FAIL ||
				bi_mod_n_pow_of_2_plus_1(
					arr + k + v->m2, n, arr + k + v->m2) == BI_FAIL)
				return (BI_FAIL);
			k += v->m;
		}
		e += v->em;
		j++;
	}
	return (BI_SUCCESS);
}

static int		fft(t_bigint *arr, size_t n, unsigned int log2n)
{
	size_t						i;
	t_bi_strassen_mul_fft_vars	v;

	if (bi_strassen_mul_shuffle_order(arr, n) == BI_FAIL)
		return (BI_FAIL);
	bi_init(&v.t);
	i = 1;
	while (i <= log2n)
	{
		v.m = 1 << i;
		v.m2 = v.m >> 1;
		v.em = 1 << (log2n - i + 1);
		if (fft_loop_by_level(arr, n, &v) == BI_FAIL)
		{
			bi_del(&v.t);
			return (BI_FAIL);
		}
		i++;
	}
	bi_del(&v.t);
	return (BI_SUCCESS);
}

static int		ifft(t_bigint *arr, size_t n, unsigned int log2n)
{
	size_t		i;

	bi_strassen_invsere_array(arr, n);
	if (fft(arr, n, log2n) == BI_FAIL)
		return (BI_FAIL);
	i = 0;
	while (i < n)
	{
		bi_right_shift(arr + i, log2n, arr + i);
		i++;
	}
	return (BI_SUCCESS);
}

int				bi_strassen_mul_bi(t_bigint *a, t_bigint *b, t_bigint *c)
{
	size_t			n;
	unsigned int	log2n;
	t_bigint		*a_arr;
	t_bigint		*b_arr;

	n = bi_strassen_mul_get_block_length(a, b);
	log2n = ft_int_log2(n);
	a_arr = bi_to_bi_array(a, n);
	b_arr = bi_to_bi_array(b, n);
	if (a_arr == NULL || b_arr == NULL)
		return (handle_return(a_arr, b_arr, n, BI_FAIL));
	if (fft(a_arr, n, log2n) == BI_FAIL || fft(b_arr, n, log2n) == BI_FAIL)
		return (handle_return(a_arr, b_arr, n, BI_FAIL));
	if (bi_strassen_mul_pointwise_prod(a_arr, b_arr, n) == BI_FAIL)
		return (handle_return(a_arr, b_arr, n, BI_FAIL));
	if (ifft(a_arr, n, log2n) == BI_FAIL)
		return (handle_return(a_arr, b_arr, n, BI_FAIL));
	if (bi_array_to_bi(a_arr, n, c) == BI_FAIL)
		return (handle_return(a_arr, b_arr, n, BI_FAIL));
	if (c->occupied != 0 && (a->sign != b->sign))
		c->sign = BI_SIGN_NEGATIVE;
	return (handle_return(a_arr, b_arr, n, BI_SUCCESS));
}
