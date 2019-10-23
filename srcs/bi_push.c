#include "bigint.h"

int		bi_push(t_bigint *bi, unsigned char data)
{
	if (bi->size == bi->occupied)
	{
		if (bi_expand(bi, 1) == BI_FAIL)
			return (BI_FAIL);
	}
	bi->data[bi->occupied] = data;
	(bi->occupied)++;
	return (BI_SUCCESS);
}
