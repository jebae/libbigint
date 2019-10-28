# libbigint

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/315747e7d94d4c1e807462dc07249b09)](https://www.codacy.com/manual/jebae/libbigint?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=jebae/libbigint&amp;utm_campaign=Badge_Grade)

C library **libbigint** is made to handle big integer.

<br><br>

## Requirements

This library is using [libft](https://github.com/jebae/libft) as alternative of standard lib functions. So at first download or git clone libft and put it in same path with libbigint.

```
# download libft
git clone https://github.com/jebae/libft.git

# directory structure of libft and libbigint
root/
  libft/
  libbigint/
```

instead of put libft in same path with libbigint, you can modify [Makefile](./Makefile) macro `LIBFT_PATH = ../libft` with your libft path.

<br><br>

## Installation

```
make
```

<br><br>

## Usage

### struct
```c
typedef struct		s_bigint
{
	char			sign;
	size_t			size; // size of memory
	size_t			occupied; // size of memory which has meaningful value
	unsigned char		*data;
}			t_bigint;
```

<br><br>

### Memory
```c
void bi_init(t_bigint *bi);
int bi_memalloc(t_bigint *bi, size_t size);
```

`bi_init` initialize `t_bigint` variable as below.

```c
bi->data = NULL;
bi->sign = BI_SIGN_POSITIVE;
bi->size = 0;
bi->occupied = 0;
```

`t_bigint` is not fixed data like `int`, `char` and `long`. Dynamic memory is malloced to `t_bigint` and unlimited big integer can be implemented. Function `bi_memalloc` exists for this purpose. It returns `BI_FAIL` if there is error from memory allocating else `BI_SUCCESS`.

<br>

```c
void bi_erase(t_bigint *bi);
void bi_del(t_bigint *bi);
```

`bi_erase` set all data as 0 including `occupied`.

`bi_del` free memory of `t_bigint` and initialize it with `bi_init`.

<br>

```c
int bi_expand(t_bigint *bi, size_t size);
int bi_expand_at_least(t_bigint *bi, size_t size);
```

`bi_expand` expand memory of `bi`. For example, if `bi->size` is 2 and `bi_expand(bi, 1)` is called, `bi`'s size increased as 3 preserving data. It returns `BI_FAIL` if there is error from memory allocating else `BI_SUCCESS`.

`bi_expand_at_least` expand memory of `bi` but not bigger than `size`. If `bi->size` is equal or bigger than `size`, nothing happens. Data is preserved. It returns `BI_FAIL` if there is error from memory allocating else `BI_SUCCESS`.

<br>

```c
int bi_push(t_bigint *bi, unsigned char value);
```

`bi_push` push 1 byte data `value` to `bi` and increase 1 to `bi->occupied`. It returns `BI_FAIL` if there is error from memory allocating else `BI_SUCCESS`.

<br><br>

## Operation

```c
// a + b = c
int bi_add_bi(t_bigint *a, t_bigint *b, t_bigint *c);

// a - b = c
int bi_sub_bi(t_bigint *a, t_bigint *b, t_bigint *c);

// bi * factor = res
int bi_mul_1byte(t_bigint *bi, unsigned char factor, t_bigint *res);

// a * b = c
int bi_mul_bi(t_bigint *a, t_bigint *b, t_bigint *c);

// bi % (2^n + 1) = res
int bi_mod_n_pow_of_2_plus_1(t_bigint *bi, size_t n, t_bigint *res);

// |bi| = res
int bi_abs(t_bigint *bi, t_bigint *res);

// bi << n = res
int bi_left_shift(t_bigint *bi, size_t n, t_bigint *res);

// bi >> n = res
int bi_right_shift(t_bigint *bi, size_t n, t_bigint *res);
```

All operation functions returns `BI_FAIL` if there is error from memory allocating else `BI_SUCCESS`.

<br><br>

## Array convert
```c
// array convert
t_bigint *bi_to_bi_array(t_bigint *bi, size_t size);
int bi_array_to_bi(t_bigint *arr, size_t size, t_bigint *res);
void bi_del_bi_array(t_bigint *arr, size_t size);
```

`bi_to_bi_array` convert `bi->data` to `t_bigint` array. It returns `NULL` if there is error from memory allocating. 

`bi_array_to_bi` convert array of `t_bigint` to single `t_bigint`. It returns `BI_FAIL` if there is error from memory allocating else `BI_SUCCESS`. `bi_del_bi_array` free memory of array.

<br><br>

## BCD (binary-coded decimal)

```c
// bin -> bcd
int bi_double_dabble(t_bigint *bin, t_bigint *bcd);

// bcd -> bin
int bi_rev_double_dabble(t_bigint *bcd, t_bigint *bin);
```

`bi_double_dabble` and `bi_rev_double_dabble` returns `BI_FAIL` if there is error from memory allocating else `BI_SUCCESS`.

<br>

```c
size_t bcd_len(t_bigint *bcd);
```

`bcd_len` returns length of BCD `bcd`.

<br>

```c
unsigned char bcd_get_digit(t_bigint *bcd, size_t n);
void bcd_set_digit(t_bigint *bcd, size_t n, unsigned char val);
```

`bcd_get_digit` returns nth digit of `bcd`.
`bcd_set_digit` set nth digit of `bcd` as `val`

<br>

```c
size_t bcd_rm_trailing_zero(t_bigint *bcd);
```

`bcd_rm_trailing_zero` remove trailing zero. e.g. 12000 -> 12. It returns number of 0 that have removed.

<br>

```c
int bcd_round(t_bigint *bcd, size_t pos, t_bigint *res);
```

`bcd_round` round bcd from `pos` digit. e.g. bcd_round(12345, 1) = 12350. It returns `BI_FAIL` if there is error from memory allocating else `BI_SUCCESS`.

<br>

```c
void bcd_iter(
	t_bigint *bcd,
	void (*f)(unsigned char, void *),
	void *arg
);
```

`bcd_iter` call function `f` with every `unsigned char` value of `bcd->data`. Function `f` receive one element of `bcd->data` and `arg` as parameter.

<br>

```c
// a + digit = b
int bcd_add_digit(t_bigint *a, unsigned char digit, t_bigint *b);
```

`bcd_add_digit` returns `BI_FAIL` if there is error from memory allocating else `BI_SUCCESS`.

<br><br>

## utils

```c
size_t bi_max_bit(t_bigint *bi);
int bi_copy(t_bigint *dst, t_bigint *src);
void bi_abs_compare(
	t_bigint *a,
	t_bigint *b,
	t_bigint **bigger,
	t_bigint **smaller
);
unsigned char bi_1byte_add_1byte(
	unsigned char a,
	unsigned char b,
	unsigned char *carry
);
unsigned char bi_add_byte_by_byte(
	t_bigint *bigger,
	t_bigint *smaller,
	t_bigint *res
);
void bi_update_occupied(t_bigint *bi);
unsigned char bi_1byte_mul_1byte(
	unsigned char a,
	unsigned char b,
	unsigned char *carry
);
int bi_get_bit(t_bigint *bi, size_t n);
void bi_set_bit(t_bigint *bi, size_t n, int value);
```