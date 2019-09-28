#include "bigint.h"

int		bi_abs(t_bigint *bi, t_bigint *res)
{
	if (bi != res)
	{
		if (bi_copy(res, bi) == BI_FAIL)
			return (BI_FAIL);
	}
	res->sign = BI_SIGN_POSITIVE;
	return (BI_SUCCESS);
}
