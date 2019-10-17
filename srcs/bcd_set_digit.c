#include "bigint.h"

void		bcd_set_digit(t_bigint *bcd, size_t n, unsigned char val)
{
	unsigned char	*byte;

	if (bcd->size * 2 < n + 1 || val > 9)
		return ;
	byte = bcd->data + n / 2;
	if (n & 1)
	{
		*byte = (*byte & 0x0f) | val << 4;
		return ;
	}
	*byte = (*byte & 0xf0) | val;
	bi_update_occupied(bcd);
}
