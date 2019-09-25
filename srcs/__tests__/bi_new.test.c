#include "bigint.test.h"

void		test_bi_new_case1(void)
{
	t_bigint	bi;
	size_t		size = 5;
	char		sign = BI_SIGN_POSITIVE;
	int			res;

	res = bi_new(&bi, size, sign);

	test(
		res == BI_SUCCESS,
		"bi_new : return value"
	);

	test(
		bi.sign == BI_SIGN_POSITIVE,
		"bi_new : bi.sign"
	);

	test(
		bi.occupied == 0,
		"bi_new : bi.occupied"
	);

	test(
		bi.size == size,
		"bi_new : bi.size"
	);

	for (size_t i=0; i < size; i++)
		test(
			bi.data[i] == 0x00,
			"bi_new : bi.data[i]"
		);
	free(bi.data);
}
