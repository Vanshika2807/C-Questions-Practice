#include<stdio.h>
int sum(int a,int b){
    return a+b;
}
int diff(int a,int b){
    return a-b;
}
int mul(int a,int b){
    return a*b;
}
int divide(int a,int b){
    return a/b;
}
int mod(int a,int b){
    return a%b;
}
int main(){
    int a;
    int b;
    int n;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&n);
    void(*operation[5])(int,int)={sum,diff,mul,divide,mod}; //void* bcoz it doesnot return anything
    operation[1](5,2);

    
}