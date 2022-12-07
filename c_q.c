//Queue
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
void enqueue(int );
void dequeue();
int peek();
void display();
int front =-1;
int rear=-1;

void enqueue(int data){
     if ((rear+1)%MAX==front){
            printf("Queue full");}
     else if (front ==-1 && rear ==-1){
               front=0;rear=0;
               queue[rear]=data;}
     else
          rear=(rear+1)%MAX;
          queue[rear]=data;}
void dequeue(){
int del;
     if (front ==-1 && rear==-1){
                 printf("Queue empty");
                 }
       
      else if(front ==rear){
             del=queue[front];
             printf("\n%d deleted",del);
             front=-1;
             rear=-1;
             }
      else
            {
            del=queue[front];
            printf("Deleted %d",del);
            front =++front%MAX;
            //printf("\n%d is the  New front ",queue[front]);
            }}

int  peek(){
   if (front =-1 && rear==-1){ 
             printf("Queue is empty");
             return 0;}
             
    else {
        return front;}}
void display()
{   int i=front;
    if (front == -1)
        printf("\nQueue empty");
    else
    {
        printf("\n");
           while(i!=rear)
              { printf("%d |",queue[i]);
               i=(i+1)%MAX;}
              
           printf("%d",queue[rear]); 
    }
}
int main()
{
    int ch, element;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display queue");
        printf("\n4.Display Front Element");
        printf("\n5.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            printf("%d",queue[front]);
            break;
        }
    } while (ch < 5);

    return 0;
}
