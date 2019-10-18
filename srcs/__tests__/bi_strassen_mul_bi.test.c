#include "bigint.test.h"

// case small
void		test_bi_strassen_mul_bi_case1(void)
{
	printf(KYEL "test_bi_strassen_mul_bi_case1\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	c;
	int			res;

	bi_init(&a);
	bi_init(&b);
	bi_init(&c);
	bi_push(&a, 0x04);
	bi_push(&b, 0x7a);
	res = bi_strassen_mul_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_strassen_mul_bi (0x04 * 0x7a) : return value"
	);

	test(
		c.occupied == 2,
		"bi_strassen_mul_bi (0x04 * 0x7a) : c.occupied"
	);

	test(
		c.data[0] == 0xe8,
		"bi_strassen_mul_bi (0x04 * 0x7a) : c.data[0]"
	);

	test(
		c.data[1] == 0x01,
		"bi_strassen_mul_bi (0x04 * 0x7a) : c.data[1]"
	);

	bi_del(&a);
	bi_del(&b);
	bi_del(&c);
}

// case big
void		test_bi_strassen_mul_bi_case2(void)
{
	printf(KYEL "test_bi_strassen_mul_bi_case2\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	t_bigint		c;
	int				res;
	unsigned char	a_arr[9] = { 0x45, 0x09, 0xf3, 0x0e, 0x98, 0xa8, 0x70, 0x10, 0x99 };
	unsigned char	b_arr[9] = { 0x22, 0x1a, 0xfe, 0x8e, 0x90, 0xb1, 0x20, 0x34, 0xe9 };
	unsigned char	expected[18] = {
		0x2a, 0x3d, 0xae, 0x23, 0xce, 0x65, 0xfd, 0xdd, 0x39,
		0x11, 0x3b, 0x34, 0x86, 0x8d, 0x6c, 0x21, 0x6f, 0x8b
	};

	bi_init(&a);
	bi_init(&b);
	bi_init(&c);
	for (size_t i=0; i < 9; i++)
	{
		bi_push(&a, a_arr[i]);
		bi_push(&b, b_arr[i]);
	}
	res = bi_strassen_mul_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_strassen_mul_bi (0x991070a8980ef30945 * 0xe93420b1908efe1a22) : return value"
	);

	test(
		c.occupied == 18,
		"bi_strassen_mul_bi (0x991070a8980ef30945 * 0xe93420b1908efe1a22) : c.occupied"
	);

	for (size_t i=0; i < 18; i++)
		test(
			c.data[i] == expected[i],
			"bi_strassen_mul_bi (0x991070a8980ef30945 * 0xe93420b1908efe1a22) : c.data[i]"
		);

	bi_del(&a);
	bi_del(&b);
	bi_del(&c);
}

// case a * 1
void		test_bi_strassen_mul_bi_case3(void)
{
	printf(KYEL "test_bi_strassen_mul_bi_case3\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	t_bigint		c;
	int				res;

	bi_init(&a);
	bi_init(&b);
	bi_init(&c);
	bi_push(&a, 0x67);
	bi_push(&a, 0x78);
	bi_push(&a, 0x89);
	bi_push(&b, 0x01);
	res = bi_strassen_mul_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_strassen_mul_bi (0x897867 * 0x01) : return value"
	);

	test(
		c.occupied == a.occupied,
		"bi_strassen_mul_bi (0x897867 * 0x01) : c.occupied"
	);

	for (size_t i=0; i < a.occupied; i++)
		test(
			c.data[i] == a.data[i],
			"bi_strassen_mul_bi (0x897867 * 0x01) : c.data[i]"
		);

	bi_del(&a);
	bi_del(&b);
	bi_del(&c);
}

// case 1 * b
void		test_bi_strassen_mul_bi_case4(void)
{
	printf(KYEL "test_bi_strassen_mul_bi_case4\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	t_bigint		c;
	int				res;

	bi_init(&a);
	bi_init(&b);
	bi_init(&c);
	bi_push(&a, 0x01);
	bi_push(&b, 0x67);
	bi_push(&b, 0x78);
	bi_push(&b, 0x89);
	res = bi_strassen_mul_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_strassen_mul_bi (0x01 * 0x897867) : return value"
	);

	test(
		c.occupied == b.occupied,
		"bi_strassen_mul_bi (0x01 * 0x897867) : c.occupied"
	);

	for (size_t i=0; i < b.occupied; i++)
		test(
			c.data[i] == b.data[i],
			"bi_strassen_mul_bi (0x01 * 0x897867) : c.data[i]"
		);

	bi_del(&a);
	bi_del(&b);
	bi_del(&c);
}

// case positive * negative
void		test_bi_strassen_mul_bi_case5(void)
{
	printf(KYEL "test_bi_strassen_mul_bi_case5\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	t_bigint		c;
	int				res;
	unsigned char	expected[5] = { 0x8a, 0x4a, 0x06, 0x55, 0x1b };

	bi_init(&a);
	bi_init(&b);
	bi_init(&c);
	bi_push(&a, 0xe6);
	bi_push(&a, 0x32);
	bi_push(&b, 0x67);
	bi_push(&b, 0x78);
	bi_push(&b, 0x89);
	b.sign = BI_SIGN_NEGATIVE;
	res = bi_strassen_mul_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_strassen_mul_bi (0x32e6 * -0x897867) : return value"
	);

	test(
		c.sign == BI_SIGN_NEGATIVE,
		"bi_strassen_mul_bi (0x32e6 * -0x897867) : c.sign"
	);

	test(
		c.occupied == 5,
		"bi_strassen_mul_bi (0x32e6 * -0x897867) : c.occupied"
	);

	for (size_t i=0; i < c.occupied; i++)
		test(
			c.data[i] == expected[i],
			"bi_strassen_mul_bi (0x32e6 * -0x897867) : c.data[i]"
		);

	bi_del(&a);
	bi_del(&b);
	bi_del(&c);
}

// case negative * positive
void		test_bi_strassen_mul_bi_case6(void)
{
	printf(KYEL "test_bi_strassen_mul_bi_case6\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	t_bigint		c;
	int				res;
	unsigned char	expected[5] = { 0x8a, 0x4a, 0x06, 0x55, 0x1b };

	bi_init(&a);
	bi_init(&b);
	bi_init(&c);
	bi_push(&a, 0xe6);
	bi_push(&a, 0x32);
	bi_push(&b, 0x67);
	bi_push(&b, 0x78);
	bi_push(&b, 0x89);
	a.sign = BI_SIGN_NEGATIVE;
	res = bi_strassen_mul_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_strassen_mul_bi (-0x32e6 * 0x897867) : return value"
	);

	test(
		c.sign == BI_SIGN_NEGATIVE,
		"bi_strassen_mul_bi (-0x32e6 * 0x897867) : c.sign"
	);

	test(
		c.occupied == 5,
		"bi_strassen_mul_bi (-0x32e6 * 0x897867) : c.occupied"
	);

	for (size_t i=0; i < b.occupied; i++)
		test(
			c.data[i] == expected[i],
			"bi_strassen_mul_bi (-0x32e6 * 0x897867) : c.data[i]"
		);

	bi_del(&a);
	bi_del(&b);
	bi_del(&c);
}

// case negative * negative
void		test_bi_strassen_mul_bi_case7(void)
{
	printf(KYEL "test_bi_strassen_mul_bi_case7\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	t_bigint		c;
	int				res;
	unsigned char	expected[5] = { 0x8a, 0x4a, 0x06, 0x55, 0x1b };

	bi_init(&a);
	bi_init(&b);
	bi_init(&c);
	bi_push(&a, 0xe6);
	bi_push(&a, 0x32);
	bi_push(&b, 0x67);
	bi_push(&b, 0x78);
	bi_push(&b, 0x89);
	a.sign = BI_SIGN_NEGATIVE;
	b.sign = BI_SIGN_NEGATIVE;
	res = bi_strassen_mul_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_strassen_mul_bi (-0x32e6 * -0x897867) : return value"
	);

	test(
		c.sign == BI_SIGN_POSITIVE,
		"bi_strassen_mul_bi (-0x32e6 * -0x897867) : c.sign"
	);

	test(
		c.occupied == 5,
		"bi_strassen_mul_bi (-0x32e6 * -0x897867) : c.occupied"
	);

	for (size_t i=0; i < b.occupied; i++)
		test(
			c.data[i] == expected[i],
			"bi_strassen_mul_bi (-0x32e6 * -0x897867) : c.data[i]"
		);

	bi_del(&a);
	bi_del(&b);
	bi_del(&c);
}

// case a * 0
void		test_bi_strassen_mul_bi_case8(void)
{
	printf(KYEL "test_bi_strassen_mul_bi_case8\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	t_bigint		c;
	int				res;

	bi_init(&a);
	bi_init(&b);
	bi_init(&c);
	bi_push(&a, 0xe6);
	bi_push(&a, 0x32);
	res = bi_strassen_mul_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_strassen_mul_bi (0x32e6 * 0x00) : return value"
	);

	test(
		c.occupied == 0,
		"bi_strassen_mul_bi (0x32e6 * 0x00) : c.occupied"
	);

	bi_del(&a);
	bi_del(&b);
	bi_del(&c);
}

// case 0 * b
void		test_bi_strassen_mul_bi_case9(void)
{
	printf(KYEL "test_bi_strassen_mul_bi_case9\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	t_bigint		c;
	int				res;

	bi_init(&a);
	bi_init(&b);
	bi_init(&c);
	bi_push(&b, 0xe6);
	bi_push(&b, 0x32);
	res = bi_strassen_mul_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_strassen_mul_bi (0x00 * 0x32e6) : return value"
	);

	test(
		c.occupied == 0,
		"bi_strassen_mul_bi (0x00 * 0x32e6) : c.occupied"
	);

	bi_del(&a);
	bi_del(&b);
	bi_del(&c);
}

// case 0 * 0
void		test_bi_strassen_mul_bi_case10(void)
{
	printf(KYEL "test_bi_strassen_mul_bi_case10\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	t_bigint		c;
	int				res;

	bi_init(&a);
	bi_init(&b);
	bi_init(&c);
	res = bi_strassen_mul_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_strassen_mul_bi (0x00 * 0x00) : return value"
	);

	test(
		c.occupied == 0,
		"bi_strassen_mul_bi (0x00 * 0x00) : c.occupied"
	);

	bi_del(&a);
	bi_del(&b);
	bi_del(&c);
}

// case big
void		test_bi_strassen_mul_bi_case11(void)
{
	printf(KYEL "test_bi_strassen_mul_bi_case11\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	t_bigint		c;
	int				res;
	unsigned char	a_arr[19] = {
		0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
		0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
		0xfe, 0xfe, 0xfe
	};
	unsigned char	b_arr[17] = {
		0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf,
		0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf,
		0xdf
	};
	unsigned char	expected[36] = {
		0x42, 0x61, 0x81, 0xa1, 0xc1, 0xe1, 0x01, 0x22, 0x42, 0x62, 0x82,
		0xa2, 0xc2, 0xe2, 0x02, 0x23, 0x43, 0x21, 0x22, 0xe0, 0xc0, 0xa0,
		0x80, 0x60, 0x40, 0x20, 0x00, 0xe0, 0xbf, 0x9f, 0x7f, 0x5f, 0x3f,
		0x1f, 0xff, 0xde
	};

	bi_init(&a);
	bi_init(&b);
	bi_init(&c);
	for (size_t i=0; i < 19; i++)
		bi_push(&a, a_arr[i]);
	for (size_t i=0; i < 17; i++)
		bi_push(&b, b_arr[i]);
	res = bi_strassen_mul_bi(&a, &b, &c);

	test(
		res == BI_SUCCESS,
		"bi_strassen_mul_bi ( ([0xfe] * 19) * ([0xdf] * 17)) : return value"
	);

	test(
		c.occupied == 36,
		"bi_strassen_mul_bi ( ([0xfe] * 19) * ([0xdf] * 17)) : c.occupied"
	);

	for (size_t i=0; i < 36; i++)
		test(
			c.data[i] == expected[i],
			"bi_strassen_mul_bi ( ([0xfe] * 19) * ([0xdf] * 17)) : c.data[i]"
		);

	bi_del(&a);
	bi_del(&b);
	bi_del(&c);
}

// case mutable a = c
void		test_bi_strassen_mul_bi_case12(void)
{
	printf(KYEL "test_bi_strassen_mul_bi_case12\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	int				res;
	unsigned char	a_arr[19] = {
		0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
		0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
		0xfe, 0xfe, 0xfe
	};
	unsigned char	b_arr[17] = {
		0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf,
		0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf,
		0xdf
	};
	unsigned char	expected[36] = {
		0x42, 0x61, 0x81, 0xa1, 0xc1, 0xe1, 0x01, 0x22, 0x42, 0x62, 0x82,
		0xa2, 0xc2, 0xe2, 0x02, 0x23, 0x43, 0x21, 0x22, 0xe0, 0xc0, 0xa0,
		0x80, 0x60, 0x40, 0x20, 0x00, 0xe0, 0xbf, 0x9f, 0x7f, 0x5f, 0x3f,
		0x1f, 0xff, 0xde
	};

	bi_init(&a);
	bi_init(&b);
	for (size_t i=0; i < 19; i++)
		bi_push(&a, a_arr[i]);
	for (size_t i=0; i < 17; i++)
		bi_push(&b, b_arr[i]);
	res = bi_strassen_mul_bi(&a, &b, &a);

	test(
		res == BI_SUCCESS,
		"bi_strassen_mul_bi ( ([0xfe] * 19) * ([0xdf] * 17)) : return value"
	);

	test(
		a.occupied == 36,
		"bi_strassen_mul_bi ( ([0xfe] * 19) * ([0xdf] * 17)) : a.occupied"
	);

	for (size_t i=0; i < 36; i++)
		test(
			a.data[i] == expected[i],
			"bi_strassen_mul_bi ( ([0xfe] * 19) * ([0xdf] * 17)) : a.data[i]"
		);

	bi_del(&a);
	bi_del(&b);
}

// case mutable b = c
void		test_bi_strassen_mul_bi_case13(void)
{
	printf(KYEL "test_bi_strassen_mul_bi_case13\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	int				res;
	unsigned char	a_arr[19] = {
		0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
		0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
		0xfe, 0xfe, 0xfe
	};
	unsigned char	b_arr[17] = {
		0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf,
		0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf,
		0xdf
	};
	unsigned char	expected[36] = {
		0x42, 0x61, 0x81, 0xa1, 0xc1, 0xe1, 0x01, 0x22, 0x42, 0x62, 0x82,
		0xa2, 0xc2, 0xe2, 0x02, 0x23, 0x43, 0x21, 0x22, 0xe0, 0xc0, 0xa0,
		0x80, 0x60, 0x40, 0x20, 0x00, 0xe0, 0xbf, 0x9f, 0x7f, 0x5f, 0x3f,
		0x1f, 0xff, 0xde
	};

	bi_init(&a);
	bi_init(&b);
	for (size_t i=0; i < 19; i++)
		bi_push(&a, a_arr[i]);
	for (size_t i=0; i < 17; i++)
		bi_push(&b, b_arr[i]);
	res = bi_strassen_mul_bi(&a, &b, &b);

	test(
		res == BI_SUCCESS,
		"bi_strassen_mul_bi ( ([0xfe] * 19) * ([0xdf] * 17)) : return value"
	);

	test(
		b.occupied == 36,
		"bi_strassen_mul_bi ( ([0xfe] * 19) * ([0xdf] * 17)) : b.occupied"
	);

	for (size_t i=0; i < 36; i++)
		test(
			b.data[i] == expected[i],
			"bi_strassen_mul_bi ( ([0xfe] * 19) * ([0xdf] * 17)) : b.data[i]"
		);

	bi_del(&a);
	bi_del(&b);
}
