#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), i;
    unsigned long long fact = 1;

    // shows error if the user enters a negative integer
    if (n < 0)
        printf("Error! Factorial of a negative number doesn't exist.");
    else {
        for (i = 1; i <= n; ++i) {
            fact *= i;
        }
        printf("Factorial of %d = %llu\n", n*2, fact);
    }

    return 0;
}

