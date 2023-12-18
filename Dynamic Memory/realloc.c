#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int *ptr=(int*)calloc(n,sizeof(int));
    for(int i=0; i<n; i++){
        ptr[i]=i+1;
    }
    for(int i=0; i<n; i++){
        printf("%d ",ptr[i]);
    }
    printf("\n");

    ptr=realloc(ptr,n);
    for(int i=n; i<2*n; i++){
        ptr[i]=i+1;
    }

    for(int i=0; i<2*n; i++){
        printf("%d ",ptr[i]);
    }
}


// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int *numbers = NULL;

//     // Attempt to reallocate memory for an array of 5 integers
//     numbers = (int *)realloc(numbers, 5 * sizeof(int));

//     if (numbers != NULL) {
//         // Now you can use the allocated memory
//         for (int i = 0; i < 5; i++) {
//             numbers[i] = i;
//             printf("numbers[%d] = %d\n", i, numbers[i]);
//         }

//         // Don't forget to free the allocated memory when done
//         free(numbers);
//     } else {
//         printf("Memory allocation failed.\n");
//     }

//     return 0;
// }