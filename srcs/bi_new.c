#include "bigint.h"

t_bigint	bi_new(size_t size)
{
	t_bigint	bi;

	bi.size = size;
	bi.data = ft_memalloc(size);
	return (bi);
}
