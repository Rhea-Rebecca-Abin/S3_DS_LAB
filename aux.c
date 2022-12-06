/*3) Find the minimum element in a stack in O (1) time using an auxiliary stack
which keeps track of the minimum element.*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stack[MAX],top=-1;
int aux[MAX],auxTop=-1;

void push(int data)
{
    if(top==MAX-1)
        printf("\nStack Overflow");
    else
    {
        stack[++top]=data;
        if(auxTop==-1)
        {
            aux[++auxTop]=data;
        }  
        else{
            if(data<=aux[auxTop])
            {
                aux[++auxTop]=data;
            }
        }
    }    
}
void pop()
{
    int del;
    if(top==-1)
    {
        printf("\nStack empty.");
    }
    else{
        del=stack[top--];
        if(del==aux[auxTop])
        {
            auxTop--;
        }
        printf("\nDeleted : %d",del);
    }
}
void display()
{
    if (top==-1)
        printf("\nStack empty");
    else
    {
        printf("\n");
        for (int i=top;i>=0;i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
void get_min()
{
    if(auxTop==-1)
        printf("\nStack Empty");
    else
        printf("\nMinimum Element : %d",aux[auxTop]);    
}

void peek(){
   if(top==-1)
        printf("Stack empty");
    else
        printf("The top is : %d",stack[top]);

}
int main()
{
    int ch,element;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Peek");
        printf("\n4.Display stack");
        printf("\n5.Display minimum");
        printf("\n0.Exit\n");
        printf("\nEnter an operation\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter element to insert\n");
            scanf("%d",&element);
            push(element);
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
            
            case 5:
                get_min();
                break;    
                
           
            case 0:
                 printf("Exiting\n");
                 exit(0);
           default:printf("Invalid choice enter again \n");
                        
        }
    }while(ch!=0);
    return 0;
}
