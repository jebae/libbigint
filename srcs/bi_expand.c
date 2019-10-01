#include "bigint.h"

int		bi_expand(t_bigint *bi, size_t size)
{
	unsigned char	*temp;

	temp = NULL;
	if (size == 0)
		return (BI_SUCCESS);
	if ((temp = ft_memalloc(bi->size + size)) == NULL)
		return (BI_FAIL);
	ft_memcpy(temp, bi->data, bi->size);
	ft_memdel((void **)&(bi->data));
	bi->data = temp;
	bi->size += size;
	return (BI_SUCCESS);
}
