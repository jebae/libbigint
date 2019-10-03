#include "bigint.h"

int		bi_resize(t_bigint *bi, size_t size)
{
	unsigned char	*temp;

	if ((temp = ft_memalloc(size)) == NULL)
		return (BI_FAIL);
	ft_memcpy(temp, bi->data, (size < bi->occupied) ? size : bi->occupied);
	ft_memdel((void **)&(bi->data));
	bi->size = size;
	bi->data = temp;
	bi_update_occupied(bi);
	return (BI_SUCCESS);
}
