#include "bigint.test.h"

void		test_bi_get_bit_case1(void)
{
	printf(KYEL "test_bi_get_bit_case1\n" KNRM);
	t_bigint	bi;
	int			expected[16] = {
		-1, -1, -1, -1, 1, 1, 1, 0,
		0, 0, 0, 1, 0, 0, 0, 1
	};

	bi_new(&bi, 3, BI_SIGN_POSITIVE);
	bi_push(&bi, 0x11);
	bi_push(&bi, 0x0e);

	for (size_t i=bi.occupied * 8; i > 0; i--)
		test(
			bi_get_bit(&bi, i - 1) == expected[16 - i],
			"bi_get_bit : bi_get_bit()"
		);

	free(bi.data);
}

void		test_bi_get_bit_case2(void)
{
	printf(KYEL "test_bi_get_bit_case2\n" KNRM);
	t_bigint	bi;
	int			expected[24] = {
		1, 0, 0, 0, 1, 1, 0, 0,
		0, 0, 0, 0, 1, 1, 1, 0,
		0, 0, 0, 1, 0, 0, 0, 0
	};

	bi_new(&bi, 3, BI_SIGN_POSITIVE);
	bi_push(&bi, 0x10);
	bi_push(&bi, 0x0e);
	bi_push(&bi, 0x8c);

	for (size_t i=bi.occupied * 8; i > 0; i--)
		test(
			bi_get_bit(&bi, i - 1) == expected[24 - i],
			"bi_get_bit : bi_get_bit()"
		);

	free(bi.data);
}

// case n >= max bit
void		test_bi_get_bit_case3(void)
{
	printf(KYEL "test_bi_get_bit_case3\n" KNRM);
	t_bigint	bi;

	bi_new(&bi, 3, BI_SIGN_POSITIVE);
	bi_push(&bi, 0x11);

	test(
		bi_get_bit(&bi, 5) == -1,
		"bi_get_bit : bi_get_bit()"
	);

	test(
		bi_get_bit(&bi, 6) == -1,
		"bi_get_bit : bi_get_bit()"
	);

	test(
		bi_get_bit(&bi, 7) == -1,
		"bi_get_bit : bi_get_bit()"
	);

	free(bi.data);
}
