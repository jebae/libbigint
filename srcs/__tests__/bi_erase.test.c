#include "bigint.test.h"

void		test_bi_erase_case1(void)
{
	printf(KYEL "test_bi_erase_case1\n" KNRM);
	t_bigint	bi;

	bi_init(&bi);
	bi_push(&bi, 0xff);
	bi_push(&bi, 0xff);
	bi_push(&bi, 0xff);
	bi_erase(&bi);

	test(
		bi.occupied == 0,
		"bi_erase : bi.occupied"
	);
	for (size_t i=0; i < 3; i++)
		test(
			bi.data[i] == 0x00,
			"bi_erase : bi.data[i]"
		);

	bi_del(&bi);
}
