#include "bigint.h"

static int		handle_fail(t_bigint *a_arr, t_bigint *b_arr, size_t n)
{
	bi_del_bi_array(a_arr, n);
	bi_del_bi_array(b_arr, n);
	return (BI_FAIL);
}

static int		fft_loop_by_level(
	t_bigint *bi_arr,
	size_t n,
	t_bi_mul_fft_vars *v
)
{
	size_t		j;
	size_t		k;
	size_t		e;

	j = 0;
	while (j < v->m2)
	{
		e = 0;
		k = j;
		while (k < n)
		{
			if (bi_pow_of_2(bi_arr + k + v->m2, e, &(v->t)) == BI_FAIL)
				return (BI_FAIL);
			if (bi_sub_bi(bi_arr + k, &(v->t), bi_arr + k + v->m2) == BI_FAIL)
				return (BI_FAIL);
			if (bi_add_bi(bi_arr + k, &(v->t), bi_arr + k) == BI_FAIL)
				return (BI_FAIL);
			bi_mod_n_pow_of_2_plus_1(bi_arr + k, n, bi_arr + k);
			bi_mod_n_pow_of_2_plus_1(bi_arr + k + v->m2, n, bi_arr + k + v->m2);
			k += v->m;
		}
		e += v->em;
		j++;
	}
	return (BI_SUCCESS);
}

static int		fft(t_bigint *bi_arr, size_t n, unsigned int log2n)
{
	size_t				i;
	t_bi_mul_fft_vars	v;

	if (bi_mul_shuffle_order(bi_arr, n) == BI_FAIL)
		return (BI_FAIL);
	if (bi_new(&v.t, 1, BI_POSITIVE) == BI_FAIL)
		return (BI_FAIL);
	i = 1;
	while (i <= log2n)
	{
		v.m = 1 << i;
		v.m2 = v.m >> 1;
		v.em = 1 << (log2n - i + 1);
		if (fft_loop_by_level(bi_arr, n, &v) == BI_FAIL)
		{
			ft_memdel((void **)&v.t.data);
			return (BI_FAIL);
		}
		i++;
	}
	ft_memdel((void **)&v.t.data);
	return (BI_SUCCESS);
}

static int		pointwise_product(t_bigint *a_arr, t_bigint *b_arr, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		if (bi_mul_bi(a_arr + i, b_arr + i, a_arr + i) == BI_FAIL)
			return (BI_FAIL);
		i++;
	}
	return (BI_SUCCESS);
}

int				bi_strassen_mul_bi(t_bigint *a, t_bigint *b, t_bigint *c)
{
	size_t		n;
	t_bigint	*a_arr;
	t_bigint	*b_arr;

	n = bi_mul_get_block_length(a, b);
	a_arr = bi_to_bi_array(a, n);
	b_arr = bi_to_bi_array(b, n);
	if (a_arr == NULL || b_arr == NULL)
		return (handle_fail(a_arr, b_arr, n));
	if (fft(a_arr) == BI_FAIL || fft(b_arr) == BI_FAIL)
		return (handle_fail(a_arr, b_arr, n));
	if (pointwise_product(a_arr, b_arr) == BI_FAIL)
		return (handle_fail(a_arr, b_arr, n));
	// get inverse array of fft(a) .* fft(b)
	// fft(inversed)
	// convert array to bigint
	// voila !!
}
