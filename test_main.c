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
	test_bi_copy_case2();
	test_bi_abs_compare_case1();
	test_bi_abs_compare_case2();
	test_bi_abs_compare_case3();
	test_bi_abs_compare_case4();
	test_bi_abs_compare_case5();
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
	test_bi_sub_bi_case13();
	test_bi_sub_bi_case14();
	test_bi_sub_bi_case15();
	test_bi_sub_bi_case16();
	test_bi_sub_bi_case17();

	// mul pow of 2
	test_bi_left_shift_case1();
	test_bi_left_shift_case2();
	test_bi_left_shift_case3();
	test_bi_left_shift_case4();
	test_bi_left_shift_case5();
	test_bi_left_shift_case6();
	test_bi_left_shift_case7();

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
	test_bi_mod_n_pow_of_2_plus_1_case15();
	test_bi_mod_n_pow_of_2_plus_1_case16();
	test_bi_mod_n_pow_of_2_plus_1_case17();

	// array
	test_bi_to_bi_array_case1();
	test_bi_to_bi_array_case2();
	test_bi_to_bi_array_case3();
	test_bi_to_bi_array_case4();
	test_bi_array_to_bi_case1();
	test_bi_array_to_bi_case2();

	// bi_mul
	test_bi_mul_1byte_case1();
	test_bi_mul_1byte_case2();
	test_bi_mul_1byte_case3();
	test_bi_mul_1byte_case4();
	test_bi_mul_bi_case1();
	test_bi_mul_bi_case2();
	test_bi_mul_bi_case3();
	test_bi_mul_bi_case4();
	test_bi_mul_bi_case5();
	test_bi_mul_bi_case6();
	test_bi_mul_bi_case7();
	test_bi_mul_bi_case8();
	test_bi_mul_bi_case9();
	test_bi_mul_bi_case10();
	test_bi_mul_bi_case11();
	test_bi_mul_bi_case12();
	test_bi_mul_bi_case13();

	// bi_strassen_mul_bi
	test_bi_strassen_mul_get_block_length_case1();
	test_bi_strassen_mul_get_block_length_case2();
	test_bi_strassen_mul_get_block_length_case3();
	test_bi_strassen_mul_shuffle_order_case1();
	test_bi_strassen_mul_shuffle_order_case2();
	test_bi_strassen_mul_shuffle_order_case3();
	test_bi_strassen_mul_pointwise_prod_case1();
	test_bi_strassen_mul_inverse_array_case1();
	test_bi_strassen_mul_bi_case1();
	test_bi_strassen_mul_bi_case2();
	test_bi_strassen_mul_bi_case3();
	test_bi_strassen_mul_bi_case4();
	test_bi_strassen_mul_bi_case5();
	test_bi_strassen_mul_bi_case6();
	test_bi_strassen_mul_bi_case7();
	test_bi_strassen_mul_bi_case8();
	test_bi_strassen_mul_bi_case9();
	test_bi_strassen_mul_bi_case10();
	test_bi_strassen_mul_bi_case11();
	test_bi_strassen_mul_bi_case12();
	test_bi_strassen_mul_bi_case13();

	// div pow of 2
	test_bi_right_shift_case1();
	test_bi_right_shift_case2();
	test_bi_right_shift_case3();
	test_bi_right_shift_case4();
	test_bi_right_shift_case5();
	test_bi_right_shift_case6();
	test_bi_right_shift_case7();

	// bi_get_bit
	test_bi_get_bit_case1();
	test_bi_get_bit_case2();
	test_bi_get_bit_case3();

	// double dabble
	test_bi_double_dabble_case1();
	test_bi_double_dabble_case2();
	test_bi_double_dabble_case3();
	test_bi_double_dabble_case4();

	// bi_set_bit
	test_bi_set_bit_case1();
	test_bi_set_bit_case2();
	test_bi_set_bit_case3();

	// reverse double dabble
	test_bi_rev_double_dabble_case1();
	test_bi_rev_double_dabble_case2();
	test_bi_rev_double_dabble_case3();
	test_bi_rev_double_dabble_case4();
	// while (1);
}
