#include "bigint.test.h"

// case 120
void		test_bcd_rm_trailing_zero_case1(void)
{
	printf(KYEL "test_bcd_rm_trailing_zero_case1\n" KNRM);
	t_bigint	bcd;

	bi_init(&bcd);
	bi_push(&bcd, 0x20);
	bi_push(&bcd, 0x01);

	test(
		bcd_rm_trailing_zero(&bcd) == 1,
		"bcd_rm_trailing_zero : return value"
	);

	test(
		bcd.occupied == 1,
		"bcd_rm_trailing_zero : bcd.occupied"
	);

	test(
		bcd.data[0] == 0x12,
		"bcd_rm_trailing_zero : bcd.data[0]"
	);

	bi_del(&bcd);
}

// case 1200000
void		test_bcd_rm_trailing_zero_case2(void)
{
	printf(KYEL "test_bcd_rm_trailing_zero_case2\n" KNRM);
	t_bigint	bcd;

	bi_init(&bcd);
	bi_push(&bcd, 0x00);
	bi_push(&bcd, 0x00);
	bi_push(&bcd, 0x20);
	bi_push(&bcd, 0x01);

	test(
		bcd_rm_trailing_zero(&bcd) == 5,
		"bcd_rm_trailing_zero : return value"
	);

	test(
		bcd.occupied == 1,
		"bcd_rm_trailing_zero : bcd.occupied"
	);

	test(
		bcd.data[0] == 0x12,
		"bcd_rm_trailing_zero : bcd.data[0]"
	);

	bi_del(&bcd);
}

// case 1000002
void		test_bcd_rm_trailing_zero_case3(void)
{
	printf(KYEL "test_bcd_rm_trailing_zero_case3\n" KNRM);
	t_bigint	bcd;

	bi_init(&bcd);
	bi_push(&bcd, 0x02);
	bi_push(&bcd, 0x00);
	bi_push(&bcd, 0x00);
	bi_push(&bcd, 0x01);

	test(
		bcd_rm_trailing_zero(&bcd) == 0,
		"bcd_rm_trailing_zero : return value"
	);

	test(
		bcd.occupied == 4,
		"bcd_rm_trailing_zero : bcd.occupied"
	);

	test(
		bcd.data[0] == 0x02,
		"bcd_rm_trailing_zero : bcd.data[0]"
	);

	test(
		bcd.data[1] == 0x00,
		"bcd_rm_trailing_zero : bcd.data[1]"
	);
	test(
		bcd.data[2] == 0x00,
		"bcd_rm_trailing_zero : bcd.data[2]"
	);
	test(
		bcd.data[3] == 0x01,
		"bcd_rm_trailing_zero : bcd.data[3]"
	);

	bi_del(&bcd);
}
