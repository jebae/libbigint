#include "bigint.h"

void			bi_set_bit(t_bigint *bi, size_t n, int value)
{
    unsigned char    *byte;

    if (value != 0 && value != 1)
        return ;
    if (bi->size * BI_UNIT_BITS <= n)
        return ;
    byte = bi->data + n / BI_UNIT_BITS;
    if (value & 1)
        *byte |= 1 << (n % BI_UNIT_BITS);
    else
        *byte &= ~(1 << (n % BI_UNIT_BITS));
	bi_update_occupied(bi);
}
