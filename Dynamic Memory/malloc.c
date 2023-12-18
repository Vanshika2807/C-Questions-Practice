#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int* ptr;
    ptr=(int*)malloc(sizeof(int)*n);
    //this ptr points to first byte of located memory
    if(ptr!=NULL){
       for(int i=0; i<n; i++){
        ptr[i]=i+1;
    }
    printf("the elements present are \n");
       for(int i=0; i<n; i++){
        printf("%d ",ptr[i]);
    }

    free(ptr);
    }

    else{
        printf("memory not allocated successfully");
    }
    
}