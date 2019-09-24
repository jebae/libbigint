#include "bigint.h"

int		bi_new(t_bigint *bi, size_t size)
{
	bi->size = size;
	bi->occupied = 0;
	if ((bi->data = ft_memalloc(size)) == NULL)
		return (BI_FAIL);
	return (BI_SUCCESS);
}
