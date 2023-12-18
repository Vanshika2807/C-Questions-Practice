#include<stdio.h>
#include<stdlib.h>
void foo(int *a){
    int *b = (int *) malloc(sizeof(int)*3);
    b[0]=3;
    b[1]=5;
    b[2]=7;
    a=b;
}

int main(){
    int a[]={1,2,3,4};
    foo(a);
    printf("%d\n",a[0]);
    return 0;
}

// #include<stdio.h>  //varun code
// void find(int *a){
//     a[1]=3;
// }
// int main(){
//     int a[2]={0,0};
//     find(a);
//     printf("%d",a[1]);
// }

// #include<stdio.h>
// void find(int *a){
//      int *b = (int *) malloc(sizeof(int)*3);
     
//     b[0]=1;
//     b[1]=3;
//     a=b;
// }
// int main(){
//     //int *a = (int*) malloc(sizeof(int)*3);
//     int a[2]={0,0};
//     find(a);
//     printf("%d",a[1]);
// }