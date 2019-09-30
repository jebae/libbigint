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
void		test_bi_abs_compare_case1(void);
void		test_bi_abs_compare_case2(void);
void		test_bi_abs_compare_case3(void);
void		test_bi_abs_compare_case4(void);
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

/*
** bi_mul_pow_of_2 test
*/
void		test_bi_mul_pow_of_2_case1(void);
void		test_bi_mul_pow_of_2_case2(void);
void		test_bi_mul_pow_of_2_case3(void);
void		test_bi_mul_pow_of_2_case4(void);
void		test_bi_mul_pow_of_2_case5(void);
void		test_bi_mul_pow_of_2_case6(void);

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

/*
** bi_array test
*/
void		test_bi_to_bi_array_case1(void);
void		test_bi_to_bi_array_case2(void);
void		test_bi_to_bi_array_case3(void);

/*
** bi_mul_bi test
*/
void		test_bi_mul_get_block_length_case1(void);
void		test_bi_mul_get_block_length_case2(void);
void		test_bi_mul_get_block_length_case3(void);

#endif
