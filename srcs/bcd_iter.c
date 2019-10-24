/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bcd_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:59:37 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 15:59:38 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

void		bcd_iter(
	t_bigint *bcd,
	void (*f)(unsigned char, void *),
	void *arg
)
{
	size_t	len;

	len = bcd_len(bcd);
	while (len > 0)
		f(bcd_get_digit(bcd, --len), arg);
}
