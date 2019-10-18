#include "bigint.test.h"

// case 54321
void		test_bcd_get_digit_case1(void)
{
	printf(KYEL "test_bcd_get_digit_case1\n" KNRM);
	t_bigint	bcd;

	bi_init(&bcd);
	bi_push(&bcd, 0x21);
	bi_push(&bcd, 0x43);
	bi_push(&bcd, 0x05);

	for (size_t i=0; i < 5; i++)
		test(
			bcd_get_digit(&bcd, i) == (unsigned char)(i + 1),
			"bcd_get_digit : return value"
		);

	test(
		bcd_get_digit(&bcd, 5) == 0,
		"bcd_get_digit : return value bigger than occupied"
	);

	test(
		bcd_get_digit(&bcd, 6) == 0,
		"bcd_get_digit : return value bigger than occupied"
	);

	bi_del(&bcd);
}

// case 0
void		test_bcd_get_digit_case2(void)
{
	printf(KYEL "test_bcd_get_digit_case2\n" KNRM);
	t_bigint	bcd;

	bi_init(&bcd);

	test(
		bcd_get_digit(&bcd, 0) == 0,
		"bcd_get_digit : return value"
	);

	test(
		bcd_get_digit(&bcd, 1) == 0,
		"bcd_get_digit : return value"
	);

	bi_del(&bcd);
}
