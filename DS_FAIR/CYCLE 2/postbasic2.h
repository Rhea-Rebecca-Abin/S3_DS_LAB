#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_SIZE 100
/*Global declarartion */
char stack[MAX_SIZE];
char infix[MAX_SIZE], postfix[MAX_SIZE];
int top = -1;

void push(char);
char pop();
int isEmpty();
void inToPost();
int space (char);
void print();
int precedence (char);

void inToPost(){
    int i,j=0;
    char symbol,next;
    for(i=0;i < strlen(infix); i++)
         {symbol=infix[i]; //if symbol is not a whitespace
         
         if (!space(symbol))
         {
         switch(symbol){
         case '(':
                 push(symbol);
                 break;
         case ')':
                 while ((next=pop()) !='(')
                      postfix[j++]=next;
                 break;
                 
         case '+':
         case '-':
         case '*':
         case '/':
         case '%':
         case '^':
                while(!isEmpty() && precedence(stack[top]) >= precedence (symbol))
                             postfix[j++]=pop();
                push(symbol);break;
         
         default ://operand
                 postfix[j++]=symbol;
         }
         }
         }
     while(!isEmpty())
           postfix[j++]=pop();
     postfix[j]='\0';
}


int space(char c)
{    //If symbol is a backspace or tab
     if (c ==' '|| c=='\t')
               return 1;
     else 
         return 0;
}

int precedence (char symbol)
{ 
    switch(symbol)
    {
    //Higher value greater precedence
    case '^':return 3;
    case '/': 
    case '*':
    case '%':return 2; 
    case '+': 
    case '-':return 1;
    default :return 0;
     }
}

void print()
{
    int i=0;
    printf("The equivalent postfix expression is :");
    while(postfix[i]){
           printf("%c",postfix[i++]);
           }
    printf("\n");
}

void push (char c)
  {
     if (top == MAX_SIZE -1)
      {printf("Stack Overflow");
      return;}
     top++;
     stack[top]=c;}

char pop()
{char c;
 if (top==-1)
   {printf("Stack underflow\n");
    exit(1);
    }
 c =stack[top];
 top=top-1;
 return c;
 }
 
 int isEmpty()
    {
      if (top==-1)
           return 1;
      else
           return 0;
           
    }
