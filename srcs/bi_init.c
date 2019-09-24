#include "bigint.h"

void		bi_init(t_bigint *bi)
{
	ft_bzero(bi->data, bi->size);
}
