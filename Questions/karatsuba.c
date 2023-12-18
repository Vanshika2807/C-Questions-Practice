// #include <stdio.h>
// #include <stdlib.h>
// #include <assert.h>
// #include <string.h>

// int get_input_length(char** x, char** y)
// {
//   int length_x = strlen(*x);
//   int length_y = strlen(*y);

//   if(length_x < length_y) {
//     char* str_a  = (char *) malloc((length_y+1) * sizeof(char));

//     for(int i = 0; i < length_y-length_x; i++)
//     {
//         str_a[i] = '0';
//     } 
//     for(int i = length_y-length_x; i < length_y; i++)
//     {
//         str_a[i] = (*x)[i-(length_y-length_x)];
//     }
//     str_a[length_y] = '\0';
//     *x = str_a;
//   }

//   else if(length_y < length_x) {
//     char* str_b  = (char *) malloc((length_x+1) * sizeof(char));

//     for(int i = 0; i < length_x-length_y; i++)
//     {
//         str_b[i] = '0';
//     } 
//     for(int i = length_x-length_y; i < length_x; i++)
//     {
//         str_b[i] = (*y)[i-(length_x-length_y)];
//     }
//     str_b[length_x] = '\0';
//     *y = str_b;
//   }

//   return strlen(*x);
// }

// char* get_sub_string(char* x, int start, int end)
// {
//     char* sub_string = (char *) malloc(sizeof(char) * (end-start+2));

//     for(int i=start; i<=end; i++)
//     {
//         sub_string[i-start] = x[i];
//     }
//     sub_string[end-start+1] = '\0';

//     return sub_string;
// }

// char* add_bit_strings(char* x, char* y)
// {
//   int length = get_input_length(&x, &y);
//   char* result = (char*) malloc(sizeof(char)*(length+2));
//   int carry = 0;
//   int bit_x, bit_y;
//   int n = length;
  
//   while(n > 0)
//   {
//       bit_x = x[n-1]-'0';
//       bit_y = y[n-1]-'0';
//       int temp = bit_x+bit_y+carry;
//       if(temp >= 2) {
//         temp = temp&1;
//         carry = 1;
//       }
//       else {
//         carry = 0;
//       }
//       result[n] = temp+'0';
//       n--;
//   }
//   if(carry == 1) result[0] = '1';
//   else {
//     for(int i=0; i < strlen(result)-1; i++) {
//         result[i] = result[i+1];
//     }
//     result[strlen(result)-1] = '\0';
//   }
//   return result;
// }

// long int fast_multiply(char* x, char* y)
// {
//   int number_of_bits = get_input_length(&x, &y);
  
//   if(number_of_bits == 0) return 0;
//   if(number_of_bits == 1) return (x[0]-'0') * (y[0]-'0');
  
//   int n_left_bits = number_of_bits / 2;
//   int n_right_bits = number_of_bits - n_left_bits;

//   char* x_left = get_sub_string(x, 0, n_left_bits-1);
//   char* x_right = get_sub_string(x, n_left_bits, number_of_bits-1);
//   char* y_left = get_sub_string(y, 0, n_left_bits-1);
//   char* y_right = get_sub_string(y, n_left_bits, number_of_bits-1);

//   long int A = fast_multiply(x_left, y_left);
//   long int B = fast_multiply(x_right, y_right);
//   long int C = fast_multiply(
//       add_bit_strings(x_left, x_right),
//       add_bit_strings(y_left, y_right));

//  // return A*(1<<(2*n_right_bits))+(C-A-B)*(1<<n_right_bits)+B;

//     return A*(1<<(2*n_right_bits))+(C-A-B)*(1<<n_right_bits)+B;

//   //return 0;
// }


// int main()
// {
//   char* s1 = "010";
//   char* s2 = "110";
//   assert(get_input_length(&s1, &s2) == 3);

//   s1 = "10";
//   s2 = "110";
//   assert(get_input_length(&s1, &s2) == 3);
//   assert(strcmp(s1, "010") == 0);
//   assert(strcmp(s2, "110") == 0);

//   s1 = "101";
//   s2 = "11";
//   assert(get_input_length(&s1, &s2) == 3);
//   assert(strcmp(s1, "101") == 0);
//   assert(strcmp(s2, "011") == 0);

//   s1 = "";
//   s2 = "";
//   assert(get_input_length(&s1, &s2) == 0);

//   s1 = "1100111";
//   assert(strcmp(get_sub_string(s1, 0, 3), "1100") == 0);
//   assert(strcmp(get_sub_string(s1, 4, 6), "111") == 0);

//   s1 = "11";
//   s2 = "11";
//   assert(strcmp(add_bit_strings(s1, s2), "110") == 0);

//   s1 = "01";
//   s2 = "10";
//   assert(strcmp(add_bit_strings(s1, s2), "11") == 0);

//   s1 = "10";
//   s2 = "111";
//   assert(strcmp(add_bit_strings(s1, s2), "1001") == 0);

//   assert(fast_multiply("1100", "1010")==120); 
//   assert(fast_multiply("110", "1010")==60); 
//   assert(fast_multiply("11", "1010")==30); 
//   assert(fast_multiply("1", "1010")==10); 
//   assert(fast_multiply("0", "1010")==00); 
//   assert(fast_multiply("111", "111")==49); 
//   assert(fast_multiply("11", "11")==9);
//   assert(fast_multiply("11", "101")==15); 

//   return 0;
// }




















// // #include<stdio.h>
// // //#include<stdlib.h>
// // #include<assert.h>
// // #include<string.h>

// // //make strings of equal length
// // int make_same_size(char **a, char**b){
// //     int length_a=strlen(*a);
// //     int length_b=strlen(*b);

// //     if(length_a <length_b){
// //         char* str_a= (char*)malloc((length_b+1)*sizeof(char)); //+1 for null character
// //         for(int i=0; i<length_b-length_a; i++){
// //             str_a[i]='0';
// //         }

// //         for(int i=length_b-length_a; i<length_b; i++){
// //             str_a[i]=(*a)[i-(length_b-length_a)];
// //         }
// //         str_a[length_b]='\0';
// //         *a=str_a;
// //     }
// //     else{
// //        char* str_b= (char*)malloc((length_a+1)*sizeof(char)); //b+1 for null character
// //         for(int i=0; i<length_a-length_b; i++){
// //             str_b[i]='0';
// //         }

// //         for(int i=length_a-length_b; i<length_a; i++){
// //             str_b[i]=(*b)[i-(length_a-length_b)];
// //         }
// //         str_b[length_a]='\0';
// //         *b=str_b; 
// //     }

// //     return strlen(*a); //now u can take either a or b as both length has become same

// // }

// // char* get_sub_string(char* a, int start, int end){
// //     char* sub_string= (char*)malloc(sizeof(char)*(end-start+2)); //end-start+1 is for  string length and +1 is for null character

// //     for(int i=start; i<=end; i++){
// //         sub_string[i-start]= a[i];
// //     }
// //     sub_string[end-start+1]='\0';
// //     return sub_string;
// // }

// // char * add_bit_string(char* a, char*b){
// //     int length= make_same_size(&a,&b);
// //     char* result=(char*)malloc(sizeof(char)*(length+2)); //1 is for carry and 1 is for null character
// //     //here carry one bit we will manage at last 
// //     int carry=0;
// //     int bit_a=0;
// //     int bit_b=0;
// //     while(length>0){
// //         bit_a=a[length-1]-'0';
// //         bit_b=b[length-1]-'0';
// //         int temp=carry+bit_a+bit_a;
// //         if(temp>=2){
// //             carry=1;
// //             temp=temp%2;
// //         }
// //         else{
// //             carry=0;
// //         }
// //         result[length]= temp+'0'; //returning character so add 0
// //         length--;
// //     }

// //     if(carry==1) result[0]='1';
// //     else{
// //         //either shift all char one by one left
// //         //when you are reading ignore first bit - not good option 
// //         for(int i=0; i<strlen(result)-1; i++){
// //             result[i]= result[i+1];
// //         }
// //         result[strlen(result)-1]= '\0';
// //     }
// //     return result;
// // }

// // long int fast_multiply(char* a, char*b){
// //     int length=make_same_size(&a,&b);
// //     //base cases
// //     if(length==0)return 0;
// //     if(length==1) return (a[0]-'0')*(b[0]-'0');

// //     int n_left_bits=length/2;
// //     int n_right_bits=length-n_left_bits;

// //     char* a_left=get_sub_string(a,0,n_left_bits-1);
// //     char* a_right= get_sub_string(a,n_left_bits,length-1);
// //      char* b_left=get_sub_string(b,0,n_left_bits-1);
// //     char* b_right= get_sub_string(b,n_left_bits,length-1);

// //     long int A= fast_multiply(a_left,b_left);
// //     long int B= fast_multiply(a_right,b_right);
// //     long int C= fast_multiply(
// //     add_bit_string(a_left,a_right),
// //     add_bit_string(b_left,b_right)
// //     );
// //     return A*(1<<(2*n_right_bits))+(C-A-B)*(1<<n_right_bits)+B;

// //     //see return statement

    
// // }

// // int main(){
// //     char * s1= "010";
// //     char* s2= "110";
// //     assert(make_same_size(&s1,&s2)==3);

// //     s1= "10";
// //     s2= "110";
// //     assert(make_same_size(&s1,&s2)==3);
// //     assert(strcmp(s1,"010")==0);

// //      s1= "010";
// //      s2= "110";
// //     assert(make_same_size(&s1,&s2)==3);
// //     assert(strcmp(s2,"110")==0);

// //     s1="1100011";
// //     assert(strcmp(get_sub_string(s1,0,4),"11000")==0);
// //     assert(strcmp(get_sub_string(s1,4,6),"011")==0);

// //     s1="01";
// //     s2="10";
// //     assert(strcmp(add_bit_string(s1,s2),"11")==0);

// //     s1="11";
// //     s2="10";
// //     assert(strcmp(add_bit_string(s1,s2),"101")==0);

// //     assert(fast_multiply("110","11")==18);
// //      assert(fast_multiply("1101","1010")==130);


// //     return 0;
// // }




#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
int makeEqual(char **x, char **y){
    int len1=strlen(*x);
    int len2=strlen(*y);
    if(len1>len2){
        char *help=(char*)malloc(sizeof(char)*len1+1);
        int i=len1-1;
        while(i>=len1-len2){
            help[i]=y[0][i-(len1-len2)];
            i--;
        }
        while(i>=0){
            help[i]='0';
            i--;
        }
        help[len1]='\0';
        *y=help;
    }
    else if(len1<len2){
        char *help=(char*)malloc(sizeof(char)*len2+1);
        int i=len2-1;
        while(i>=len2-len1){
            help[i]=x[0][i-(len2-len1)];
            i--;
        }
        while(i>=0){
            help[i]='0';
            i--;
        }
        help[len2]='\0';
        *x=help;
    }
    return strlen(*x);
}
char* get(char*x, int left,int right){
    char *y=(char*)malloc(sizeof(char)*(right-left+2));
    for(int i=left;i<=right;i++){
        y[i-left]=x[i];
    }
    y[right-left+1]='\0';
    return y;
}
char* sum(char *x,char *y){
    int len=makeEqual(&x,&y);
    char* sum=(char*)malloc(sizeof(char)*(len+2));
    int carry=0;
    sum[len+1]='\0';
    for(int i=len-1;i>=0;i--){
        int s=(x[i]-'0')+(y[i]-'0')+carry;
        if(s>=2){
            carry=1;
        }
        else{
            carry=0;
        }
        sum[i+1]=(char)((s%2)+'0');
    }
    if(carry==1){
        sum[0]='1';
    }
    else{
        for(int i=0;i<=len;i++){
            sum[i]=sum[i+1];
        }
    }
    return sum;
}
long long int fast_mult(char *x,char *y){
    int get_len=makeEqual(&x,&y);
    // printf("%s %s\n",x,y);
    if(get_len==0){
        return 0;
    }
    else if(get_len==1){
        return (x[0]-'0')*(y[0]-'0');
    }
    int left=get_len/2;
    int right=get_len-left;
    char *xl=get(x,0,left-1);
    char *xr=get(x,left,get_len-1);
    char *yl=get(y,0,left-1);
    char *yr=get(y,left,get_len-1);
    long long int l1=fast_mult(xl,yl);
    long long int l2=fast_mult(xr,yr);
    char *xlxr=sum(xl,xr);
    char *ylyr=sum(yl,yr);
    long long int l3=fast_mult(xlxr,ylyr);
    long long int ans = (1ll << (2 * right)) * l1 + (1ll << right) * (l3-l2-l1) + l2;
    free(xl);
    free(xr);
    free(yl);
    free(yr);
    free(xlxr);
    free(ylyr);
    return ans;
}
int main(){
    assert(fast_mult("101","101")==25);
    assert(fast_mult("0101","1010")==50);
    assert(fast_mult("1011","10")==22);
}