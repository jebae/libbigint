#include "bigint.h"

static int		set_negate_data(t_bigint *bi, size_t size)
{
	unsigned char	*negate;

	negate = ft_memalloc(size);
	if (negate == NULL)
		return (BI_FAIL);
	ft_memcpy(negate, bi->data, bi->occupied);
	ft_memnegate(negate, size);
	bi->data = negate;
	bi->occupied = size;
	return (BI_SUCCESS);
}

static int		pass_to_add(t_bigint *a, t_bigint *b, t_bigint *c)
{
	char	sign;

	sign = b->sign;
	b->sign ^= 1;
	if (bi_add_bi(a, b, c) == BI_FAIL)
	{
		b->sign ^= 1;
		return (BI_FAIL);
	}
	b->sign ^= 1;
	return (BI_SUCCESS);
}

static char		get_sign(t_bigint *a, t_bigint *bigger)
{
	if (bigger == a)
	{
		if (bigger->sign == BI_SIGN_POSITIVE)
			return (BI_SIGN_POSITIVE);
		else
			return (BI_SIGN_NEGATIVE);
	}
	else
	{
		if (bigger->sign == BI_SIGN_POSITIVE)
			return (BI_SIGN_NEGATIVE);
		else
			return (BI_SIGN_POSITIVE);
	}
}

int				bi_sub_bi(t_bigint *a, t_bigint *b, t_bigint *c)
{
	t_bigint		*bigger;
	t_bigint		*smaller;
	t_bigint		temp;

	if (a->sign != b->sign)
		return (pass_to_add(a, b, c));
	bi_abs_compare(a, b, &bigger, &smaller);
	if (bi_init(c, bigger->occupied) == BI_FAIL)
		return (BI_FAIL);
	c->sign = get_sign(a, bigger);
	if (bigger->occupied == 0)
		return (BI_SUCCESS);
	temp = *smaller;
	if (set_negate_data(smaller, bigger->occupied) == BI_FAIL)
	{
		*smaller = temp;
		return (BI_FAIL);
	}
	bi_add_byte_by_byte(bigger, smaller, c);
	update_occupied(c);
	ft_memdel((void **)&(smaller->data));
	*smaller = temp;
	return (BI_SUCCESS);
}
