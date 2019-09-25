#include "bigint.h"

int				bi_sub_bi(t_bigint *a, t_bigint *b, t_bigint *c)
{
	size_t			temp_occupied;
	t_bigint		*bigger;
	t_bigint		*smaller;

	bi_abs_compare(a, b, &bigger, &smaller);
	if (bi_init(c, bigger->occupied) == BI_FAIL)
		return (BI_FAIL);
	if (bigger->occupied == 0) // handle 0
		return (BI_SUCCESS);
	temp_occupied = smaller->occupied;
	if (bi_negate(smaller, bigger->occupied) == BI_FAIL)
		return (BI_FAIL);
	bi_add_byte_by_byte(bigger, smaller, c);
	// need update new occupied
	return (BI_SUCCESS);
}
