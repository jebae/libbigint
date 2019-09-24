#ifndef BIGINT_H
# define BIGINT_H

# include "libft.h"

# define BI_SUCCESS				0
# define BI_FAIL				1

typedef struct		s_bigint
{
	size_t			size;
	size_t			occupied;
	unsigned char	*data;
}					t_bigint;

int					bi_new(t_bigint *bi, size_t size);
void				bi_erase(t_bigint *bi);
int					bi_expand(t_bigint *bi, size_t size);
int					bi_push(t_bigint *bi, char value);

# endif
