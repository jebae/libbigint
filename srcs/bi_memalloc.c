#include "bigint.h"

int		bi_memalloc(t_bigint *bi, size_t size)
{
	if (bi->data != NULL && bi->size >= size)
		bi_erase(bi);
	bi_del(bi);
	if (size == 0)
		return (BI_SUCCESS);
	if ((bi->data = ft_memalloc(size)) == NULL)
		return (BI_FAIL);
	bi->size = size;
	return (BI_SUCCESS);
}
