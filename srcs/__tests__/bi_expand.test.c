#include "bigint.test.h"

void		test_bi_expand_case1(void)
{
	printf(KYEL "test_bi_expand_case1\n" KNRM);
	t_bigint	bi;
	int			res;

	bi_init(&bi);
	bi_push(&bi, 0xff);
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
		bi.data[0] == 0xff,
		"bi_expand : bi.data[0]"
	);
	for (size_t i=1; i < 16; i++)
		test(
			bi.data[i] == 0x00,
			"bi_expand : bi.data[i]"
		);

	bi_del(&bi);
}
