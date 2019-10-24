/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_add_bi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:59:56 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 15:59:57 by jebae            ###   ########.fr       */
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

static int		pass_to_sub(t_bigint *a, t_bigint *b, t_bigint *c)
{
	char	sign;

	sign = b->sign;
	b->sign ^= 1;
	if (bi_sub_bi(a, b, c) == BI_FAIL)
	{
		b->sign ^= 1;
		return (BI_FAIL);
	}
	b->sign ^= 1;
	return (BI_SUCCESS);
}

static char		get_sign(t_bigint *a, t_bigint *b)
{
	if (a->occupied == 0 && b->occupied == 0)
		return (BI_SIGN_POSITIVE);
	else if (a->occupied == 0)
		return (b->sign);
	else
		return (a->sign);
}

int				bi_add_bi(t_bigint *a, t_bigint *b, t_bigint *c)
{
	unsigned char	carry;
	t_bigint		*bigger;
	t_bigint		*smaller;

	if (a->sign != b->sign)
		return (pass_to_sub(a, b, c));
	bi_abs_compare(a, b, &bigger, &smaller);
	if (set_mem(c, bigger->occupied, (c == a || c == b)) == BI_FAIL)
		return (BI_FAIL);
	c->sign = get_sign(a, b);
	carry = bi_add_byte_by_byte(bigger, smaller, c);
	if (carry && bi_push(c, carry) == BI_FAIL)
		return (BI_FAIL);
	return (BI_SUCCESS);
}
