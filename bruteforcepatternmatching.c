#include <stdio.h>
#include <string.h>

// Global declarations
char s[100], p[100];
int ls, lp;
int i, j, k;
int flag = 0;

// Brute-force pattern matching function
void Bruteforce() {
    // Remove trailing newline characters from fgets
    s[strcspn(s, "\n")] = '\0';
    p[strcspn(p, "\n")] = '\0';

    ls = strlen(s);
    lp = strlen(p);

    for (i = 0; i <= ls - lp; i++) {
        k = i;
        j = 0;
        while (s[k] == p[j] && j < lp) {
            k++;
            j++;
        }
        if (j == lp) {
            printf("Pattern found at position: %d\n", i);
            flag = 1;
        }
    }

    if (!flag) {
        printf("Pattern not found.\n");
    }
}

int main() {
    printf("Enter the main string: ");
    fgets(s, sizeof(s), stdin);

    printf("Enter the pattern to search: ");
    fgets(p, sizeof(p), stdin);

    Bruteforce();

    return 0;
}