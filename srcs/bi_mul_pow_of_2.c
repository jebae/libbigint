#include "bigint.h"

static int		set_mem(
	t_bigint *res,
	t_bigint *bi,
	size_t n,
	size_t unit_bits
)
{
	size_t			total_bits;
	size_t			size;

	total_bits = n + bi_max_bit(bi);
	size = total_bits / unit_bits +
		((total_bits % unit_bits) ? 1 : 0);
	if (res == bi)
	{
		if (bi_expand_at_least(bi, size) == BI_FAIL)
			return (BI_FAIL);
	}
	else
	{
		if (bi_init(res, size) == BI_FAIL)
			return (BI_FAIL);
		ft_memcpy(res->data, bi->data, bi->occupied);
	}
	res->occupied = size;
	return (BI_SUCCESS);
}

static void		shift_by_byte(t_bigint *bi, size_t n, size_t unit_bits)
{
	size_t		i;
	size_t		shift;

	shift = n / unit_bits;
	if (shift == 0)
		return ;
	i = bi->occupied;
	while (i - shift > 0)
	{
		bi->data[i - 1] = bi->data[i - 1 - shift];
		bi->data[i - 1 - shift] = 0x00;
		i--;
	}
}

static void		shift_by_bit(t_bigint *bi, size_t n, size_t unit_bits)
{
	int				shift;
	size_t			i;
	unsigned char	*prev;

	shift = n % unit_bits;
	if (shift == 0)
		return ;
	i = bi->occupied - 1;
	prev = bi->data + i;
	*prev <<= shift;
	while (i > 0)
	{
		*prev |= (unsigned short)(bi->data[i - 1]) << shift >> unit_bits;
		bi->data[i - 1] <<= shift;
		prev = bi->data + (i - 1);
		i--;
	}
}

int				bi_mul_pow_of_2(t_bigint *bi, size_t n, t_bigint *res)
{
	static size_t	unit_bits = sizeof(unsigned char) * 8;

	if (set_mem(res, bi, n, unit_bits) == BI_FAIL)
		return (BI_FAIL);
	shift_by_byte(res, n, unit_bits);
	shift_by_bit(res, n, unit_bits);
	res->sign = bi->sign;
	bi_update_occupied(res);
	return (BI_SUCCESS);
}
