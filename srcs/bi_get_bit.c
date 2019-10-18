#include "bigint.h"

int			bi_get_bit(t_bigint *bi, size_t n)
{
    unsigned char    byte;

	if (bi->occupied == 0 && n == 0)
		return (0);
    if (bi_max_bit(bi) <= n)
        return (-1);
    byte = bi->data[n / BI_UNIT_BITS];
    return ((byte >> (n % BI_UNIT_BITS)) & 0x1);
}
