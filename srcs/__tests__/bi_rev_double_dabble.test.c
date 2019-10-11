#include "bigint.test.h"

void		test_bi_rev_double_dabble_case1(void)
{
	printf(KYEL "test_bi_rev_double_dabble_case1\n" KNRM);
    t_bigint    bcd;
    t_bigint    bi;
    int         res;

	bi_new(&bcd, 1, BI_SIGN_POSITIVE);
	bi_new(&bi, 1, BI_SIGN_NEGATIVE);

	bi_push(&bcd, 0x80);
    bi_push(&bcd, 0x01);

	res = bi_rev_double_dabble(&bcd, &bi);

	test(
		res == BI_SUCCESS,
		"bi_rev_double_dabble : return value"
	);

    test(
        bi.occupied == 1,
        "bi_rev_double_dabble : bi.occupied"
    );

    test(
        bi.sign == bcd.sign,
        "bi_rev_double_dabble : bi.sign"
    );

    test(
        bi.data[0] == 0xb4,
        "bi_rev_double_dabble : bi.data[0]"
    );

	free(bi.data);
	free(bcd.data);
}

// case negative
void		test_bi_rev_double_dabble_case2(void)
{
	printf(KYEL "test_bi_rev_double_dabble_case2\n" KNRM);
    t_bigint    bcd;
    t_bigint    bi;
    int         res;

	bi_new(&bcd, 1, BI_SIGN_NEGATIVE);
	bi_new(&bi, 1, BI_SIGN_POSITIVE);

	bi_push(&bcd, 0x80);
    bi_push(&bcd, 0x01);

	res = bi_rev_double_dabble(&bcd, &bi);

    test(
		res == BI_SUCCESS,
		"bi_rev_double_dabble : return value"
	);

    test(
        bi.occupied == 1,
        "bi_rev_double_dabble : bi.occupied"
    );

    test(
        bi.sign == bcd.sign,
        "bi_rev_double_dabble : bi.sign"
    );

    test(
        bi.data[0] == 0xb4,
        "bi_rev_double_dabble : bi.data[0]"
    );

	free(bi.data);
	free(bcd.data);
}

// case big
void		test_bi_rev_double_dabble_case3(void)
{
	printf(KYEL "test_bi_rev_double_dabble_case3\n" KNRM);
    t_bigint    bcd;
    t_bigint    bi;
    int         res;
    unsigned char	expected[5] = {
		0xda, 0x74, 0xb7, 0x72, 0xc5
	};

	bi_new(&bcd, 1, BI_SIGN_POSITIVE);
	bi_new(&bi, 1, BI_SIGN_NEGATIVE);

	bi_push(&bcd, 0x53);
    bi_push(&bcd, 0x00);
    bi_push(&bcd, 0x05);
    bi_push(&bcd, 0x61);
    bi_push(&bcd, 0x82);
    bi_push(&bcd, 0x93);

	res = bi_rev_double_dabble(&bcd, &bi);

    test(
		res == BI_SUCCESS,
		"bi_rev_double_dabble : return value"
	);

    test(
        bi.occupied == 5,
        "bi_rev_double_dabble : bi.occupied"
    );

    test(
        bi.sign == bcd.sign,
        "bi_rev_double_dabble : bi.sign"
    );

    for (size_t i=bi.occupied; i > 0; i--)
		test(
			bi.data[i - 1] == expected[5 - i],
			"bi_rev_double_dabble : bi.data[i]"
		);

	free(bi.data);
	free(bcd.data);
}

// case 0
void		test_bi_rev_double_dabble_case4(void)
{
	printf(KYEL "test_bi_rev_double_dabble_case4\n" KNRM);
    t_bigint    bcd;
    t_bigint    bi;
    int         res;

	bi_new(&bcd, 1, BI_SIGN_POSITIVE);
	bi_new(&bi, 1, BI_SIGN_NEGATIVE);

	res = bi_rev_double_dabble(&bcd, &bi);

    test(
		res == BI_SUCCESS,
		"bi_rev_double_dabble : return value"
	);

    test(
        bi.occupied == 0,
        "bi_rev_double_dabble : bi.occupied"
    );

    test(
        bi.sign == BI_SIGN_POSITIVE,
        "bi_rev_double_dabble : bi.sign"
    );

	free(bi.data);
	free(bcd.data);
}