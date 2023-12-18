#include<stdio.h>
#include<stdlib.h>
void foo(char **x){  //here passed by reference 
    char *y= (char*)malloc(sizeof(char));
    y[0]='H';
    y[1]='e';
    y[2]='\0';
    *x=y;
}
// void foo(char *x){  //here copy is created
//     char *y= (char*)malloc(sizeof(char));
//     y[0]='H';
//     y[1]='e';
//     y[2]='\0';
//     printf("sizeof y string is %d\n",sizeof(y)); //y is pointer so 8 bytes
//     x=y;
// }
int main(){
    char *x="Hello";
    foo(&x); //here passed by reference
    //foo(x);
    printf("%s\n",x);
    return 0;
}