#include<stdio.h>
long int fibonacci(int n){

     if(n==0){

       return 1;

     }

     long int a=fibonacci(n-1);

     return a*n;

}



int main(){

   int n;

   scanf("%d",&n);

   long int x=fibonacci(n);

   printf("%ld",x);

}


