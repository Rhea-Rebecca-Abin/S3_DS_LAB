//4) Convert a given decimal number into binary and hex.
#include<stdio.h>
#define MAX_SIZE 100
#include "stack_basic.h"


int pop_bit()
{
    int del;
    if(top==-1)
    {
        printf("\nStack empty.");
        return -1;
    }
    else
    {
        del=stack[top--];
        return del;
    }
}


void convertToBinary(int num)
{
    while(num!=0)
    {
        push(num%2);
        num/=2;
    }
}
void displayBinary()
{
    printf("\nBinary : ");
    while(top!=-1)
    {
        printf("%d",pop_bit());
    }
    printf("\n");
}
void convertToHex(int num)
{
    while(num!=0)
    {
        push(num%16);
        num/=16;
    }
}
void displayHex()
{
    printf("\nHex : ");
    while(top!=-1)
    {
        int disp=pop_bit();
        if (disp >=10)
             printf("%c",disp+55);
        
         else
             printf("%d",disp); }
    }
    

int main()
{
    int num;
    printf("Enter a number : ");
    scanf("%d",&num);
    convertToBinary(num);
    displayBinary();
    convertToHex(num);
    displayHex();
    return 0;
}
