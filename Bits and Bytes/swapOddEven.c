#include<stdio.h>
int main(){
    unsigned int a;
    scanf("%u",&a);

    //to make even mask
   unsigned int even_mask=0;
    for(int i=1; i<=32; i++){
        even_mask=even_mask<<1;
        even_mask=even_mask|1;
        even_mask=even_mask<<1;
    }

    // unsigned int even_mask =  0xAAAAAAAA;
    // unsigned int odd_mask= 0x55555555;

   unsigned int odd_mask=~even_mask;
   unsigned  int evenbits=even_mask&a;
    unsigned int oddbits=odd_mask&a;
    unsigned int ans=(evenbits>>1)|(oddbits<<1);
    printf("%u",ans);
}