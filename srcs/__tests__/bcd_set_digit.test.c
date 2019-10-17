#include "bigint.test.h"

// case 54321
void		test_bcd_set_digit_case1(void)
{
	printf(KYEL "test_bcd_set_digit_case1\n" KNRM);
	t_bigint	bcd;

	bi_new(&bcd, 1, BI_SIGN_POSITIVE);
	bi_push(&bcd, 0x21);
	bi_push(&bcd, 0x43);
	bi_push(&bcd, 0x05);

	for (size_t i=0; i < 5; i++)
		bcd_set_digit(&bcd, i, i + 2);

	test(
		bcd.data[0] == 0x32,
		"bcd_set_digit : bcd.data[0]"
	);

	test(
		bcd.data[1] == 0x54,
		"bcd_set_digit : bcd.data[1]"
	);

	test(
		bcd.data[2] == 0x06,
		"bcd_set_digit : bcd.data[2]"
	);

	free(bcd.data);
}

// case 0
void		test_bcd_set_digit_case2(void)
{
	printf(KYEL "test_bcd_set_digit_case2\n" KNRM);
	t_bigint	bcd;

	bi_new(&bcd, 1, BI_SIGN_POSITIVE);

	bcd_set_digit(&bcd, 0, 9);
	bcd_set_digit(&bcd, 1, 9);

	test(
		bcd.data[0] == 0x99,
		"bcd_set_digit : bcd.data[0]"
	);

	free(bcd.data);
}

// case bigger than 9
void		test_bcd_set_digit_case3(void)
{
	printf(KYEL "test_bcd_set_digit_case3\n" KNRM);
	t_bigint	bcd;

	bi_new(&bcd, 1, BI_SIGN_POSITIVE);
	bi_push(&bcd, 0x21);

	bcd_set_digit(&bcd, 0, 10);
	bcd_set_digit(&bcd, 1, 11);

	test(
		bcd.data[0] == 0x21,
		"bcd_set_digit : bcd.data[0]"
	);

	free(bcd.data);
}

// case set 0 to first bits
void		test_bcd_set_digit_case4(void)
{
	printf(KYEL "test_bcd_set_digit_case4\n" KNRM);
	t_bigint	bcd;

	bi_new(&bcd, 5, BI_SIGN_POSITIVE);
	bi_push(&bcd, 0x21);
	bi_push(&bcd, 0x43);
	bi_push(&bcd, 0x05);

	bcd_set_digit(&bcd, 4, 0);

	test(
		bcd.occupied == 2,
		"bcd_set_digit : bcd.occupied"
	);

	test(
		bcd.data[2] == 0x00,
		"bcd_set_digit : bcd.data[2]"
	);

	free(bcd.data);
}
