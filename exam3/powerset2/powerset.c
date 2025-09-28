#include <stdio.h>
#include <math.h>

void print_powerset(int arr[], int n) {
    int total = 1 << n;  // 2^n subsets

    for (int mask = 0; mask < total; ++mask) {
        printf("{ ");
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                printf("%d ", arr[i]);
            }
        }
        printf("}\n");
    }
}

int main() {
    int arr[] = {1, 2, 3};  // You can change this
    int n = sizeof(arr) / sizeof(arr[0]);

    print_powerset(arr, n);

    return 0;
}
