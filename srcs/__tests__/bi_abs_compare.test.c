#include "bigint.test.h"

void		test_bi_abs_compare_case1(void)
{
	printf(KYEL "test_bi_abs_compare_case1\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	*bigger;
	t_bigint	*smaller;

	bi_init(&a);
	bi_init(&b);

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

	bi_del(&a);
	bi_del(&b);
}

void		test_bi_abs_compare_case2(void)
{
	printf(KYEL "test_bi_abs_compare_case2\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	*bigger;
	t_bigint	*smaller;

	bi_init(&a);
	bi_init(&b);

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

	bi_del(&a);
	bi_del(&b);
}

void		test_bi_abs_compare_case3(void)
{
	printf(KYEL "test_bi_abs_compare_case3\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	*bigger;
	t_bigint	*smaller;

	bi_init(&a);
	bi_init(&b);

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

	bi_del(&a);
	bi_del(&b);
}

// case 0, 0
void		test_bi_abs_compare_case4(void)
{
	printf(KYEL "test_bi_abs_compare_case4\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	*bigger;
	t_bigint	*smaller;

	bi_init(&a);
	bi_init(&b);

	bi_abs_compare(&a, &b, &bigger, &smaller);

	test(
		bigger == &a,
		"bi_abs_compare (0x00 == 0x00) : bigger"
	);

	test(
		smaller == &b,
		"bi_abs_compare (0x00 == 0x00) : smaller"
	);

	bi_del(&a);
	bi_del(&b);
}

void		test_bi_abs_compare_case5(void)
{
	printf(KYEL "test_bi_abs_compare_case5\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	*bigger;
	t_bigint	*smaller;

	bi_init(&a);
	bi_init(&b);

	// a = 0x0f75, b = 0x03a4 -> a > b
	bi_push(&a, 0x75);
	bi_push(&a, 0x0f);
	bi_push(&b, 0xa4);
	bi_push(&b, 0x03);

	bi_abs_compare(&a, &b, &bigger, &smaller);

	test(
		bigger == &a,
		"bi_abs_compare (0x0f75 > 0x03a4) : bigger"
	);

	test(
		smaller == &b,
		"bi_abs_compare (0x0f75 > 0x03a4) : smaller"
	);

	bi_del(&a);
	bi_del(&b);
}
