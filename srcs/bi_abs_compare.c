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
		while (i > 0 && (a->data[i - 1] == b->data[i - 1]))
			i--;
		if (i > 0 && a->data[i - 1] < b->data[i - 1])
		{
			*bigger = b;
			*smaller = a;
		}
	}
}
