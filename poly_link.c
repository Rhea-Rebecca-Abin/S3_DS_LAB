//Representing polynomial using linked list
#include<stdio.h>
#include <stdlib.h>
struct node{
     float coef;
     int expon;
     struct node* next;
};



 
struct node* insert(struct node* head, float co,int ex){
        struct node* temp;    
        struct node* newnode=malloc(sizeof(struct node));
        newnode->coef=co;
        newnode->expon=ex;
        newnode->next=NULL;
        
        if (head == NULL || ex > head->expon)
        {     
         newnode->next=head;
         head=newnode;}
         
         else{
            temp=head;
            while(temp->next !=NULL && temp->next->expon >= ex)
                        temp=temp->next;
            
             newnode->next=temp->next;
             temp->next=newnode;
             }
          printf("Sucess");
          return head;
          }
struct node* create(struct node* head){
      int n;
      float coefficient;
      int exponent;
      printf("Enter no of terms:");
      scanf("%d",&n);
      for (int i=0;i<n;i++){
             printf("Enter coefficient for term %d:",i+1);
             scanf("%f",&coefficient);
             printf("ENter exponent for term %d:",i+1);
             scanf("%d",&exponent);
             head=insert(head,coefficient,exponent);
      }}
        
void print(struct node* head){
   
      if (head ==NULL){
           printf("Polynomial does not exist");}
      else
          {
           struct node* temp=head;
           while (temp!=NULL){
                   printf("%.2fx^%d",temp->coef,temp->expon);
                   temp=temp->next;
                   if (temp !=NULL)
                        printf(" + ");
                   else
                      printf("\n");
                      }}}
           
              

void main(){

struct node* head=NULL;
printf("Enter the polynomial:\n");
head=create(head);
printf("Creation successful");
print(head);
}
