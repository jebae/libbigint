#include "bigint.h"

void		bi_erase(t_bigint *bi)
{
	bi->occupied = 0;
	ft_bzero(bi->data, bi->size);
}
