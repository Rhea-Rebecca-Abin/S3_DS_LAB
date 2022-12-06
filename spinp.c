#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 101
typedef struct{
int row;
int col;
int value;
}matrix;
void main()
{
matrix s[MAX_TERMS];

int m,n,i,j,k,p,q,r;
printf("Enter no of rows and columns of matrix:");
scanf("%d%d",&m,&n);
s[0].row=m;
s[0].col=n;

printf("Enter no of non zero elements:");
scanf("%d",&k);
if (k> (m*n))
    {fprintf(stderr,"\nNon zero elements greater than matrix capacity!\n");
    exit(1);}
int v=1;
s[0].value=k;

void input_sparse(){
printf("\nEnter row no (ASCENDING ORDER ,starting from 0), column no (starting from 0 ) and non zero value :\n");
for(i=0;i<k;i++)
    {printf("\nEnter row no from 0 to %d:",m-1);
     scanf("%d",&p);
     s[v].row=p;
     if (p<0 || p>m-1)
          {fprintf(stderr,"\nWrong index entered of row...sorry exiting from program!\n");
           exit(1);}
     printf("Enter col no from 0 to %d:",n-1 );
     scanf("%d",&q);
      s[v].col=q;
      if (q<0 || q>n-1)
          {fprintf(stderr,"\nWrong index of column..sorry exiting from program!\n");
           exit(1);}
      printf("Enter value :");
     scanf("%d",&r);
      s[v].value=r;
      v++;}
} 
input_sparse(); 


     
printf("\nRow\tColumn\tValue");
printf("\n%d\t%d\t%d",s[0].row,s[0].col,s[0].value);


for(j=1;j<=k;j++)
      {printf("\n%d\t%d\t%d",s[j].row,s[j].col,s[j].value);}
      
if (k==0)
       {printf("\nSparsity is 1 all elements are zeroes");}
else {
float sparsity;
int sparse;
sparse=(m*n)-k;
sparsity =(float)((float)sparse/(float)(m*n));
printf("\nSparsity of the matrix is : %f ",sparsity);
printf("\n");}



}
