/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_get_bit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:00:19 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:06:00 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

int			bi_get_bit(t_bigint *bi, size_t n)
{
	unsigned char	byte;

	if (bi->occupied == 0)
		return (0);
	if (bi_max_bit(bi) <= n)
		return (0);
	byte = bi->data[n / BI_UNIT_BITS];
	return ((byte >> (n % BI_UNIT_BITS)) & 0x1);
}
