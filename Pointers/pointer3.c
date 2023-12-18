#include <stdio.h>

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two numbers
int subtract(int a, int b) {
    return a - b;
}

int main() {
    // Function pointers
    int (*operation)(int, int);

    // Point the function pointer to the 'add' function
    operation = add;

    // Call the function through the function pointer
    int result = operation(5, 3);
    printf("Result of add operation: %d\n", result);

    // Point the function pointer to the 'subtract' function
    operation = subtract;

    // Call the function through the function pointer
    result = operation(5, 3);
    printf("Result of subtract operation: %d\n", result);

    return 0;
}
