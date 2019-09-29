#include "bigint.test.h"

int		main(void)
{
	// memory management
	test_bi_new_case1();
	test_bi_erase_case1();
	test_bi_expand_case1();
	test_bi_resize_case1();
	test_bi_resize_case2();
	test_bi_push_case1();
	test_bi_push_case2();
	test_bi_expand_at_least_case1();
	test_bi_expand_at_least_case2();

	// op_utils
	test_bi_copy_case1();
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
	test_bi_add_bi_case10();
	test_bi_add_bi_case11();

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
	test_bi_sub_bi_case11();
	test_bi_sub_bi_case12();

	// pow of 2
	test_bi_mul_pow_of_2_case1();
	test_bi_mul_pow_of_2_case2();
	test_bi_mul_pow_of_2_case3();
	test_bi_mul_pow_of_2_case4();
	test_bi_mul_pow_of_2_case5();
	test_bi_mul_pow_of_2_case6();

	// abs
	test_bi_abs_case1();
	test_bi_abs_case2();

	// bi_mod_n_pow_of_2_plus_1
	test_bi_mod_n_pow_of_2_plus_1_case1();
	test_bi_mod_n_pow_of_2_plus_1_case2();
	test_bi_mod_n_pow_of_2_plus_1_case3();
	test_bi_mod_n_pow_of_2_plus_1_case4();
	test_bi_mod_n_pow_of_2_plus_1_case5();
	test_bi_mod_n_pow_of_2_plus_1_case6();
	test_bi_mod_n_pow_of_2_plus_1_case7();
	test_bi_mod_n_pow_of_2_plus_1_case8();
	test_bi_mod_n_pow_of_2_plus_1_case9();
	test_bi_mod_n_pow_of_2_plus_1_case10();
	test_bi_mod_n_pow_of_2_plus_1_case11();
	test_bi_mod_n_pow_of_2_plus_1_case12();
	test_bi_mod_n_pow_of_2_plus_1_case13();
	test_bi_mod_n_pow_of_2_plus_1_case14();
}
