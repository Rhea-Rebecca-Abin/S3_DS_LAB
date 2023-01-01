#include "postbasic2.h"
int main()
{
  printf("Enter the infix expression : ");
  scanf("%[^\n]",infix);
  
  inToPost();
  print();
  return 0;
}
