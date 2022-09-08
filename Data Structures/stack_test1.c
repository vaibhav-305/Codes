/*#include<stdio.h>
#include<stdlib.h>
#define max1 5
typedef struct stack
{
int arr[max1],top;
}st;
int main()
{
void push(st *s,int num);
int pop (st *s);
st s;
s.top=-1;
push(&s,9);
push(&s,89);
push(&s,19);
push(&s,56);
push(&s,77);
push(&s,5);
int g,i;
for(i=0;i<7;i++)
{
g=pop(&s);
printf("%d\n",g);
}
return 0;
}
void push(st *s,int num)
{
if (s->top==max1-1)
{
    printf("\nstack is full");
    return ;
}
s->top++;
s->arr[s->top]=num;
}
int pop (st *s)
{
int y;
if(s->top==-1)
{
 printf("\nstack is empty");
 return ;
}

y=s->arr[s->top];
s->arr[s->top]=0;
s->top--;
return y;
}*/
#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int data;
    struct stack  *ptr;
}stk;
int main()
{
stk *top=NULL;
int i,d,k,num;
printf("enter total val");
scanf("%d",&k);
for(i=0;i<k;i++)
{
scanf("%d",&num);
push(&top,num);
}

return 0;
}
void push(stk **top,int num)
{
stk *temp;
temp=(stk *)malloc(sizeof(stk));
if(temp==NULL)
{
printf("stack over flow");
return ;
}
temp->data=num;
temp->ptr=*top;
}
