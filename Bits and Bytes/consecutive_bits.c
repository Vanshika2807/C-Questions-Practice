//to check if there are consecutive one bits
//logic: left shift the no and after that do and with original no
//if result comes to be non-zero then their are consecutive 1 bits

#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int x=n<<1;
    printf("after doing left shift number is %d\n",x);
    int y=x&n;
    printf("after doing and number is %d\n",y);
    if((x&n)!=0){
        printf("there are consecutive ones present ");
        return 0;
    }
    printf("there are no consecutive ones present");
}

// Check if a string has m consecutive 1’s or 0’s