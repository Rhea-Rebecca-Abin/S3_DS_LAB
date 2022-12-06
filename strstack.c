/*
5) Check whether a string is palindrome.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
 
int top = -1, front = 0;
int stack[MAX];
void push(char);
void pop();
 
void main()
{
    int i, choice;
    char s[MAX], b;
    do
    {
        printf("1-enter string\n2-exit\n");
        printf("enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the String\n");
            scanf("%s", s);
            for (i = 0;s[i] != '\0';i++)
            {
                b = s[i];
                if (b >='A' && b <='Z')
                      b=b+32;
                      //printf("%c",b);
                push(b);
            }
            for (i = 0;i < (strlen(s) / 2);i++)
            {
                if (stack[top] == stack[front])
                {
                    pop();
                    front++;
                }
                else
                {
                    printf("%s is not a palindrome\n", s);
                    break; 
                }
            }
            if ((strlen(s) / 2)  ==  front)
                printf("%s is palindrome\n",  s);
            front  =  0;
            top  =  -1;
            break;
        case 2:printf("Exiting!");
            exit(0);
        default:
            printf("Enter correct choice again\n");
        }
    }
while(choice!=0);
 
}
void push(char a)
{
    top++;
    stack[top]  =  a;
}
 

void pop()
{
    top--;
}
