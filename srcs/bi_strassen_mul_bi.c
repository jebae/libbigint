#include "bigint.h"

static int		handle_fail(t_bigint *a_arr, t_bigint *b_arr, size_t n)
{
	bi_del_bi_array(a_arr, n);
	bi_del_bi_array(b_arr, n);
	return (BI_FAIL);
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
			BI_HANDLE_FUNC_FAIL(bi_mul_pow_of_2(arr + k + v->m2, e, &(v->t)));
			BI_HANDLE_FUNC_FAIL(
				bi_sub_bi(arr + k, &(v->t), arr + k + v->m2));

			/*
			printf("[%zu] sub : ", k + v->m2);

			printf("%c", (arr[k].sign == BI_SIGN_POSITIVE) ? '+' : '-');
			for (size_t i=arr[k].occupied; i > 0; i--)
				printf("%02x", arr[k].data[i - 1]);

			printf(" - ");

			printf("%c", (v->t.sign == BI_SIGN_POSITIVE) ? '+' : '-');
			for (size_t i=v->t.occupied; i > 0; i--)
				printf("%02x", v->t.data[i - 1]);

			printf(" = ");

			printf("%c", (arr[k + v->m2].sign == BI_SIGN_POSITIVE) ? '+' : '-');
			for (size_t i=arr[k + v->m2].occupied; i > 0; i--)
				printf("%02x", arr[k + v->m2].data[i - 1]);
			printf("\n");
			*/

			BI_HANDLE_FUNC_FAIL(bi_add_bi(arr + k, &(v->t), arr + k));
			BI_HANDLE_FUNC_FAIL(
				bi_mod_n_pow_of_2_plus_1(arr + k, n, arr + k));
			BI_HANDLE_FUNC_FAIL(bi_mod_n_pow_of_2_plus_1(
				arr + k + v->m2, n, arr + k + v->m2));
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
	if (bi_new(&v.t, 1, BI_SIGN_POSITIVE) == BI_FAIL)
		return (BI_FAIL);
	i = 1;
	while (i <= log2n)
	{
		v.m = 1 << i;
		v.m2 = v.m >> 1;
		v.em = 1 << (log2n - i + 1);
		if (fft_loop_by_level(arr, n, &v) == BI_FAIL)
		{
			ft_memdel((void **)&v.t.data);
			return (BI_FAIL);
		}
		i++;
	}
	ft_memdel((void **)&v.t.data);
	return (BI_SUCCESS);
}

static int		ifft(t_bigint *arr, size_t n, unsigned int log2n)
{
	size_t		i;

	bi_strassen_invsere_array(arr, n);
	BI_HANDLE_FUNC_FAIL(fft(arr, n, log2n));
	i = 0;
	while (i < n)
	{
		bi_div_pow_of_2(arr + i, log2n, arr + i);
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
		return (handle_fail(a_arr, b_arr, n));
	if (fft(a_arr, n, log2n) == BI_FAIL || fft(b_arr, n, log2n) == BI_FAIL)
		return (handle_fail(a_arr, b_arr, n));

	/*
	printf("============ F{ a } ==============\n");
	for (size_t i=0; i < n; i++)
	{
		printf("[%zu] : (%c)", i, a_arr[i].sign == BI_SIGN_POSITIVE ? '+' : '-');
		for (size_t j=a_arr[i].occupied; j > 0; j--)
			printf("%02x ", a_arr[i].data[j - 1]);
		printf("\n");
	}
	

	printf("============ F{ b } ==============\n");
	for (size_t i=0; i < n; i++)
	{
		printf("[%zu] : (%c)", i, b_arr[i].sign == BI_SIGN_POSITIVE ? '+' : '-');
		for (size_t j=b_arr[i].occupied; j > 0; j--)
			printf("%02x ", b_arr[i].data[j - 1]);
		printf("\n");
	}
	*/

	if (bi_strassen_mul_pointwise_prod(a_arr, b_arr, n) == BI_FAIL)
		return (handle_fail(a_arr, b_arr, n));
	if (ifft(a_arr, n, log2n) == BI_FAIL)
		return (handle_fail(a_arr, b_arr, n));
	if (bi_array_to_bi(a_arr, n, c) == BI_FAIL)
		return (BI_FAIL);
	return (BI_SUCCESS);
}
