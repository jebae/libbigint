#include "bigint.h"

int		bi_expand_at_least(t_bigint *bi, size_t size)
{
	if (bi->size >= size)
		return (BI_SUCCESS);
	if (bi_expand(bi, size - bi->size) == BI_FAIL)
		return (BI_FAIL);
	return (BI_SUCCESS);
}
