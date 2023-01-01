#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include "postbasic2.h"
int  s[MAX_SIZE]; 


int post_eval();
void push_p(int);
int pop_p();
void inToPostfix();

int main(){

int result;
  printf("Enter the infix expression   : ");
  scanf("%[^\n]",infix);
  
  inToPostfix();
  result =post_eval();
  print();
  printf("The result obtained after postfix evaluation is : ");
  printf("%d\n",result);
  return 0;
}


void inToPostfix(){
    int i,j=0;
    char symbol,next;
    for(i=0;i < strlen(infix); i++)
         {symbol=infix[i]; //if symbol is not a whitespace
         
         if (!space(symbol))
         {
         switch(symbol){
         case '(':
                 push_p(symbol);
                 break;
         case ')':
                 while ((next=pop_p()) !='(')
                      postfix[j++]=next;
                 break;
                 
         case '+':
         case '-':
         case '*':
         case '/':
         case '%':
         case '^':
                while(!isEmpty() && precedence(s[top]) >= precedence (symbol))
                             postfix[j++]=pop_p();
                push_p(symbol);break;
         
         default ://operand
                 postfix[j++]=symbol;
         }
         }
         }
     while(!isEmpty())
           postfix[j++]=pop_p();
     postfix[j]='\0';
}

int post_eval(){
   int i,a,b;
   for(i=0;i<strlen(postfix); i++) {
        if(postfix[i] >= '0' && postfix[i]<='9')
           { push_p(postfix[i]-'0');}//Pushing integer equivalent
        else 
           {
            a=pop_p();
            b=pop_p();
            switch(postfix[i]){
            
            case '+' :
                 push_p(b+a);break;
            case '-' :
                 push_p(b-a);break;
            case '*' :
                 push_p(b*a);break;
            case '/':
                 push_p(b/a);break;
            case '^':
                 push_p(pow(b,a)); break;
            case '%':
                 push_p(b%a);break;
            }
            }
            }
            return pop_p();
            }

           
void push_p (int v)
  {
     if (top == MAX_SIZE -1)
      {printf("Stack Overflow");
      return;}
     top++;
     s[top]=v;}

int pop_p()
{int v;
 if (top==-1)
   {printf("STACK UNDERFLOW\n");
    exit(1);
    }
 v =s[top];
 top=top-1;
 return v;
 }
