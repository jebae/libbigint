#ifndef BIGINT_H
# define BIGINT_H

# include "libft.h"
# include <stdio.h>

# define BI_SUCCESS				0
# define BI_FAIL				1
# define BI_SIGN_POSITIVE		1
# define BI_SIGN_NEGATIVE		0

typedef struct		s_bigint
{
	char			sign;
	size_t			size;
	size_t			occupied;
	unsigned char	*data;
}					t_bigint;

/*
** memory management
*/
int					bi_new(t_bigint *bi, size_t size, char sign);
int					bi_init(t_bigint *res, size_t size);
void				bi_erase(t_bigint *bi);
int					bi_expand(t_bigint *bi, size_t size);
int					bi_expand_at_least(t_bigint *bi, size_t size);
int					bi_resize(t_bigint *bi, size_t size);
int					bi_push(t_bigint *bi, char value);

/*
** operator utils
*/
size_t				bi_max_bit(t_bigint *bi);
int					bi_copy(t_bigint *dst, t_bigint *src);
void				bi_abs_compare(
	t_bigint *a,
	t_bigint *b,
	t_bigint **bigger,
	t_bigint **smaller
);
unsigned char		bi_add_one_byte(
	unsigned char a,
	unsigned char b,
	unsigned char *carry
);
unsigned char		bi_add_byte_by_byte(
	t_bigint *bigger,
	t_bigint *smaller,
	t_bigint *res
);
void				bi_update_occupied(t_bigint *bi);

/*
** operator
*/
int					bi_add_bi(t_bigint *a, t_bigint *b, t_bigint *c);
int					bi_sub_bi(t_bigint *a, t_bigint *b, t_bigint *c);
int					bi_abs(t_bigint *bi, t_bigint *res);
int					bi_mul_pow_of_2(t_bigint *bi, size_t n, t_bigint *res);

/*
** mod_n_pow_of_2_plus_1
*/

int					bi_mod_n_pow_of_2_plus_1_handle_fail(
	t_bigint *p,
	t_bigint *q
);
int					bi_mod_n_pow_of_2_plus_1_handle_0(
	t_bigint *bi,
	t_bigint *res
);
int					bi_mod_n_pow_of_2_plus_1(
	t_bigint *bi,
	size_t n,
	t_bigint *res
);

/*
** bi_array
*/
t_bigint			*bi_to_bi_array(t_bigint *bi, size_t size);
void				bi_del_bi_array(t_bigint *arr, size_t size);

/*
** bi_mul_bi
*/
size_t				bi_mul_get_block_length(t_bigint *a, t_bigint *b);

# endif
