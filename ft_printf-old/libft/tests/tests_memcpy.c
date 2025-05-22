#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../ft_memcpy.c"

int main(void)
{
    // Test 1: 
	char	dest1[4] = {'a', 'a', 'a', 'a'};
	char	src1[4] = {'w', 'x', 'y', 'z'};
	char	expected1[4] = {'w', 'x', 'y', 'z'};
	int		len1 = 4;
	ft_memcpy(dest1, src1, len1);
    assert(memcmp(dest1, expected1, len1) == 0);

	// Test 2: Partial copy
	char	dest2[5] = "abcde";
	char	src2[5] = "hello";
	char 	expected2[5] = "helde";
	int		len2 = 3;
	ft_memcpy(dest2, src2, len2);
	assert(memcmp(dest2, expected2, sizeof(expected2)) == 0);

	// Test 3: Copy with embedded nulls
	char	dest3[] = {'0', '0', '0', '0', '0'};
	char	src3[] = {'1', '0', '2', '0', '3'};
	char	expected3[] = {'1', '0', '2', '0', '3'};
	int		len3 = 5;
	ft_memcpy(dest3, src3, len3);
	assert(memcmp(dest3, expected3, len3) == 0);

	// Test 4: Copy to struct
	typedef struct {
        int a;
        char b;
    } Data;
    Data		src4 = {42, 'a'};
	Data		dest4 = {0, 'b'};
	Data		expected4 = {42, 'a'};
	int		len4 = sizeof(Data);
	ft_memcpy(&dest4, &src4, len4);
	assert(dest4.a == expected4.a);
	assert(strcmp(&dest4.b, &expected4.b) == 0);
	assert(dest4.b == expected4.b);

	
	// Test 5: n = 0 (no op)
	char	dest5[] = {5, 5, 5, 5};
	char	src5[] = {0, 1, 2, 3};
	char	expected5[] = {5, 5, 5, 5};
	int		len5 = 0;
	ft_memcpy(dest5, src5, len5);
	assert(memcmp(dest5, expected5, len5) == 0);

	// Test 6: copy null - terminated string
	char	dest6[] = "yo";
	char	src6[] = "hi";
	char	expected6[] = "hi";
	int		len6 = 3;
	ft_memcpy(dest6, src6, len6);
	assert(memcmp(dest6, expected6, len6) == 0);

    printf("All tests passed!\n");
    return 0;
}