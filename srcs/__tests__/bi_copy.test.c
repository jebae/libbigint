#include "bigint.test.h"

void		test_bi_copy_case1(void)
{
	printf(KYEL "test_bi_copy_case1\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 3, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_NEGATIVE);
	bi_push(&a, 0x11);
	bi_push(&a, 0x0e);
	res = bi_copy(&b, &a);

	test(
		res == BI_SUCCESS,
		"bi_copy : return value"
	);

	test(
		b.occupied == a.occupied,
		"bi_copy : b.occupied"
	);

	test(
		b.sign == a.sign,
		"bi_copy : b.sign"
	);

	for (size_t i=0; i < a.occupied; i++)
		test(
			b.data[i] == a.data[i],
			"bi_copy : b.data[i]"
		);

	free(a.data);
	free(b.data);
}
