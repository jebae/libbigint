#include "bigint.h"

void	bi_del(t_bigint *bi)
{
	ft_memdel((void **)&bi->data);
	bi_init(bi);
}