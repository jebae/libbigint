#include "bigint.h"

static int	copy_arr(t_bigint *arr, t_bigint **copy, size_t size)
{
	size_t		i;

	if ((*copy = ft_memalloc(sizeof(t_bigint) * size)) == NULL)
		return (BI_FAIL);
	i = 0;
	while (i < size)
	{
		(*copy)[i] = arr[i];
		i++;
	}
	return (BI_SUCCESS);
}

size_t		bi_mul_get_block_length(t_bigint *a, t_bigint *b)
{
	static size_t	unit_bits = 8;
	size_t			length;
	size_t			min;

	length = 32;
	min = bi_max_bit(a) + bi_max_bit(b);
	min = min / unit_bits + ((min % unit_bits) ? 1 : 0);
	while (length < min)
		length <<= 1;
	return (length);
}

int			bi_mul_shuffle_order(t_bigint *arr, size_t size)
{
	size_t		num_bits;
	size_t		i;
	t_bigint	*copy;

	if (size == 0)
		return (BI_SUCCESS);
	if (copy_arr(arr, &copy, size) == BI_FAIL)
		return (BI_FAIL);
	num_bits = ft_int_log2(size);
	i = 0;
	while (i < size)
	{
		arr[i] = copy[ft_bit_reverse(i, num_bits)];
		i++;
	}
	ft_memdel((void **)&copy);
	return (BI_SUCCESS);
}
