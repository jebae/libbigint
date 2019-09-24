#include "bigint.h"

int		bi_push(t_bigint *bi, char value)
{
	if (bi->size == bi->occupied)
	{
		if (bi_expand(bi, 1) == BI_FAIL)
			return (BI_FAIL);
	}
	bi->data[bi->occupied] = value;
	(bi->occupied)++;
	return (BI_SUCCESS);
}
