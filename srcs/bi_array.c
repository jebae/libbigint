/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:59:59 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:06:49 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

static t_bigint		*to_array_handle_fail(t_bigint *arr, size_t size)
{
	bi_del_bi_array(arr, size);
	return (NULL);
}

static int			to_bi_handle_fail(t_bigint *to_add)
{
	bi_del(to_add);
	return (BI_FAIL);
}

void				bi_del_bi_array(t_bigint *arr, size_t size)
{
	size_t		i;

	if (arr == NULL)
		return ;
	i = 0;
	while (i < size)
		bi_del(&(arr[i++]));
	ft_memdel((void **)&arr);
}

t_bigint			*bi_to_bi_array(t_bigint *bi, size_t size)
{
	t_bigint	*arr;
	size_t		i;

	if (size == 0)
		return (NULL);
	if ((arr = ft_memalloc(sizeof(t_bigint) * size)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		bi_init(arr + i);
		if (bi_expand_at_least(&(arr[i++]), 1) == BI_FAIL)
			return (to_array_handle_fail(arr, size));
	}
	i = 0;
	while (i < bi->occupied && i < size)
	{
		arr[i].sign = bi->sign;
		if (bi->data[i])
			bi_push(arr + i, bi->data[i]);
		i++;
	}
	return (arr);
}

int					bi_array_to_bi(
	t_bigint *arr,
	size_t size,
	t_bigint *res
)
{
	size_t			i;
	t_bigint		to_add;

	if (bi_memalloc(res, 1) == BI_FAIL)
		return (BI_FAIL);
	bi_init(&to_add);
	i = 0;
	while (i < size)
	{
		if (bi_left_shift(arr + i, BI_UNIT_BITS * i, &to_add) == BI_FAIL)
			return (to_bi_handle_fail(&to_add));
		if (bi_add_bi(res, &to_add, res) == BI_FAIL)
			return (to_bi_handle_fail(&to_add));
		i++;
	}
	bi_del(&to_add);
	return (BI_SUCCESS);
}
