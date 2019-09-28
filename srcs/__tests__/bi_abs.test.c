#include "bigint.test.h"

void		test_bi_abs_case1(void)
{
	printf(KYEL "test_bi_abs_case1\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	int			res;

	bi_new(&a, 1, BI_SIGN_NEGATIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x04);
	bi_push(&a, 0x23);
	res = bi_abs(&a, &b);

	test(
		res == BI_SUCCESS,
		"bi_abs : return value"
	);

	test(
		b.size == a.size,
		"bi_abs : b.size"
	);

	test(
		b.occupied == a.occupied,
		"bi_abs : b.occupied"
	);

	test(
		b.sign == BI_SIGN_POSITIVE,
		"bi_abs : b.sign"
	);

	test(
		b.data[0] == a.data[0],
		"bi_abs : b.data[0]"
	);

	test(
		b.data[1] == a.data[1],
		"bi_abs : b.data[1]"
	);

	free(a.data);
	free(b.data);
}

// case mutable
void		test_bi_abs_case2(void)
{
	printf(KYEL "test_bi_abs_case2\n" KNRM);
	t_bigint	a;
	int			res;

	bi_new(&a, 1, BI_SIGN_NEGATIVE);
	bi_push(&a, 0x04);
	bi_push(&a, 0x23);
	res = bi_abs(&a, &a);

	test(
		res == BI_SUCCESS,
		"bi_abs : return value"
	);

	test(
		a.size == 2,
		"bi_abs : a.size"
	);

	test(
		a.occupied == 2,
		"bi_abs : a.occupied"
	);

	test(
		a.sign == BI_SIGN_POSITIVE,
		"bi_abs : a.sign"
	);

	test(
		a.data[0] == 0x04,
		"bi_abs : a.data[0]"
	);

	test(
		a.data[1] == 0x23,
		"bi_abs : a.data[1]"
	);

	free(a.data);
}
