#include "bigint.test.h"

int		main(void)
{
	// basic function
	test_bi_new_case1();
	test_bi_init_case1();

	char *mem = ft_memalloc(2);

	mem[0] = 0xb5;
	mem[1] = 0x3b;
	//short *ptr = (short *)mem;
	mem[0] <<= 1;
	for (int i=7; i >= 0; i--)
		printf("%c", (*mem & (1 << i) ? '1' : '0'));
}
