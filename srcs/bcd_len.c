#include "bigint.h"

size_t		bcd_len(t_bigint *bcd)
{
	if (bcd->occupied == 0)
		return (1);
	if (bcd->data[bcd->occupied - 1] & 0xf0)
		return (bcd->occupied * 2);
	return (bcd->occupied * 2 - 1);
}
