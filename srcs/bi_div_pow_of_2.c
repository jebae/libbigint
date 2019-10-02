#include "bigint.h"

static void		shift_by_byte(t_bigint *bi, size_t n, size_t unit_bits)
{
	size_t		i;
	size_t		shift;

	shift = n / unit_bits;
	if (shift == 0)
		return ;
	i = 0;
	while (i + shift < bi->occupied)
	{
		bi->data[i] = bi->data[i + shift];
		bi->data[i + shift] = 0x00;
		i++;
	}
	while (i < shift)
		bi->data[i++] = 0x00;
	bi_update_occupied(bi);
}

static void		shift_by_bit(t_bigint *bi, size_t n, size_t unit_bits)
{
	size_t			shift;
	size_t			i;
	unsigned char	*prev;
	unsigned short	cur;

	shift = n % unit_bits;
	if (shift == 0)
		return ;
	prev = bi->data;
	*prev >>= shift;
	i = 1;
	while (i < bi->occupied)
	{
		cur = bi->data[i];
		cur = cur << unit_bits >> shift;
		*prev |= (unsigned char)cur;
		bi->data[i] = cur >> unit_bits;
		prev = bi->data + i;
		i++;
	}
}

int				bi_div_pow_of_2(t_bigint *bi, size_t n, t_bigint *res)
{
	static size_t	unit_bits = sizeof(unsigned char) * 8;

	if (bi != res && bi_copy(res, bi) == BI_FAIL)
		return (BI_FAIL);
	shift_by_byte(res, n, unit_bits);
	shift_by_bit(res, n, unit_bits);
	res->sign = bi->sign;
	bi_update_occupied(res);
	return (BI_SUCCESS);
}
