#include "bigint.h"

static int		alloc_res_mem(t_bigint *res, size_t size)
{
	if (res->size >= size)
		return (BI_SUCCESS);
	if (bi_expand(res, size - res->size) == BI_FAIL)
		return (BI_FAIL);
	bi_erase(res);
	return (BI_SUCCESS);
}

static void		set_res_sign(t_bigint *a, t_bigint *b, t_bigint *c)
{
	if (a->sign == b->sign)
		c->sign = a->sign;
}

int				bi_add_bi(t_bigint *a, t_bigint *b, t_bigint *c)
{
	size_t			i;
	t_bigint		*bigger;
	t_bigint		*smaller;
	unsigned char	carry;

	bi_abs_compare(a, b, &bigger, &smaller);
	if (alloc_res_mem(c, bigger->occupied) == BI_FAIL)
		return (BI_FAIL);
	// add line to handle sub when sign is different
	set_res_sign(a, b, c);
	i = 0;
	carry = 0x00;
	while (i < smaller->occupied)
	{
		bi_push(c, bi_add_one_byte(a->data[i], b->data[i], &carry));
		i++;
	}
	while (i < bigger->occupied)
	{
		bi_push(c, bi_add_one_byte(bigger->data[i], 0x00, &carry));
		i++;
	}
	if (carry && bi_push(c, carry) == BI_FAIL)
		return (BI_FAIL);
	return (BI_SUCCESS);
}
