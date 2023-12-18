#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
}stu;

void addinLL(int val, struct Node** head){
    struct Node* temp = NULL;
    temp->data = val;
    (*head)->next=temp;
    *head=temp;
}
int main(){
     struct Node* head=NULL;
     head->data=-1;
    //  head->next=NULL;
     printf("head value is %d\n",head->data);
    //  addinLL(10,&head);
    //  printf("head value is %d",head->data);
}