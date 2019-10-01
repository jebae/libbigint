#include "bigint.h"

static t_bigint		*handle_fail(t_bigint *arr, size_t size)
{
	bi_del_bi_array(arr, size);
	return (NULL);
}

void				bi_del_bi_array(t_bigint *arr, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
		ft_memdel((void **)&(arr[i++].data));
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
		arr[i++].data = NULL;
	i = 0;
	while (i < bi->occupied && i < size)
	{
		if (bi_new(arr + i, 1, bi->sign) == BI_FAIL)
			return (handle_fail(arr, size));
		bi_push(&(arr[i]), bi->data[i]);
		i++;
	}
	while (i < size)
	{
		if (bi_new(arr + i, 1, BI_SIGN_POSITIVE) == BI_FAIL)
			return (handle_fail(arr, size));
		i++;
	}
	return (arr);
}

// array to bigint
