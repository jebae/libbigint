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

// case mutable
void		test_bi_copy_case2(void)
{
	printf(KYEL "test_bi_copy_case2\n" KNRM);
	t_bigint	a;
	int			res;

	bi_new(&a, 3, BI_SIGN_NEGATIVE);
	bi_push(&a, 0x11);
	bi_push(&a, 0x0e);
	res = bi_copy(&a, &a);

	test(
		res == BI_SUCCESS,
		"bi_copy : return value"
	);

	test(
		a.occupied == 2,
		"bi_copy : a.occupied"
	);

	test(
		a.sign == BI_SIGN_NEGATIVE,
		"bi_copy : a.sign"
	);

	test(
		a.data[0] == 0x11,
		"bi_copy : a.data[0]"
	);

	test(
		a.data[1] == 0x0e,
		"bi_copy : a.data[1]"
	);

	free(a.data);
}
