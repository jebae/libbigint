#include "bigint.h"

int		bi_abs(t_bigint *bi, t_bigint *res)
{
	if (bi != res)
		BI_HANDLE_FUNC_FAIL(bi_copy(res, bi));
	res->sign = BI_SIGN_POSITIVE;
	return (BI_SUCCESS);
}
