#include "bigint.test.h"

// size shrink
void		test_bi_resize_case1(void)
{
	printf(KYEL "test_bi_resize_case1\n" KNRM);
	t_bigint	bi;
	int			res;

	bi_new(&bi, 1, BI_SIGN_POSITIVE);
	bi_push(&bi, 0xff);
	bi_push(&bi, 0x00);
	bi_push(&bi, 0xff);
	res = bi_resize(&bi, 2);

	test(
		res == BI_SUCCESS,
		"bi_resize : return value"
	);

	test(
		bi.size == 2,
		"bi_resize : bi.size"
	);

	test(
		bi.occupied == 1,
		"bi_resize : bi.occupied"
	);

	test(
		bi.data[0] == 0xFF,
		"bi_resize : bi.data[0]"
	);

	free(bi.data);
}

// size expand
void		test_bi_resize_case2(void)
{
	printf(KYEL "test_bi_resize_case2\n" KNRM);
	t_bigint	bi;
	int			res;

	bi_new(&bi, 1, BI_SIGN_POSITIVE);
	bi_push(&bi, 0xff);
	bi_push(&bi, 0x00);
	bi_push(&bi, 0xff);
	res = bi_resize(&bi, 4);

	test(
		res == BI_SUCCESS,
		"bi_resize : return value"
	);

	test(
		bi.size == 4,
		"bi_resize : bi.size"
	);

	test(
		bi.occupied == 3,
		"bi_resize : bi.occupied"
	);

	test(
		bi.data[1] == 0x00,
		"bi_resize : bi.data[1]"
	);

	test(
		bi.data[2] == 0xFF,
		"bi_resize : bi.data[2]"
	);

	free(bi.data);
}
