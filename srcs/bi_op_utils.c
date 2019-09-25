#include "bigint.h"

char	bi_add_one_byte(
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

void	bi_abs_compare(
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
