#include "bigint.test.h"

// need leak test
void		test_bi_expand_case1(void)
{
	printf(KYEL "test_bi_expand_case1\n" KNRM);
	t_bigint	bi;
	size_t		size = 1;
	int			res;

	bi_new(&bi, size, BI_SIGN_POSITIVE);
	bi.data[0] = 0xFF;
	res = bi_expand(&bi, 15);

	test(
		res == BI_SUCCESS,
		"bi_expand : return value"
	);

	test(
		bi.size == 16,
		"bi_expand : bi.size"
	);

	test(
		bi.data[0] == 0xFF,
		"bi_expand : bi.data[0]"
	);
	for (size_t i=1; i < 16; i++)
		test(
			bi.data[i] == 0x00,
			"bi_expand : bi.data[i]"
		);
	free(bi.data);
}
