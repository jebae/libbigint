/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bcd_round.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:40:59 by jebae             #+#    #+#             */
/*   Updated: 2019/10/28 14:41:00 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

static void		set_zero_below_pos(t_bigint *bcd, size_t pos)
{
	while (pos)
	{
		bcd_set_digit(bcd, pos - 1, 0);
		pos--;
	}
}

static int		handle_last_carry(t_bigint *res, size_t len)
{
	if (len & 1)
		bcd_set_digit(res, len, 1);
	else if (bi_push(res, 0x01) == BI_FAIL)
		return (BI_FAIL);
	return (BI_SUCCESS);
}

int				bcd_round(t_bigint *bcd, size_t pos, t_bigint *res)
{
	unsigned char	digit;
	unsigned char	carry;
	size_t			len;
	size_t			i;

	if (bi_copy(res, bcd) == BI_FAIL)
		return (BI_FAIL);
	if (pos > 0 && (digit = bcd_get_digit(res, pos - 1)) >= 5)
	{
		carry = 1;
		len = bcd_len(res);
		i = pos;
		while (i < len && carry)
		{
			digit = bcd_get_digit(res, i) + carry;
			bcd_set_digit(res, i, digit % 10);
			carry = digit / 10;
			i++;
		}
		if (carry > 0 && handle_last_carry(res, len) == BI_FAIL)
			return (BI_FAIL);
	}
	set_zero_below_pos(res, pos);
	bi_update_occupied(res);
	return (BI_SUCCESS);
}
