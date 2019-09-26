#include "bigint.test.h"

// case one size
void		test_bi_mul_pow_of_2_case1(void)
{
	printf(KYEL "test_bi_mul_pow_of_2_case1\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0xff);
	res = bi_mul_pow_of_2(&a, 7, &b);

	test(
		res == BI_SUCCESS,
		"bi_mul_pow_of_2 (0xff, 7) : return value"
	);

	test(
		b.sign = BI_SIGN_POSITIVE,
		"bi_mul_pow_of_2 (0xff, 7) : b.sign"
	);

	test(
		b.occupied == 2,
		"bi_mul_pow_of_2 (0xff, 7) : b.occupied"
	);

	test(
		b.data[0] == 0x80,
		"bi_mul_pow_of_2 (0xff, 7) : b.data[0]"
	);

	test(
		b.data[1] == 0x7f,
		"bi_mul_pow_of_2 (0xff, 7) : b.data[1]"
	);

	free(a.data);
	free(b.data);
}

// case multi size
void		test_bi_mul_pow_of_2_case2(void)
{
	printf(KYEL "test_bi_mul_pow_of_2_case2\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0xff);
	bi_push(&a, 0xa9);
	res = bi_mul_pow_of_2(&a, 7, &b);

	test(
		res == BI_SUCCESS,
		"bi_mul_pow_of_2 (0xa9ff, 7) : return value"
	);

	test(
		b.occupied == 3,
		"bi_mul_pow_of_2 (0xa9ff, 7) : b.occupied"
	);

	test(
		b.data[0] == 0x80,
		"bi_mul_pow_of_2 (0xa9ff, 7) : b.data[0]"
	);

	test(
		b.data[1] == 0xff,
		"bi_mul_pow_of_2 (0xa9ff, 7) : b.data[1]"
	);

	test(
		b.data[2] == 0x54,
		"bi_mul_pow_of_2 (0xa9ff, 7) : b.data[2]"
	);

	free(a.data);
	free(b.data);
}

// case more than 2^8
void		test_bi_mul_pow_of_2_case3(void)
{
	printf(KYEL "test_bi_mul_pow_of_2_case3\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0xff);
	bi_push(&a, 0x29);
	res = bi_mul_pow_of_2(&a, 33, &b);

	test(
		res == BI_SUCCESS,
		"bi_mul_pow_of_2 (0x29ff, 33) : return value"
	);

	test(
		b.occupied == 6,
		"bi_mul_pow_of_2 (0x29ff, 33) : b.occupied"
	);

	for (int i=0; i < 4; i++)
		test(
			b.data[i] == 0x00,
			"bi_mul_pow_of_2 (0x29ff, 33) : b.data[i] (0 <= i <= 3)"
		);

	test(
		b.data[4] == 0xfe,
		"bi_mul_pow_of_2 (0x29ff, 33) : b.data[4]"
	);

	test(
		b.data[5] == 0x53,
		"bi_mul_pow_of_2 (0x29ff, 33) : b.data[5]"
	);

	free(a.data);
	free(b.data);
}

// case very small
void		test_bi_mul_pow_of_2_case4(void)
{
	printf(KYEL "test_bi_mul_pow_of_2_case4\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x05);
	res = bi_mul_pow_of_2(&a, 2, &b);

	test(
		res == BI_SUCCESS,
		"bi_mul_pow_of_2 (0x05, 2) : return value"
	);

	test(
		b.occupied == 1,
		"bi_mul_pow_of_2 (0x05, 2) : b.occupied"
	);

	test(
		b.data[0] == 0x14,
		"bi_mul_pow_of_2 (0x05, 2) : b.data[0]"
	);

	free(a.data);
	free(b.data);
}