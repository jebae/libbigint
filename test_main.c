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
	test_bi_max_bit_case1();
	test_bi_max_bit_case2();
	test_bi_max_bit_case3();

	// add
	test_bi_add_bi_case1();
	test_bi_add_bi_case2();
	test_bi_add_bi_case3();
	test_bi_add_bi_case4();
	test_bi_add_bi_case5();
	test_bi_add_bi_case6();
	test_bi_add_bi_case7();
	test_bi_add_bi_case8();
	test_bi_add_bi_case9();

	// sub
	test_bi_sub_bi_case1();
	test_bi_sub_bi_case2();
	test_bi_sub_bi_case3();
	test_bi_sub_bi_case4();
	test_bi_sub_bi_case5();
	test_bi_sub_bi_case6();
	test_bi_sub_bi_case7();
	test_bi_sub_bi_case8();
	test_bi_sub_bi_case9();
	test_bi_sub_bi_case10();

	// pow of 2
	test_bi_mul_pow_of_2_case1();
	test_bi_mul_pow_of_2_case2();
	test_bi_mul_pow_of_2_case3();
	test_bi_mul_pow_of_2_case4();
}
