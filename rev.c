#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;
};
struct node* head=NULL;

struct node* create(struct node* head,int data){
        struct node* newnode=malloc(sizeof(struct node));
        newnode->data=data;
        newnode->next=NULL;
        if (head ==NULL){
               
               head=newnode;}
        else{
             struct node* temp=head;
             while(temp->next!=NULL){
                   temp=temp->next;}
             temp->next=newnode;}
        return head;
        }
void display(struct node* head){
                        
        if (head ==NULL){
               
               printf("Linked list doesn't exist");}
        else{
              struct node* temp=head;
              while(temp!=NULL){
                 if(temp->next!=NULL)
                   {   printf("%d->",temp->data);
                         temp=temp->next;}
                  else
                       {   printf("%d",temp->data);
                         temp=temp->next;}}}
           } 
           
struct node* reverse(struct node* head){
     struct node* prevnode=NULL;
     struct node* currentnode=head;
     struct node* nextnode=head;
     while(nextnode!=NULL){
     
              nextnode=nextnode->next;
              currentnode->next=prevnode;
              prevnode=currentnode;
              currentnode=nextnode;}
              head=prevnode;
      return head;  }   
void main(){
int data,n;
printf("ENter no of terms");
scanf("%d",&n);
for(int i=0;i<n;i++){
         printf("\nENter  data:");
         scanf("%d",&data);
         head=create(head,data);}
display(head);
head=reverse(head);
printf("\nReversed!!!");
printf("\n");
display(head);}         
                 
             
