#include<stdio.h>
#include<stdbool.h>
int front=0;
int size=0;
int arr[5];
int n=sizeof(arr)/sizeof(arr[0]);

bool isFull();
bool isEmpty();

void sort(){
    int k=front;
    for(int i=k; i<size; i++){
        for(int j=i+1; j<size-i-1; j++){
            if(arr[i]>arr[j]){
                arr[i]=arr[i]^arr[j];
                arr[j]=arr[i]^arr[j];
                arr[i]=arr[i]^arr[j]; 
            }
        }
    }
}

void insert(int key){
    if(isFull()){
        printf("queue is full");
        return;
    }
    int index=(front+size)%n;
    arr[index]=key;
    size++;
    sort();
}
void delete(){
    if(isEmpty()){
        printf("queue is empty");
        return;
    }
    front=(front+1)%n;
    size--;
}

bool isFull(){
    if(size==n){
        return true;
    }
    return false;
}
bool isEmpty(){
    if(size==0){
        return true;
    }
    return false;
}
void traverse(){
    int k=front;
    int i=0;
    while(i<size){
        printf("%d ",arr[k]);
        k=(k+1)%n;
        i++;
    }
}
int main(){

    int arr[5];
  
    insert(10);
     insert(20);
      insert(30);
       insert(40);
       printf("%d\n",size);
        printf("%d\n",front);
       isFull();
       isEmpty();
       delete();
       delete();
       delete();
       insert(50);
       isEmpty();
       isFull();
       traverse();



}