/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_right_shift.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:01:20 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:01:21 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

static void		shift_by_byte(t_bigint *bi, size_t n)
{
	size_t		i;
	size_t		shift;

	shift = n / BI_UNIT_BITS;
	if (shift == 0)
		return ;
	i = 0;
	while (i + shift < bi->occupied)
	{
		bi->data[i] = bi->data[i + shift];
		bi->data[i + shift] = 0x00;
		i++;
	}
	while (i < bi->occupied && i < shift)
		bi->data[i++] = 0x00;
	bi_update_occupied(bi);
}

static void		shift_by_bit(t_bigint *bi, size_t n)
{
	size_t			shift;
	size_t			i;
	unsigned char	*prev;
	unsigned short	cur;

	shift = n % BI_UNIT_BITS;
	if (shift == 0 || bi->occupied == 0)
		return ;
	prev = bi->data;
	*prev >>= shift;
	i = 1;
	while (i < bi->occupied)
	{
		cur = bi->data[i];
		cur = cur << BI_UNIT_BITS >> shift;
		*prev |= (unsigned char)cur;
		bi->data[i] = cur >> BI_UNIT_BITS;
		prev = bi->data + i;
		i++;
	}
}

int				bi_right_shift(t_bigint *bi, size_t n, t_bigint *res)
{
	if (bi_copy(res, bi) == BI_FAIL)
		return (BI_FAIL);
	shift_by_byte(res, n);
	shift_by_bit(res, n);
	bi_update_occupied(res);
	return (BI_SUCCESS);
}
