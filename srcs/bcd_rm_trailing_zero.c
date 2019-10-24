/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bcd_rm_trailing_zero.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:59:43 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 15:59:43 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

size_t		bcd_rm_trailing_zero(t_bigint *bcd)
{
	size_t		n;
	size_t		i;

	n = 0;
	i = 0;
	while (i < bcd->occupied && (bcd->data[i] & 0x0f) == 0)
	{
		n += 1;
		if (bcd->data[i] != 0)
			break ;
		n += 1;
		i++;
	}
	if (n)
		bi_right_shift(bcd, 4 * n, bcd);
	return (n);
}
