#include "bigint.test.h"

// case a's max bit + b's max bit <= length * 8 
void		test_bi_strassen_mul_get_block_length_case1(void)
{
	printf(KYEL "test_bi_strassen_mul_get_block_length_case1\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	size_t		length;

	bi_init(&a);
	bi_init(&b);
	bi_push(&a, 0xff);
	bi_push(&b, 0xff);
	length = bi_strassen_mul_get_block_length(&a, &b);

	test(
		length == 32,
		"bi_strassen_mul_get_block_length : length"
	);

	bi_del(&a);
	bi_del(&b);
}

// case a's max bit + b's max bit > length * 8 
void		test_bi_strassen_mul_get_block_length_case2(void)
{
	printf(KYEL "test_bi_strassen_mul_get_block_length_case2\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	size_t		length;

	bi_init(&a);
	bi_init(&b);
	for (int i=0; i < 17; i++)
	{
		bi_push(&a, 0xff);
		bi_push(&b, 0xff);
	}
	length = bi_strassen_mul_get_block_length(&a, &b);

	test(
		length == 64,
		"bi_strassen_mul_get_block_length : length"
	);

	bi_del(&a);
	bi_del(&b);
}

// case a's max bit + b's max bit > length * 8
void		test_bi_strassen_mul_get_block_length_case3(void)
{
	printf(KYEL "test_bi_strassen_mul_get_block_length_case3\n" KNRM);
	t_bigint	a;
	t_bigint	b;
	size_t		length;

	bi_init(&a);
	bi_init(&b);
	for (int i=0; i < 33; i++)
	{
		bi_push(&a, 0xff);
		bi_push(&b, 0xff);
	}
	length = bi_strassen_mul_get_block_length(&a, &b);

	test(
		length == 128,
		"bi_strassen_mul_get_block_length : length"
	);

	bi_del(&a);
	bi_del(&b);
}
