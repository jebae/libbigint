#include "bigint.h"

int		bi_push(t_bigint *bi, char data)
{
	if (bi->size == bi->occupied)
		BI_HANDLE_FUNC_FAIL(bi_expand(bi, 1));
	bi->data[bi->occupied] = data;
	(bi->occupied)++;
	return (BI_SUCCESS);
}
