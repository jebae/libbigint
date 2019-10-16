#include "bigint.test.h"

// case 12345
void		test_bcd_len_case1(void)
{
	printf(KYEL "test_bcd_len_case1\n" KNRM);
	t_bigint	bcd;
	size_t		expected = 5;

	bi_new(&bcd, 1, BI_SIGN_POSITIVE);
	bi_push(&bcd, 0x45);
	bi_push(&bcd, 0x23);
	bi_push(&bcd, 0x01);

	test(
		bcd_len(&bcd) == expected,
		"bcd_len : return value"
	);

	free(bcd.data);
}

// case 112345
void		test_bcd_len_case2(void)
{
	printf(KYEL "test_bcd_len_case2\n" KNRM);
	t_bigint	bcd;
	size_t		expected = 6;

	bi_new(&bcd, 1, BI_SIGN_POSITIVE);
	bi_push(&bcd, 0x45);
	bi_push(&bcd, 0x23);
	bi_push(&bcd, 0x11);

	test(
		bcd_len(&bcd) == expected,
		"bcd_len : return value"
	);

	free(bcd.data);
}

// case 10
void		test_bcd_len_case3(void)
{
	printf(KYEL "test_bcd_len_case3\n" KNRM);
	t_bigint	bcd;
	size_t		expected = 2;

	bi_new(&bcd, 1, BI_SIGN_POSITIVE);
	bi_push(&bcd, 0x10);

	test(
		bcd_len(&bcd) == expected,
		"bcd_len : return value"
	);

	free(bcd.data);
}

// case 8
void		test_bcd_len_case4(void)
{
	printf(KYEL "test_bcd_len_case4\n" KNRM);
	t_bigint	bcd;
	size_t		expected = 1;

	bi_new(&bcd, 1, BI_SIGN_POSITIVE);
	bi_push(&bcd, 0x08);

	test(
		bcd_len(&bcd) == expected,
		"bcd_len : return value"
	);

	free(bcd.data);
}

// case 123000000000
void		test_bcd_len_case5(void)
{
	printf(KYEL "test_bcd_len_case5\n" KNRM);
	t_bigint	bcd;
	size_t		expected = 12;

	bi_new(&bcd, 1, BI_SIGN_POSITIVE);
	bi_push(&bcd, 0x00);
	bi_push(&bcd, 0x00);
	bi_push(&bcd, 0x00);
	bi_push(&bcd, 0x00);
	bi_push(&bcd, 0x30);
	bi_push(&bcd, 0x12);

	test(
		bcd_len(&bcd) == expected,
		"bcd_len : return value"
	);

	free(bcd.data);
}

// case 0
void		test_bcd_len_case6(void)
{
	printf(KYEL "test_bcd_len_case6\n" KNRM);
	t_bigint	bcd;
	size_t		expected = 1;

	bi_new(&bcd, 1, BI_SIGN_POSITIVE);

	test(
		bcd_len(&bcd) == expected,
		"bcd_len : return value"
	);

	free(bcd.data);
}
