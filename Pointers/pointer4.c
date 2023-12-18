#include <stdio.h>

// Function that takes a void* parameter and retrieves the integer value
void processInteger(void* data) {
    int value = *((int*)data); // Typecasting the void* to an int* and dereferencing it
    printf("Value received: %d\n", value);
}

int main() {
    int num = 42;

    // Pass the address of 'num' as void* to the function
    processInteger(&num);

    return 0;
}




