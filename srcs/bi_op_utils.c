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

unsigned char	bi_add_one_byte(
	unsigned char a,
	unsigned char b,
	unsigned char *carry
)
{
	unsigned short		res;

	res = a + b + *carry;
	if (res > 0xff)
		*carry = 0x01;
	else
		*carry = 0x00;
	return ((unsigned char)res);
}

unsigned char	bi_add_byte_by_byte(
	t_bigint *bigger,
	t_bigint *smaller,
	t_bigint *res
)
{
	size_t			i;
	unsigned char	carry;

	i = 0;
	carry = 0x00;
	while (i < smaller->occupied)
	{
		bi_push(res,
			bi_add_one_byte(smaller->data[i], bigger->data[i], &carry));
		i++;
	}
	while (i < bigger->occupied)
	{
		bi_push(res, bi_add_one_byte(bigger->data[i], 0x00, &carry));
		i++;
	}
	return (carry);
}

void			update_occupied(t_bigint *bi)
{
	size_t		i;

	i = 0;
	while (bi->occupied > 0 && bi->data[bi->occupied - 1] == 0x00)
		(bi->occupied)--;
}
