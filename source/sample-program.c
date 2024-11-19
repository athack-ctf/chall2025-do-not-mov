#include <stdio.h>

int main() {
    int fib[5]; // Array to store the first 5 Fibonacci numbers
    fib[0] = 0; // First Fibonacci number
    fib[1] = 1; // Second Fibonacci number

    // Compute the remaining Fibonacci numbers
    for (int i = 2; i < 5; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Calculate the sum of the first 5 Fibonacci numbers
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += fib[i];
    }

    // Output the sum
    printf("The sum of the first 5 Fibonacci numbers is: %d\n", sum);

    return 0;
}
