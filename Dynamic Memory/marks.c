#include<stdio.h>

#include<stdlib.h>

int main(){

   int* ptr=(int*)malloc(sizeof(int));

   int index=0;

   printf("print marks of first student\n");

   int n;

   scanf("%d",&n);

   ptr[index]=n;

   printf("marks of first is %d\n",ptr[index]);

   printf("do you want to see more marks if yes print 1 else print 0\n");

   int a;

   scanf("%d",&a);

   if(!a){

      free(ptr);

      return 0;

   }

   ptr=realloc(ptr,sizeof(int));

   int x;

   scanf("%d",&x);

  ptr[++index]=x;

   printf("marks of second is %d\n",ptr[index]);

    printf("do you want to see more marks if yes print 1 else print 0\n");

   scanf("%d",&a);

   if(!a){
      free(ptr);
      return 0;
   }
   ptr=realloc(ptr,sizeof(int));
   scanf("%d",&x);
   ptr[++index]=x;
   printf("marks of third is %d\n",ptr[index]);
   free(ptr);

}



