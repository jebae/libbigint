#include "bigint.h"

int			bi_init(t_bigint *bi, size_t size)
{
	if (bi->size < size)
	{
		if (bi_expand(bi, size - bi->size) == BI_FAIL)
			return (BI_FAIL);
	}
	bi_erase(bi);
	return (BI_SUCCESS);
}
