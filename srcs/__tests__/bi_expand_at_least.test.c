#include "bigint.test.h"

// case expand
void		test_bi_expand_at_least_case1(void)
{
	printf(KYEL "test_bi_expand_at_least_case1\n" KNRM);
	t_bigint	bi;
	int			res;

	bi_init(&bi);
	bi_push(&bi, 0xf9);
	bi_push(&bi, 0x1e);
	res = bi_expand_at_least(&bi, 16);

	test(
		res == BI_SUCCESS,
		"bi_expand_at_least : return value"
	);

	test(
		bi.size == 16,
		"bi_expand_at_least : bi.size"
	);

	test(
		bi.occupied == 2,
		"bi_expand_at_least : bi.occupied"
	);

	test(
		bi.data[0] == 0xf9,
		"bi_expand_at_least : bi.data[0]"
	);

	test(
		bi.data[1] == 0x1e,
		"bi_expand_at_least : bi.data[1]"
	);

	bi_del(&bi);
}

// case not expand really
void		test_bi_expand_at_least_case2(void)
{
	printf(KYEL "test_bi_expand_at_least_case2\n" KNRM);
	t_bigint	bi;
	size_t		size = 10;
	int			res;

	bi_init(&bi);
	bi_memalloc(&bi, size);
	bi_push(&bi, 0xf9);
	bi_push(&bi, 0x1e);
	res = bi_expand_at_least(&bi, 8);

	test(
		res == BI_SUCCESS,
		"bi_expand_at_least : return value"
	);

	test(
		bi.size == 10,
		"bi_expand_at_least : bi.size"
	);

	test(
		bi.occupied == 2,
		"bi_expand_at_least : bi.occupied"
	);

	test(
		bi.data[0] == 0xf9,
		"bi_expand_at_least : bi.data[0]"
	);

	test(
		bi.data[1] == 0x1e,
		"bi_expand_at_least : bi.data[1]"
	);

	bi_del(&bi);
}
