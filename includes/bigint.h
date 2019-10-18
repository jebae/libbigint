#ifndef BIGINT_H
# define BIGINT_H

# include "libft.h"
# include <stdio.h>

# define BI_SUCCESS				0
# define BI_FAIL				1
# define BI_SIGN_POSITIVE		0
# define BI_SIGN_NEGATIVE		1

# define BI_HANDLE_FUNC_FAIL(F) if ((F) == BI_FAIL) return (BI_FAIL)
# define BI_UNIT_BITS			8

typedef struct		s_bigint
{
	char			sign;
	size_t			size;
	size_t			occupied;
	unsigned char	*data;
}					t_bigint;

typedef struct		s_bi_strassen_mul_fft_vars
{
	size_t		m;
	size_t		m2;
	size_t		em;
	t_bigint	t;
}					t_bi_strassen_mul_fft_vars;

/*
** memory management
*/
int					bi_memalloc(t_bigint *bi, size_t size);
void				bi_init(t_bigint *bi);
void				bi_del(t_bigint *bi);
void				bi_erase(t_bigint *bi);
int					bi_expand(t_bigint *bi, size_t size);
int					bi_expand_at_least(t_bigint *bi, size_t size);
int					bi_push(t_bigint *bi, unsigned char value);

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
unsigned char		bi_1byte_add_1byte(
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
unsigned char		bi_1byte_mul_1byte(
	unsigned char a,
	unsigned char b,
	unsigned char *carry
);
int					bi_get_bit(t_bigint *bi, size_t n);
void				bi_set_bit(t_bigint *bi, size_t n, int value);

/*
** add
*/
int					bi_add_bi(t_bigint *a, t_bigint *b, t_bigint *c);

/*
** subtract
*/
int					bi_sub_bi(t_bigint *a, t_bigint *b, t_bigint *c);

/*
** abs
*/
int					bi_abs(t_bigint *bi, t_bigint *res);

/*
** multiply 2^n
*/
int					bi_left_shift(t_bigint *bi, size_t n, t_bigint *res);

/*
** divide by 2^n
*/
int					bi_right_shift(t_bigint *bi, size_t n, t_bigint *res);

/*
** modulo 2^n + 1
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
** array
*/
t_bigint			*bi_to_bi_array(t_bigint *bi, size_t size);
void				bi_del_bi_array(t_bigint *arr, size_t size);
int					bi_array_to_bi(
	t_bigint *arr,
	size_t size, 
	t_bigint *res
);

/*
** multiply
*/
int					bi_mul_1byte(
	t_bigint *bi,
	unsigned char factor,
	t_bigint *res
);
int					bi_mul_bi(t_bigint *a, t_bigint *b, t_bigint *c);

/*
** strassen multiply
*/
size_t				bi_strassen_mul_get_block_length(t_bigint *a, t_bigint *b);
int					bi_strassen_mul_shuffle_order(t_bigint *arr, size_t size);
int					bi_strassen_mul_pointwise_prod(
	t_bigint *a_arr,
	t_bigint *b_arr,
	size_t n
);
void				bi_strassen_invsere_array(t_bigint *arr, size_t n);
int					bi_strassen_mul_bi(t_bigint *a, t_bigint *b, t_bigint *c);

/*
** double dabble
*/
int					bi_double_dabble(t_bigint *bin, t_bigint *bcd);
int             	bi_rev_double_dabble(t_bigint *bcd, t_bigint *bin);

/*
** bcd
*/
size_t				bcd_len(t_bigint *bcd);
unsigned char		bcd_get_digit(t_bigint *bcd, size_t n);
void				bcd_set_digit(t_bigint *bcd, size_t n, unsigned char val);
size_t				bcd_rm_trailing_zero(t_bigint *bcd);
void				bcd_iter(
	t_bigint *bcd,
	void (*f)(unsigned char, void *),
	void *arg
);

#endif
