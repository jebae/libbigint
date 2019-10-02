#include "bigint.test.h"

void		test_bi_array_to_bi_case1(void)
{
	printf(KYEL "test_bi_array_to_bi_case1\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	*arr;
	size_t		size = 32;
	int			res;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x01);
	bi_push(&a, 0x02);
	bi_push(&a, 0x03);
	bi_push(&a, 0x04);
	bi_push(&a, 0x05);
	arr = bi_to_bi_array(&a, size);
	res = bi_array_to_bi(arr, size, &b);

	test(
		res == BI_SUCCESS,
		"bi_array_to_bi : return value"
	);

	test(
		b.sign == a.sign,
		"bi_array_to_bi : b.sign"
	);

	test(
		b.occupied == a.occupied,
		"bi_array_to_bi : b.occupied"
	);

	for (size_t i=0; i < a.occupied; i++)
		test(
			b.data[i] == a.data[i],
			"bi_array_to_bi : b.data[i]"
		);

	free(a.data);
	free(b.data);
	bi_del_bi_array(arr, size);
}

// case negative
void		test_bi_array_to_bi_case2(void)
{
	printf(KYEL "test_bi_array_to_bi_case2\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	t_bigint	*arr;
	size_t		size = 32;
	int			res;

	bi_new(&a, 1, BI_SIGN_NEGATIVE);
	bi_new(&b, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x01);
	bi_push(&a, 0x02);
	bi_push(&a, 0x03);
	bi_push(&a, 0x04);
	bi_push(&a, 0x05);
	arr = bi_to_bi_array(&a, size);
	res = bi_array_to_bi(arr, size, &b);

	test(
		res == BI_SUCCESS,
		"bi_array_to_bi : return value"
	);

	test(
		b.sign == a.sign,
		"bi_array_to_bi : b.sign"
	);

	test(
		b.occupied == a.occupied,
		"bi_array_to_bi : b.occupied"
	);

	for (size_t i=0; i < a.occupied; i++)
		test(
			b.data[i] == a.data[i],
			"bi_array_to_bi : b.data[i]"
		);

	free(a.data);
	free(b.data);
	bi_del_bi_array(arr, size);
}
