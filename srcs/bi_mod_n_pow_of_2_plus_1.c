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
	if (bi_new(p, size, BI_SIGN_POSITIVE) == BI_FAIL)
		return (BI_FAIL);
	if (bi_new(q, size, BI_SIGN_POSITIVE) == BI_FAIL)
		return (BI_FAIL);
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

	bi_init(q, q->size);
	i = max_bit_index / unit_bits;
	while (i > 0)
	{
		bi_push(q, bi->data[i - 1]);
		i--;
	}
	i = max_bit_index % unit_bits;
	while (i > 0)
	{
		q->data[q->occupied] |= (bi->data[q->occupied] & (1 << (i - 1)));
		i--;
	}
}

static void		set_mod_result(
	t_bigint *res,
	t_bigint *m,
	size_t n,
	size_t neg_depth
)
{
	if (neg_depth & 1)
	{
		m->data[m->occupied - 1] = 0x00;
		m->occupied = 0;
		if (n == 0)
			bi_push(m, 0x02);
		else
		{
			bi_push(m, 0x01);
			bi_mul_pow_of_2(m, n, m);
		}
		// need one more bigint variable?
		// res = M - |res|
	}
	else
		// res = res
}

int			bi_mod_n_pow_of_2_plus_1(
	t_bigint *bi,
	size_t n,
	t_bigint *res
)
{
	t_bigint	p;
	t_bigint	q;
	size_t		neg_depth;
	size_t		max_bit;

	max_bit = bi_max_bit(bi);
	if (init_pq(&p, &q, max_bit) == BI_FAIL)
		return (BI_FAIL);
	if (bi_copy(res, bi) == BI_FAIL)
	{
		ft_memdel((void **)&p);
		ft_memdel((void **)&q);
		return (BI_FAIL);
	}
	neg_depth = 0;
	while ((max_bit - 1) >= n)
	{
		set_p(&p, max_bit - 1, n);
		set_q(&q, res, max_bit - 1);
		bi_sub_bi(&q, &p, res);
		if (res->occupied != 0 && res->sign == BI_SIGN_NEGATIVE)
			neg_depth++;
		max_bit = bi_max_bit(res);
	}
	set_mod_result(res, max_bit - 1, n, neg_depth);
	return (BI_SUCCESS);
}
