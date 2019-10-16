#include "bigint.h"

unsigned char		bcd_get_digit(t_bigint *bcd, size_t n)
{
	unsigned char	byte;

	if (bcd->occupied * 2 < n + 1)
		return (0);
	byte = bcd->data[n / 2];
	if (n & 1)
		return (byte >> 4);
	return (byte & 0x0f);
}
