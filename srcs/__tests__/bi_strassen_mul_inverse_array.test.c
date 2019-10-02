#include "bigint.test.h"

void		test_bi_strassen_mul_inverse_array_case1(void)
{
	printf(KYEL "test_bi_strassen_mul_inverse_array_case1\n" KNRM);
	t_bigint	bi;
	t_bigint	*bi_arr;
	size_t		n = 8;

	bi_new(&bi, 1, BI_SIGN_POSITIVE);
	for (size_t i=0; i < n; i++)
		bi_push(&bi, i);
	bi_arr = bi_to_bi_array(&bi, n);
	bi_strassen_invsere_array(bi_arr, n);

	test(
		bi_arr[0].data[0] == bi.data[0],
		"test_bi_strassen_mul_inverse_array_case1 (0 ~ 7) : bi_arr[0].data"
	);
	for (size_t i=1; i < n; i++)
		test(
			bi_arr[i].data[0] == bi.data[n - i],
			"test_bi_strassen_mul_inverse_array_case1 (0 ~ 7) : bi_arr[i].data"
		);

	free(bi.data);
	bi_del_bi_array(bi_arr, n);
}

