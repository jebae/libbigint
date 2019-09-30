#include "bigint.h"

size_t		bi_mul_get_block_length(t_bigint *a, t_bigint *b)
{
	static size_t	unit_bits = 8;
	size_t			length;
	size_t			min;

	length = 32;
	min = bi_max_bit(a) + bi_max_bit(b);
	min = min / unit_bits + ((min % unit_bits) ? 1 : 0);
	while (length < min)
		length <<= 1;
	return (length);
}
