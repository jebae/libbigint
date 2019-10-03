#include "bigint.h"

static int	handle_return(t_bigint *res, t_bigint *to_add, int ret)
{
	ft_memdel((void **)&(res->data));
	ft_memdel((void **)&(to_add->data));
	return (ret);
}

static int	preprocess(
	t_bigint *res,
	t_bigint *to_add
)
{
	BI_HANDLE_FUNC_FAIL(bi_new(res, 1, BI_SIGN_POSITIVE));
	if (bi_new(to_add, 1, BI_SIGN_POSITIVE) == BI_FAIL)
	{
		ft_memdel((void **)&(res->data));
		return (BI_FAIL);
	}
	return (BI_SUCCESS);
}

static char		get_sign(t_bigint *a, t_bigint *b)
{
	if (a->occupied == 0 || b->occupied == 0)
		return (BI_SIGN_POSITIVE);
	else if (a->sign == b->sign)
		return (BI_SIGN_POSITIVE);
	else
		return (BI_SIGN_NEGATIVE);
}

int				bi_mul_1byte(
	t_bigint *bi,
	unsigned char factor,
	t_bigint *res
)
{
	unsigned char		carry;
	size_t				i;

	BI_HANDLE_FUNC_FAIL(bi_init(res, bi->occupied));
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

	BI_HANDLE_FUNC_FAIL(preprocess(&res, &to_add));
	i = 0;
	while (i < b->occupied)
	{
		if (bi_mul_1byte(a, b->data[i], &to_add) == BI_FAIL)
			return (handle_return(&res, &to_add, BI_FAIL));
		if (bi_mul_pow_of_2(&to_add, 8 * i, &to_add) == BI_FAIL)
			return (handle_return(&res, &to_add, BI_FAIL));
		if (bi_add_bi(&res, &to_add, &res) == BI_FAIL)
			return (handle_return(&res, &to_add, BI_FAIL));
		i++;
	}
	res.sign = get_sign(a, b);
	if (bi_copy(c, &res) == BI_FAIL)
		return (handle_return(&res, &to_add, BI_FAIL));
	return (handle_return(&res, &to_add, BI_SUCCESS));
}
