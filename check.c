#include <stdio.h>
#include <stdlib.h>

int check(char **m, int n) {
    // Create an array to count the occurrences of each letter in each row
    int row_counts[n][26];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            row_counts[i][j] = 0;
        }
    }

    // Iterate over each row of the matrix and count the occurrences of each letter
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c = m[i][j];
            row_counts[i][c - 'A']++;
        }
    }

    // Iterate over the row counts and find the row with the maximum count for any letter
    int max_count = 0;
    int max_row = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (row_counts[i][j] > 1 && row_counts[i][j] > max_count) {
                max_count = row_counts[i][j];
                max_row = i;
            }
        }
    }

    return max_row;

}

int main() {
    char *matrix[] = {
        "XAEIOU",
        "UXAEIO",
        "OUXAIE",
        "IOUXAE",
        "EIOUXA",
        "XYZXYX"
    };
    int result = check(matrix, 6);
    if (result == -1) {
        printf("No rows contain the same letter more than once.\n");
    } else {
        printf("Row %d contains the same letter more than once.\n", result);
    }
    return 0;
}