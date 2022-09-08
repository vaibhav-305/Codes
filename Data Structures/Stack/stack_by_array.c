#include <stdio.h>
#include <stdlib.h>
#define max1 10
typedef struct stack
{
    int arr[max1],top;
}st;
void push(st *,int );
void pop(st* );
void display(st *);
void peep(st *);
int main()
{
    st s;
    s.top=-1;
    int v,val;
    printf("Enter No. of values:");
    scanf("%d",&v);
    printf("Enter values:\n");
    for(int i=0;i<v;i++)
    {
        scanf("%d",&val);
        push(&s,val);
    }
    display(&s);
    peep(&s);
    pop(&s);
    display(&s);
    pop(&s);
    pop(&s);
    peep(&s);
    pop(&s);
    peep(&s);
    display(&s);

  return 0;
}
void push(st *s,int val)
{
    if(s->top==max1-1){
        printf("\nStack full");
        return ;
        }
    s->top++;
    s->arr[s->top]=val;
}
void pop(st *s)
{
    if(s->top==-1)
    {
        printf("\nEmpty Stack");
        return ;
    }
    int i=s->arr[s->top];
    printf("\nPopped value=%d",i);
    s->top--;
}
void display(st *s)
{
    printf("\nStack: ");
    if(s->top==-1)
    {
        printf("Stack is Empty");
        return ;
    }
    for(int i=0;i<=s->top;i++)
        printf("%d ",s->arr[i]);
}
void peep(st *s)
{

    printf("\nPeep look:");
    if(s->top==-1)
    {
        printf("Stack is empty");
        return ;
    }
    printf("%d",s->arr[s->top]);
}
