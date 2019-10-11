#include "bigint.h"

static t_bigint		*to_array_handle_fail(t_bigint *arr, size_t size)
{
	bi_del_bi_array(arr, size);
	return (NULL);
}

static int			to_bi_handle_fail(t_bigint *to_add)
{
	ft_memdel((void **)&(to_add->data));
	return (BI_FAIL);
}

void				bi_del_bi_array(t_bigint *arr, size_t size)
{
	size_t		i;

	i = 0;
	if (arr == NULL)
		return ;
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
			return (to_array_handle_fail(arr, size));
		bi_push(arr + i, bi->data[i]);
		i++;
	}
	while (i < size)
	{
		if (bi_new(arr + i, 1, BI_SIGN_POSITIVE) == BI_FAIL)
			return (to_array_handle_fail(arr, size));
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

	BI_HANDLE_FUNC_FAIL(bi_init(res, 1));
	BI_HANDLE_FUNC_FAIL(bi_new(&to_add, 1, BI_SIGN_POSITIVE));
	i = 0;
	while (i < size)
	{
		if (bi_left_shift(arr + i, BI_UNIT_BITS * i, &to_add) == BI_FAIL)
			return (to_bi_handle_fail(&to_add));
		if (bi_add_bi(res, &to_add, res) == BI_FAIL)
			return (to_bi_handle_fail(&to_add));
		i++;
	}
	ft_memdel((void **)&to_add.data);
	return (BI_SUCCESS);
}
