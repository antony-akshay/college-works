#include <stdio.h>

// function declaration
int add(int a, int b);

int main() {
    int x, y, sum;

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    sum = add(x, y);

    printf("Sum = %d\n", sum);

    return 0;
}

// function definition
int add(int a, int b) {
    return a - b;
}
