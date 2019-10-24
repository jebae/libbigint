/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:59:51 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 15:59:52 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

int		bi_abs(t_bigint *bi, t_bigint *res)
{
	if (bi != res && bi_copy(res, bi) == BI_FAIL)
		return (BI_FAIL);
	res->sign = BI_SIGN_POSITIVE;
	return (BI_SUCCESS);
}
