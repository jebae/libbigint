#include "bigint.h"

int		bi_shrink(t_bigint *bi, size_t size)
{
	if (size == 0)
		return (BI_SUCCESS);
	if (size > bi->size)
		return (BI_FAIL);
	while (size--)
		bi->data[--(bi->occupied)] = 0x00;
	return (BI_SUCCESS);
}
