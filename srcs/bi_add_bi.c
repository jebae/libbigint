#include "bigint.h"

static int		pass_to_sub(t_bigint *a, t_bigint *b, t_bigint *c)
{
	char	sign;

	sign = b->sign;
	b->sign ^= 1;
	if (bi_sub_bi(a, b, c) == BI_FAIL)
	{
		b->sign ^= 1;
		return (BI_FAIL);
	}
	b->sign ^= 1;
	return (BI_SUCCESS);
}

int				bi_add_bi(t_bigint *a, t_bigint *b, t_bigint *c)
{
	unsigned char	carry;
	t_bigint		*bigger;
	t_bigint		*smaller;

	if (a->sign != b->sign)
		return (pass_to_sub(a, b, c));
	bi_abs_compare(a, b, &bigger, &smaller);
	c->sign = a->sign;
	if (bi_init(c, bigger->occupied) == BI_FAIL)
		return (BI_FAIL);
	if (bigger->occupied == 0)
		return (BI_SUCCESS);
	carry = bi_add_byte_by_byte(bigger, smaller, c);
	if (carry && bi_push(c, carry) == BI_FAIL)
		return (BI_FAIL);
	return (BI_SUCCESS);
}
