//Queue
#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int queue[MAX];
void enqueue(int );
void dequeue();
void peek();
void display();
int front =-1;
int rear=-1;

void enqueue(int data){
     if (rear==MAX -1){
            printf("Queue full");}
     else if (front ==-1 && rear ==-1){
               front=0;rear=0;
               queue[rear]=data;}
     else
          queue[++rear]=data;}
void dequeue(){
int del;
     if (front ==-1 && rear==-1){
                 printf("Queue empty");
                 }
       
      else if(front ==rear){
             printf("\n%d deleted",queue[front]);
             front=-1;
             rear=-1;
             }
      else
            printf("Deleted %d",queue[front++]);}

void peek(){
   if (front =-1 && rear==-1){ 
             printf("Queue is empty");}
             
    else {
        printf("%d",queue[front]);}}
void display()
{
    if (front == -1)
        printf("\nQueue empty");
    else
    {
        printf("\n");
        for (int i = front; i <= rear; i++)
        {
            if(i!=rear)
                 printf("%d|", queue[i]);
             else
                  printf("%d ", queue[i]);
        }
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
            
            break;
        }
    } while (ch < 5);

    return 0;
}
