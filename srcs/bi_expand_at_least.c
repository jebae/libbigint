#include "bigint.h"

int		bi_expand_at_least(t_bigint *bi, size_t size)
{
	if (bi->size >= size)
		return (BI_SUCCESS);
	BI_HANDLE_FUNC_FAIL(bi_expand(bi, size - bi->size));
	return (BI_SUCCESS);
}
