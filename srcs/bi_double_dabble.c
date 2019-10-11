#include "bigint.h"

static int		set_mem(t_bigint *bin, t_bigint *bcd)
{
	size_t		size;

	size = bin->occupied * 10 + 2;
	size = (size % BI_UNIT_BITS == 0)
		? size / BI_UNIT_BITS
		: size / BI_UNIT_BITS + 1;
	BI_HANDLE_FUNC_FAIL(bi_init(bcd, size));
	return (BI_SUCCESS);
}

static int		bcd_shift(t_bigint *bcd, int bit)
{
	BI_HANDLE_FUNC_FAIL(bi_mul_pow_of_2(bcd, 1, bcd));
	bcd->data[0] |= bit;
	return (BI_SUCCESS);
}

static void		add_3_if_gte_5(t_bigint *bcd)
{
	size_t		i;

	i = 0;
	while (i < bcd->occupied)
	{
		if ((bcd->data[i] & 0x0f) > 0x04)
			bcd->data[i] += 0x03;
		if ((bcd->data[i] & 0xf0) > 0x40)
			bcd->data[i] += 0x30;
		i++;
	}
}

int				bi_double_dabble(t_bigint *bin, t_bigint *bcd)
{
	size_t		i;
	int			bit;

	BI_HANDLE_FUNC_FAIL(set_mem(bin, bcd));
	i = bi_max_bit(bin);
	while (i > 0)
	{
		add_3_if_gte_5(bcd);
		bit = bi_get_bit(bin, i - 1);
		BI_HANDLE_FUNC_FAIL(bcd_shift(bcd, bit));
		i--;
	}
	bcd->sign = bin->sign;
	return (BI_SUCCESS);
}
