/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:00:31 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:00:31 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

int		bi_memalloc(t_bigint *bi, size_t size)
{
	if (bi->data != NULL && bi->size >= size)
	{
		bi_erase(bi);
		return (BI_SUCCESS);
	}
	bi_del(bi);
	if (size == 0)
		return (BI_SUCCESS);
	if ((bi->data = ft_memalloc(size)) == NULL)
		return (BI_FAIL);
	bi->size = size;
	return (BI_SUCCESS);
}
