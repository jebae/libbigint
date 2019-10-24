/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:00:12 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:00:14 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

int		bi_expand(t_bigint *bi, size_t size)
{
	unsigned char	*temp;

	if (size == 0)
		return (BI_SUCCESS);
	if ((temp = ft_memalloc(bi->size + size)) == NULL)
		return (BI_FAIL);
	ft_memcpy(temp, bi->data, bi->occupied);
	ft_memdel((void **)&bi->data);
	bi->data = temp;
	bi->size += size;
	return (BI_SUCCESS);
}
