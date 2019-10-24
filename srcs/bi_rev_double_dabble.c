/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_rev_double_dabble.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:05:09 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:05:19 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

static int		set_mem(t_bigint *bin, t_bigint *bcd)
{
	size_t		size;

	size = bcd->occupied * 7;
	size = (size % BI_UNIT_BITS == 0)
		? size / BI_UNIT_BITS
		: size / BI_UNIT_BITS + 1;
	if (bi_memalloc(bin, size) == BI_FAIL)
		return (BI_FAIL);
	return (BI_SUCCESS);
}

static void		sub_3_if_gte_8(t_bigint *bcd)
{
	size_t		i;

	i = 0;
	while (i < bcd->occupied)
	{
		if ((bcd->data[i] & 0x0f) > 0x07)
			bcd->data[i] -= 0x03;
		if ((bcd->data[i] & 0xf0) > 0x70)
			bcd->data[i] -= 0x30;
		i++;
	}
}

int				bi_rev_double_dabble(t_bigint *bcd, t_bigint *bin)
{
	size_t		i;
	t_bigint	copy;

	bi_init(&copy);
	if (set_mem(bin, bcd) == BI_FAIL)
		return (BI_FAIL);
	if (bi_copy(&copy, bcd) == BI_FAIL)
		return (BI_FAIL);
	i = 0;
	while (copy.occupied != 0)
	{
		bi_set_bit(bin, i, bi_get_bit(&copy, 0));
		bi_right_shift(&copy, 1, &copy);
		sub_3_if_gte_8(&copy);
		i++;
	}
	bin->sign = bcd->sign;
	bi_update_occupied(bin);
	bi_del(&copy);
	return (BI_SUCCESS);
}
