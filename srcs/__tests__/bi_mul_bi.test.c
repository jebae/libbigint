#include "bigint.test.h"

void		test_bi_mul_1byte_case1(void)
{
	printf(KYEL "test_bi_mul_1byte_case1\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	unsigned char	factor;
	int				res;

	factor = 0xea;
	bi_new(&a, 1, BI_SIGN_NEGATIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x04);
	bi_push(&a, 0x7a);
	bi_push(&a, 0x90);
	res = bi_mul_1byte(&a, factor, &b);

	test(
		res == BI_SUCCESS,
		"bi_mul_bi (0x907a04 * 0xea) : return value"
	);

	test(
		b.sign == a.sign,
		"bi_mul_bi (0x907a04 * 0xea) : b.sign"
	);

	test(
		b.occupied == 4,
		"bi_mul_bi (0x907a04 * 0xea) : b.occupied"
	);

	test(
		b.data[0] == 0xa8,
		"bi_mul_bi (0x907a04 * 0xea) : b.data[0]"
	);

	test(
		b.data[1] == 0x87,
		"bi_mul_bi (0x907a04 * 0xea) : b.data[1]"
	);

	test(
		b.data[2] == 0x0f,
		"bi_mul_bi (0x907a04 * 0xea) : b.data[2]"
	);

	test(
		b.data[3] == 0x84,
		"bi_mul_bi (0x907a04 * 0xea) : b.data[3]"
	);

	free(a.data);
	free(b.data);
}

// case a * 0
void		test_bi_mul_1byte_case2(void)
{
	printf(KYEL "test_bi_mul_1byte_case2\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	unsigned char	factor;
	int				res;

	factor = 0x00;
	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x04);
	bi_push(&a, 0x7a);
	bi_push(&a, 0x90);
	res = bi_mul_1byte(&a, factor, &b);

	test(
		res == BI_SUCCESS,
		"bi_mul_bi (0x907a04 * 0) : return value"
	);

	test(
		b.occupied == 0,
		"bi_mul_bi (0x907a04 * 0) : b.occupied"
	);

	free(a.data);
	free(b.data);
}

// case 0 * factor
void		test_bi_mul_1byte_case3(void)
{
	printf(KYEL "test_bi_mul_1byte_case3\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	unsigned char	factor;
	int				res;

	factor = 0xea;
	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	res = bi_mul_1byte(&a, factor, &b);

	test(
		res == BI_SUCCESS,
		"bi_mul_bi (0x00 * 0xea) : return value"
	);

	test(
		b.occupied == 0,
		"bi_mul_bi (0x00 * 0xea) : b.occupied"
	);

	free(a.data);
	free(b.data);
}
/*
// case small
void		test_bi_mul_bi_case1(void)
{
	printf(KYEL "test_bi_mul_bi_case1\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_new(&c, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x04);
	bi_push(&b, 0x7a);
	res = bi_mul_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_mul_bi (0x04 * 0x7a) : return value"
	);

	test(
		c.occupied == 2,
		"bi_mul_bi (0x04 * 0x7a) : c.occupied"
	);

	test(
		c.data[0] == 0xe8,
		"bi_mul_bi (0x04 * 0x7a) : c.data[0]"
	);

	test(
		c.data[1] == 0x01,
		"bi_mul_bi (0x04 * 0x7a) : c.data[1]"
	);

	free(a.data);
	free(b.data);
	free(c.data);
}

// case big
void		test_bi_mul_bi_case2(void)
{
	printf(KYEL "test_bi_mul_bi_case2\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	t_bigint		c;
	int				res;
	unsigned char	a_arr[9] = { 0x45, 0x09, 0xf3, 0x0e, 0x98, 0xa8, 0x70, 0x10, 0x99 };
	unsigned char	b_arr[9] = { 0x22, 0x1a, 0xfe, 0x8e, 0x90, 0xb1, 0x20, 0x34, 0xe9 };
	unsigned char	expected[10] = { 0x6a, 0x12, 0xb6, 0xa7, 0x3f, 0x5e, 0xc5, 0x73, 0xaa, 0x8e };

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	for (int i=0; i < 9; i++)
	{
		bi_push(&a, a_arr[i]);
		bi_push(&b, b_arr[i]);
	}
	res = bi_mul_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_mul_bi (0x991070a8980ef30945 * 0xe93420b1908efe1a22) : return value"
	);

	test(
		c.occupied == 10,
		"bi_mul_bi (0x991070a8980ef30945 * 0xe93420b1908efe1a22) : c.occupied value"
	);

	for (int i=0; i < 10; i++)
		test(
			c.data[i] == expected[i],
			"bi_mul_bi (0x991070a8980ef30945 * 0xe93420b1908efe1a22) : c.data[i]"
		);

	free(a.data);
	free(b.data);
	free(c.data);
}

// case a * 1
void		test_bi_mul_bi_case3(void)
{
	printf(KYEL "test_bi_mul_bi_case3\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	t_bigint		c;
	int				res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x67);
	bi_push(&a, 0x78);
	bi_push(&a, 0x89);
	bi_push(&b, 0x01);
	res = bi_mul_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_mul_bi (0x897867 * 0x01) : return value"
	);

	test(
		c.occupied == a.occupied,
		"bi_mul_bi (0x897867 * 0x01) : c.occupied"
	);

	for (int i=0; i < a.occupied; i++)
		test(
			c.data[i] == a.data[i],
			"bi_mul_bi (0x897867 * 0x01) : c.data[i]"
		);

	free(a.data);
	free(b.data);
	free(c.data);
}

// case 1 * b
void		test_bi_mul_bi_case4(void)
{
	printf(KYEL "test_bi_mul_bi_case4\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	t_bigint		c;
	int				res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x01);
	bi_push(&b, 0x67);
	bi_push(&b, 0x78);
	bi_push(&b, 0x89);
	res = bi_mul_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_mul_bi (0x01 * 0x897867) : return value"
	);

	test(
		c.occupied == b.occupied,
		"bi_mul_bi (0x01 * 0x897867) : c.occupied"
	);

	for (int i=0; i < b.occupied; i++)
		test(
			c.data[i] == b.data[i],
			"bi_mul_bi (0x01 * 0x897867) : c.data[i]"
		);

	free(a.data);
	free(b.data);
	free(c.data);
}

// case positive * negative
void		test_bi_mul_bi_case5(void)
{
	printf(KYEL "test_bi_mul_bi_case5\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	t_bigint		c;
	int				res;
	unsigned char	expected[5] = { 0x8a, 0x4a, 0x06, 0x55, 0x1b };

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_NEGATIVE);
	bi_push(&a, 0xe6);
	bi_push(&a, 0x32);
	bi_push(&b, 0x67);
	bi_push(&b, 0x78);
	bi_push(&b, 0x89);
	res = bi_mul_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_mul_bi (0x32e6 * -0x897867) : return value"
	);

	test(
		c.sign == BI_SIGN_NEGATIVE,
		"bi_mul_bi (0x32e6 * -0x897867) : c.sign"
	);

	test(
		c.occupied == 5,
		"bi_mul_bi (0x32e6 * -0x897867) : c.occupied"
	);

	for (int i=0; i < b.occupied; i++)
		test(
			c.data[i] == expected[i],
			"bi_mul_bi (0x32e6 * -0x897867) : c.data[i]"
		);

	free(a.data);
	free(b.data);
	free(c.data);
}

// case negative * positive
void		test_bi_mul_bi_case6(void)
{
	printf(KYEL "test_bi_mul_bi_case6\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	t_bigint		c;
	int				res;
	unsigned char	expected[5] = { 0x8a, 0x4a, 0x06, 0x55, 0x1b };

	bi_new(&a, 1, BI_SIGN_NEGATIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0xe6);
	bi_push(&a, 0x32);
	bi_push(&b, 0x67);
	bi_push(&b, 0x78);
	bi_push(&b, 0x89);
	res = bi_mul_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_mul_bi (-0x32e6 * 0x897867) : return value"
	);

	test(
		c.sign == BI_SIGN_NEGATIVE,
		"bi_mul_bi (-0x32e6 * 0x897867) : c.sign"
	);

	test(
		c.occupied == 5,
		"bi_mul_bi (-0x32e6 * 0x897867) : c.occupied"
	);

	for (int i=0; i < b.occupied; i++)
		test(
			c.data[i] == expected[i],
			"bi_mul_bi (-0x32e6 * 0x897867) : c.data[i]"
		);

	free(a.data);
	free(b.data);
	free(c.data);
}

// case negative * negative
void		test_bi_mul_bi_case7(void)
{
	printf(KYEL "test_bi_mul_bi_case7\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	t_bigint		c;
	int				res;
	unsigned char	expected[5] = { 0x8a, 0x4a, 0x06, 0x55, 0x1b };

	bi_new(&a, 1, BI_SIGN_NEGATIVE);
	bi_new(&b, 1, BI_SIGN_NEGATIVE);
	bi_push(&a, 0xe6);
	bi_push(&a, 0x32);
	bi_push(&b, 0x67);
	bi_push(&b, 0x78);
	bi_push(&b, 0x89);
	res = bi_mul_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_mul_bi (-0x32e6 * -0x897867) : return value"
	);

	test(
		c.sign == BI_SIGN_NEGATIVE,
		"bi_mul_bi (-0x32e6 * -0x897867) : c.sign"
	);

	test(
		c.occupied == 5,
		"bi_mul_bi (-0x32e6 * -0x897867) : c.occupied"
	);

	for (int i=0; i < b.occupied; i++)
		test(
			c.data[i] == expected[i],
			"bi_mul_bi (-0x32e6 * -0x897867) : c.data[i]"
		);

	free(a.data);
	free(b.data);
	free(c.data);
}

// case a * 0
void		test_bi_mul_bi_case8(void)
{
	printf(KYEL "test_bi_mul_bi_case8\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	t_bigint		c;
	int				res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0xe6);
	bi_push(&a, 0x32);
	res = bi_mul_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_mul_bi (0x32e6 * 0x00) : return value"
	);

	test(
		c.occupied == 0,
		"bi_mul_bi (0x32e6 * 0x00) : c.occupied"
	);

	free(a.data);
	free(b.data);
	free(c.data);
}

// case 0 * b
void		test_bi_mul_bi_case9(void)
{
	printf(KYEL "test_bi_mul_bi_case9\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	t_bigint		c;
	int				res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&b, 0xe6);
	bi_push(&b, 0x32);
	res = bi_mul_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_mul_bi (0x00 * 0x32e6) : return value"
	);

	test(
		c.occupied == 0,
		"bi_mul_bi (0x00 * 0x32e6) : c.occupied"
	);

	free(a.data);
	free(b.data);
	free(c.data);
}

// case 0 * 0
void		test_bi_mul_bi_case10(void)
{
	printf(KYEL "test_bi_mul_bi_case10\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	t_bigint		c;
	int				res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	res = bi_mul_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_mul_bi (0x00 * 0x00) : return value"
	);

	test(
		c.occupied == 0,
		"bi_mul_bi (0x00 * 0x00) : c.occupied"
	);

	free(a.data);
	free(b.data);
	free(c.data);
}

// case big to handle array length = 64
void		test_bi_mul_bi_case11(void)
{
	printf(KYEL "test_bi_mul_bi_case11\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	t_bigint		c;
	int				res;
	unsigned char	a_arr[19] = { 0xfe, };
	unsigned char	b_arr[17] = { 0xdf, };
	unsigned char	expected[19] = {
		0x82, 0xcb, 0x0e, 0x53, 0x97, 0xdb, 0x1f, 0x64, 0x88, 0x14, 0x8c,
		0x57, 0x13, 0xcf, 0x8a, 0x46, 0x02, 0xbe, 0xfb
	};

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	for (int i=0; i < 19; i++)
		bi_push(&a, a_arr[i]);
	for (int i=0; i < 17; i++)
		bi_push(&b, b_arr[i]);
	res = bi_mul_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_mul_bi ( ([0xfe] * 19) * ([0xdf] * 17)) : return value"
	);

	test(
		c.occupied == 19,
		"bi_mul_bi ( ([0xfe] * 19) * ([0xdf] * 17)) : c.occupied"
	);

	for (int i=0; i < 19; i++)
		test(
			c.data[i] == expected[i],
		"bi_mul_bi ( ([0xfe] * 19) * ([0xdf] * 17)) : c.data[i]"
		);

	free(a.data);
	free(b.data);
	free(c.data);
}
*/

// mutable
