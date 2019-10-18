#include "bigint.h"

void		bcd_iter(
	t_bigint *bcd,
	void (*f)(unsigned char, void *),
	void *arg
)
{
	size_t	len;

	len = bcd_len(bcd);
	while (len > 0)
		f(bcd_get_digit(bcd, --len), arg);
}
