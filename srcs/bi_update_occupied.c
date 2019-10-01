#include "bigint.h"

void			bi_update_occupied(t_bigint *bi)
{
	size_t		i;

	i = bi->size;
	while (i > 0 && bi->data[i - 1] == 0x00)
		i--;
	bi->occupied = i;
	if (bi->occupied == 0)
		bi->sign = BI_SIGN_POSITIVE;
}
