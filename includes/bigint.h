#ifndef BIGINT_H
# define BIGINT_H

# include "libft.h"

typedef struct		s_bigint
{
	char			*data;
	size_t			size;
}					t_bigint;

t_bigint			bi_new(size_t size);
void				bi_init(t_bigint *bi);

# endif
