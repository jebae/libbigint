#include "bigint.h"

int		bi_copy(t_bigint *dst, t_bigint *src)
{
	size_t	i;

	if (dst == src)
		return (BI_SUCCESS);
	if (bi_memalloc(dst, src->occupied) == BI_FAIL)
		return (BI_FAIL);
	dst->sign = src->sign;
	dst->occupied = src->occupied;
	i = 0;
	while (i < src->occupied)
	{
		dst->data[i] = src->data[i];
		i++;
	}
	return (BI_SUCCESS);
}
