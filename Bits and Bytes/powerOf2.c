#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);

    //approach1 - complexity- O(log n)
    int k=n;
    int j=n;
    while(k%2==0){
        k=k/2;
    }
    if(k==1){
        printf("number is power of 2\n");
    }
    else{
        printf("number is not power of 2\n");
    }
    

    //approach2  complexity- O(1)
    if((n & (n-1)) ==0){
       printf("number is power of 2\n");
    }
    else{
        printf("number is not power of 2\n");
    }

    //approach3   complexity- O(log n)
    int setbits=0;
    while(j>0){
        if((j&1)!=0){
            setbits++;
        }
       // printf("hello");
        j=j>>1;
    }
    if(setbits==1){
        printf("number is power of 2");
    }
    else{
         printf("number is not power of 2");
    }
}