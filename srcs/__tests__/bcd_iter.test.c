#include "bigint.test.h"

static void	iter(unsigned char data, void *arg)
{
	unsigned char	*ptr;

	ptr = arg;
	*ptr += data;
}

// case 54321
void		test_bcd_iter_case1(void)
{
	printf(KYEL "test_bcd_iter_case1\n" KNRM);
	t_bigint		bcd;
	unsigned char	arg = 0;

	bi_init(&bcd);
	bi_push(&bcd, 0x21);
	bi_push(&bcd, 0x43);
	bi_push(&bcd, 0x05);

	bcd_iter(&bcd, &iter, (void *)&arg);

	test(
		arg == 15,
		"bcd_iter : arg"
	);

	bi_del(&bcd);
}
