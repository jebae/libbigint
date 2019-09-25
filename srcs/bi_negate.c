#include "bigint.h"

static int	modify_size(t_bigint *bi, size_t size)
{
	if (bi->size < size)
	{
		if (bi_expand(bi, size - bi->size) == BI_FAIL)
			return (BI_FAIL);
	}
	else if (bi->size > size)
		return (bi_shrink(bi, bi->size - size));
	return (BI_SUCCESS);
}

#include <stdio.h>
int			bi_negate(t_bigint *bi, size_t size)
{
	unsigned char	carry;
	size_t			i;

	if (modify_size(bi, size) == BI_FAIL)
		return (BI_FAIL);
	i = 0;
	while (i < size)
	{
		bi->data[i] = ~(bi->data[i]);
		i++;
	}
	carry = 0x01;
	i = 0;
	bi->occupied = 0;
	while (i < size)
	{
		bi_push(bi, bi_add_one_byte(bi->data[i], 0x00, &carry));
		i++;
	}
	return (BI_SUCCESS);
}
