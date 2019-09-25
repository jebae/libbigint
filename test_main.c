#include "bigint.test.h"

int		main(void)
{
	// basic function
	test_bi_new_case1();
	test_bi_erase_case1();
	test_bi_expand_case1();
	test_bi_push_case1();
	test_bi_push_case2();

	// op_utils
	test_bi_abs_compare_case1();
	test_bi_abs_compare_case2();
	test_bi_abs_compare_case3();
	test_bi_abs_compare_case4();

	// add
	test_bi_add_bi_case1();
	test_bi_add_bi_case2();
	test_bi_add_bi_case3();
}
