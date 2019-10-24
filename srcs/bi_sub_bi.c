/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_sub_bi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:01:31 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:01:32 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

static int		set_mem(t_bigint *bi, size_t size, int mutable)
{
	int		(*f)(t_bigint *, size_t);

	if (mutable)
		f = &bi_expand_at_least;
	else
		f = &bi_memalloc;
	if (f(bi, size) == BI_FAIL)
		return (BI_FAIL);
	return (BI_SUCCESS);
}

static int		set_negate_data(t_bigint *bi, size_t size)
{
	unsigned char	*negate;

	if ((negate = ft_memalloc(size)) == NULL)
		return (BI_FAIL);
	ft_memcpy(negate, bi->data, bi->occupied);
	ft_memnegate(negate, size);
	bi->data = negate;
	bi->occupied = size;
	return (BI_SUCCESS);
}

static int		pass_to_add(t_bigint *a, t_bigint *b, t_bigint *c)
{
	char	sign;

	sign = b->sign;
	b->sign ^= 1;
	if (bi_add_bi(a, b, c) == BI_FAIL)
	{
		b->sign ^= 1;
		return (BI_FAIL);
	}
	b->sign ^= 1;
	return (BI_SUCCESS);
}

static char		get_sign(t_bigint *a, t_bigint *bigger)
{
	if (bigger == a)
	{
		if (bigger->sign == BI_SIGN_POSITIVE)
			return (BI_SIGN_POSITIVE);
		else
			return (BI_SIGN_NEGATIVE);
	}
	else
	{
		if (bigger->sign == BI_SIGN_POSITIVE)
			return (BI_SIGN_NEGATIVE);
		else
			return (BI_SIGN_POSITIVE);
	}
}

int				bi_sub_bi(t_bigint *a, t_bigint *b, t_bigint *c)
{
	int				mutable;
	t_bigint		*bigger;
	t_bigint		*smaller;
	t_bigint		temp;

	if (a->sign != b->sign)
		return (pass_to_add(a, b, c));
	bi_abs_compare(a, b, &bigger, &smaller);
	mutable = (c == a || c == b);
	if (set_mem(c, bigger->occupied, mutable) == BI_FAIL)
		return (BI_FAIL);
	c->sign = get_sign(a, bigger);
	temp = *smaller;
	if (set_negate_data(&temp, bigger->occupied) == BI_FAIL)
		return (BI_FAIL);
	bi_add_byte_by_byte(bigger, &temp, c);
	bi_update_occupied(c);
	bi_del(&temp);
	return (BI_SUCCESS);
}
