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
		"bi_double_dabble : bcd.sign"
	);

	test(
		bcd.data[0] == 0x79,
		"bi_double_dabble : bcd.data[0]"
	);

	test(
		bcd.data[1] == 0x52,
		"bi_double_dabble : bcd.data[1]"
	);

	test(
		bcd.data[2] == 0x06,
		"bi_double_dabble : bcd.data[2]"
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
		"bi_double_dabble : bcd.sign"
	);

	test(
		bcd.data[0] == 0x79,
		"bi_double_dabble : bcd.data[0]"
	);

	test(
		bcd.data[1] == 0x52,
		"bi_double_dabble : bcd.data[1]"
	);

	test(
		bcd.data[2] == 0x06,
		"bi_double_dabble : bcd.data[2]"
	);

	free(bi.data);
	free(bcd.data);
}

// case big
void		test_bi_double_dabble_case3(void)
{
	printf(KYEL "test_bi_double_dabble_case3\n" KNRM);
	t_bigint		bi;
	t_bigint		bcd;
	int				res;
	unsigned char	expected[6] = {
		0x93, 0x82, 0x61, 0x05, 0x00, 0x53
	};

	bi_new(&bi, 1, BI_SIGN_POSITIVE);
	bi_new(&bcd, 1, BI_SIGN_NEGATIVE);

	bi_push(&bi, 0xc5);
	bi_push(&bi, 0x72);
	bi_push(&bi, 0xb7);
	bi_push(&bi, 0x74);
	bi_push(&bi, 0xda);

	res = bi_double_dabble(&bi, &bcd);

	test(
		res == BI_SUCCESS,
		"bi_double_dabble : return value"
	);

	test(
		bcd.occupied == 6,
		"bi_double_dabble : bcd.occupied"
	);

	test(
		bcd.sign == bi.sign,
		"bi_double_dabble : bcd.sign"
	);

	for (size_t i=bcd.occupied; i > 0; i--)
		test(
			bcd.data[i - 1] == expected[6 - i],
			"bi_double_dabble : bcd.data[i]"
		);

	free(bi.data);
	free(bcd.data);
}

// case 0
void		test_bi_double_dabble_case4(void)
{
	printf(KYEL "test_bi_double_dabble_case4\n" KNRM);
	t_bigint		bi;
	t_bigint		bcd;
	int				res;

	bi_new(&bi, 1, BI_SIGN_POSITIVE);
	bi_new(&bcd, 1, BI_SIGN_NEGATIVE);

	res = bi_double_dabble(&bi, &bcd);

	test(
		res == BI_SUCCESS,
		"bi_double_dabble : return value"
	);

	test(
		bcd.occupied == 0,
		"bi_double_dabble : bcd.occupied"
	);

	test(
		bcd.sign == BI_SIGN_POSITIVE,
		"bi_double_dabble : bcd.sign"
	);

	free(bi.data);
	free(bcd.data);
}
