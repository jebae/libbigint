#include "bigint.h"

void			bi_abs_compare(
	t_bigint *a,
	t_bigint *b,
	t_bigint **bigger,
	t_bigint **smaller
)
{
	size_t			i;

	*bigger = a;
	*smaller = b;
	if (a->occupied < b->occupied)
	{
		*bigger = b;
		*smaller = a;
	}
	else if (a->occupied == b->occupied)
	{
		i = a->occupied;
		while (i > 0)
		{
			if (a->data[i - 1] < b->data[i - 1])
			{
				*bigger = b;
				*smaller = a;
				return ;
			}
			i--;
		}
	}
}

unsigned char	bi_1byte_add_1byte(
	unsigned char a,
	unsigned char b,
	unsigned char *carry
)
{
	unsigned short		res;

	res = a + b + *carry;
	*carry = res >> 8;
	return ((unsigned char)res);
}

unsigned char	bi_add_byte_by_byte(
	t_bigint *bigger,
	t_bigint *smaller,
	t_bigint *res
)
{
	size_t			i;
	size_t			j;
	unsigned char	carry;

	i = 0;
	carry = 0x00;
	j = smaller->occupied;
	while (i < j)
	{
		res->data[i] =
			bi_1byte_add_1byte(smaller->data[i], bigger->data[i], &carry);
		i++;
	}
	j = bigger->occupied;
	while (i < j)
	{
		res->data[i] =
			bi_1byte_add_1byte(bigger->data[i], 0x00, &carry);
		i++;
	}
	res->occupied = i;
	return (carry);
}

unsigned char	bi_1byte_mul_1byte(
	unsigned char a,
	unsigned char b,
	unsigned char *carry
)
{
	unsigned short		res;

	res = a * b + *carry;
	*carry = res >> 8;
	return ((unsigned char)res);
}
