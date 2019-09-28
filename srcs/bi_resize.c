#include "bigint.h"

int		bi_resize(t_bigint *bi, size_t size)
{
	unsigned char	*temp;

	temp = bi->data;
	if ((bi->data = ft_memalloc(size)) == NULL)
		return (BI_FAIL);
	ft_memcpy(bi->data, temp, (size < bi->size) ? size : bi->size);
	bi->size = size;
	bi_update_occupied(bi);
	ft_memdel((void **)&temp);
	return (BI_SUCCESS);
}
