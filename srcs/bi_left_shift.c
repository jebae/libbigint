/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_left_shift.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:00:24 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:00:25 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

static int		set_mem(
	t_bigint *res,
	t_bigint *bi,
	size_t n
)
{
	size_t			total_bits;
	size_t			size;

	total_bits = n + bi_max_bit(bi);
	size = total_bits / BI_UNIT_BITS +
		((total_bits % BI_UNIT_BITS) ? 1 : 0);
	if (res == bi)
	{
		if (bi_expand_at_least(bi, size) == BI_FAIL)
			return (BI_FAIL);
	}
	else
	{
		if (bi_memalloc(res, size) == BI_FAIL)
			return (BI_FAIL);
		ft_memcpy(res->data, bi->data, bi->occupied);
	}
	res->occupied = size;
	return (BI_SUCCESS);
}

static void		shift_by_byte(t_bigint *bi, size_t n)
{
	size_t		i;
	size_t		shift;

	shift = n / BI_UNIT_BITS;
	if (shift == 0)
		return ;
	i = bi->occupied;
	while (i > shift)
	{
		bi->data[i - 1] = bi->data[i - 1 - shift];
		bi->data[i - 1 - shift] = 0x00;
		i--;
	}
}

static void		shift_by_bit(t_bigint *bi, size_t n)
{
	size_t			shift;
	size_t			i;
	unsigned char	*prev;

	shift = n % BI_UNIT_BITS;
	if (shift == 0)
		return ;
	i = bi->occupied - 1;
	prev = bi->data + i;
	*prev <<= shift;
	while (i > 0)
	{
		*prev |= (unsigned short)(bi->data[i - 1]) << shift >> BI_UNIT_BITS;
		bi->data[i - 1] <<= shift;
		prev = bi->data + (i - 1);
		i--;
	}
}

int				bi_left_shift(t_bigint *bi, size_t n, t_bigint *res)
{
	if (set_mem(res, bi, n) == BI_FAIL)
		return (BI_FAIL);
	shift_by_byte(res, n);
	shift_by_bit(res, n);
	res->sign = bi->sign;
	bi_update_occupied(res);
	return (BI_SUCCESS);
}
