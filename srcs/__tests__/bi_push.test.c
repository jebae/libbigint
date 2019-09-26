#include "bigint.test.h"

void		test_bi_push_case1(void)
{
	printf(KYEL "test_bi_push_case1\n" KNRM);
	t_bigint	bi;
	size_t		size = 2;
	int			res;

	bi_new(&bi, size, BI_SIGN_POSITIVE);
	res = bi_push(&bi, 0x11);

	test(
		res == BI_SUCCESS,
		"bi_push (0x11) : return value"
	);

	test(
		bi.occupied == 1,
		"bi_push (0x11) : bi.occupied"
	);

	test(
		bi.data[0] == 0x11,
		"bi_push (0x11) : bi.data[0]"
	);
	free(bi.data);
}

void		test_bi_push_case2(void)
{
	printf(KYEL "test_bi_push_case2\n" KNRM);
	t_bigint	bi;
	size_t		size = 2;
	int			res;

	bi_new(&bi, size, BI_SIGN_POSITIVE);
	res = bi_push(&bi, 0x01);
	res = bi_push(&bi, 0x02);
	res = bi_push(&bi, 0x03);

	test(
		res == BI_SUCCESS,
		"bi_push (0x0i) : return value"
	);

	test(
		bi.size == 3,
		"bi_push (0x0i) : bi.size"
	);

	test(
		bi.occupied == 3,
		"bi_push (0x0i) : bi.occupied"
	);
	for (int i=0; i < 3; i++)
		test(
			bi.data[i] == 0x01 * (i + 1),
			"bi_push (0x0i) : bi.data[i]"
		);
	free(bi.data);
}
