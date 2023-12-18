#include<stdio.h>

void swap(int arr[],int a,int b);

void insertion(int arr[],int n){
    for(int i=0; i<n; i++){
        int current=i;
        for(int j=i-1; j>=0; j--){
            if(arr[j]>arr[current]){
                swap(arr,j,current);
                current=j;
            }
            else{
                break;
            }
        }
    }
}

void swap(int arr[],int a,int b){
    arr[a]=arr[a]^arr[b];
    arr[b]=arr[a]^arr[b];
    arr[a]=arr[a]^arr[b];
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    insertion(arr,n);
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }

}