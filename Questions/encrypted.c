// There is a list of encrypted files of size n, each with a different value, and a list of n binary values. A value of 1 represents a file that has been decrypted, and 0 represents an encrypted file that is not yet decrypted. The value sum of the encrypted files is the sum of all values of the files where the corresponding value in the binary list is
// 1. In a single operation, a group of up to k encrypted files can be decrypted simultaneously.
// The values of the encrypted files and the binary list are given, along with the maximum number of encrypted files that can be decrypted in a single operation. Find the maximum possible value sum of the decrypted files.
// Note: A group, i.e., subarray is defined as any contiguous segment of the array.

// Example 1
// Given n = 4, k = 2, encrypted_file = [7, 4, 3, 5], and
// binary = [1, 0, 0, 0].


// Example 2
// Given n = 6, k = 2, encrypted_file = [1 , 3, 5, 2 , 5 ,4], and
// binary = [1,1, 0, 1, 0, 0].

// Answer is 15

// #include<stdio.h>
// int main(){
//     int n=6;
//     int k=2;
//     //int arr[4]= {7,4,3,5};
//     int arr[6]={1 , 3, 5, 2 , 5 ,4};
//     //int bin[4]={1,0,0,0};
//    int bin[6]={1,1, 0, 1, 0, 0};

//     //encrypted=0
//     //decrypted=1
//     //find sum of decrypted files

//     int ans=0;
//     for(int i=0; i<n; i++){
//         if(bin[i]==1){
//             ans += arr[i];
//         }
//     }
//     //printf("%d\n",ans);

//     int sum=0;

//     for(int i=0; i<k; i++){
//         if(bin[i]==0){
//             sum=sum+arr[i];
//         }
//     }

//     int max=sum;

//     for(int i=k; i<n; i++){
//         if(bin[i-k]==0){
//             sum=sum-arr[i-k];
//         }
//         if(bin[i]==0){
//             sum=sum+arr[i];
//         }
//         if(sum>max){
//             max=sum;
//         }
//     }
//     ans=ans+max;
//     printf("%d",ans);
// }

#include<stdio.h>
int main(){
    // int arr[5]={1,2,3,4,5};
    // arr[10]=10;
    // printf("%d\n",arr[10]);

    // char str1[6]="Hello"; //give size one more
    // str1[0]='h';
    // printf("%s\n",str1);

    char *str2="Hello";
    str2[0]='h';
     printf("%s\n",str2);

     int *ptr;
     *ptr=5;
     printf("%d",*ptr);

}



