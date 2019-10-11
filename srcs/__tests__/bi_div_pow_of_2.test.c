#include "bigint.test.h"

// case one size
void		test_bi_right_shift_case1(void)
{
	printf(KYEL "test_bi_right_shift_case1\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_NEGATIVE);
	bi_push(&a, 0xff);
	res = bi_right_shift(&a, 7, &b);

	test(
		res == BI_SUCCESS,
		"bi_right_shift (0xff, 7) : return value"
	);

	test(
		b.sign == a.sign,
		"bi_right_shift (0xff, 7) : b.sign"
	);

	test(
		b.occupied == 1,
		"bi_right_shift (0xff, 7) : b.occupied"
	);

	test(
		b.data[0] == 0x01,
		"bi_right_shift (0xff, 7) : b.data[0]"
	);

	free(a.data);
	free(b.data);
}

// case multi size
void		test_bi_right_shift_case2(void)
{
	printf(KYEL "test_bi_right_shift_case2\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0xff);
	bi_push(&a, 0xa9);
	res = bi_right_shift(&a, 7, &b);

	test(
		res == BI_SUCCESS,
		"bi_right_shift (0xa9ff, 7) : return value"
	);

	test(
		b.occupied == 2,
		"bi_right_shift (0xa9ff, 7) : b.occupied"
	);

	test(
		b.data[0] == 0x53,
		"bi_right_shift (0xa9ff, 7) : b.data[0]"
	);

	test(
		b.data[1] == 0x01,
		"bi_right_shift (0xa9ff, 7) : b.data[1]"
	);

	free(a.data);
	free(b.data);
}

// case more than 2^8
void		test_bi_right_shift_case3(void)
{
	printf(KYEL "test_bi_right_shift_case3\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0xff);
	bi_push(&a, 0x01);
	bi_push(&a, 0x00);
	bi_push(&a, 0xa2);
	bi_push(&a, 0x8f);
	res = bi_right_shift(&a, 33, &b);

	test(
		res == BI_SUCCESS,
		"bi_right_shift (0x8fa20001ff, 33) : return value"
	);

	test(
		b.occupied == 1,
		"bi_right_shift (0x8fa20001ff, 33) : b.occupied"
	);

	test(
		b.data[0] == 0x47,
		"bi_right_shift (0x8fa20001ff, 33) : b.data[0]"
	);

	free(a.data);
	free(b.data);
}

// case very small
void		test_bi_right_shift_case4(void)
{
	printf(KYEL "test_bi_right_shift_case4\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x0d);
	res = bi_right_shift(&a, 2, &b);

	test(
		res == BI_SUCCESS,
		"bi_right_shift (0x0d, 2) : return value"
	);

	test(
		b.occupied == 1,
		"bi_right_shift (0x0d, 2) : b.occupied"
	);

	test(
		b.data[0] == 0x03,
		"bi_right_shift (0x0d, 2) : b.data[0]"
	);

	free(a.data);
	free(b.data);
}

// case n = 0
void		test_bi_right_shift_case5(void)
{
	printf(KYEL "test_bi_right_shift_case5\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x05);
	bi_push(&a, 0xa9);
	res = bi_right_shift(&a, 0, &b);

	test(
		res == BI_SUCCESS,
		"bi_right_shift (0xa905, 0) : return value"
	);

	test(
		b.occupied == 2,
		"bi_right_shift (0xa905, 0) : b.occupied"
	);

	test(
		b.data[0] == a.data[0],
		"bi_right_shift (0xa905, 0) : b.data[0]"
	);

	test(
		b.data[1] == a.data[1],
		"bi_right_shift (0xa905, 0) : b.data[1]"
	);

	free(a.data);
	free(b.data);
}

// case mutable
void		test_bi_right_shift_case6(void)
{
	printf(KYEL "test_bi_right_shift_case6\n" KNRM);
	t_bigint	a;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x05);
	bi_push(&a, 0xa9);
	res = bi_right_shift(&a, 9, &a);

	test(
		res == BI_SUCCESS,
		"bi_right_shift (0xa905, 9) : return value"
	);

	test(
		a.occupied == 1,
		"bi_right_shift (0xa905, 9) : a.occupied"
	);

	test(
		a.data[0] == 0x54,
		"bi_right_shift (0xa905, 9) : a.data[0]"
	);

	free(a.data);
}

// case bi = 0
void		test_bi_right_shift_case7(void)
{
	printf(KYEL "test_bi_right_shift_case7\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	res = bi_right_shift(&a, 4, &b);

	test(
		res == BI_SUCCESS,
		"bi_right_shift (0x00, 0) : return value"
	);

	test(
		b.occupied == 0,
		"bi_right_shift (0x00, 0) : b.occupied"
	);

	free(a.data);
	free(b.data);
}
