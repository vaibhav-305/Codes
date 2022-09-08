#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int data;
    struct stack *ptr;
}stk;
void push(stk **,int );
void pop(stk **);
int main()
{
    stk *top=NULL;
    int i,val;
    printf("Enter no. of values:");
    scanf("%d",&i);
    printf("Enter values:\n");
    for(int x=0;x<i;x++)
    {
        scanf("%d",&val);
        push(&top,val);
    }
    pop(&top);
    pop(&top);
    pop(&top);
    pop(&top);
  return 0;
}
void push(stk **top,int val)
{
    stk *temp;
    temp=(stk *)malloc(sizeof(stk));
    if(temp==NULL)
    {
        printf("Stack Overflow");
        return ;
    }
    temp->data=val;
    temp->ptr=*top;
    *top=temp;
}
void pop(stk **top)
{
    int d;
    if((*top)==NULL)
    {
        printf("\nStack Underflow");
        return ;
    }
    d=(*top)->data;
    printf("\nPopped value: %d",d);
    (*top)=(*top)->ptr;
}
