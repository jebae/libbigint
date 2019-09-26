#include "bigint.test.h"

// case one size
void		test_bi_sub_bi_case1(void)
{
	printf(KYEL "test_bi_sub_bi_case1\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_new(&c, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x71);
	bi_push(&b, 0x04);
	res = bi_sub_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_sub_bi (0x71 - 0x04) : return value"
	);

	// test if smaller bi is not modified
	test(
		b.occupied == 1,
		"bi_sub_bi (0x71 - 0x04) : b.occupied"
	);

	test(
		b.data[0] == 0x04,
		"bi_sub_bi (0x71 - 0x04) : b.data[0]"
	);

	test(
		c.sign == BI_SIGN_POSITIVE,
		"bi_sub_bi (0x71 - 0x04) : c.sign"
	);

	test(
		c.size == a.occupied,
		"bi_sub_bi (0x71 - 0x04) : c.size"
	);

	test(
		c.occupied == 1,
		"bi_sub_bi (0x71 - 0x04) : c.occupied"
	);

	test(
		c.data[0] == 0x71 - 0x04,
		"bi_sub_bi (0x71 - 0x04) : c.data[0]"
	);

	free(a.data);
	free(b.data);
	free(c.data);
}

// case multi size
void		test_bi_sub_bi_case2(void)
{
	printf(KYEL "test_bi_sub_bi_case2\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_new(&a, 2, BI_SIGN_POSITIVE);
	bi_new(&b, 2, BI_SIGN_POSITIVE);
	bi_new(&c, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x71);
	bi_push(&a, 0xff);
	bi_push(&b, 0x04);
	bi_push(&b, 0xff);
	res = bi_sub_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_sub_bi (0xff71 - 0xff04) : return value"
	);

	// test if smaller bi is not modified
	test(
		b.occupied == 2,
		"bi_sub_bi (0xff71 - 0xff04) : b.occupied"
	);

	test(
		b.data[0] == 0x04,
		"bi_sub_bi (0xff71 - 0xff04) : b.data[0]"
	);

	test(
		b.data[1] == 0xff,
		"bi_sub_bi (0xff71 - 0xff04) : b.data[1]"
	);

	test(
		c.sign == BI_SIGN_POSITIVE,
		"bi_sub_bi (0xff71 - 0xff04) : c.sign"
	);

	test(
		c.size == a.occupied,
		"bi_sub_bi (0xff71 - 0xff04) : c.size"
	);

	test(
		c.occupied == 1,
		"bi_sub_bi (0xff71 - 0xff04) : c.occupied"
	);

	test(
		c.data[0] == 0xff71 - 0xff04,
		"bi_sub_bi (0xff71 - 0xff04) : c.data[0]"
	);

	test(
		c.data[1] == 0x00,
		"bi_sub_bi (0xff71 - 0xff04) : c.data[1]"
	);

	free(a.data);
	free(b.data);
	free(c.data);
}

// case different size
void		test_bi_sub_bi_case3(void)
{
	printf(KYEL "test_bi_sub_bi_case3\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_new(&c, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x04);
	bi_push(&a, 0x03);
	bi_push(&a, 0x01);
	bi_push(&b, 0x71);
	bi_push(&b, 0xff);
	res = bi_sub_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_sub_bi (0x010304 - 0xff71) : return value"
	);

	// test if smaller bi is not modified
	test(
		b.occupied == 2,
		"bi_sub_bi (0x010304 - 0xff71) : b.occupied"
	);

	test(
		b.data[0] == 0x71,
		"bi_sub_bi (0x010304 - 0xff71) : b.data[0]"
	);

	test(
		b.data[1] == 0xff,
		"bi_sub_bi (0x010304 - 0xff71) : b.data[1]"
	);

	test(
		c.sign == BI_SIGN_POSITIVE,
		"bi_sub_bi (0x010304 - 0xff71) : c.sign"
	);

	test(
		c.size == a.occupied,
		"bi_sub_bi (0x010304 - 0xff71) : c.size"
	);

	test(
		c.occupied == 2,
		"bi_sub_bi (0x010304 - 0xff71) : c.occupied"
	);

	test(
		c.data[0] == 0x93,
		"bi_sub_bi (0x010304 - 0xff71) : c.data[0]"
	);

	test(
		c.data[1] == 0x03,
		"bi_sub_bi (0x010304 - 0xff71) : c.data[1]"
	);

	test(
		c.data[2] == 0x00,
		"bi_sub_bi (0x010304 - 0xff71) : c.data[2]"
	);

	free(a.data);
	free(b.data);
	free(c.data);
}

// case a - b (a < b)
void		test_bi_sub_bi_case4(void)
{
	printf(KYEL "test_bi_sub_bi_case4\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_new(&c, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x71);
	bi_push(&a, 0xff);
	bi_push(&b, 0x04);
	bi_push(&b, 0x03);
	bi_push(&b, 0x01);
	res = bi_sub_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_sub_bi (0xff71 - 0x010304) : return value"
	);

	// test if smaller bi is not modified
	test(
		a.occupied == 2,
		"bi_sub_bi (0xff71 - 0x010304) : a.occupied"
	);

	test(
		a.data[0] == 0x71,
		"bi_sub_bi (0xff71 - 0x010304) : a.data[0]"
	);

	test(
		a.data[1] == 0xff,
		"bi_sub_bi (0xff71 - 0x010304) : a.data[1]"
	);

	test(
		c.sign == BI_SIGN_NEGATIVE,
		"bi_sub_bi (0xff71 - 0x010304) : c.sign"
	);

	test(
		c.size == b.occupied,
		"bi_sub_bi (0xff71 - 0x010304) : return value"
	);

	test(
		c.occupied == 2,
		"bi_sub_bi (0xff71 - 0x010304) : c.occupied"
	);

	test(
		c.data[0] == 0x93,
		"bi_sub_bi (0xff71 - 0x010304) : c.data[0]"
	);

	test(
		c.data[1] == 0x03,
		"bi_sub_bi (0xff71 - 0x010304) : c.data[1]"
	);

	test(
		c.data[2] == 0x00,
		"bi_sub_bi (0xff71 - 0x010304) : c.data[2]"
	);

	free(a.data);
	free(b.data);
	free(c.data);
}

// case 0 - b
void		test_bi_sub_bi_case5(void)
{
	printf(KYEL "test_bi_sub_bi_case5\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_new(&c, 1, BI_SIGN_POSITIVE);
	bi_push(&b, 0xef);
	bi_push(&b, 0xff);
	bi_push(&b, 0xff);
	res = bi_sub_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_sub_bi (0x00 - 0xffffef) : return value"
	);

	test(
		c.sign == BI_SIGN_NEGATIVE,
		"bi_sub_bi (0x00 - 0xffffef) : c.sign"
	);

	// test if smaller bi is not modified
	test(
		a.occupied == 0,
		"bi_sub_bi (0x00 - 0xffffef) : a.occupied"
	);

	test(
		a.data[0] == 0x00,
		"bi_sub_bi (0x00 - 0xffffef) : a.data[0]"
	);

	test(
		c.size == b.occupied,
		"bi_sub_bi (0x00 - 0xffffef) : c.size"
	);

	test(
		c.occupied == b.occupied,
		"bi_sub_bi (0x00 - 0xffffef) : c.occupied"
	);

	test(
		c.data[0] == b.data[0],
		"bi_sub_bi (0x00 - 0xffffef) : c.data[0]"
	);

	test(
		c.data[1] == b.data[1],
		"bi_sub_bi (0x00 - 0xffffef) : c.data[1]"
	);

	test(
		c.data[2] == b.data[2],
		"bi_sub_bi (0x00 - 0xffffef) : c.data[2]"
	);

	free(a.data);
	free(b.data);
	free(c.data);
}

// case a - 0
void		test_bi_sub_bi_case6(void)
{
	printf(KYEL "test_bi_sub_bi_case6\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_new(&c, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0xef);
	bi_push(&a, 0xff);
	bi_push(&a, 0xff);
	res = bi_sub_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_sub_bi (0xffffef - 0x00) : return value"
	);

	// test if smaller bi is not modified
	test(
		b.occupied == 0,
		"bi_sub_bi (0xffffef - 0x00) : b.occupied"
	);

	test(
		b.data[0] == 0x00,
		"bi_sub_bi (0xffffef - 0x00) : b.data[0]"
	);

	test(
		c.sign == BI_SIGN_POSITIVE,
		"bi_sub_bi (0xffffef - 0x00) : c.sign"
	);

	test(
		c.size == a.occupied,
		"bi_sub_bi (0xffffef - 0x00) : c.size"
	);

	test(
		c.occupied == a.occupied,
		"bi_sub_bi (0xffffef - 0x00) : c.occupied"
	);

	test(
		c.data[0] == a.data[0],
		"bi_sub_bi (0xffffef - 0x00) : c.data[0]"
	);

	test(
		c.data[1] == a.data[1],
		"bi_sub_bi (0xffffef - 0x00) : c.data[1]"
	);

	test(
		c.data[2] == a.data[2],
		"bi_sub_bi (0xffffef - 0x00) : c.data[2]"
	);

	free(a.data);
	free(b.data);
	free(c.data);
}

// case 0 - 0
void		test_bi_sub_bi_case7(void)
{
	printf(KYEL "test_bi_sub_bi_case7\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_new(&c, 1, BI_SIGN_POSITIVE);
	res = bi_sub_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_sub_bi (0x00 - 0x00) : return value"
	);

	test(
		c.size == 1,
		"bi_sub_bi (0x00 - 0x00) : c.size"
	);

	test(
		c.occupied == 0,
		"bi_sub_bi (0x00 - 0x00) : c.occupied"
	);

	free(a.data);
	free(b.data);
	free(c.data);
}

// case negative - positive
void		test_bi_sub_bi_case8(void)
{
	printf(KYEL "test_bi_sub_bi_case8\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_new(&a, 1, BI_SIGN_NEGATIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_new(&c, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0xff);
	bi_push(&a, 0xef);
	bi_push(&b, 0x0f);
	bi_push(&b, 0xff);
	res = bi_sub_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_sub_bi (-0xefff - 0xff0f) : return value"
	);

	test(
		c.sign == BI_SIGN_NEGATIVE,
		"bi_sub_bi (-0xefff - 0xff0f) : c.occupied"
	);

	test(
		c.occupied == 3,
		"bi_sub_bi (-0xefff - 0xff0f) : c.occupied"
	);

	test(
		c.data[0] == 0x0e,
		"bi_sub_bi (-0xefff - 0xff0f) : c.data[0]"
	);

	test(
		c.data[1] == 0xef,
		"bi_sub_bi (-0xefff - 0xff0f) : c.data[1]"
	);

	test(
		c.data[2] == 0x01,
		"bi_sub_bi (-0xefff - 0xff0f) : c.data[2]"
	);

	free(a.data);
	free(b.data);
	free(c.data);
}

// case positive - negative
void		test_bi_sub_bi_case9(void)
{
	printf(KYEL "test_bi_sub_bi_case9\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_NEGATIVE);
	bi_new(&c, 1, BI_SIGN_NEGATIVE);
	bi_push(&a, 0xff);
	bi_push(&a, 0xef);
	bi_push(&b, 0x0f);
	bi_push(&b, 0xff);
	res = bi_sub_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_sub_bi (0xefff - -0xff0f) : return value"
	);

	test(
		c.sign == BI_SIGN_POSITIVE,
		"bi_sub_bi (0xefff - -0xff0f) : c.occupied"
	);

	test(
		c.occupied == 3,
		"bi_sub_bi (0xefff - -0xff0f) : c.occupied"
	);

	test(
		c.data[0] == 0x0e,
		"bi_sub_bi (0xefff - -0xff0f) : c.data[0]"
	);

	test(
		c.data[1] == 0xef,
		"bi_sub_bi (0xefff - -0xff0f) : c.data[1]"
	);

	test(
		c.data[2] == 0x01,
		"bi_sub_bi (0xefff - -0xff0f) : c.data[2]"
	);

	free(a.data);
	free(b.data);
	free(c.data);
}

// case negative - negative
void		test_bi_sub_bi_case10(void)
{
	printf(KYEL "test_bi_sub_bi_case10\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_new(&a, 1, BI_SIGN_NEGATIVE);
	bi_new(&b, 1, BI_SIGN_NEGATIVE);
	bi_new(&c, 1, BI_SIGN_NEGATIVE);
	bi_push(&a, 0xff);
	bi_push(&a, 0xef);
	bi_push(&b, 0x0f);
	bi_push(&b, 0xff);
	res = bi_sub_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_sub_bi (-0xefff - -0xff0f) : return value"
	);

	test(
		c.sign == BI_SIGN_POSITIVE,
		"bi_sub_bi (-0xefff - -0xff0f) : c.occupied"
	);

	test(
		c.occupied == 2,
		"bi_sub_bi (-0xefff - -0xff0f) : c.occupied"
	);

	test(
		c.data[0] == 0x10,
		"bi_sub_bi (-0xefff - -0xff0f) : c.data[0]"
	);

	test(
		c.data[1] == 0x0f,
		"bi_sub_bi (-0xefff - -0xff0f) : c.data[1]"
	);

	free(a.data);
	free(b.data);
	free(c.data);
}
