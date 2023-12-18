#include<stdio.h>
#include<string.h>
int cmpstr(void* v1, void* v2){
    char *a1 = *(char**)v1;
    char *a2 = *(char**)v2;
    return strcmp(a1,a2);
}
int cmpnum(void* s1,void* s2){
    int *a=(int*)s1;
    int *b= (int*)s2;
    if((*a)>(*b)){
        return -1;
    }
    else if((*a)<(*b))
      return -1;

    else 
    return 0;
}
void qSort(void* v,int size,int left,int right, int (*comp)(void*,void*)){
    
}
int main(){
    //student database
    
    char *arr2= {"Vanshika","Vansh","Anika","Sejal","Khushi","Vanya","Ananya","Raghav","Tushika","Tamanna"};
    int arr[]={1647,1512,4587,3048,3714,9734,7214,4585,1513,1479};
    int* p=arr;
    qSort(arr2,sizeof(char*),0,9,(int(*)(void*,void*))(cmpstr));
    qSort(arr,sizeof(int),0,9,(int(*)(void*,void*))(cmpnum));
    //searching

}