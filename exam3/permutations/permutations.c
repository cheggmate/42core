#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// // Function to calculate factorial of a number
// long long factorial(int n) {
//     long long fact = 1;
//     for (int i = 1; i <= n; i++) {
//         fact *= i;
//     }
//     return fact;
// }

// Function to swap two characters
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Function to print the permutations of the string
void print_permutations(char *str, int left, int right) {
    if (left == right) {
        printf("%s\n", str);  // Print the current permutation
    } else {
        for (int i = left; i <= right; i++) {
            // Skip if the character is the same as the previous one (to avoid duplicates)
            if (i != left && str[i] == str[left]) {
                continue;
            }

            // Swap the current character with the first character of the substring
            swap(&str[left], &str[i]);

            // Recursively generate permutations for the remaining part
            print_permutations(str, left + 1, right);

            // Backtrack by swapping the characters back
            swap(&str[left], &str[i]);
        }
    }
}

// Function to calculate the number of distinct permutations
// long long distinct_permutations(char *str) {
//     int len = strlen(str);
//     int freq[256] = {0};  // Array to store the frequency of each character
    
//     // Count the frequency of each character
//     for (int i = 0; i < len; i++) {
//         freq[(int)str[i]]++;
//     }

//     // Calculate the factorial of the length of the string
//     long long total_permutations = factorial(len);

//     // Divide by the factorial of the frequency of each character
//     for (int i = 0; i < 256; i++) {
//         if (freq[i] > 1) {
//             total_permutations /= factorial(freq[i]);
//         }
//     }

//     return total_permutations;
// }

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }
	int len = strlen(argv[1]);

    // Print the distinct permutations
    printf("Distinct permutations:\n");
	print_permutations(argv[1], 0, len - 1);

    // Print the total number of distinct permutations
    // long long result = distinct_permutations(str);
    // printf("The total number of distinct permutations is: %lld\n", result);

    return 0;
}
