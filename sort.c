#include<stdio.h>
#include <stdlib.h>
struct node{
    
     int data;
     struct node* next;
};

struct node* insert(struct node*,int);
struct node * create(struct node*);
void print(struct node*);



 
struct node* insert(struct node* head,int data){
        struct node* temp;    
        struct node* newnode=malloc(sizeof(struct node));
        
        newnode->data=data;
        newnode->next=NULL;
        
        if (head == NULL || data < head->data)
        {     
         newnode->next=head;
         head=newnode;}
         
         else{
            temp=head;
            while(temp->next !=NULL && temp->next->data <=data)
                        temp=temp->next;
            
             newnode->next=temp->next;
             temp->next=newnode;
             }
          printf("\nSuccess");
          return head;
          }
struct node* create(struct node* head){
      int n;
      //float coefficient;
      int data;
      printf("Enter no of terms:");
      scanf("%d",&n);
      for (int i=0;i<n;i++){
             printf("Enter data:");
             
             scanf("%d",&data);
             head=insert(head,data);
      }
      return head;}
struct node* search(struct node* head,int data){   
         struct node* temp=head;
         int count=0,flag=0;
         while(temp!=NULL){
              count ++;
              if (temp->data ==data){
                      printf("\nFound");
                      flag=1;
                      printf("%d",count);
                      break;}
              temp=temp->next;}
              if (flag==0){printf("Not found");}
         return head;}


     
void print(struct node* head){
   
      if (head ==NULL){
           printf("Polynomial does not exist");}
      else
          {
           struct node* temp=head;
           while (temp!=NULL){
                   printf("%d->",temp->data);
                   temp=temp->next;
                   if (temp !=NULL)
                        printf(" -> ");
                   else
                      printf("\n");
                      }}}
           
              

void main(){

struct node* head=NULL;
int data;

head=create(head);
printf("\nCreation successful\n");
print(head);
printf("Enter data search");
scanf("%d",&data);
head=search(head,data);
}
