#include "bigint.test.h"

// case one size
void		test_bi_add_bi_case1(void)
{
	printf(KYEL "test_bi_add_bi_case1\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_init(&a);
	bi_init(&b);
	bi_init(&c);
	bi_push(&a, 0x04);
	bi_push(&b, 0x7a);
	res = bi_add_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_add_bi (0x04 + 0x7a) : return value"
	);

	test(
		c.size == 1,
		"bi_add_bi (0x04 + 0x7a) : c.size"
	);

	test(
		c.occupied == 1,
		"bi_add_bi (0x04 + 0x7a) : c.occupied"
	);

	test(
		c.data[0] == 0x04 + 0x7a,
		"bi_add_bi (0x04 + 0x7a) : c.data[0]"
	);

	bi_del(&a);
	bi_del(&b);
	bi_del(&c);
}

// case multi size
void		test_bi_add_bi_case2(void)
{
	printf(KYEL "test_bi_add_bi_case2\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_init(&a);
	bi_init(&b);
	bi_init(&c);
	bi_push(&a, 0xff);
	bi_push(&a, 0xff);
	bi_push(&b, 0xff);
	bi_push(&b, 0xf2);
	res = bi_add_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_add_bi (0xffff + 0xf2ff) : return value"
	);

	test(
		c.size == 3,
		"bi_add_bi (0xffff + 0xf2ff) : c.size"
	);

	test(
		c.occupied == 3,
		"bi_add_bi (0xffff + 0xf2ff) : c.occupied"
	);

	test(
		c.data[0] == 0xfe,
		"bi_add_bi (0xffff + 0xf2ff) : c.data[0]"
	);

	test(
		c.data[1] == 0xf2,
		"bi_add_bi (0xffff + 0xf2ff) : c.data[1]"
	);

	test(
		c.data[2] == 0x01,
		"bi_add_bi (0xffff + 0xf2ff) : c.data[2]"
	);

	bi_del(&a);
	bi_del(&b);
	bi_del(&c);
}

// case negative + negative
void		test_bi_add_bi_case3(void)
{
	printf(KYEL "test_bi_add_bi_case3\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_init(&a);
	bi_init(&b);
	bi_init(&c);
	bi_push(&a, 0xff);
	bi_push(&a, 0xff);
	bi_push(&b, 0xff);
	bi_push(&b, 0xf2);
	a.sign = BI_SIGN_NEGATIVE;
	b.sign = BI_SIGN_NEGATIVE;
	res = bi_add_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_add_bi (0xffff + 0xf2ff) : return value"
	);

	test(
		c.sign == BI_SIGN_NEGATIVE,
		"bi_add_bi (0xffff + 0xf2ff) : c.sign"
	);

	test(
		c.size == 3,
		"bi_add_bi (0xffff + 0xf2ff) : c.size"
	);

	test(
		c.occupied == 3,
		"bi_add_bi (0xffff + 0xf2ff) : c.occupied"
	);

	test(
		c.data[0] == 0xfe,
		"bi_add_bi (0xffff + 0xf2ff) : c.data[0]"
	);

	test(
		c.data[1] == 0xf2,
		"bi_add_bi (0xffff + 0xf2ff) : c.data[1]"
	);

	test(
		c.data[2] == 0x01,
		"bi_add_bi (0xffff + 0xf2ff) : c.data[2]"
	);

	bi_del(&a);
	bi_del(&b);
	bi_del(&c);
}

// case different size
void		test_bi_add_bi_case4(void)
{
	printf(KYEL "test_bi_add_bi_case4\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_init(&a);
	bi_init(&b);
	bi_init(&c);
	bi_push(&a, 0xff);
	bi_push(&a, 0xff);
	bi_push(&b, 0x10);
	res = bi_add_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_add_bi (0xffff + 0x10) : return value"
	);

	test(
		c.sign == BI_SIGN_POSITIVE,
		"bi_add_bi (0xffff + 0x10) : c.sign"
	);

	test(
		c.size == 3,
		"bi_add_bi (0xffff + 0x10) : c.size"
	);

	test(
		c.occupied == 3,
		"bi_add_bi (0xffff + 0x10) : c.occupied"
	);

	test(
		c.data[0] == 0x0f,
		"bi_add_bi (0xffff + 0x10) : c.data[0]"
	);

	test(
		c.data[1] == 0x00,
		"bi_add_bi (0xffff + 0x10) : c.data[1]"
	);

	test(
		c.data[2] == 0x01,
		"bi_add_bi (0xffff + 0x10) : c.data[2]"
	);

	bi_del(&a);
	bi_del(&b);
	bi_del(&c);
}

// case a + 0
void		test_bi_add_bi_case5(void)
{
	printf(KYEL "test_bi_add_bi_case5\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_init(&a);
	bi_init(&b);
	bi_init(&c);
	bi_push(&a, 0x90);
	bi_push(&a, 0xff);
	b.sign = BI_SIGN_NEGATIVE;
	c.sign = BI_SIGN_NEGATIVE;
	res = bi_add_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_add_bi (0xff90 + 0x00) : return value"
	);

	test(
		c.sign == BI_SIGN_POSITIVE,
		"bi_add_bi (0xff90 + 0x00) : c.sign"
	);

	test(
		c.size == a.occupied,
		"bi_add_bi (0xff90 + 0x00) : c.size"
	);

	test(
		c.occupied == a.occupied,
		"bi_add_bi (0xff90 + 0x00) : c.occupied"
	);

	test(
		c.data[0] == 0x90,
		"bi_add_bi (0xff90 + 0x00) : c.data[0]"
	);

	test(
		c.data[1] == 0xff,
		"bi_add_bi (0xff90 + 0x00) : c.data[1]"
	);

	bi_del(&a);
	bi_del(&b);
	bi_del(&c);
}

// case 0 + b
void		test_bi_add_bi_case6(void)
{
	printf(KYEL "test_bi_add_bi_case6\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_init(&a);
	bi_init(&b);
	bi_init(&c);
	bi_push(&b, 0x90);
	bi_push(&b, 0xff);
	a.sign = BI_SIGN_NEGATIVE;
	c.sign = BI_SIGN_NEGATIVE;
	res = bi_add_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_add_bi (0x00 + 0xff90) : return value"
	);

	test(
		c.sign == BI_SIGN_POSITIVE,
		"bi_add_bi (0x00 + 0xff90) : c.sign"
	);

	test(
		c.size == b.occupied,
		"bi_add_bi (0x00 + 0xff90) : c.size"
	);

	test(
		c.occupied == b.occupied,
		"bi_add_bi (0x00 + 0xff90) : c.occupied"
	);

	test(
		c.data[0] == 0x90,
		"bi_add_bi (0x00 + 0xff90) : c.data[0]"
	);

	test(
		c.data[1] == 0xff,
		"bi_add_bi (0x00 + 0xff90) : c.data[1]"
	);

	bi_del(&a);
	bi_del(&b);
	bi_del(&c);
}

// case 0 + 0
void		test_bi_add_bi_case7(void)
{
	printf(KYEL "test_bi_add_bi_case7\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_init(&a);
	bi_init(&b);
	bi_init(&c);
	res = bi_add_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_add_bi (0x00 + 0x00) : return value"
	);

	test(
		c.size == 0,
		"bi_add_bi (0x00 + 0x00) : c.size"
	);

	test(
		c.occupied == 0,
		"bi_add_bi (0x00 + 0x00) : c.occupied"
	);

	bi_del(&a);
	bi_del(&b);
	bi_del(&c);
}

// case negative + positive
void		test_bi_add_bi_case8(void)
{
	printf(KYEL "test_bi_add_bi_case8\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_init(&a);
	bi_init(&b);
	bi_init(&c);
	bi_push(&a, 0xff);
	bi_push(&a, 0xff);
	bi_push(&b, 0x10);
	a.sign = BI_SIGN_NEGATIVE;
	res = bi_add_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_add_bi (-0xffff + 0x10) : return value"
	);

	test(
		c.sign == BI_SIGN_NEGATIVE,
		"bi_add_bi (-0xffff + 0x10) : c.sign"
	);

	test(
		c.occupied == 2,
		"bi_add_bi (-0xffff + 0x10) : c.occupied"
	);

	test(
		c.data[0] == 0xef,
		"bi_add_bi (-0xffff + 0x10) : c.data[0]"
	);

	test(
		c.data[1] == 0xff,
		"bi_add_bi (-0xffff + 0x10) : c.data[1]"
	);

	bi_del(&a);
	bi_del(&b);
	bi_del(&c);
}

// case positive + negative
void		test_bi_add_bi_case9(void)
{
	printf(KYEL "test_bi_add_bi_case9\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_init(&a);
	bi_init(&b);
	bi_init(&c);
	bi_push(&a, 0xff);
	bi_push(&a, 0xff);
	bi_push(&b, 0x10);
	b.sign = BI_SIGN_NEGATIVE;
	res = bi_add_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_add_bi (0xffff + -0x10) : return value"
	);

	test(
		c.sign == BI_SIGN_POSITIVE,
		"bi_add_bi (0xffff + -0x10) : c.sign"
	);

	test(
		c.occupied == 2,
		"bi_add_bi (0xffff + -0x10) : c.occupied"
	);

	test(
		c.data[0] == 0xef,
		"bi_add_bi (0xffff + -0x10) : c.data[0]"
	);

	test(
		c.data[1] == 0xff,
		"bi_add_bi (0xffff + -0x10) : c.data[1]"
	);

	bi_del(&a);
	bi_del(&b);
	bi_del(&c);
}

// case mutable b = c
void		test_bi_add_bi_case10(void)
{
	printf(KYEL "test_bi_add_bi_case10\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_init(&a);
	bi_init(&b);
	bi_push(&a, 0xff);
	bi_push(&a, 0xff);
	bi_push(&b, 0x10);
	res = bi_add_bi(&a, &b, &b);

	test(
		res == BI_SUCCESS,
		"bi_add_bi (0xffff + 0x10) : return value"
	);

	test(
		b.sign == BI_SIGN_POSITIVE,
		"bi_add_bi (0xffff + 0x10) : b.sign"
	);

	test(
		b.occupied == 3,
		"bi_add_bi (0xffff + 0x10) : b.occupied"
	);

	test(
		b.data[0] == 0x0f,
		"bi_add_bi (0xffff + 0x10) : b.data[0]"
	);

	test(
		b.data[1] == 0x00,
		"bi_add_bi (0xffff + 0x10) : b.data[1]"
	);

	test(
		b.data[2] == 0x01,
		"bi_add_bi (0xffff + 0x10) : b.data[2]"
	);

	bi_del(&a);
	bi_del(&b);
}

// case mutable a = c
void		test_bi_add_bi_case11(void)
{
	printf(KYEL "test_bi_add_bi_case11\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_init(&a);
	bi_init(&b);
	bi_push(&a, 0xff);
	bi_push(&a, 0xff);
	bi_push(&b, 0x10);
	res = bi_add_bi(&a, &b, &a);

	test(
		res == BI_SUCCESS,
		"bi_add_bi (0xffff + 0x10) : return value"
	);

	test(
		a.sign == BI_SIGN_POSITIVE,
		"bi_add_bi (0xffff + 0x10) : b.sign"
	);

	test(
		a.occupied == 3,
		"bi_add_bi (0xffff + 0x10) : a.occupied"
	);

	test(
		a.data[0] == 0x0f,
		"bi_add_bi (0xffff + 0x10) : a.data[0]"
	);

	test(
		a.data[1] == 0x00,
		"bi_add_bi (0xffff + 0x10) : a.data[1]"
	);

	test(
		a.data[2] == 0x01,
		"bi_add_bi (0xffff + 0x10) : a.data[2]"
	);

	bi_del(&a);
	bi_del(&b);
}
