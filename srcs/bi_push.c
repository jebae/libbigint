/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:00:43 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:00:44 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

int		bi_push(t_bigint *bi, unsigned char data)
{
	if (bi->size == bi->occupied)
	{
		if (bi_expand(bi, 1) == BI_FAIL)
			return (BI_FAIL);
	}
	bi->data[bi->occupied] = data;
	(bi->occupied)++;
	return (BI_SUCCESS);
}
