#include "bigint.test.h"

void		test_bi_add_bi_case1(void)
{
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_new(&c, 1, BI_SIGN_POSITIVE);
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

	free(a.data);
	free(b.data);
	free(c.data);
}

void		test_bi_add_bi_case2(void)
{
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_new(&a, 2, BI_SIGN_POSITIVE);
	bi_new(&b, 2, BI_SIGN_POSITIVE);
	bi_new(&c, 1, BI_SIGN_POSITIVE);
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

	free(a.data);
	free(b.data);
	free(c.data);
}

void		test_bi_add_bi_case3(void)
{
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_new(&a, 2, BI_SIGN_NEGATIVE);
	bi_new(&b, 2, BI_SIGN_NEGATIVE);
	bi_new(&c, 1, BI_SIGN_POSITIVE);
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

	free(a.data);
	free(b.data);
	free(c.data);
}
