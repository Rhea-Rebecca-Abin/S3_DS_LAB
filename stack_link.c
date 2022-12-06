/*9. Implement a stack using singly linked list (this can be considered as a part of
the previous assignment on stack)*/
#include<stdio.h>
#include<stdlib.h>
struct node{

int data;
struct node* link;
};
struct node*top=NULL;


void push(int data);
void pop();
void  peek();
void display();

void push(int data){

   struct node* newNode;
   newNode=malloc(sizeof(newNode));
   if (newNode==NULL){
      printf("Stack Overflow");
      exit(1);
      }
      
   newNode->data=data;
   newNode->link=NULL;
   
   newNode->link=top;
   top=newNode;
}

void pop(){
   struct node* temp;
   temp=top;
   if (top==NULL){
     printf("\nStack Underflow");
     //return;
     }
   else{
   int del=temp->data;
   top=top->link;
   free(temp);
   temp=NULL;
   printf("\n%d popped ",del);}
   }
   


void  peek(){

if(top==NULL){
   printf("Stack empty");
   
   }
else 
    printf("\nThe top is : %d",top->data);
}

void display(){

   struct node* temp;
   temp=top;
   if (top==NULL){
   
       printf("\nStack Underflow");
       }
   else{
   printf("\nThe Stack elements are ");
   while(temp!=NULL){
        printf("\n%d",temp->data);
        temp=temp->link;}}
        
   printf("\n");}
void main(){

int c,data;
do
   {
   printf("\n-------------------------------------------------------------------\n");
   printf("\nChoose operation");
   printf("\n1.Push");
   printf("\n2.Pop");
   printf("\n3.Peek");
   printf("\n4.Display");
   printf("\n0.Exit");
   printf("\n");
   scanf("\n%d",&c);
   printf("\n-------------------------------------------------------------------\n");
   switch(c){
   
      case 1:printf("\nEnter data to pushed :");
             scanf("%d",&data);
             push(data);
             break;
             
      case 2:pop();
             break;
             
      case 3:peek();
              break;
      case 4:display();
              break;
      case 0:printf("\nExiting..");
             exit(1);
      default :printf("\nWrong choice\n");
               break;}}
       while(c!=0);}
