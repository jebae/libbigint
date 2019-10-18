#include "bigint.test.h"

// case size = 8
void		test_bi_strassen_mul_shuffle_order_case1(void)
{
	printf(KYEL "test_bi_strassen_mul_shuffle_order_case1\n" KNRM);
	t_bigint	bi;
	t_bigint	*arr;
	int			res;
	size_t		size = 8;
	size_t		expected[8] = {0, 4, 2, 6, 1, 5, 3, 7};

	bi_init(&bi);
	for (size_t i=0; i < size; i++)
		bi_push(&bi, i);
	arr = bi_to_bi_array(&bi, size);
	res = bi_strassen_mul_shuffle_order(arr, size);

	test(
		res == BI_SUCCESS,
		"bi_strassen_mul_shuffle_order (size = 8) : return value"
	);

	for (size_t i=0; i < size; i++)
	{
		if (expected[i] == 0)
			test(
				arr[i].occupied == 0,
				"bi_strassen_mul_shuffle_order (size = 8) : arr[i].occupied"
			);
		else
			test(
				arr[i].data[0] == expected[i],
				"bi_strassen_mul_shuffle_order (size = 8) : arr[i].data"
			);
	}

	bi_del(&bi);
	bi_del_bi_array(arr, size);
}

// case size = 16
void		test_bi_strassen_mul_shuffle_order_case2(void)
{
	printf(KYEL "test_bi_strassen_mul_shuffle_order_case2\n" KNRM);
	t_bigint	bi;
	t_bigint	*arr;
	int			res;
	size_t		size = 16;
	size_t		expected[16] = {
		0, 8, 4, 12, 2, 10, 6, 14,
		1, 9, 5, 13, 3, 11, 7, 15
	};

	bi_init(&bi);
	for (size_t i=0; i < size; i++)
		bi_push(&bi, i);
	arr = bi_to_bi_array(&bi, size);
	res = bi_strassen_mul_shuffle_order(arr, size);

	test(
		res == BI_SUCCESS,
		"bi_strassen_mul_shuffle_order (size = 16) : return value"
	);

	for (size_t i=0; i < size; i++)
	{
		if (expected[i] == 0)
			test(
				arr[i].occupied == 0,
				"bi_strassen_mul_shuffle_order (size = 16) : arr[i].occupied"
			);
		else
			test(
				arr[i].data[0] == expected[i],
				"bi_strassen_mul_shuffle_order (size = 16) : arr[i].data"
			);
	}

	bi_del(&bi);
	bi_del_bi_array(arr, size);
}

// case size = 32
void		test_bi_strassen_mul_shuffle_order_case3(void)
{
	printf(KYEL "test_bi_strassen_mul_shuffle_order_case3\n" KNRM);
	t_bigint	bi;
	t_bigint	*arr;
	int			res;
	size_t		size = 32;
	size_t		expected[32] = {
		0, 16, 8, 24, 4, 20, 12, 28,
		2, 18, 10, 26, 6, 22, 14, 30,
		1, 17, 9, 25, 5, 21, 13, 29,
		3, 19, 11, 27, 7, 23, 15, 31
	};

	bi_init(&bi);
	for (size_t i=0; i < size; i++)
		bi_push(&bi, i);
	arr = bi_to_bi_array(&bi, size);
	res = bi_strassen_mul_shuffle_order(arr, size);

	test(
		res == BI_SUCCESS,
		"bi_strassen_mul_shuffle_order (size = 32) : return value"
	);

	for (size_t i=0; i < size; i++)
	{
		if (expected[i] == 0)
			test(
				arr[i].occupied == 0,
				"bi_strassen_mul_shuffle_order (size = 32) : arr[i].occupied"
			);
		else
			test(
				arr[i].data[0] == expected[i],
				"bi_strassen_mul_shuffle_order (size = 32) : arr[i].data"
			);
	}

	bi_del(&bi);
	bi_del_bi_array(arr, size);
}
