#ifndef BIGINT_H
# define BIGINT_H

# include "libft.h"

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
** basic function
*/
int					bi_new(t_bigint *bi, size_t size, char sign);
void				bi_erase(t_bigint *bi);
int					bi_expand(t_bigint *bi, size_t size);
int					bi_shrink(t_bigint *bi, size_t size);
int					bi_push(t_bigint *bi, char value);

/*
** operator utils
*/
int					bi_init(t_bigint *res, size_t size);
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

/*
** operator
*/
int					bi_negate(t_bigint *bi, size_t size);
int					bi_add_bi(t_bigint *a, t_bigint *b, t_bigint *c);
int					bi_sub_bi(t_bigint *a, t_bigint *b, t_bigint *c);

# endif
