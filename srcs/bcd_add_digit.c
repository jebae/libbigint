/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bcd_add_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:40:51 by jebae             #+#    #+#             */
/*   Updated: 2019/10/28 14:40:51 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

static int		handle_last_carry(t_bigint *bcd, size_t len)
{
	if (len & 1)
		bcd_set_digit(bcd, len, 1);
	else if (bi_push(bcd, 0x01) == BI_FAIL)
		return (BI_FAIL);
	return (BI_SUCCESS);
}

int				bcd_add_digit(t_bigint *a, unsigned char digit, t_bigint *b)
{
	size_t			len;
	size_t			i;

	if (digit > 9)
		return (BI_SUCCESS);
	if (bi_copy(b, a) == BI_FAIL)
		return (BI_FAIL);
	if (digit == 0)
		return (BI_SUCCESS);
	len = bcd_len(b);
	i = 0;
	while (i < len)
	{
		digit = bcd_get_digit(b, i) + digit;
		bcd_set_digit(b, i, digit % 10);
		digit /= 10;
		i++;
	}
	if (digit && handle_last_carry(b, len) == BI_FAIL)
		return (BI_FAIL);
	bi_update_occupied(b);
	return (BI_SUCCESS);
}
