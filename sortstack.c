//4) Implement a sorted push so that stack is always maintained in sorted order.
#include <stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
#include "stack_basic.h"

void push_sort(int data)
{
    if(top==MAX_SIZE-1)
        printf("\nStack Overflow");
    else if(top==-1)
        stack[++top]=data;
    else
    {
        int tempStack[MAX_SIZE],tempTop=-1;
        while(data>stack[top]&&top!=-1)
        {
            int del=stack[top--];
            tempStack[++tempTop]=del;
        }
        stack[++top]=data;
        while(tempTop>=0)
        {
            int del=tempStack[tempTop--];
            stack[++top]=del;
        }
    }    
}


void main()
{
    int ch,element;
    do
    {
        printf("\nChoose operation");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Peek");
        printf("\n4.Display");
        printf("\n0.Exit");
        printf("\nEnter an option\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the element to insert\n");
                scanf("%d",&element);
                push_sort(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;        
            case 4:
                display();
                break;
                
            case 0:
                 printf("Exiting\n");
                 exit(0);
            default:printf("Invalid choice enter again \n");
        }
    }while(ch!=0);
    
}
