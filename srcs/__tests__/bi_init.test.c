#include "bigint.test.h"

void		test_bi_init_case1(void)
{
	t_bigint	bi;
	size_t		size = 5;

	bi = bi_new(size);
	bi.data[0] = 0xFF;
	bi_init(&bi);

	for (size_t i=0; i < size; i++)
		test(
			bi.data[i] == 0x00,
			"bi_init : bi.data[i]"
		);
	free(bi.data);
}
