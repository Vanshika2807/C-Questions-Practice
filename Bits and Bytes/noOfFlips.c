#include<stdio.h>
int main(){
    //two numbers given check how many bits of a to flip to convert to b
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    int c=a^b;
    int setbits=0;

    while(c>0){
        if((c&1)!=0){
            setbits++;
        }
        c=c>>1;
    }

    printf("no of bits you have to flip is %d",setbits);

}