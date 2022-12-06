#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100

int top=-1;
char stack[MAX_SIZE];
void push(char);
char pop();
int isEmpty();

int check_balanced(char*);
int match_char(char,char);


int main(){
     
     char expr[MAX_SIZE];
     int balanced;
     printf("Enter the algebraic expression :");
     scanf("%[^\n]",expr);
     
     balanced=check_balanced(expr);
     if (balanced ==1)
            printf("The expression is valid");
     else
         printf("The expression is not valid");
     
     
     return 0;
}

int check_balanced(char* s){

  int i;char temp;
  for(i=0;i<strlen(s);i++){
  
      //If symbol is left bracket push that onto stack
      if(s[i]=='[' || s[i]== '{'|| s[i]=='(')
             push(s[i]);
       //If the symbol is a right bracket      
      if (s[i]==']' || s[i]=='}' || s[i]==')')
      {
             if(isEmpty()){
                  printf("Right backets are more than the left .\n");
                  return 0; }//Expression  not balanced
             
             else {
                   temp=pop();
                   if(!match_char(temp,s[i])){
                          printf("Mismatched brackets..\n");
                          return 0;}
                   }
                  }
     }
     
  if(isEmpty()){
        printf("Brackets are well balanced.\n");
        return 1;
        }
  else{
      printf("Left brackets are more than the right.\n"); 
      return 0;}
    
    
} 

int match_char(char a, char b){
     if(a == '[' && b==']')
           return 1;
     if (a == '{' && b == '}')
           return 1;
     if (a =='(' && b ==')')
            return 1;
     return 0;
}    
      
void push(char c)
{
     if (top ==MAX_SIZE -1)
           {printf("Stack Overflow");
           exit(1);}
     stack[++top]=c;
}    
    
char pop()  {
   char c;
   if(isEmpty()){
     printf("Stack Underflow");
     exit(1);}
   c=stack[top];
   top--;
   return c;
}

int isEmpty(){
    if (top ==-1)
         return 1;
         
    else 
         return 0;
}   
    
    
