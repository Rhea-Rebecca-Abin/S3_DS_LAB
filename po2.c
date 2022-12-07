//Representing polynomial using linked list
#include<stdio.h>
#include <stdlib.h>
struct node{
     float coef;
     int expon;
     struct node* next;
};

void display(struct node*);

 
struct node* insert(struct node* head,float co,int ex){
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
          printf("\nSuccess");
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
      }
      return head;}
int COMPARE(int a,int b){
     if(a>b) return 1;
     if(a<b) return -1;
     if (a==b) return 0;}


void polyadd(struct node* head1, struct node* head2){
        float coefficient;
        struct node* temp1= head1;
        struct node* temp2=head2;
        struct node* head3=NULL;
        while(temp1!=NULL && temp2!=NULL){
        
                 switch(COMPARE(temp1->expon,temp2->expon)){
                 case 1:
                       head3=insert(head3,temp1->coef,temp1->expon);
                       temp1=temp1->next;
                       break;
                 case -1:
                        head3=insert(head3,temp2->coef,temp2->expon);
                       temp2=temp2->next;
                       break;
                
                 case 0:
                   coefficient =temp1->coef+temp2->coef;
                   if (coefficient!=0){
                   
                               head3=insert(head3,coefficient,temp1->expon);
                   temp1=temp1->next;
                   temp2=temp2->next;
                   break;}}}
           while(temp1!=NULL){
                 head3=insert(head3,temp1->coef,temp1->expon);
                       temp1=temp1->next;}
                 
           while(temp2!=NULL){
            
                    head3=insert(head3,temp2->coef,temp2->expon);
                    temp2=temp2->next;
                    }
           printf("Added polynomial, is");
           display(head3);
          }   
        
        
        
        
        
        
           
void display(struct node* head){
   
      if (head ==NULL){
           printf("Polynomial does not exist");}
      else
          {
           struct node* temp=head;
           while (temp!=NULL){
                   printf("%.1fx^%d",temp->coef,temp->expon);
                   temp=temp->next;
                   if (temp !=NULL)
                        printf(" + ");
                   else
                      printf("\n");
                      }}}
           
              

void main(){
struct node* head1=NULL;
struct node* head2=NULL;

printf("\nEnter the polynomial 1:\n");
head1=create(head1);
display(head1);
printf("\nCreation successful\n");
printf("\nEnter the polynomial 2:\n");
head2=create(head2);

display(head2);
polyadd(head1,head2);
}
