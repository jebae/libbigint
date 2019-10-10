#include "bigint.test.h"

void		test_bi_double_dabble_case1(void)
{
	printf(KYEL "test_bi_double_dabble_case1\n" KNRM);
	t_bigint	bi;
	t_bigint	bcd;
	int			res;

	bi_new(&bi, 1, BI_SIGN_POSITIVE);
	bi_new(&bcd, 1, BI_SIGN_NEGATIVE);

	bi_push(&bi, 0xff);
	bi_push(&bi, 0xfe);

	res = bi_double_dabble(&bi, &bcd);

	test(
		res == BI_SUCCESS,
		"bi_double_dabble : return value"
	);

	test(
		bcd.occupied == 3,
		"bi_double_dabble : bcd.occupied"
	);

	test(
		bcd.sign == bi.sign,
		"bi_double_dabble : b.sign"
	);

	test(
		bcd.data[0] == 0x79,
		"bi_double_dabble : b.data[0]"
	);

	test(
		bcd.data[1] == 0x52,
		"bi_double_dabble : b.data[1]"
	);

	test(
		bcd.data[2] == 0x06,
		"bi_double_dabble : b.data[2]"
	);

	free(bi.data);
	free(bcd.data);
}

// case negative
void		test_bi_double_dabble_case2(void)
{
	printf(KYEL "test_bi_double_dabble_case2\n" KNRM);
	t_bigint	bi;
	t_bigint	bcd;
	int			res;

	bi_new(&bi, 1, BI_SIGN_NEGATIVE);
	bi_new(&bcd, 1, BI_SIGN_POSITIVE);

	bi_push(&bi, 0xff);
	bi_push(&bi, 0xfe);

	res = bi_double_dabble(&bi, &bcd);

	test(
		res == BI_SUCCESS,
		"bi_double_dabble : return value"
	);

	test(
		bcd.occupied == 3,
		"bi_double_dabble : bcd.occupied"
	);

	test(
		bcd.sign == bi.sign,
		"bi_double_dabble : b.sign"
	);

	test(
		bcd.data[0] == 0x79,
		"bi_double_dabble : b.data[0]"
	);

	test(
		bcd.data[1] == 0x52,
		"bi_double_dabble : b.data[1]"
	);

	test(
		bcd.data[2] == 0x06,
		"bi_double_dabble : b.data[2]"
	);

	free(bi.data);
	free(bcd.data);
}

// case big
