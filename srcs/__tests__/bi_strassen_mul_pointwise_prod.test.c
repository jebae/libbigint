#include "bigint.test.h"

void		test_bi_strassen_mul_pointwise_prod_case1(void)
{
	printf(KYEL "test_bi_strassen_mul_pointwise_prod_case1\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	*a_arr;
	t_bigint	*b_arr;
	size_t		n = 5;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	for (size_t i=0; i < n; i++)
	{
		bi_push(&a, i);
		bi_push(&b, i);
	}
	a_arr = bi_to_bi_array(&a, n);
	b_arr = bi_to_bi_array(&b, n);
	bi_strassen_mul_pointwise_prod(a_arr, b_arr, n);

	for (size_t i=0; i < n; i++)
		test(
			a_arr[i].data[0] == i * i,
			"bi_strassen_mul_pointwise_prod : a_arr[i].data"
		);

	free(a.data);
	free(b.data);
	bi_del_bi_array(a_arr, n);
	bi_del_bi_array(b_arr, n);
}
