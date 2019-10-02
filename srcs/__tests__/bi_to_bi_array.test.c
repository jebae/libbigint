#include "bigint.test.h"

// case bi.occupied < size
void		test_bi_to_bi_array_case1(void)
{
	printf(KYEL "test_bi_to_bi_array_case1\n" KNRM);
	t_bigint	a;
	t_bigint	*arr;
	size_t		size = 32;
	size_t		i = 0;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x01);
	bi_push(&a, 0x02);
	bi_push(&a, 0x03);
	bi_push(&a, 0x04);
	bi_push(&a, 0x05);
	arr = bi_to_bi_array(&a, 32);

	for (i=0; i < a.occupied; i++)
		test(
			arr[i].data[0] == a.data[i],
			"bi_to_bi_array : arr[i].data"
		);
	for (; i < size; i++)
		test(
			arr[i].occupied == 0,
			"bi_to_bi_array : arr[i] zero pad"
		);

	free(a.data);
	bi_del_bi_array(arr, size);
}

// case bi.occupied > size
void		test_bi_to_bi_array_case2(void)
{
	printf(KYEL "test_bi_to_bi_array_case2\n" KNRM);
	t_bigint	a;
	t_bigint	*arr;
	size_t		size = 3;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x01);
	bi_push(&a, 0x02);
	bi_push(&a, 0x03);
	bi_push(&a, 0x04);
	bi_push(&a, 0x05);
	arr = bi_to_bi_array(&a, size);

	for (size_t i=0; i < size; i++)
		test(
			arr[i].data[0] = a.data[i],
			"bi_to_bi_array : arr[i].data"
		);

	free(a.data);
	bi_del_bi_array(arr, size);
}

// case size = 0
void		test_bi_to_bi_array_case3(void)
{
	printf(KYEL "test_bi_to_bi_array_case3\n" KNRM);
	t_bigint	a;
	t_bigint	*arr;

	bi_new(&a, 1, BI_SIGN_POSITIVE);
	bi_push(&a, 0x01);
	bi_push(&a, 0x02);
	bi_push(&a, 0x03);
	bi_push(&a, 0x04);
	bi_push(&a, 0x05);
	arr = bi_to_bi_array(&a, 0);

	test(
		arr == NULL,
		"bi_to_bi_array : arr"
	);

	free(a.data);
}

// case negative
void		test_bi_to_bi_array_case4(void)
{
	printf(KYEL "test_bi_to_bi_array_case4\n" KNRM);
	t_bigint	a;
	t_bigint	*arr;
	size_t		size = 32;
	size_t		i = 0;

	bi_new(&a, 1, BI_SIGN_NEGATIVE);
	bi_push(&a, 0x01);
	bi_push(&a, 0x02);
	bi_push(&a, 0x03);
	bi_push(&a, 0x04);
	bi_push(&a, 0x05);
	arr = bi_to_bi_array(&a, 32);

	for (i=0; i < a.occupied; i++)
	{
		test(
			arr[i].data[0] == a.data[i],
			"bi_to_bi_array : arr[i].data"
		);

		test(
			arr[i].sign == a.sign,
			"bi_to_bi_array : arr[i].data"
		);
	}
	for (; i < size; i++)
		test(
			arr[i].occupied == 0,
			"bi_to_bi_array : arr[i] zero pad"
		);

	free(a.data);
	bi_del_bi_array(arr, size);
}
