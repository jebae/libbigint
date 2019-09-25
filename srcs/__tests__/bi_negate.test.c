#include "bigint.test.h"

// case expand size
void		test_bi_negate_case1(void)
{
	t_bigint	bi;

	bi_new(&bi, 2, BI_SIGN_POSITIVE);
	bi_push(&bi, 0x9c);
	bi_push(&bi, 0xfe);
	bi_negate(&bi, 3);

	test(
		bi.size == 3,
		"bi_negate (0xfe9c) : bi.size"
	);

	test(
		bi.occupied == 3,
		"bi_negate (0xfe9c) : bi.occupied"
	);

	test(
		bi.data[0] == 0x64,
		"bi_negate (0xfe9c) : bi.data[0]"
	);

	test(
		bi.data[1] == 0x01,
		"bi_negate (0xfe9c) : bi.data[1]"
	);

	test(
		bi.data[2] == 0xff,
		"bi_negate (0xfe9c) : bi.data[2]"
	);

	free(bi.data);
}

// case shrink size
void		test_bi_negate_case2(void)
{
	t_bigint	bi;

	bi_new(&bi, 3, BI_SIGN_POSITIVE);
	bi_push(&bi, 0x64);
	bi_push(&bi, 0x01);
	bi_push(&bi, 0xff);
	bi_negate(&bi, 2);

	test(
		bi.size == 3,
		"bi_negate (0xff0164) : bi.size"
	);

	test(
		bi.occupied == 2,
		"bi_negate (0xff0164) : bi.occupied"
	);

	test(
		bi.data[0] == 0x9c,
		"bi_negate (0xff0164) : bi.data[0]"
	);

	test(
		bi.data[1] == 0xfe,
		"bi_negate (0xff0164) : bi.data[1]"
	);

	test(
		bi.data[2] == 0x00,
		"bi_negate (0xff0164) : bi.data[2]"
	);

	free(bi.data);
}
