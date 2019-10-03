#include "bigint.h"

/*
** bi_max_bit returns size of used bits
** not index of biggest bit
*/

size_t			bi_max_bit(t_bigint *bi)
{
	static size_t	unit_bits = sizeof(unsigned char) * 8;
	size_t			res;
	int				i;

	if (bi->occupied == 0)
		return (1);
	res = (bi->occupied - 1) * unit_bits;
	i = unit_bits;
	while (i > 0)
	{
		if (bi->data[bi->occupied - 1] & (1 << (i - 1)))
			return (res + i);
		i--;
	}
	return (res);
}
