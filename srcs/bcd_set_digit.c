/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bcd_set_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:59:48 by jebae             #+#    #+#             */
/*   Updated: 2019/10/27 00:51:11 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

void		bcd_set_digit(t_bigint *bcd, size_t n, unsigned char val)
{
	unsigned char	*byte;

	if (bcd->size * 2 < n + 1 || val > 9)
		return ;
	byte = bcd->data + n / 2;
	if (n & 1)
	{
		*byte = (*byte & 0x0f) | (val << 4);
		return ;
	}
	*byte = (*byte & 0xf0) | val;
}
