// #include<stdio.h>
// #include<stdlib.h>
// int main(){
//     int n;
//     scanf("%d",&n);
  
//     int *ptr=(int*)calloc(n,sizeof(int));
    
//     for(int i=0; i<n; i++){
//         ptr[i]=i+1;
//     }
//     for(int i=0; i<n; i++){
//         printf("%d ",ptr[i]);
//     }
//     printf("\n");
//     free(ptr);
//     for(int i=0; i<n; i++){
//         printf("%d ",ptr[i]);
//     }
// }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Allocate memory for a string of length 10
    char *str = (char *)calloc(10, sizeof(char));

    if (str != NULL) {
        // Since calloc initializes with null characters, str is already an empty string
        printf("Allocated string: \"%s\"\n", str);

        // Assign a value to the string
        strcpy(str, "Hello");

        // Print the updated string
        printf("Updated string: \"%s\"\n", str);

        // Don't forget to free the allocated memory when done
        free(str);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}