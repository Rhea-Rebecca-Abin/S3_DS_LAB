#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>

#define MAX_TERMS 100
typedef struct
{
    float coef;
    int expon;
}polynomial;

void main()
{
polynomial terms[MAX_TERMS];
int n,i,j,avail=0,exp;
float coef;
printf("Enter no of terms :");
scanf("%d",&n);
for(i=0;i<n;i++)

 { printf("\nEnter coefficient :");
   scanf("%f",&coef);
   terms[avail].coef=coef;
   printf("\nEnter exponent:");
   scanf("%d",&exp);
   terms[avail].expon=exp;
   avail++;}



int k=0;
    if (avail=1 && terms[k].expon ==0)
                printf("\n%.2f",terms[k].coef);
                
    else{         
    printf("\n%.2fx^%d ",terms[k].coef,terms[k].expon);
    //printf("\n");
    for(i=k+1;i<n;i++)
    {
         if(terms[i].expon==0)
            {printf("+ %.2f ",terms[i].coef);
           // printf("\n");
           }
        else
            {printf("+ %.2fx^%d ",terms[i].coef,terms[i].expon);
            //printf("\n");
            }
    }}
    printf("\n");
    
float x;
printf("Enter the value of x :\n");
scanf("%f",&x);
float sum=0;
for(i=0;i<n;i++)
   {sum=sum+(terms[i].coef*(pow(x,terms[i].expon)));}


printf("The value of polynomial is :\t%f",sum);
printf("\n");
}


