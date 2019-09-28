#include "bigint.test.h"

void		test_bi_max_bit_case1(void)
{
	printf(KYEL "test_bi_max_bit_case1\n" KNRM);
	t_bigint	a;
	size_t		res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x04);
	res = bi_max_bit(&a);

	test(
		res == 3,
		"bi_max_bit (0x04) : return value"
	);

	free(a.data);
}

void		test_bi_max_bit_case2(void)
{
	printf(KYEL "test_bi_max_bit_case2\n" KNRM);
	t_bigint	a;
	size_t		res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x04);
	bi_push(&a, 0x10);
	res = bi_max_bit(&a);

	test(
		res == 13,
		"bi_max_bit (0x1004) : return value"
	);

	free(a.data);
}

// case 0
void		test_bi_max_bit_case3(void)
{
	printf(KYEL "test_bi_max_bit_case3\n" KNRM);
	t_bigint	a;
	size_t		res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	res = bi_max_bit(&a);

	test(
		res == 1,
		"bi_max_bit (0x00) : return value"
	);

	free(a.data);
}
