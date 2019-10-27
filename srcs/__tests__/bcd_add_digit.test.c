#include "bigint.test.h"

// case add 1
void		test_bcd_add_digit_case1(void)
{
	printf(KYEL "test_bcd_add_digit_case1\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	int				res;
	unsigned char	expected[3] = {0x46, 0x23, 0x01};

	bi_init(&a);
	bi_init(&b);
	bi_push(&a, 0x45);
	bi_push(&a, 0x23);
	bi_push(&a, 0x01);

	res = bcd_add_digit(&a, 1, &b);

	test(
		res == BI_SUCCESS,
		"bcd_add_digit : return value"
	);

	test(
		b.occupied == 3,
		"bcd_add_digit : b.occupied"
	);

	for (size_t i=0; i < b.occupied; i++)
		test(
			b.data[i] == expected[i],
			"bcd_add_digit : b.data[i]"
		);

	bi_del(&a);
	bi_del(&b);
}

// case add 1 with carry
void		test_bcd_add_digit_case2(void)
{
	printf(KYEL "test_bcd_add_digit_case2\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	int				res;
	unsigned char	expected[4] = {0x00, 0x00, 0x00, 0x01};

	bi_init(&a);
	bi_init(&b);
	bi_push(&a, 0x99);
	bi_push(&a, 0x99);
	bi_push(&a, 0x99);

	res = bcd_add_digit(&a, 1, &b);

	test(
		res == BI_SUCCESS,
		"bcd_add_digit : return value"
	);

	test(
		b.occupied == 4,
		"bcd_add_digit : b.occupied"
	);

	for (size_t i=0; i < b.occupied; i++)
		test(
			b.data[i] == expected[i],
			"bcd_add_digit : b.data[i]"
		);

	bi_del(&a);
	bi_del(&b);
}

// case add 1 with carry
void		test_bcd_add_digit_case3(void)
{
	printf(KYEL "test_bcd_add_digit_case3\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	int				res;
	unsigned char	expected[3] = {0x00, 0x00, 0x10};

	bi_init(&a);
	bi_init(&b);
	bi_push(&a, 0x99);
	bi_push(&a, 0x99);
	bi_push(&a, 0x09);

	res = bcd_add_digit(&a, 1, &b);

	test(
		res == BI_SUCCESS,
		"bcd_add_digit : return value"
	);

	test(
		b.occupied == 3,
		"bcd_add_digit : b.occupied"
	);

	for (size_t i=0; i < b.occupied; i++)
		test(
			b.data[i] == expected[i],
			"bcd_add_digit : b.data[i]"
		);

	bi_del(&a);
	bi_del(&b);
}

// case add 0
void		test_bcd_add_digit_case4(void)
{
	printf(KYEL "test_bcd_add_digit_case4\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	int				res;
	unsigned char	expected[3] = {0x56, 0x34, 0x12};

	bi_init(&a);
	bi_init(&b);
	bi_push(&a, 0x56);
	bi_push(&a, 0x34);
	bi_push(&a, 0x12);

	res = bcd_add_digit(&a, 0, &b);

	test(
		res == BI_SUCCESS,
		"bcd_add_digit : return value"
	);

	test(
		b.occupied == 3,
		"bcd_add_digit : b.occupied"
	);

	for (size_t i=0; i < b.occupied; i++)
		test(
			b.data[i] == expected[i],
			"bcd_add_digit : b.data[i]"
		);

	bi_del(&a);
	bi_del(&b);
}

// case add 9
void		test_bcd_add_digit_case5(void)
{
	printf(KYEL "test_bcd_add_digit_case5\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	int				res;
	unsigned char	expected[3] = {0x65, 0x34, 0x12};

	bi_init(&a);
	bi_init(&b);
	bi_push(&a, 0x56);
	bi_push(&a, 0x34);
	bi_push(&a, 0x12);

	res = bcd_add_digit(&a, 9, &b);

	test(
		res == BI_SUCCESS,
		"bcd_add_digit : return value"
	);

	test(
		b.occupied == 3,
		"bcd_add_digit : b.occupied"
	);

	for (size_t i=0; i < b.occupied; i++)
		test(
			b.data[i] == expected[i],
			"bcd_add_digit : b.data[i]"
		);

	bi_del(&a);
	bi_del(&b);
}

// case add 9 with carry
void		test_bcd_add_digit_case6(void)
{
	printf(KYEL "test_bcd_add_digit_case6\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	int				res;
	unsigned char	expected[4] = {0x08, 0x00, 0x00, 0x01};

	bi_init(&a);
	bi_init(&b);
	bi_push(&a, 0x99);
	bi_push(&a, 0x99);
	bi_push(&a, 0x99);

	res = bcd_add_digit(&a, 9, &b);

	test(
		res == BI_SUCCESS,
		"bcd_add_digit : return value"
	);

	test(
		b.occupied == 4,
		"bcd_add_digit : b.occupied"
	);

	for (size_t i=0; i < b.occupied; i++)
		test(
			b.data[i] == expected[i],
			"bcd_add_digit : b.data[i]"
		);

	bi_del(&a);
	bi_del(&b);
}

// case add bigger than 9
void		test_bcd_add_digit_case7(void)
{
	printf(KYEL "test_bcd_add_digit_case7\n" KNRM);
	t_bigint		a;
	t_bigint		b;
	int				res;

	bi_init(&a);
	bi_init(&b);
	bi_push(&a, 0x45);
	bi_push(&a, 0x23);
	bi_push(&a, 0x01);

	res = bcd_add_digit(&a, 15, &b);

	test(
		res == BI_SUCCESS,
		"bcd_add_digit : return value"
	);

	test(
		b.data == NULL,
		"bcd_add_digit : b.data"
	);

	test(
		b.occupied == 0,
		"bcd_add_digit : b.occupied"
	);

	bi_del(&a);
	bi_del(&b);
}

// case mutable
void		test_bcd_add_digit_case8(void)
{
	printf(KYEL "test_bcd_add_digit_case8\n" KNRM);
	t_bigint		a;
	int				res;
	unsigned char	expected[3] = {0x46, 0x23, 0x01};

	bi_init(&a);
	bi_push(&a, 0x45);
	bi_push(&a, 0x23);
	bi_push(&a, 0x01);

	res = bcd_add_digit(&a, 1, &a);

	test(
		res == BI_SUCCESS,
		"bcd_add_digit : return value"
	);

	test(
		a.occupied == 3,
		"bcd_add_digit : a.occupied"
	);

	for (size_t i=0; i < a.occupied; i++)
		test(
			a.data[i] == expected[i],
			"bcd_add_digit : a.data[i]"
		);

	bi_del(&a);
}
