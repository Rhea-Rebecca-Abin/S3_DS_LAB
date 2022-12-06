
#include<stdio.h>
#include <stdlib.h>
#include "stack_basic.h"

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
                
            case 0:
                 printf("Exiting\n");
                 exit(0);
            default:printf("Invalid choice enter again \n");
        }
    }while(ch!=0);
    
}
