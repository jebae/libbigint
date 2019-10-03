#include "bigint.h"

int		bi_copy(t_bigint *dst, t_bigint *src)
{
	size_t	i;

	if (dst == src)
		return (BI_SUCCESS);
	BI_HANDLE_FUNC_FAIL(bi_init(dst, src->occupied));
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
