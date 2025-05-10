#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "../ft_atoi.c"

int	main(void)
{
	// Test 1: Basic positive number
    int out1;
    out1 = ft_atoi("1234");
    assert(out1 = 1234);

    // Test 2: Basic negative number
    int out2;
    out2 = ft_atoi("-567");
    assert(out2 == -567);

    // Test 3: Leading whitespace
    int out3;
    out3 = ft_atoi("    42");
    assert(out3 == 42);

    // Test 4: With Leading plus sign
    int out4;
    out4 = ft_atoi("+89");
    assert(out4 == 89);

    // Test 5: With training characters
    int out5;
    out5 = ft_atoi("100abc");
    assert(out5 == 100);

    // Test 6: Only non-digit characters
    int out6;
    out6 = ft_atoi("xyz");
    assert(out6 == 0);

    // Test 7: Empty string
    int out7;
    out7 = ft_atoi("");
    assert(out7 == 0);

    // Test 8: Overflow case
    // int out8;
    // out8 = ft_atoi("2147483648");
    // assert(out8 == INT_MAX); // sometimes the behaviour may be undefined

    // Test 9: Underflow case
    // int out9;
    // out9 = ft_atoi("-2147483649");
    // assert(out9 == INT_MIN); // sometimes the behaviour may be undefined

    // Test 10: Zero with other digits
    int out10;
    out10 = ft_atoi("0000123");
    assert(out10 == 123);

    // Test 11: + sign
    int out11;
    out11 = ft_atoi("+");
    assert(out11 == 0);

    // Test 12: - sign
    int out12;
    out12 = ft_atoi("-");
    assert(out12 == 0);

    // Test 13: sign followed by space
    int out13;
    out13 = ft_atoi("- 123");
    assert(out13 == 0);

    // Test 14: embedded whitespace
    int out14;
    out14 = ft_atoi("1 2 3");
    assert(out14 == 1);

    printf("All tests passed!\n");
    return 0;
}