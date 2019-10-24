/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_op_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:00:41 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:00:41 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

unsigned char	bi_1byte_add_1byte(
	unsigned char a,
	unsigned char b,
	unsigned char *carry
)
{
	unsigned short		res;

	res = a + b + *carry;
	*carry = res >> 8;
	return ((unsigned char)res);
}

unsigned char	bi_add_byte_by_byte(
	t_bigint *bigger,
	t_bigint *smaller,
	t_bigint *res
)
{
	size_t			i;
	size_t			j;
	unsigned char	carry;

	i = 0;
	carry = 0x00;
	j = smaller->occupied;
	while (i < j)
	{
		res->data[i] =
			bi_1byte_add_1byte(smaller->data[i], bigger->data[i], &carry);
		i++;
	}
	j = bigger->occupied;
	while (i < j)
	{
		res->data[i] =
			bi_1byte_add_1byte(bigger->data[i], 0x00, &carry);
		i++;
	}
	res->occupied = i;
	return (carry);
}

unsigned char	bi_1byte_mul_1byte(
	unsigned char a,
	unsigned char b,
	unsigned char *carry
)
{
	unsigned short		res;

	res = a * b + *carry;
	*carry = res >> 8;
	return ((unsigned char)res);
}
