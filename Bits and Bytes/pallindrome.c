#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int m=n;
    int x=0;
    while(m>0){
         x=x<<1;
        x=x|(m&1);
       
        m=m>>1;
    }

    if(x==n){
        printf("number is pallindrome");
    }
    else{
        printf("number is not pallindrome");
    }
}