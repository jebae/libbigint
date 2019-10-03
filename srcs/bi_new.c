#include "bigint.h"

int		bi_new(t_bigint *bi, size_t size, char sign)
{
	if ((bi->data = ft_memalloc(size)) == NULL)
		return (BI_FAIL);
	bi->size = size;
	bi->sign = sign;
	bi->occupied = 0;
	return (BI_SUCCESS);
}
