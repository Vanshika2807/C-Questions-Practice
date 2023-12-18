#include <stdio.h>

int main() {
    int num = 42;
    int *ptr1 = &num;          // Pointer to an integer variable (stores the address of num)
    int **ptr2 = &ptr1;        // Pointer to a pointer (stores the address of ptr1)
    int ***ptr3 = &ptr1;       // Pointer to a pointer-to-pointer (stores the address of ptr2)

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);

    printf("Value of ptr1: %p\n", ptr1);
    printf("Address of ptr1: %p\n", &ptr1);

    printf("Value of ptr2: %p\n", ptr2);
    printf("Address of ptr2: %p\n", &ptr2);

    printf("Value of ptr3: %p\n", ptr3);
    printf("Address of ptr3: %p\n", &ptr3);

    printf("Value at the address stored in ptr3: %d\n", ***ptr3);

    return 0;
}
