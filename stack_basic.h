#define MAX_SIZE 100
int stack[MAX_SIZE],top=-1;
void push(int data)
{
    if(top==MAX_SIZE-1)
        printf("Stack Overflow\n");
    else
    stack[++top]=data;
}
int pop()
{
    
    if(top==-1)
        printf("Stack Empty\n");
     
    else
    {
        int d=stack[top--];
        printf("Deleted : %d\n",d);
    }    
}

void peek(){
	int a;
	if(top==-1)
        printf("Stack Empty\n");
	
	else{
	a=stack[top];
	printf("Top is : %d",a);}}
void display()
{
    if(top==-1)
        printf("Stack empty.\n");
    else
    {
        printf("\n");
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}

