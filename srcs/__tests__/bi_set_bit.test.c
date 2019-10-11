#include "bigint.test.h"

void		test_bi_set_bit_case1(void)
{
	printf(KYEL "test_bi_set_bit_case1\n" KNRM);
	t_bigint	bi;

	bi_new(&bi, 1, BI_SIGN_POSITIVE);

	bi_push(&bi, 0xff);
	bi_push(&bi, 0xfe);

    bi_set_bit(&bi, 0, 0);
	bi_set_bit(&bi, 1, 0);
    bi_set_bit(&bi, 8, 1);
    bi_set_bit(&bi, 14, 0);

	test(
		bi.data[0] == 0xfc,
		"bi_set_bit : bi.data[0]"
	);

    test(
		bi.data[1] == 0xbf,
		"bi_set_bit : bi.data[1]"
	);

	free(bi.data);
}

// case invalid bit
void		test_bi_set_bit_case2(void)
{
	printf(KYEL "test_bi_set_bit_case2\n" KNRM);
	t_bigint	bi;

	bi_new(&bi, 1, BI_SIGN_POSITIVE);

	bi_push(&bi, 0xff);
	bi_push(&bi, 0xfe);

    bi_set_bit(&bi, 16, 0);

	test(
		bi.data[0] == 0xff,
		"bi_set_bit : bi.data[0]"
	);

    test(
		bi.data[1] == 0xfe,
		"bi_set_bit : bi.data[1]"
	);

	free(bi.data);
}

// case invalid value
void		test_bi_set_bit_case3(void)
{
	printf(KYEL "test_bi_set_bit_case3\n" KNRM);
	t_bigint	bi;

	bi_new(&bi, 1, BI_SIGN_POSITIVE);

	bi_push(&bi, 0xff);
	bi_push(&bi, 0xfe);

    bi_set_bit(&bi, 0, -1);

	test(
		bi.data[0] == 0xff,
		"bi_set_bit : bi.data[0]"
	);

    test(
		bi.data[1] == 0xfe,
		"bi_set_bit : bi.data[1]"
	);

	free(bi.data);
}