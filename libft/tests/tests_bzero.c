#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../ft_bzero.c"

int main(void)
{
    int i;

    // Test 1: Zeroing a character array
    char    buffer1[5] = {'A', 'B', 'C', 'D', 'E'};
    char    buffer1_test[5] = {0, 0, 0, 0, 0};
    ft_bzero(buffer1, 5);
    assert(memcmp(buffer1, buffer1_test, 5) == 0);
    
    // Test 2: Zeroing partial memory
    char    buffer2[5] = {'A', 'B', 'C', 'D', 'E'};
    char    buffer2_test[5] = {'A', 'B', 0, 0, 'E'};
    ft_bzero(buffer2 + 2, 2);
    assert(memcmp(buffer2, buffer2_test, 5) == 0);
    
    // Test 3: Zeroing struct memory
    typedef struct {
        int a;
        float b;
    } Data;
    Data    d = {42, 3.14};
    bzero(&d, sizeof(d));
    assert(d.a == 0);
    assert(d.b == 0);

    // Test 4: Zeroing already-zeroed memory
    char    buffer4[4] = {0, 0, 0, 0};
    ft_bzero(buffer4, 4);
    for (i = 0; i < 4; i++)
        assert(buffer4[i] == 0);

    // Test 5: Zeroing with size zero
    char    buffer5[4] = {'A', 'B', 'C', 'D'};
    char    buffer5_test[4] = {'A', 'B', 'C', 'D'};
    ft_bzero(buffer5, 0);
    assert(memcmp(buffer5, buffer5_test, 5 ));


    printf("All tests passed!\n");
    return 0;
}