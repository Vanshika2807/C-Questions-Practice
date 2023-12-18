#include<stdio.h>



//here you have to find position of an element in an unsorted array using binary search

//for this one more array to store index of elements and apply binary Search on those after sorting them


void swap(int *arr,int *arr2,int j,int i){

	arr[j]=arr[j]^arr[i];

	arr[i]=arr[j]^arr[i];

	arr[j]=arr[j]^arr[i];



	int temp = arr2[j];

	arr2[j] = arr2[i];

	arr2[i] = temp;

    return;

}



void bubbleSort(int arr[],int arr2[],int n){
	// int n=sizeof(arr)/sizeof(arr[0]);

	for(int i=0; i<n-1; i++){

		int count=0;

		for(int j=0; j<n-i-1; j++){

			if(arr[j]>arr[j+1]){
				count++;
				swap(arr,arr2,j,j+1);

			}

		}

	if(count==0){

	     break;  }

	}

   return;

}



int main(){



    int arr[]={40,50,10,5,7,100};

    int arr2[]={0,1,2,3,4,5};



//given key k

   int key;

   scanf("%d",&key);

   //apply bubble sort on both arrays

    bubbleSort(arr,arr2,6);
    
    int n=6;
    // int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n; i++){
        printf("%d %d\n",arr[i],arr2[i]);
    }
    

    int l=0;

    int r=n-1;

	int mid = (l+r)/2;

    while(l<=r){

	if(arr[mid]==key){

		printf("element is found at index %d",arr2[mid]);

		return 0;

	}

	else if(arr[mid]<key){

		l=mid+1;

	}

	else{
	    r=mid-1;
	}

	mid=(l+r)/2;

    }

   printf("element not found");

   return 0;

}

