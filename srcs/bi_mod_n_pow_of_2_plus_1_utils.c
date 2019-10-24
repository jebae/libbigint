/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_mod_n_pow_of_2_plus_1_utils.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:00:36 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:03:13 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

int		bi_mod_n_pow_of_2_plus_1_handle_fail(t_bigint *p, t_bigint *q)
{
	ft_memdel((void **)(p->data));
	ft_memdel((void **)(q->data));
	return (BI_FAIL);
}

int		bi_mod_n_pow_of_2_plus_1_handle_0(t_bigint *bi, t_bigint *res)
{
	unsigned char	first_one_byte;

	if (bi->occupied == 0)
		bi_erase(res);
	else
	{
		first_one_byte = bi->data[0];
		bi_erase(res);
		if (!(first_one_byte & 0x01))
			return (BI_SUCCESS);
		bi_push(res, 0x01);
	}
	return (BI_SUCCESS);
}
