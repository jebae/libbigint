#include "bigint.h"

/*
** bi_mod_n_pow_of_2_plus_1 use equation below
** A = 2^n * p + q
** M = 2^n + 1
** A mod M = (q - p) mod M
*/

static int		init_pq(t_bigint *p, t_bigint *q, size_t max_bit)
{
	static size_t	unit_bits = sizeof(unsigned char) * 8;
	size_t			size;

	size = max_bit / unit_bits + ((max_bit % unit_bits) ? 1 : 0);
	BI_HANDLE_FUNC_FAIL(bi_new(p, size, BI_SIGN_POSITIVE));
	if (bi_new(q, size, BI_SIGN_POSITIVE) == BI_FAIL)
	{
		ft_memdel((void **)&(p->data));
		return (BI_FAIL);
	}
	bi_push(p, 0x01);
	return (BI_SUCCESS);
}

static void		set_p(t_bigint *p, size_t max_bit_index, size_t n)
{
	p->data[p->occupied - 1] = 0x00;
	p->occupied = 0;
	bi_push(p, 0x01);
	bi_mul_pow_of_2(p, max_bit_index - n, p);
}

static void		set_q(t_bigint *q, t_bigint *bi, size_t max_bit_index)
{
	static size_t	unit_bits = sizeof(unsigned char) * 8;
	size_t			i;
	size_t			j;

	bi_init(q, q->size);
	j = max_bit_index / unit_bits;
	i = 0;
	while (i < j)
	{
		q->data[i] = bi->data[i];
		i++;
	}
	i = max_bit_index % unit_bits;
	while (i > 0)
	{
		q->data[j] |= (bi->data[j] & (1 << (i - 1)));
		i--;
	}
	bi_update_occupied(q);
}

static int		set_mod_result(
	t_bigint *res,
	t_bigint *m,
	size_t n,
	size_t neg_depth
)
{
	if (res->occupied == 0)
		neg_depth = 0;
	bi_abs(res, res);
	if (neg_depth & 1)
	{
		m->data[m->occupied - 1] = 0x00;
		m->occupied = 0;
		bi_push(m, 0x01);
		if (bi_mul_pow_of_2(m, n, m) == BI_FAIL)
		{
			ft_memdel((void **)&(m->data));
			return (BI_FAIL);
		}
		m->data[0] |= 0x01;
		if (bi_sub_bi(m, res, res) == BI_FAIL)
		{
			ft_memdel((void **)&(m->data));
			return (BI_FAIL);
		}
	}
	ft_memdel((void **)&(m->data));
	return (BI_SUCCESS);
}

int				bi_mod_n_pow_of_2_plus_1(
	t_bigint *bi,
	size_t n,
	t_bigint *res
)
{
	t_bigint	p;
	t_bigint	q;
	size_t		neg_depth;
	size_t		max_bit;

	if (n == 0)
		return (bi_mod_n_pow_of_2_plus_1_handle_0(bi, res));
	max_bit = bi_max_bit(bi);
	BI_HANDLE_FUNC_FAIL(init_pq(&p, &q, max_bit));
	if (bi_copy(res, bi) == BI_FAIL)
		return (bi_mod_n_pow_of_2_plus_1_handle_fail(&p, &q));
	neg_depth = (bi->sign == BI_SIGN_NEGATIVE) ? 1 : 0;
	while (max_bit >= n + 1)
	{
		set_p(&p, max_bit - 1, n);
		set_q(&q, res, max_bit - 1);
		bi_sub_bi(&q, &p, res);
		if (res->sign == BI_SIGN_NEGATIVE)
			neg_depth++;
		max_bit = bi_max_bit(res);
	}
	ft_memdel((void **)&(q.data));
	return (set_mod_result(res, &p, n, neg_depth));
}
