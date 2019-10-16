#ifndef BIGINT_TEST_H
# define BIGINT_TEST_H

# include "bigint.h"
# include <stdio.h>

void		test(int res, const char *msg);

/*
** memory management test
*/
void		test_bi_new_case1(void);
void		test_bi_erase_case1(void);
void		test_bi_expand_case1(void);
void		test_bi_resize_case1(void);
void		test_bi_resize_case2(void);
void		test_bi_push_case1(void);
void		test_bi_push_case2(void);
void		test_bi_expand_at_least_case1(void);
void		test_bi_expand_at_least_case2(void);

/*
** operator utils test
*/
void		test_bi_copy_case1(void);
void		test_bi_copy_case2(void);
void		test_bi_abs_compare_case1(void);
void		test_bi_abs_compare_case2(void);
void		test_bi_abs_compare_case3(void);
void		test_bi_abs_compare_case4(void);
void		test_bi_abs_compare_case5(void);
void		test_bi_max_bit_case1(void);
void		test_bi_max_bit_case2(void);
void		test_bi_max_bit_case3(void);

/*
** bi_add_bi test
*/
void		test_bi_add_bi_case1(void);
void		test_bi_add_bi_case2(void);
void		test_bi_add_bi_case3(void);
void		test_bi_add_bi_case4(void);
void		test_bi_add_bi_case5(void);
void		test_bi_add_bi_case6(void);
void		test_bi_add_bi_case7(void);
void		test_bi_add_bi_case8(void);
void		test_bi_add_bi_case9(void);
void		test_bi_add_bi_case10(void);
void		test_bi_add_bi_case11(void);

/*
** bi_sub_bi test
*/
void		test_bi_sub_bi_case1(void);
void		test_bi_sub_bi_case2(void);
void		test_bi_sub_bi_case3(void);
void		test_bi_sub_bi_case4(void);
void		test_bi_sub_bi_case5(void);
void		test_bi_sub_bi_case6(void);
void		test_bi_sub_bi_case7(void);
void		test_bi_sub_bi_case8(void);
void		test_bi_sub_bi_case9(void);
void		test_bi_sub_bi_case10(void);
void		test_bi_sub_bi_case11(void);
void		test_bi_sub_bi_case12(void);
void		test_bi_sub_bi_case13(void);
void		test_bi_sub_bi_case14(void);
void		test_bi_sub_bi_case15(void);
void		test_bi_sub_bi_case16(void);
void		test_bi_sub_bi_case17(void);

/*
** bi_left_shift test
*/
void		test_bi_left_shift_case1(void);
void		test_bi_left_shift_case2(void);
void		test_bi_left_shift_case3(void);
void		test_bi_left_shift_case4(void);
void		test_bi_left_shift_case5(void);
void		test_bi_left_shift_case6(void);
void		test_bi_left_shift_case7(void);

/*
** bi_right_shift test
*/
void		test_bi_right_shift_case1(void);
void		test_bi_right_shift_case2(void);
void		test_bi_right_shift_case3(void);
void		test_bi_right_shift_case4(void);
void		test_bi_right_shift_case5(void);
void		test_bi_right_shift_case6(void);
void		test_bi_right_shift_case7(void);

/*
** bi_abs test
*/
void		test_bi_abs_case1(void);
void		test_bi_abs_case2(void);

/*
** bi_mod_n_pow_of_2_plus_1 test
*/
void		test_bi_mod_n_pow_of_2_plus_1_case1(void);
void		test_bi_mod_n_pow_of_2_plus_1_case2(void);
void		test_bi_mod_n_pow_of_2_plus_1_case3(void);
void		test_bi_mod_n_pow_of_2_plus_1_case4(void);
void		test_bi_mod_n_pow_of_2_plus_1_case5(void);
void		test_bi_mod_n_pow_of_2_plus_1_case6(void);
void		test_bi_mod_n_pow_of_2_plus_1_case7(void);
void		test_bi_mod_n_pow_of_2_plus_1_case8(void);
void		test_bi_mod_n_pow_of_2_plus_1_case9(void);
void		test_bi_mod_n_pow_of_2_plus_1_case10(void);
void		test_bi_mod_n_pow_of_2_plus_1_case11(void);
void		test_bi_mod_n_pow_of_2_plus_1_case12(void);
void		test_bi_mod_n_pow_of_2_plus_1_case13(void);
void		test_bi_mod_n_pow_of_2_plus_1_case14(void);
void		test_bi_mod_n_pow_of_2_plus_1_case15(void);
void		test_bi_mod_n_pow_of_2_plus_1_case16(void);
void		test_bi_mod_n_pow_of_2_plus_1_case17(void);

/*
** bi_array test
*/
void		test_bi_to_bi_array_case1(void);
void		test_bi_to_bi_array_case2(void);
void		test_bi_to_bi_array_case3(void);
void		test_bi_to_bi_array_case4(void);
void		test_bi_array_to_bi_case1(void);
void		test_bi_array_to_bi_case2(void);

/*
** bi_strassen_mul_bi test
*/
void		test_bi_strassen_mul_get_block_length_case1(void);
void		test_bi_strassen_mul_get_block_length_case2(void);
void		test_bi_strassen_mul_get_block_length_case3(void);
void		test_bi_strassen_mul_shuffle_order_case1(void);
void		test_bi_strassen_mul_shuffle_order_case2(void);
void		test_bi_strassen_mul_shuffle_order_case3(void);
void		test_bi_strassen_mul_pointwise_prod_case1(void);
void		test_bi_strassen_mul_inverse_array_case1(void);
void		test_bi_strassen_mul_bi_case1(void);
void		test_bi_strassen_mul_bi_case2(void);
void		test_bi_strassen_mul_bi_case3(void);
void		test_bi_strassen_mul_bi_case4(void);
void		test_bi_strassen_mul_bi_case5(void);
void		test_bi_strassen_mul_bi_case6(void);
void		test_bi_strassen_mul_bi_case7(void);
void		test_bi_strassen_mul_bi_case8(void);
void		test_bi_strassen_mul_bi_case9(void);
void		test_bi_strassen_mul_bi_case10(void);
void		test_bi_strassen_mul_bi_case11(void);
void		test_bi_strassen_mul_bi_case12(void);
void		test_bi_strassen_mul_bi_case13(void);
void		test_bi_strassen_mul_bi_case0(void);

/*
** bi_mul_bi test
*/
void		test_bi_mul_1byte_case1(void);
void		test_bi_mul_1byte_case2(void);
void		test_bi_mul_1byte_case3(void);
void		test_bi_mul_1byte_case4(void);
void		test_bi_mul_bi_case1(void);
void		test_bi_mul_bi_case2(void);
void		test_bi_mul_bi_case3(void);
void		test_bi_mul_bi_case4(void);
void		test_bi_mul_bi_case5(void);
void		test_bi_mul_bi_case6(void);
void		test_bi_mul_bi_case7(void);
void		test_bi_mul_bi_case8(void);
void		test_bi_mul_bi_case9(void);
void		test_bi_mul_bi_case10(void);
void		test_bi_mul_bi_case11(void);
void		test_bi_mul_bi_case12(void);
void		test_bi_mul_bi_case13(void);

/*
** bi_get_bit test
*/
void		test_bi_get_bit_case1(void);
void		test_bi_get_bit_case2(void);
void		test_bi_get_bit_case3(void);

/*
** double dabble test
*/
void		test_bi_double_dabble_case1(void);
void		test_bi_double_dabble_case2(void);
void		test_bi_double_dabble_case3(void);
void		test_bi_double_dabble_case4(void);

/*
** bi_set_bit test
*/
void		test_bi_set_bit_case1(void);
void		test_bi_set_bit_case2(void);
void		test_bi_set_bit_case3(void);

/*
** reverse double dabble test
*/
void		test_bi_rev_double_dabble_case1(void);
void		test_bi_rev_double_dabble_case2(void);
void		test_bi_rev_double_dabble_case3(void);
void		test_bi_rev_double_dabble_case4(void);

/*
* bcd_len test
*/
void		test_bcd_len_case1(void);
void		test_bcd_len_case2(void);
void		test_bcd_len_case3(void);
void		test_bcd_len_case4(void);
void		test_bcd_len_case5(void);

/*
* bcd_get_digit test
*/
void		test_bcd_get_digit_case1(void);
void		test_bcd_get_digit_case2(void);

/*
* bcd_set_digit test
*/
void		test_bcd_set_digit_case1(void);
void		test_bcd_set_digit_case2(void);
void		test_bcd_set_digit_case3(void);

#endif
