#include "bigint.h"

/*
** bi_max_bit returns size of used bits
** not index of biggest bit
*/

size_t			bi_max_bit(t_bigint *bi)
{
	size_t			res;
	int				i;

	if (bi->occupied == 0)
		return (1);
	res = (bi->occupied - 1) * BI_UNIT_BITS;
	i = BI_UNIT_BITS;
	while (i > 0)
	{
		if (bi->data[bi->occupied - 1] & (1 << (i - 1)))
			return (res + i);
		i--;
	}
	return (res);
}
