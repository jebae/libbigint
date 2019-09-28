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

	bi_init(q, q->size);
	i = max_bit_index / unit_bits;
	printf("mbi : %zu\n", max_bit_index);
	printf("i : %zu, bi->occupied : %zu\n", i, bi->occupied);
	while (i > 0)
	{
		q->data[i - 1] = bi->data[i - 1];
		i--;
	}
	i = max_bit_index % unit_bits;
	while (i > 0)
	{
		q->data[q->occupied - 1] |=
			(bi->data[q->occupied - 1] & (1 << (i - 1)));
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
	bi_abs(res, res);
	printf("neg : %zu\n", neg_depth);
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
			m->data[0] |= 0x01;
		}
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
	if (init_pq(&p, &q, max_bit) == BI_FAIL)
		return (BI_FAIL);
	if (bi_copy(res, bi) == BI_FAIL)
		return (bi_mod_n_pow_of_2_plus_1_handle_fail(&p, &q));
	neg_depth = (bi->sign == BI_SIGN_NEGATIVE) ? 1 : 0;
	while (max_bit - 1 >= n)
	{
		set_p(&p, max_bit - 1, n);
		printf("p : %02x%02x%02x (occ : %zu)\n", p.data[2], p.data[1], p.data[0], p.occupied);
		set_q(&q, res, max_bit - 1);
		printf("q : %02x%02x%02x (occ : %zu)\n", q.data[2], q.data[1], q.data[0], q.occupied);
		bi_sub_bi(&q, &p, res);
		printf("r : %02x%02x%02x (sign : %d, occ : %zu)\n", res->data[2], res->data[1], res->data[0], res->sign, res->occupied);
		printf("\n");
		if (res->occupied != 0 && res->sign == BI_SIGN_NEGATIVE)
			neg_depth++;
		max_bit = bi_max_bit(res);
	}
	ft_memdel((void **)&(q.data));
	if (res->occupied == 0)
		neg_depth = 0;
	return (set_mod_result(res, &p, n, neg_depth));
}
