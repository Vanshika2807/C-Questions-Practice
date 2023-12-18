#include<stdio.h>

void swap(int arr[],int a,int b);
void quickSort(int arr[],int l,int r){
    if(l>r){
        return;
    }
    int p=l;
    int next=l;
    //this loop will make sure that all elements at left of pivot are less than pivot
    //all element at right of pivot are greater than pivot
    //now only job is to sort left and right part by this function only

    for(int i=next+1; i<=r; i++){
        if(arr[i]<arr[p]){
            next++;
            swap(arr,next,i);
        }
    }

    //now swap elements at p and next 
    swap(arr,p,next);
    p=next;

    quickSort(arr,l,p-1);
    quickSort(arr,p+1,r);

    //now do this 
}

void swap(int arr[],int a,int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    quickSort(arr,0,n-1);

    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
}