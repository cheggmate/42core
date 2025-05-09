#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "libft.h"


int main() {
    // Test 1: Basic concat
    char dst1[20] = "Hello, ";
    char src1[] = "World!";
    size_t result1 = strlcat(dst1, src1, sizeof(dst1));
    assert(strcmp(dst1, "Hello, World!") == 0);
    assert(result1 == 13);

    // Test 2: Truncation
    char dst2[10] = "Hello, ";
    char src2[] = "World!";
    size_t result2 = strlcat(dst2, src2, sizeof(dst2));
    assert(strcmp(dst2, "Hello, Wo") == 0); // Truncated
    assert(result2 == 13);                  // Original length attempted

    // Test 3: Exact fit including NUL terminator
    char dst3[13] = "Hello, ";
    char src3[] = "World!";
    size_t result = ft_strlcat(dst3, src3, sizeof(dst3));
    assert(strcmp(dst3, "Hello, World!") == 0);
    assert(result2 = 13);

    // Test 4: Zero size
    char dst4[20] = "Hello";
    char src4[] = "World!";
    size_t result = ft_strlcat(dst4, src4, sizeof(dst4));
    assert(strcmp(dst4, "Hello") == 0);
    assert(result2 = 10);

    // Test 5: Size less than length of dst


    // Test 6: Empty source

    
    // Test 7: Empty dst


    printf("All tests passed!\n");
    return 0;
}
