/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_double_dabble.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:00:07 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:06:23 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

static int		set_mem(t_bigint *bcd, t_bigint *bin)
{
	size_t		size;

	size = bin->occupied * 10 + 2;
	size = (size % BI_UNIT_BITS == 0)
		? size / BI_UNIT_BITS
		: size / BI_UNIT_BITS + 1;
	if (bi_memalloc(bcd, size) == BI_FAIL)
		return (BI_FAIL);
	return (BI_SUCCESS);
}

static int		bcd_left_shift(t_bigint *bcd, int bit)
{
	if (bi_left_shift(bcd, 1, bcd) == BI_FAIL)
		return (BI_FAIL);
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

	if (set_mem(bcd, bin) == BI_FAIL)
		return (BI_FAIL);
	i = bin->occupied * BI_UNIT_BITS;
	while (i > 0)
	{
		add_3_if_gte_5(bcd);
		bit = bi_get_bit(bin, i - 1);
		bcd_left_shift(bcd, bit);
		i--;
	}
	bcd->sign = bin->sign;
	bi_update_occupied(bcd);
	return (BI_SUCCESS);
}
