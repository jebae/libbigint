#include "bigint.test.h"

void		test_bi_erase_case1(void)
{
	t_bigint	bi;
	size_t		size = 5;

	bi_new(&bi, size, BI_SIGN_POSITIVE);
	bi.data[0] = 0xFF;
	bi.occupied = 2;
	bi_erase(&bi);

	test(
		bi.occupied == 0,
		"bi_init : bi.occupied"
	);
	for (size_t i=0; i < size; i++)
		test(
			bi.data[i] == 0x00,
			"bi_init : bi.data[i]"
		);
	free(bi.data);
}
