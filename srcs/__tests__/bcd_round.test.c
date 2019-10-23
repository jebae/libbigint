#include "bigint.test.h"

// case ceil
void		test_bcd_round_case1(void)
{
	printf(KYEL "test_bcd_round_case1\n" KNRM);
	t_bigint		bcd;
	t_bigint		rounded;
	unsigned char	expected[3] = { 0x50, 0x23, 0x01 };
	int				res;

	bi_init(&bcd);
	bi_init(&rounded);
	bi_push(&bcd, 0x45);
	bi_push(&bcd, 0x23);
	bi_push(&bcd, 0x01);

	res = bcd_round(&bcd, 1, &rounded);

	test(
		res == BI_SUCCESS,
		"bcd_round : return value"
	);

	test(
		rounded.occupied == 3,
		"bcd_round : rounded.occupied"
	);

	for (size_t i=0; i < rounded.occupied; i++)
		test(
			rounded.data[i] == expected[i],
			"bcd_round : rounded.data[i]"
		);

	bi_del(&bcd);
	bi_del(&rounded);
}

// case ceil
void		test_bcd_round_case2(void)
{
	printf(KYEL "test_bcd_round_case2\n" KNRM);
	t_bigint		bcd;
	t_bigint		rounded;
	unsigned char	expected[7] = { 0x00, 0x00, 0x00, 0x80, 0x23, 0x11, 0x70 };
	int				res;

	bi_init(&bcd);
	bi_init(&rounded);
	bi_push(&bcd, 0x98);
	bi_push(&bcd, 0x99);
	bi_push(&bcd, 0x99);
	bi_push(&bcd, 0x79);
	bi_push(&bcd, 0x23);
	bi_push(&bcd, 0x11);
	bi_push(&bcd, 0x70);

	res = bcd_round(&bcd, 4, &rounded);

	test(
		res == BI_SUCCESS,
		"bcd_round : return value"
	);

	test(
		rounded.occupied == 7,
		"bcd_round : rounded.occupied"
	);

	for (size_t i=0; i < rounded.occupied; i++)
		test(
			rounded.data[i] == expected[i],
			"bcd_round : rounded.data[i]"
		);

	bi_del(&bcd);
	bi_del(&rounded);
}

// case ceil (carry 1)
void		test_bcd_round_case3(void)
{
	printf(KYEL "test_bcd_round_case3\n" KNRM);
	t_bigint		bcd;
	t_bigint		rounded;
	unsigned char	expected[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 };
	int				res;

	bi_init(&bcd);
	bi_init(&rounded);
	bi_push(&bcd, 0x98);
	bi_push(&bcd, 0x99);
	bi_push(&bcd, 0x99);
	bi_push(&bcd, 0x99);
	bi_push(&bcd, 0x99);
	bi_push(&bcd, 0x99);
	bi_push(&bcd, 0x99);

	res = bcd_round(&bcd, 8, &rounded);

	test(
		res == BI_SUCCESS,
		"bcd_round : return value"
	);

	test(
		rounded.occupied == 8,
		"bcd_round : rounded.occupied"
	);

	for (size_t i=0; i < rounded.occupied; i++)
		test(
			rounded.data[i] == expected[i],
			"bcd_round : rounded.data[i]"
		);

	bi_del(&bcd);
	bi_del(&rounded);
}

// case floor
void		test_bcd_round_case4(void)
{
	printf(KYEL "test_bcd_round_case4\n" KNRM);
	t_bigint		bcd;
	t_bigint		rounded;
	unsigned char	expected[7] = { 0x00, 0x00, 0x00, 0x95, 0x99, 0x99, 0x99 };
	int				res;

	bi_init(&bcd);
	bi_init(&rounded);
	bi_push(&bcd, 0x98);
	bi_push(&bcd, 0x99);
	bi_push(&bcd, 0x29);
	bi_push(&bcd, 0x95);
	bi_push(&bcd, 0x99);
	bi_push(&bcd, 0x99);
	bi_push(&bcd, 0x99);

	res = bcd_round(&bcd, 6, &rounded);

	test(
		res == BI_SUCCESS,
		"bcd_round : return value"
	);

	test(
		rounded.occupied == 7,
		"bcd_round : rounded.occupied"
	);

	for (size_t i=0; i < rounded.occupied; i++)
		test(
			rounded.data[i] == expected[i],
			"bcd_round : rounded.data[i]"
		);

	bi_del(&bcd);
	bi_del(&rounded);
}

// case pos = 0
void		test_bcd_round_case5(void)
{
	printf(KYEL "test_bcd_round_case5\n" KNRM);
	t_bigint		bcd;
	t_bigint		rounded;
	unsigned char	expected[3] = { 0x45, 0x23, 0x01 };
	int				res;

	bi_init(&bcd);
	bi_init(&rounded);
	bi_push(&bcd, 0x45);
	bi_push(&bcd, 0x23);
	bi_push(&bcd, 0x01);

	res = bcd_round(&bcd, 0, &rounded);

	test(
		res == BI_SUCCESS,
		"bcd_round : return value"
	);

	test(
		rounded.occupied == 3,
		"bcd_round : rounded.occupied"
	);

	for (size_t i=0; i < rounded.occupied; i++)
		test(
			rounded.data[i] == expected[i],
			"bcd_round : rounded.data[i]"
		);

	bi_del(&bcd);
	bi_del(&rounded);
}

// case bcd = 0
void		test_bcd_round_case6(void)
{
	printf(KYEL "test_bcd_round_case6\n" KNRM);
	t_bigint		bcd;
	t_bigint		rounded;
	int				res;

	bi_init(&bcd);
	bi_init(&rounded);

	res = bcd_round(&bcd, 3, &rounded);

	test(
		res == BI_SUCCESS,
		"bcd_round : return value"
	);

	test(
		rounded.occupied == 0,
		"bcd_round : rounded.occupied"
	);

	bi_del(&bcd);
	bi_del(&rounded);
}
// case mutable
void		test_bcd_round_case7(void)
{
	printf(KYEL "test_bcd_round_case7\n" KNRM);
	t_bigint		bcd;
	unsigned char	expected[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 };
	int				res;

	bi_init(&bcd);
	bi_push(&bcd, 0x98);
	bi_push(&bcd, 0x99);
	bi_push(&bcd, 0x99);
	bi_push(&bcd, 0x99);
	bi_push(&bcd, 0x99);
	bi_push(&bcd, 0x99);
	bi_push(&bcd, 0x99);

	res = bcd_round(&bcd, 8, &bcd);

	test(
		res == BI_SUCCESS,
		"bcd_round : return value"
	);

	test(
		bcd.occupied == 8,
		"bcd_round : bcd.occupied"
	);

	for (size_t i=0; i < bcd.occupied; i++)
		test(
			bcd.data[i] == expected[i],
			"bcd_round : bcd.data[i]"
		);

	bi_del(&bcd);
}
