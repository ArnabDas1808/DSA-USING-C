#include <stdio.h>

int factorial(int n, int result) {
    if (n == 0 || n == 1) {
        return result;
    }
    return factorial(n - 1, result * n);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    int result = factorial(num, 1);
    printf("Factorial of %d is %d\n", num, result);

    return 0;
}
