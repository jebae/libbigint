#include "bigint.h"

int		bi_mod_n_pow_of_2_plus_1_handle_fail(t_bigint *p, t_bigint *q)
{
	ft_memdel((void **)(p->data));
	ft_memdel((void **)(q->data));
	return (BI_FAIL);
}

int		bi_mod_n_pow_of_2_plus_1_handle_0(t_bigint *bi, t_bigint *res)
{
	if (bi_init(res, 1) == BI_FAIL)
		return (BI_FAIL);
	if (bi->occupied == 0 || !(bi->data[0] & 0x01))
		return (BI_SUCCESS);
	bi_push(res, 0x01);
	return (BI_SUCCESS);
}
