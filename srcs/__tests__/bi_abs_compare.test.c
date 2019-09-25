#include "bigint.test.h"

void		test_bi_abs_compare_case1(void)
{
	t_bigint	a;
	t_bigint	b;
	t_bigint	*bigger;
	t_bigint	*smaller;
	size_t		size = 2;

	bi_new(&a, size, BI_SIGN_POSITIVE);
	bi_new(&b, size, BI_SIGN_POSITIVE);

	// a = 0xfeff, b = 0xff90 -> a < b
	bi_push(&a, 0xff);
	bi_push(&a, 0xfe);
	bi_push(&b, 0x90);
	bi_push(&b, 0xff);

	bi_abs_compare(&a, &b, &bigger, &smaller);

	test(
		bigger == &b,
		"bi_abs_compare (0xfeff < 0xff90) : bigger"
	);

	test(
		smaller == &a,
		"bi_abs_compare (0xfeff < 0xff90) : smaller"
	);

	free(a.data);
	free(b.data);
}

void		test_bi_abs_compare_case2(void)
{
	t_bigint	a;
	t_bigint	b;
	t_bigint	*bigger;
	t_bigint	*smaller;
	size_t		size = 2;

	bi_new(&a, size, BI_SIGN_POSITIVE);
	bi_new(&b, size, BI_SIGN_NEGATIVE);

	// a = 0xfeff, b = 0xff90 -> a < b
	bi_push(&a, 0xff);
	bi_push(&a, 0xfe);
	bi_push(&b, 0x90);
	bi_push(&b, 0xff);

	bi_abs_compare(&a, &b, &bigger, &smaller);

	test(
		bigger == &b,
		"bi_abs_compare (0xfeff < 0xff90) : bigger"
	);

	test(
		smaller == &a,
		"bi_abs_compare (0xfeff < 0xff90) : smaller"
	);

	free(a.data);
	free(b.data);
}

void		test_bi_abs_compare_case3(void)
{
	t_bigint	a;
	t_bigint	b;
	t_bigint	*bigger;
	t_bigint	*smaller;
	size_t		size = 2;

	bi_new(&a, size, BI_SIGN_POSITIVE);
	bi_new(&b, size, BI_SIGN_NEGATIVE);

	// a = 0xfeff, b = 0xff -> a > b
	bi_push(&a, 0xff);
	bi_push(&a, 0xfe);
	bi_push(&b, 0xff);

	bi_abs_compare(&a, &b, &bigger, &smaller);

	test(
		bigger == &a,
		"bi_abs_compare (0xfeff > 0xff) : bigger"
	);

	test(
		smaller == &b,
		"bi_abs_compare (0xfeff > 0xff) : smaller"
	);

	free(a.data);
	free(b.data);
}

void		test_bi_abs_compare_case4(void)
{
	t_bigint	a;
	t_bigint	b;
	t_bigint	*bigger;
	t_bigint	*smaller;
	size_t		size = 2;

	bi_new(&a, size, BI_SIGN_POSITIVE);
	bi_new(&b, size, BI_SIGN_NEGATIVE);

	// a = 0xffff, b = 0xffff -> a == b
	bi_push(&a, 0xff);
	bi_push(&a, 0xff);
	bi_push(&b, 0xff);
	bi_push(&b, 0xff);

	bi_abs_compare(&a, &b, &bigger, &smaller);

	test(
		bigger == &a,
		"bi_abs_compare (0xffff == 0xffff) : bigger"
	);

	test(
		smaller == &b,
		"bi_abs_compare (0xffff == 0xffff) : smaller"
	);

	free(a.data);
	free(b.data);
}
