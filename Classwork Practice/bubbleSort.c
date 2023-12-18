#include<stdio.h>
#include<stdbool.h>
void swap(int arr[],int n,int a,int b){
    // arr[a]=arr[a]^arr[b];
    // arr[b]=arr[a]^arr[b];
    // arr[a]=arr[a]^arr[b];
    printf("%d ",arr[a]);
    printf("%d ",arr[b]);
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
    printf("%d ",arr[a]);
    printf("%d ",arr[b]);
    printf("\n");
}
int main(){
 
    int arr[5]={10,5,11,4,1};
    int n=sizeof(arr)/sizeof(arr[0]);
   // bool flag=true;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                //flag=false;
                swap(arr,5,i,j);
            }
        }

        // if(flag==true){
        //     break;
        // }

    }
    printf("\n");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
}