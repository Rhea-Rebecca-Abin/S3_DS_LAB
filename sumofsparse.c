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
matrix s1[MAX_TERMS];
matrix s2[MAX_TERMS];
matrix s3[MAX_TERMS];
int m,n,i,j,k,p,q,r,u,g;
//Entering rows and columns
printf("Enter no of rows and columns of matrix 1:");
scanf("%d%d",&m,&n);
printf("Enter no of rows and columns of matrix 2:");
scanf("%d%d",&u,&g);
//Checking 
if (m==u && n==g)
     //Input Sparse representation for first matrix
{    s1[0].row=m;
     s1[0].col=n;

     printf("\nEnter no of non zero elements for MATRIX 1:");
     scanf("%d",&k);
     if (k> (m*n))
        {fprintf(stderr,"\nNon zero elements greater than matrix capacity!\n");
             exit(1);}
     int v=1;
     s1[0].value=k;
 
     
       printf("\nEnter row no (ASCENDING ORDER ,starting from 0), column no (starting from 0 ) and  non zero value :\n");
       for(i=0;i<k;i++)
         {printf("\nEnter row no from 0 to %d:",m-1);
                    scanf("%d",&p);
                     s1[v].row=p;
          if (p<0 || p>m-1)
          {fprintf(stderr,"\nWrong index entered of row...sorry exiting from program!\n");
           exit(1);}
          printf("Enter col no from 0 to %d:",n-1 );
               scanf("%d",&q);
               s1[v].col=q;
          if (q<0 || q>n-1)
                {fprintf(stderr,"\nWrong index of column..sorry exiting from program!\n");
                 exit(1);}
                 printf("Enter value :");
                 scanf("%d",&r);
                 s1[v].value=r;
                 v++;}
    printf("\nRow\tColumn\tValue");
    printf("\n%d\t%d\t%d",s1[0].row,s1[0].col,s1[0].value);
    printf("\n---------------------------------------");
    for(j=1;j<=s1[0].value;j++)
        
       {printf("\n%d\t%d\t%d",s1[j].row,s1[j].col,s1[j].value);}
    
     
     
     //Input Sparse representation for second matrix
     s2[0].row=m;
     s2[0].col=n;
     int h;
     printf("\nEnter no of non zero elements for MATRIX 2:");
     scanf("%d",&h);
     if (h> (m*n))
        {fprintf(stderr,"\nNon zero elements greater than matrix capacity!\n");
             exit(1);}
     
     s2[0].value=h;
     int b=1;
 
     
       printf("\nEnter row no (ASCENDING ORDER ,starting from 0), column no (starting from 0 ) and  non zero value :\n");
       for(i=0;i<h;i++)
         {printf("\nEnter row no from 0 to %d:",m-1);
                    scanf("%d",&p);
                     s2[b].row=p;
          if (p<0 || p>m-1)
          {fprintf(stderr,"\nWrong index entered of row...sorry exiting from program!\n");
           exit(1);}
          printf("Enter col no from 0 to %d:",n-1 );
               scanf("%d",&q);
               s2[b].col=q;
          if (q<0 || q>n-1)
                {fprintf(stderr,"\nWrong index of column..sorry exiting from program!\n");
                 exit(1);}
                 printf("Enter value :");
                 scanf("%d",&r);
                 s2[b].value=r;
                 b++;}
      printf("\nRow\tColumn\tValue");
    printf("\n%d\t%d\t%d",s2[0].row,s2[0].col,s2[0].value);
    printf("\n---------------------------------------");
    for(j=1;j<=s2[0].value;j++)
        
       {printf("\n%d\t%d\t%d",s2[j].row,s2[j].col,s2[j].value);}
 
    s3[0].row=s1[0].row;
    s3[0].col=s1[0].col;

    int z = 1, x = 1, y = 1;

    for (int i = 0; i < s1[0].row; i++)
        for (int j = 0; j < s1[0].col; j++)
        {
            if (s1[x].row == i && s1[x].col == j && s2[y].row == i && s2[y].col == j)
            {
                s3[z].row = i;
                s3[z].col = j;
                s3[z].value = s1[x].value + s2[y].value;
                x++;
                y++;
                z++;
            }
            else if (s1[x].row == i && s1[x].col == j)
            {
                s3[z].row = i;
                s3[z].col = j;
                s3[z].value = s1[x].value;
                x++;
                z++;
            }
            else if (s2[y].row == i && s2[y].col == j)
            {
                s3[z].row = i;
                s3[z].col = j;
                s3[z].value = s2[y].value;
                y++;
                z++;
            }
        }
    s3[0].value = --z;
               
    
    printf("\nADDITION ");
    printf("\nRow\tColumn\tValue");
    printf("\n%d\t%d\t%d",s3[0].row,s3[0].col,s3[0].value);
    printf("\n---------------------------------------");
    for(j=1;j<=s3[0].value;j++)
        
       {printf("\n%d\t%d\t%d",s3[j].row,s3[j].col,s3[j].value);
       }
     printf("\n");
}
else
  printf("Matrices incompatible for addition\n");
}


      
      
      
      
      
