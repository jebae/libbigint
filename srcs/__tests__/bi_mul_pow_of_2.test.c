#include "bigint.test.h"

// case one size
void		test_bi_left_shift_case1(void)
{
	printf(KYEL "test_bi_left_shift_case1\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_NEGATIVE);
	bi_push(&a, 0xff);
	res = bi_left_shift(&a, 7, &b);

	test(
		res == BI_SUCCESS,
		"bi_left_shift (0xff, 7) : return value"
	);

	test(
		b.sign == a.sign,
		"bi_left_shift (0xff, 7) : b.sign"
	);

	test(
		b.occupied == 2,
		"bi_left_shift (0xff, 7) : b.occupied"
	);

	test(
		b.data[0] == 0x80,
		"bi_left_shift (0xff, 7) : b.data[0]"
	);

	test(
		b.data[1] == 0x7f,
		"bi_left_shift (0xff, 7) : b.data[1]"
	);

	free(a.data);
	free(b.data);
}

// case multi size
void		test_bi_left_shift_case2(void)
{
	printf(KYEL "test_bi_left_shift_case2\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0xff);
	bi_push(&a, 0xa9);
	res = bi_left_shift(&a, 7, &b);

	test(
		res == BI_SUCCESS,
		"bi_left_shift (0xa9ff, 7) : return value"
	);

	test(
		b.occupied == 3,
		"bi_left_shift (0xa9ff, 7) : b.occupied"
	);

	test(
		b.data[0] == 0x80,
		"bi_left_shift (0xa9ff, 7) : b.data[0]"
	);

	test(
		b.data[1] == 0xff,
		"bi_left_shift (0xa9ff, 7) : b.data[1]"
	);

	test(
		b.data[2] == 0x54,
		"bi_left_shift (0xa9ff, 7) : b.data[2]"
	);

	free(a.data);
	free(b.data);
}

// case more than 2^8
void		test_bi_left_shift_case3(void)
{
	printf(KYEL "test_bi_left_shift_case3\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0xff);
	bi_push(&a, 0x29);
	res = bi_left_shift(&a, 33, &b);

	test(
		res == BI_SUCCESS,
		"bi_left_shift (0x29ff, 33) : return value"
	);

	test(
		b.occupied == 6,
		"bi_left_shift (0x29ff, 33) : b.occupied"
	);

	for (int i=0; i < 4; i++)
		test(
			b.data[i] == 0x00,
			"bi_left_shift (0x29ff, 33) : b.data[i] (0 <= i <= 3)"
		);

	test(
		b.data[4] == 0xfe,
		"bi_left_shift (0x29ff, 33) : b.data[4]"
	);

	test(
		b.data[5] == 0x53,
		"bi_left_shift (0x29ff, 33) : b.data[5]"
	);

	free(a.data);
	free(b.data);
}

// case very small
void		test_bi_left_shift_case4(void)
{
	printf(KYEL "test_bi_left_shift_case4\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x05);
	res = bi_left_shift(&a, 2, &b);

	test(
		res == BI_SUCCESS,
		"bi_left_shift (0x05, 2) : return value"
	);

	test(
		b.occupied == 1,
		"bi_left_shift (0x05, 2) : b.occupied"
	);

	test(
		b.data[0] == 0x14,
		"bi_left_shift (0x05, 2) : b.data[0]"
	);

	free(a.data);
	free(b.data);
}

// case n = 0
void		test_bi_left_shift_case5(void)
{
	printf(KYEL "test_bi_left_shift_case5\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x05);
	bi_push(&a, 0xa9);
	res = bi_left_shift(&a, 0, &b);

	test(
		res == BI_SUCCESS,
		"bi_left_shift (0xa905, 0) : return value"
	);

	test(
		b.occupied == 2,
		"bi_left_shift (0xa905, 0) : b.occupied"
	);

	test(
		b.data[0] == a.data[0],
		"bi_left_shift (0xa905, 0) : b.data[0]"
	);

	test(
		b.data[1] == a.data[1],
		"bi_left_shift (0xa905, 0) : b.data[1]"
	);

	free(a.data);
	free(b.data);
}

// case res = bi (mutable mul)
void		test_bi_left_shift_case6(void)
{
	printf(KYEL "test_bi_left_shift_case6\n" KNRM);
	t_bigint	a;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x05);
	bi_push(&a, 0xa9);
	res = bi_left_shift(&a, 9, &a);

	test(
		res == BI_SUCCESS,
		"bi_left_shift (0xa905, 9) : return value"
	);

	test(
		a.occupied == 4,
		"bi_left_shift (0xa905, 9) : a.occupied"
	);

	test(
		a.data[0] == 0x00,
		"bi_left_shift (0xa905, 9) : a.data[0]"
	);

	test(
		a.data[1] == 0x0a,
		"bi_left_shift (0xa905, 9) : a.data[1]"
	);

	test(
		a.data[2] == 0x52,
		"bi_left_shift (0xa905, 9) : a.data[2]"
	);

	test(
		a.data[3] == 0x01,
		"bi_left_shift (0xa905, 9) : a.data[3]"
	);

	free(a.data);
}

// case bi = 0
void		test_bi_left_shift_case7(void)
{
	printf(KYEL "test_bi_left_shift_case7\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	res = bi_left_shift(&a, 4, &b);

	test(
		res == BI_SUCCESS,
		"bi_left_shift (0x00, 0) : return value"
	);

	test(
		b.occupied == 0,
		"bi_left_shift (0x00, 0) : b.occupied"
	);

	free(a.data);
	free(b.data);
}
