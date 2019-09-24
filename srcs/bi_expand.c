#include "bigint.h"

int		bi_expand(t_bigint *bi, size_t size)
{
	unsigned char	*temp;

	temp = bi->data;
	if ((bi->data = ft_memalloc(bi->size + size)) == NULL)
		return (BI_FAIL);
	ft_memcpy(bi->data, temp, bi->size);
	bi->size += size;
	ft_memdel((void **)&temp);
	return (BI_SUCCESS);
}
