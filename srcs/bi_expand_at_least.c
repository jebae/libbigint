/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_expand_at_least.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:00:16 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:00:17 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

int		bi_expand_at_least(t_bigint *bi, size_t size)
{
	if (bi->size >= size)
		return (BI_SUCCESS);
	if (bi_expand(bi, size - bi->size) == BI_FAIL)
		return (BI_FAIL);
	return (BI_SUCCESS);
}
