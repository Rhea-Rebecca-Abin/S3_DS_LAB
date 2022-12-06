/*2) Implement multiple stacks (2 stacks) using an array. Consider memory
efficient implementation*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
int stack[MAX_SIZE],top1=-1,top2=MAX_SIZE;
void push(int stackNo,int data)
{
     if (stackNo==1)
    {
        if (top1==top2 - 1)
        {
            printf("\nStack 1 full");
        }
        else
        {
            stack[++top1]=data;
        }
    }
    else if(stackNo==2)
    {
        if (top2==top1+1)
        {
            printf("\nStack 2 full");
        }
        else
        {
            stack[--top2]=data;
        }
    }
}
void pop(int stackNo)
{
    if (stackNo==1)
    {
        if (top1==-1)
        {
            printf("\nStack 1 empty");
           
        }
        else
        printf("Popped element is : %d", stack[top1--]);
    }
    else if(stackNo==2)
    {
        if (top2==MAX_SIZE)
        {
            printf("\nStack 2 empty");
            
        }
        else
        printf("Popped element is : %d", stack[top2++]);
    }
}
void peek(int stackNo)
{ 
   if(stackNo==1)
         {if ( top1==-1)
                printf("Stack1 empty");
         else
              printf("The top of Stack1 is : %d",stack[top1]);}
   else if(stackNo==2)
          {if (top2==MAX_SIZE)
                 printf("Stack2 empty");
            else  
                printf("The top of Stack2 is :%d",stack[top2]);}
}
void display(int stackNo)
{
    if (stackNo==1)
    {
        if (top1==-1)
        {
            printf("\nStack 1 empty");
            //return;
        }
        else
        {printf("\nElements of stack 1\n");
        for(int i=top1;i>=0;i--)
            printf("%d\n",stack[i]);}
    }
    else if(stackNo==2)
    {
        if (top2==MAX_SIZE)
        {
            printf("\nStack 2 empty");
            //return;
        }
        else{
        printf("\nElements of stack 2\n");
        for(int i=top2;i<=MAX_SIZE-1;i++)
            printf("%d\n", stack[i]);}
    }
}
void main()
{
    int stackNo, ch, element;
    printf("\nEnter stack number (1 or 2) ");
    scanf("%d", &stackNo);
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Peek");
        printf("\n4.Display");
        printf("\n5.Change stack number");
        printf("\n0. EXIT\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert ");
            scanf("%d",&element);
            push(stackNo,element);
            break;
        case 2:
            pop(stackNo);
            break;
            
        case 3:
            peek(stackNo);
            break;
        case 4:
            display(stackNo);
            break;
        case 5:
            printf("\nEnter stack number (1 or 2)");
            scanf("%d", &stackNo);
            break;
        case 0: printf("\nEXITING...");
                exit(0);
        default: printf("Invalid choice enter again");
        }
    } while(ch!=0);
    
}
