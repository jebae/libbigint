#include "bigint.h"

static int	handle_fail(t_bigint *res, t_bigint *to_add)
{
	ft_memdel((void **)&(res->data));
	ft_memdel((void **)&(to_add->data));
	return (BI_FAIL);
}

int			bi_mul_1byte(
	t_bigint *bi,
	unsigned char factor,
	t_bigint *res
)
{
	unsigned char		carry;
	size_t				i;

	if (bi_init(res, bi->occupied) == BI_FAIL)
		return (BI_FAIL);
	i = 0;
	carry = 0x00;
	while (i < bi->occupied)
	{
		res->data[i] = bi_1byte_mul_1byte(bi->data[i], factor, &carry);
		i++;
	}
	res->occupied = i;
	res->sign = bi->sign;
	if (carry && bi_push(res, carry) == BI_FAIL)
		return (BI_FAIL);
	bi_update_occupied(res);
	return (BI_SUCCESS);
}

int			bi_mul_bi(t_bigint *a, t_bigint *b, t_bigint *c)
{
	size_t			i;
	t_bigint		res;
	t_bigint		to_add;

	if (bi_new(&res, 1, a->sign) == BI_FAIL)
		return (BI_FAIL);
	if (bi_new(&to_add, 1, BI_SIGN_POSITIVE) == BI_FAIL)
	{
		ft_memdel((void **)&res.data);
		return (BI_FAIL);
	}
	i = 0;
	while (i < b->occupied)
	{
		if (bi_mul_1byte(a, b->data[i], &to_add) == BI_FAIL)
			return (handle_fail(&res, &to_add));
		// push pad to_add
		bi_add_bi(&res, &to_add, &res);
		i++;
	}
}
