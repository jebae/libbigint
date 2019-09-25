#include "bigint.h"

static void		set_res_sign(t_bigint *a, t_bigint *b, t_bigint *c)
{
	if (a->sign == b->sign)
		c->sign = a->sign;
}

int				bi_add_bi(t_bigint *a, t_bigint *b, t_bigint *c)
{
	unsigned char	carry;
	t_bigint		*bigger;
	t_bigint		*smaller;

	bi_abs_compare(a, b, &bigger, &smaller);
	// add line to handle sub when sign is different
	if (bi_init(c, bigger->occupied) == BI_FAIL)
		return (BI_FAIL);
	if (bigger->occupied == 0) // handle 0
		return (BI_SUCCESS);
	set_res_sign(a, b, c);
	carry = bi_add_byte_by_byte(bigger, smaller, c);
	if (carry && bi_push(c, carry) == BI_FAIL)
		return (BI_FAIL);
	return (BI_SUCCESS);
}
