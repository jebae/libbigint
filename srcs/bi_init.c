#include "bigint.h"

int			bi_init(t_bigint *bi, size_t size)
{
	if (bi->size < size)
		BI_HANDLE_FUNC_FAIL(bi_expand(bi, size - bi->size));
	bi_erase(bi);
	bi->sign = BI_SIGN_POSITIVE;
	return (BI_SUCCESS);
}
