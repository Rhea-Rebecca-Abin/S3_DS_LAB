#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;
};
struct node* head =NULL;
int count =0;
struct node* createnode(int data){

    struct node* newnode;
    newnode =malloc(sizeof(struct node));
    if (newnode == NULL)
            { printf("Stack overflow");
             exit(1);}
    newnode->next=NULL;
    newnode->data=data;
    
    return(newnode);
}

void addend(int data){

     struct node* newnode;
     newnode=createnode(data);
     if (head==NULL)
           {head=newnode;
           count ++;}
     else
         {struct node* temp =head;
         while(temp->next!=NULL)
              temp=temp->next;
         temp->next=newnode;
         //newnode->next=NULL;
         printf("\nSucess");count++;
         }
}  


void addat(int pos,int data){
     struct node* newnode;
     struct node* temp =head;
     newnode=createnode(data);
     pos--;
     while(pos!=1){
         temp=temp->next;
         pos--;
         }
     newnode->next=temp->next;
     temp->next=newnode;
     printf("\nInserted");count ++;
          
  }

void addatbeg(int data){
     struct node* newnode;
     newnode=createnode(data);
     if (head == NULL)
             {head=newnode;
             count ++;}
     else 
        {
         newnode->next=head;
         head=newnode;
         printf("Inserted");count ++;
         }}
        
void add_element_after(int data,int node_after){
       struct node* newnode;
       newnode=createnode(data);
       if (head==NULL){
             head=newnode;count ++;}
             
       else 
          {struct node* temp = head;
           while (temp!=NULL && temp->data!=node_after){
                  
                   temp=temp->next;
                  }
           if (temp == NULL)
                  printf("%d not found in the list",node_after);
           else{
           newnode->next=temp->next;
           temp->next=newnode; 
           printf("Element inserted ");count ++;
           }}}               
           
void addbefore(int data , int node_before){

     struct node* newnode;
     newnode=createnode(data);
     if (head == NULL){
          head=newnode;count++;
          }
          
     else{
         struct node* temp =head;
         while (temp!=NULL && temp->next->data!=node_before){
                  
                   temp=temp->next;
                  }
           if (temp == NULL)
                  printf("%d not found in the list",node_before);
           else{
           newnode->next=temp->next;
           temp->next=newnode; 
           printf("Element inserted ");count ++;
           }}}     
         
         
void del_beg(){
  if (head==NULL) printf("Linked list doesn't exist");
  else{
   struct node* temp=head ;
   head=head->next;
   free(temp);
   printf("\n deleted");
   }}
       
void del_end(){
      
     if (head==NULL) printf("Linked list doesn't exist");
  else{
   struct node* temp=head ;
   while(temp->next->next!=NULL){
           temp=temp->next;
           }
   temp->next=NULL;
   free(temp->next);
   printf("\nDeleted");
   }}
     

void delatpos(int pos){
    if(head ==NULL){
         printf("Linked list is empty");}
    else{ 
          struct node* temp=head;
          if (pos==1){
              
              head=head->next;
              free(temp);}
          else
             
              for(int i=1;i<pos-1;i++){
                     temp=temp->next;
                     }
              struct node* del=temp->next;
              temp->next=temp->next->next;
              free(del);
              printf("Deleted");
              }}

void small(){
      if (head ==NULL){
             printf("Linked list is empty");
             }
      else{
           struct node* temp=head;
           int small= temp->data;
           while(temp!=NULL)
              {  if (temp->data<small)
                       {small=temp->data;
                       struct node* del=temp;
                       temp=temp->next;
                       free(del);}
                 temp=temp->next;}
            printf("\n%d",small);}}
                              
          
             
     
        
void display()
{
    if(head==NULL)
        printf("\nList Empty\n");
    else
    {
        struct node*temp=head;
        printf("Head");
        while(temp!=NULL)
        {
            printf("->%d",temp->data);
            temp=temp->next;
        }
    }
    printf("\n\n");
}
int main()
{
    int choice,pos,node_after,node_before;
    do
    {
        int data;
        printf("\n1.Add elements at the end\n");
       
        printf("\n2.posElements");
        printf("\n3.addat beg");
         printf("\n4.Display Elements");
        printf("\n5.Add elements after ");
        printf("\n6.Add before ");
        printf("\n7.Delete beginning");
        printf("\n8.Delete end");
        printf("\n9.delete small");
        printf("\n10.Delete at pos");
        printf("11.Small");
        printf("\n0..Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter value : ");
                scanf("%d",&data);
                addend(data);
                printf("%d",count);
                break;
            
           
                
           
            case 2:printf("Enter value : ");
                scanf("%d",&data);
                printf("Enter position :");
                scanf("%d",&pos);
                addat(pos,data);
                printf("%d",count);
                break;
            
             case 3:
                   printf("Eneter data");
                   scanf("%d",&data);
                   addatbeg(data);
                   printf("%d",count);
                   break;
                

            
             case 4:
                display();
                break;
            case 5:
                printf("Enter value : ");
                scanf("%d",&data);
                printf("Enter node after :");
                scanf("%d",&node_after);
                add_element_after(data,node_after);
                printf("%d",count);
                break;
                 
            case 6:printf("Enter value : ");
                  scanf("%d",&data);
                  printf("Enter node before :");
                  scanf("%d",&node_before);
                  addbefore(data,node_before);
                  printf("%d",count);
                break;
                
            case 7:del_beg();
                   break;
            case 8:
                   del_end();
                   break;
                  
            
            case 10:printf("Enter position :");
                    scanf("%d",&pos);
                    delatpos(pos);
                    break;
                    
            case 11:
                    small();
                    break;
            case 0:
                exit(1);

            default:
                printf("Invalid Choice\n");
                break;
        }
    }while(choice!=0);
    return 0;
}
