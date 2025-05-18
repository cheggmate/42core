#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "../ft_strnstr.c"

void run_test(const char *haystack, const char *needle, size_t len, const char *expected_desc) {
    char *result = ft_strnstr(haystack, needle, len);
    if (result) {
        printf("✅ \"%s\" in \"%s\" (len=%zu) => \"%s\" | Expected: %s\n",
               needle, haystack, len, result, expected_desc);
    } else {
        printf("❌ \"%s\" in \"%s\" (len=%zu) => NULL | Expected: %s\n",
               needle, haystack, len, expected_desc);
    }
}

int main(void)
{
    // Test1: Basic match
	run_test("hello world", "world", 11, "\"world\"");

	// Test2: partial length match
	run_test("hello world", "world", 5, "NULL");

	// Test3: Needle at the start
	run_test("start middle end", "start", 5, "\"start middle end\"");

	// Test4: Needle at the end
	run_test("find it at the end", "end", 20, "\"end\"");

	// Test5: Needle not present
	run_test("no match here", "xyz", 20, "NULL");

	// Test6: Needle is empty string
	run_test("non-empty haystack", "", 10, "\"non-empty haystack\"");

	// Test7: Haystack is empty string
	run_test("", "needle", 10, "NULL");

	// Test8: Both haystack and needle empty
	run_test("", "", 0, "\"\"");

	// Test9: Needle longer than haystack
	run_test("short", "this is longer", 10, "NULL");

	// Test10:  Length limit shorter than needle
    run_test("abcdefg", "def", 2, "NULL");
    
	// Test11: Exact match at the limit
    run_test("abcdefg", "def", 6, "\"defg\"");

	// Test12: Match beyond the limit
    run_test("abcdefg", "def", 4, "NULL");

	// Test13: Repeated characters
    run_test("aaaabaaaac", "aaac", 10, "\"aaac\"");

	// Test14: libft tests
	run_test("aaabcabcd", "cd", 8, "NULL");

    // printf("All tests passed!\n");
    return 0;
}