#include "bigint.test.h"

// case q - p < 0
void		test_bi_mod_n_pow_of_2_plus_1_case1(void)
{
	printf(KYEL "test_bi_mod_n_pow_of_2_plus_1_case1\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x80);

	// A mod 17
	res = bi_mod_n_pow_of_2_plus_1(&a, 4, &b);

	test(
		res == BI_SUCCESS,
		"bi_mod_n_pow_of_2_plus_1 (128 mod 17) : return value"
	);

	test(
		b.sign == BI_SIGN_POSITIVE,
		"bi_mod_n_pow_of_2_plus_1 (128 mod 17) : b.sign"
	);

	test(
		b.occupied == 1,
		"bi_mod_n_pow_of_2_plus_1 (128 mod 17) : b.occupied"
	);

	test(
		b.data[0] == 0x09,
		"bi_mod_n_pow_of_2_plus_1 (128 mod 17) : b.data[0]"
	);

	free(a.data);
	free(b.data);
}

// case p = 2^0 = 1
void		test_bi_mod_n_pow_of_2_plus_1_case2(void)
{
	printf(KYEL "test_bi_mod_n_pow_of_2_plus_1_case2\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x15);

	// A mod 17
	res = bi_mod_n_pow_of_2_plus_1(&a, 4, &b);

	test(
		res == BI_SUCCESS,
		"bi_mod_n_pow_of_2_plus_1 (21 mod 17) : return value"
	);

	test(
		b.sign == BI_SIGN_POSITIVE,
		"bi_mod_n_pow_of_2_plus_1 (21 mod 17) : b.sign"
	);

	test(
		b.occupied == 1,
		"bi_mod_n_pow_of_2_plus_1 (21 mod 17) : b.occupied"
	);

	test(
		b.data[0] == 0x04,
		"bi_mod_n_pow_of_2_plus_1 (21 mod 17) : b.data[0]"
	);

	free(a.data);
	free(b.data);
}

// case A's max bit < n
void		test_bi_mod_n_pow_of_2_plus_1_case3(void)
{
	printf(KYEL "test_bi_mod_n_pow_of_2_plus_1_case3\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x0c);

	// A mod 17
	res = bi_mod_n_pow_of_2_plus_1(&a, 4, &b);

	test(
		res == BI_SUCCESS,
		"bi_mod_n_pow_of_2_plus_1 (12 mod 17) : return value"
	);

	test(
		b.sign == BI_SIGN_POSITIVE,
		"bi_mod_n_pow_of_2_plus_1 (12 mod 17) : b.sign"
	);

	test(
		b.occupied == 1,
		"bi_mod_n_pow_of_2_plus_1 (12 mod 17) : b.occupied"
	);

	test(
		b.data[0] == 0x0c,
		"bi_mod_n_pow_of_2_plus_1 (12 mod 17) : b.data[0]"
	);

	free(a.data);
	free(b.data);
}

// case multiple bits bigger than n is 1
void		test_bi_mod_n_pow_of_2_plus_1_case4(void)
{
	printf(KYEL "test_bi_mod_n_pow_of_2_plus_1_case4\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0xb5);
	bi_push(&a, 0x02);

	// A mod 17
	res = bi_mod_n_pow_of_2_plus_1(&a, 4, &b);

	test(
		res == BI_SUCCESS,
		"bi_mod_n_pow_of_2_plus_1 (693 mod 17) : return value"
	);

	test(
		b.sign == BI_SIGN_POSITIVE,
		"bi_mod_n_pow_of_2_plus_1 (693 mod 17) : b.sign"
	);

	test(
		b.occupied == 1,
		"bi_mod_n_pow_of_2_plus_1 (693 mod 17) : b.occupied"
	);

	test(
		b.data[0] == 0x0d,
		"bi_mod_n_pow_of_2_plus_1 (693 mod 17) : b.data[0]"
	);

	free(a.data);
	free(b.data);
}

// case negative
void		test_bi_mod_n_pow_of_2_plus_1_case5(void)
{
	printf(KYEL "test_bi_mod_n_pow_of_2_plus_1_case5\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_NEGATIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0xb5);
	bi_push(&a, 0x02);

	// A mod 17
	res = bi_mod_n_pow_of_2_plus_1(&a, 4, &b);

	test(
		res == BI_SUCCESS,
		"bi_mod_n_pow_of_2_plus_1 (-693 mod 17) : return value"
	);

	test(
		b.sign == BI_SIGN_POSITIVE,
		"bi_mod_n_pow_of_2_plus_1 (-693 mod 17) : b.sign"
	);

	test(
		b.occupied == 1,
		"bi_mod_n_pow_of_2_plus_1 (-693 mod 17) : b.occupied"
	);

	test(
		b.data[0] == 0x04,
		"bi_mod_n_pow_of_2_plus_1 (-693 mod 17) : b.data[0]"
	);

	free(a.data);
	free(b.data);
}

// case n = 0, A = odd number
void		test_bi_mod_n_pow_of_2_plus_1_case6(void)
{
	printf(KYEL "test_bi_mod_n_pow_of_2_plus_1_case6\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0xb5);
	bi_push(&a, 0x02);

	// A mod 1
	res = bi_mod_n_pow_of_2_plus_1(&a, 0, &b);

	test(
		res == BI_SUCCESS,
		"bi_mod_n_pow_of_2_plus_1 (693 mod 2) : return value"
	);

	test(
		b.sign == BI_SIGN_POSITIVE,
		"bi_mod_n_pow_of_2_plus_1 (693 mod 2) : b.sign"
	);

	test(
		b.occupied == 1,
		"bi_mod_n_pow_of_2_plus_1 (693 mod 2) : b.occupied"
	);

	test(
		b.data[0] == 0x01,
		"bi_mod_n_pow_of_2_plus_1 (693 mod 2) : b.data[0]"
	);

	free(a.data);
	free(b.data);
}

// case n = 0, A = even number
void		test_bi_mod_n_pow_of_2_plus_1_case7(void)
{
	printf(KYEL "test_bi_mod_n_pow_of_2_plus_1_case7\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0xb4);
	bi_push(&a, 0x02);

	// A mod 1
	res = bi_mod_n_pow_of_2_plus_1(&a, 0, &b);

	test(
		res == BI_SUCCESS,
		"bi_mod_n_pow_of_2_plus_1 (692 mod 2) : return value"
	);

	test(
		b.sign == BI_SIGN_POSITIVE,
		"bi_mod_n_pow_of_2_plus_1 (692 mod 2) : b.sign"
	);

	test(
		b.occupied == 0,
		"bi_mod_n_pow_of_2_plus_1 (692 mod 2) : b.occupied"
	);

	free(a.data);
	free(b.data);
}

/*
** case much of negative in loop
** e.g. 1 0000 0000, n = 2
** in upon case, q is always smaller than p
*/
void		test_bi_mod_n_pow_of_2_plus_1_case8(void)
{
	printf(KYEL "test_bi_mod_n_pow_of_2_plus_1_case8\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x00);
	bi_push(&a, 0x01);

	// A mod 5
	res = bi_mod_n_pow_of_2_plus_1(&a, 2, &b);

	test(
		res == BI_SUCCESS,
		"bi_mod_n_pow_of_2_plus_1 (256 mod 5) : return value"
	);

	test(
		b.sign == BI_SIGN_POSITIVE,
		"bi_mod_n_pow_of_2_plus_1 (256 mod 5) : b.sign"
	);

	test(
		b.occupied == 1,
		"bi_mod_n_pow_of_2_plus_1 (256 mod 5) : b.occupied"
	);

	test(
		b.data[0] == 0x01,
		"bi_mod_n_pow_of_2_plus_1 (256 mod 5) : b.data[0]"
	);

	free(a.data);
	free(b.data);
}

// case A = 0
void		test_bi_mod_n_pow_of_2_plus_1_case9(void)
{
	printf(KYEL "test_bi_mod_n_pow_of_2_plus_1_case9\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);

	// A mod 5
	res = bi_mod_n_pow_of_2_plus_1(&a, 2, &b);

	test(
		res == BI_SUCCESS,
		"bi_mod_n_pow_of_2_plus_1 (0 mod 5) : return value"
	);

	test(
		b.sign == BI_SIGN_POSITIVE,
		"bi_mod_n_pow_of_2_plus_1 (0 mod 5) : b.sign"
	);

	test(
		b.occupied == 0,
		"bi_mod_n_pow_of_2_plus_1 (0 mod 5) : b.occupied"
	);

	free(a.data);
	free(b.data);
}

// case big
void		test_bi_mod_n_pow_of_2_plus_1_case10(void)
{
	printf(KYEL "test_bi_mod_n_pow_of_2_plus_1_case10\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x03);
	bi_push(&a, 0x00);
	bi_push(&a, 0x03);

	// A mod 2^16 + 1
	res = bi_mod_n_pow_of_2_plus_1(&a, 16, &b);

	test(
		res == BI_SUCCESS,
		"bi_mod_n_pow_of_2_plus_1 (196611 mod 65537) : return value"
	);

	test(
		b.sign == BI_SIGN_POSITIVE,
		"bi_mod_n_pow_of_2_plus_1 (196611 mod 65537) : b.sign"
	);

	test(
		b.occupied == 0,
		"bi_mod_n_pow_of_2_plus_1 (196611 mod 65537) : b.occupied"
	);

	free(a.data);
	free(b.data);
}

// case big 2
void		test_bi_mod_n_pow_of_2_plus_1_case11(void)
{
	printf(KYEL "test_bi_mod_n_pow_of_2_plus_1_case11\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x05);
	bi_push(&a, 0xb9);
	bi_push(&a, 0xa7);
	bi_push(&a, 0x03);
	bi_push(&a, 0xef);

	// A mod 2^16 + 1
	res = bi_mod_n_pow_of_2_plus_1(&a, 16, &b);

	test(
		res == BI_SUCCESS,
		"bi_mod_n_pow_of_2_plus_1 (1026558507269 mod 65537) : return value"
	);

	test(
		b.sign == BI_SIGN_POSITIVE,
		"bi_mod_n_pow_of_2_plus_1 (1026558507269 mod 65537) : b.sign"
	);

	test(
		b.occupied == 2,
		"bi_mod_n_pow_of_2_plus_1 (1026558507269 mod 65537) : b.occupied"
	);

	test(
		b.data[0] == 0x4d,
		"bi_mod_n_pow_of_2_plus_1 (1026558507269 mod 65537) : b.data[0]"
	);

	test(
		b.data[1] == 0xb6,
		"bi_mod_n_pow_of_2_plus_1 (1026558507269 mod 65537) : b.data[1]"
	);

	free(a.data);
	free(b.data);
}

// case big A = 0
void		test_bi_mod_n_pow_of_2_plus_1_case12(void)
{
	printf(KYEL "test_bi_mod_n_pow_of_2_plus_1_case12\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);

	// A mod 2^16 + 1
	res = bi_mod_n_pow_of_2_plus_1(&a, 16, &b);

	test(
		res == BI_SUCCESS,
		"bi_mod_n_pow_of_2_plus_1 (0 mod 65537) : return value"
	);

	test(
		b.sign == BI_SIGN_POSITIVE,
		"bi_mod_n_pow_of_2_plus_1 (0 mod 65537) : b.sign"
	);

	test(
		b.occupied == 0,
		"bi_mod_n_pow_of_2_plus_1 (0 mod 65537) : b.occupied"
	);

	free(a.data);
	free(b.data);
}

// case mutable
void		test_bi_mod_n_pow_of_2_plus_1_case13(void)
{
	printf(KYEL "test_bi_mod_n_pow_of_2_plus_1_case13\n" KNRM);
	t_bigint	a;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x05);
	bi_push(&a, 0xb9);
	bi_push(&a, 0xa7);
	bi_push(&a, 0x03);
	bi_push(&a, 0xef);

	// A mod 2^16 + 1
	res = bi_mod_n_pow_of_2_plus_1(&a, 16, &a);

	test(
		res == BI_SUCCESS,
		"bi_mod_n_pow_of_2_plus_1 (1026558507269 mod 65537) : return value"
	);

	test(
		a.sign == BI_SIGN_POSITIVE,
		"bi_mod_n_pow_of_2_plus_1 (1026558507269 mod 65537) : a.sign"
	);

	test(
		a.occupied == 2,
		"bi_mod_n_pow_of_2_plus_1 (1026558507269 mod 65537) : a.occupied"
	);

	test(
		a.data[0] == 0x4d,
		"bi_mod_n_pow_of_2_plus_1 (1026558507269 mod 65537) : a.data[0]"
	);

	test(
		a.data[1] == 0xb6,
		"bi_mod_n_pow_of_2_plus_1 (1026558507269 mod 65537) : a.data[1]"
	);

	free(a.data);
}

// case mutable n = 0
void		test_bi_mod_n_pow_of_2_plus_1_case14(void)
{
	printf(KYEL "test_bi_mod_n_pow_of_2_plus_1_case14\n" KNRM);
	t_bigint	a;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x05);
	bi_push(&a, 0xb9);
	bi_push(&a, 0xa7);
	bi_push(&a, 0x03);
	bi_push(&a, 0xef);

	// A mod 2^16 + 1
	res = bi_mod_n_pow_of_2_plus_1(&a, 0, &a);

	test(
		res == BI_SUCCESS,
		"bi_mod_n_pow_of_2_plus_1 (1026558507269 mod 2) : return value"
	);

	test(
		a.sign == BI_SIGN_POSITIVE,
		"bi_mod_n_pow_of_2_plus_1 (1026558507269 mod 2) : a.sign"
	);

	test(
		a.occupied == 1,
		"bi_mod_n_pow_of_2_plus_1 (1026558507269 mod 2) : a.occupied"
	);

	test(
		a.data[0] == 0x01,
		"bi_mod_n_pow_of_2_plus_1 (1026558507269 mod 2) : a.data[0]"
	);

	free(a.data);
}

// case mutable negative
void		test_bi_mod_n_pow_of_2_plus_1_case15(void)
{
	printf(KYEL "test_bi_mod_n_pow_of_2_plus_1_case15\n" KNRM);
	t_bigint	a;
	int			res;

	bi_new(&a, 1, BI_SIGN_NEGATIVE);
	bi_push(&a, 0x05);
	bi_push(&a, 0xb9);
	bi_push(&a, 0xa7);
	bi_push(&a, 0x03);
	bi_push(&a, 0xef);

	// A mod 2^16 + 1
	res = bi_mod_n_pow_of_2_plus_1(&a, 16, &a);

	test(
		res == BI_SUCCESS,
		"bi_mod_n_pow_of_2_plus_1 (1026558507269 mod 65537) : return value"
	);

	test(
		a.sign == BI_SIGN_POSITIVE,
		"bi_mod_n_pow_of_2_plus_1 (1026558507269 mod 65537) : a.sign"
	);

	test(
		a.occupied == 2,
		"bi_mod_n_pow_of_2_plus_1 (1026558507269 mod 65537) : a.occupied"
	);

	test(
		a.data[0] == 0xb4,
		"bi_mod_n_pow_of_2_plus_1 (1026558507269 mod 65537) : a.data[0]"
	);

	test(
		a.data[1] == 0x49,
		"bi_mod_n_pow_of_2_plus_1 (1026558507269 mod 65537) : a.data[1]"
	);

	free(a.data);
}

// case A's max bit < n
void		test_bi_mod_n_pow_of_2_plus_1_case16(void)
{
	printf(KYEL "test_bi_mod_n_pow_of_2_plus_1_case16\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_NEGATIVE);
	bi_push(&a, 0x0c);
	bi_push(&a, 0xf1);

	// A mod 2^100 + 1
	res = bi_mod_n_pow_of_2_plus_1(&a, 100, &b);

	test(
		res == BI_SUCCESS,
		"bi_mod_n_pow_of_2_plus_1 (0xf10c mod 2^100 + 1) : return value"
	);

	test(
		b.sign == BI_SIGN_POSITIVE,
		"bi_mod_n_pow_of_2_plus_1 (0xf10c mod 2^100 + 1) : b.sign"
	);

	test(
		b.occupied == 2,
		"bi_mod_n_pow_of_2_plus_1 (0xf10c mod 2^100 + 1) : b.occupied"
	);

	test(
		b.data[0] == 0x0c,
		"bi_mod_n_pow_of_2_plus_1 (0xf10c mod 2^100 + 1) : b.data[0]"
	);

	test(
		b.data[1] == 0xf1,
		"bi_mod_n_pow_of_2_plus_1 (0xf10c mod 2^100 + 1) : b.data[1]"
	);

	free(a.data);
	free(b.data);
}

// case A's max bit < n (negative A)
void		test_bi_mod_n_pow_of_2_plus_1_case17(void)
{
	printf(KYEL "test_bi_mod_n_pow_of_2_plus_1_case17\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	int				res;
	unsigned char	expected[13] = {
		0xf5, 0x0e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff,	0x0f
	};

	bi_new(&a, 1, BI_SIGN_NEGATIVE);
	bi_new(&b, 1, BI_SIGN_NEGATIVE);
	bi_push(&a, 0x0c);
	bi_push(&a, 0xf1);

	// A mod 2^100 + 1
	res = bi_mod_n_pow_of_2_plus_1(&a, 100, &b);

	test(
		res == BI_SUCCESS,
		"bi_mod_n_pow_of_2_plus_1 (-0xf10c mod 2^100 + 1) : return value"
	);

	test(
		b.sign == BI_SIGN_POSITIVE,
		"bi_mod_n_pow_of_2_plus_1 (-0xf10c mod 2^100 + 1) : b.sign"
	);

	test(
		b.occupied == 13,
		"bi_mod_n_pow_of_2_plus_1 (-0xf10c mod 2^100 + 1) : b.occupied"
	);

	for (int i=0; i < 13; i++)
		test(
			b.data[i] == expected[i],
			"bi_mod_n_pow_of_2_plus_1 (-0xf10c mod 2^100 + 1) : b.data[i]"
		);

	free(a.data);
	free(b.data);
}
