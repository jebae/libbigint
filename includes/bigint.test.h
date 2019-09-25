#ifndef BIGINT_TEST_H
# define BIGINT_TEST_H

# include "bigint.h"
# include <stdio.h>

void		test(int res, const char *msg);

/*
** basic function test
*/
void		test_bi_new_case1(void);
void		test_bi_erase_case1(void);
void		test_bi_expand_case1(void);
void		test_bi_push_case1(void);
void		test_bi_push_case2(void);
void		test_bi_plus_bi_case1(void);
void		test_bi_plus_bi_case2(void);

/*
** op_utils test
*/
void		test_bi_abs_compare_case1(void);
void		test_bi_abs_compare_case2(void);
void		test_bi_abs_compare_case3(void);
void		test_bi_abs_compare_case4(void);

/*
** bi_add_bi test
*/
void		test_bi_add_bi_case1(void);
void		test_bi_add_bi_case2(void);
void		test_bi_add_bi_case3(void);

#endif
