#include<stdio.h>

void merge(int arr[], int l,int r, int mid){
    int left_size=mid-l+1;
    int right_size= r-mid;
    int arr2[left_size];
    int arr3[right_size];
    int i=0;
    int j=0;
    int k=l;
    for(int m=l; m<=mid; m++){
        arr2[i]=arr[m];
        i++;
    }
    for(int n=mid+1; n<=r; n++){
        arr3[j]=arr[n];
        j++;
    }

    i=0;
    j=0;
    while(i<left_size && j<right_size){
        if(arr2[i]<=arr3[j]){
            arr[k]=arr2[i];
            k++;
            i++;
        }
        else{
            arr[k]=arr3[j];
            k++;
            j++;
        }
    }

    while(i<left_size){
        arr[k]=arr2[i];
        i++;
        k++;
    }

    while(j<right_size){
        arr[k]=arr3[j];
        k++;
        j++;
    }

   // printf("hello");

}

void mergeSort(int arr[], int l, int r){

    //base condition
    if(l>=r){
        return ;
    }
   // printf("hello");
    int mid=(l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,r,mid);
  
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++){
        //int p;
        scanf("%d",&arr[i]);
        //arr[i]=p;
    }
  
    mergeSort(arr,0,n-1);
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
}