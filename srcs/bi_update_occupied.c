/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_update_occupied.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:01:34 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:01:34 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

void			bi_update_occupied(t_bigint *bi)
{
	size_t		i;

	i = bi->size;
	while (i > 0 && bi->data[i - 1] == 0x00)
		i--;
	bi->occupied = i;
	if (bi->occupied == 0)
		bi->sign = BI_SIGN_POSITIVE;
}
