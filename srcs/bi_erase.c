#include "bigint.h"

void		bi_erase(t_bigint *bi)
{
	ft_bzero(bi->data, bi->occupied);
	bi->occupied = 0;
}
