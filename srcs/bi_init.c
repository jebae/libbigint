#include "bigint.h"

void		bi_init(t_bigint *bi)
{
	bi->data = NULL;
	bi->sign = BI_SIGN_POSITIVE;
	bi->size = 0;
	bi->occupied = 0;
}
