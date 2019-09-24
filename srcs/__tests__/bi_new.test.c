#include "bigint.test.h"

void		test_bi_new_case1(void)
{
	t_bigint	bi;
	size_t		size = 5;
	int			res;

	res = bi_new(&bi, size);

	test(
		res == BI_SUCCESS,
		"bi_new : return value"
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
