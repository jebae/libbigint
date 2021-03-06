/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:00:21 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 16:00:22 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

void		bi_init(t_bigint *bi)
{
	bi->data = NULL;
	bi->sign = BI_SIGN_POSITIVE;
	bi->size = 0;
	bi->occupied = 0;
}
