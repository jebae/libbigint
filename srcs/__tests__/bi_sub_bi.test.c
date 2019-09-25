#include "bigint.test.h"

// case one size
void		test_bi_sub_bi_case1(void)
{
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

// case 0 - b
void		test_bi_sub_bi_case5(void)
{
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
// negative - positive
// positive - negative
// negative - negative
