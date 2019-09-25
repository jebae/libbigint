#include "bigint.test.h"

void		test_bi_shrink_case1(void)
{
	t_bigint	bi;
	int			res;

	bi_new(&bi, 3, BI_SIGN_POSITIVE);
	bi_push(&bi, 0xff);
	bi_push(&bi, 0xff);
	bi_push(&bi, 0xff);
	res = bi_shrink(&bi, 2);

	test(
		res == BI_SUCCESS,
		"bi_shrink : return value"
	);

	test(
		bi.occupied == 1,
		"bi_shrink : bi.occupied"
	);

	test(
		bi.data[0] == 0xff,
		"bi_shrink : bi.data[0]"
	);

	test(
		bi.data[1] == 0x00,
		"bi_shrink : bi.data[1]"
	);

	test(
		bi.data[2] == 0x00,
		"bi_shrink : bi.data[2]"
	);
	free(bi.data);
}

void		test_bi_shrink_case2(void)
{
	t_bigint	bi;
	int			res;

	bi_new(&bi, 3, BI_SIGN_POSITIVE);
	bi_push(&bi, 0xff);
	bi_push(&bi, 0xff);
	bi_push(&bi, 0xff);
	res = bi_shrink(&bi, 4);

	test(
		res == BI_FAIL,
		"bi_shrink : return value"
	);

	test(
		bi.occupied == 3,
		"bi_shrink : bi.occupied"
	);

	test(
		bi.data[0] == 0xff,
		"bi_shrink : bi.data[0]"
	);

	test(
		bi.data[1] == 0xff,
		"bi_shrink : bi.data[1]"
	);

	test(
		bi.data[2] == 0xff,
		"bi_shrink : bi.data[2]"
	);
	free(bi.data);
}
