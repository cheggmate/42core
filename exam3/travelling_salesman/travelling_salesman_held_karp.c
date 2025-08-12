#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// Number of cities (set dynamically)
int n;
// Distance matrix
int **dist;

// DP table: dp[subset][last] = minimum cost to reach 'last' city visiting 'subset' cities
int **dp;
// Parent table to reconstruct path if needed
int **parent;

// Utility: bit count
int bit_count(int x) {
    int c = 0;
    while (x) {
        c += x & 1;
        x >>= 1;
    }
    return c;
}

int min(int a, int b) {
    return a < b ? a : b;
}

void held_karp() {
    int N = 1 << n; // number of subsets

    // Allocate DP tables
    dp = malloc(N * sizeof(int *));
    parent = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        dp[i] = malloc(n * sizeof(int));
        parent[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            dp[i][j] = INT_MAX / 2; // large number to avoid overflow
            parent[i][j] = -1;
        }
    }

    // Base case: starting at city 0, cost is 0
    dp[1][0] = 0;

    // Iterate through all subsets of cities
    for (int subset = 1; subset < N; subset += 2) { // subset must include city 0 (LSB = 1)
        for (int last = 0; last < n; last++) {
            if (!(subset & (1 << last))) continue; // last city not in subset
            if (dp[subset][last] == INT_MAX / 2) continue; // not reachable

            // Try to extend path to next city
            for (int next = 0; next < n; next++) {
                if (subset & (1 << next)) continue; // next already visited
                int next_subset = subset | (1 << next);
                int new_cost = dp[subset][last] + dist[last][next];
                if (new_cost < dp[next_subset][next]) {
                    dp[next_subset][next] = new_cost;
                    parent[next_subset][next] = last;
                }
            }
        }
    }

    // Close the tour by returning to city 0
    int min_cost = INT_MAX;
    int last_city = -1;
    int full_set = (1 << n) - 1;
    for (int i = 1; i < n; i++) {
        if (dp[full_set][i] + dist[i][0] < min_cost) {
            min_cost = dp[full_set][i] + dist[i][0];
            last_city = i;
        }
    }

    printf("Minimum tour cost: %d\n", min_cost);

    // Optional: reconstruct path
    /*
    int *path = malloc(n * sizeof(int));
    int current_set = full_set;
    int current_city = last_city;
    for (int i = n - 1; i > 0; i--) {
        path[i] = current_city;
        int temp = parent[current_set][current_city];
        current_set = current_set & ~(1 << current_city);
        current_city = temp;
    }
    path[0] = 0;
    printf("Path: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", path[i]);
    }
    printf("0\n");
    free(path);
    */

    // Free memory
    for (int i = 0; i < N; i++) {
        free(dp[i]);
        free(parent[i]);
    }
    free(dp);
    free(parent);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <number_of_cities> <distance_matrix>\n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);
    int expected_args = n * n + 2;
    if (argc != expected_args) {
        printf("Expected %d distances for %d cities, got %d\n", n * n, n, argc - 2);
        return 1;
    }

    // Allocate dist matrix
    dist = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        dist[i] = malloc(n * sizeof(int));
    }

    int idx = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = atoi(argv[idx++]);
        }
    }

    // Run Held-Karp
    held_karp();

    // Free dist matrix
    for (int i = 0; i < n; i++) free(dist[i]);
    free(dist);

    return 0;
}
