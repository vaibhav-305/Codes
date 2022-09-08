#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX1 10
typedef struct Queue
{
    int arr[MAX1];
    int rear,front;

}que;
void addq(que *qu1,int val);
void delq(que *qu1);
int main()
{
   int i,j,val,n;
   que q1;
   q1.rear=-1;
   q1.front=-1;
   printf("Enter No. of values: ");
   scanf("%d",&n);
   printf("Enter Values:-\n");
   for(i=1;i<=n;i++)
   {
       scanf("%d",&val);
       addq(&q1,val);
   }
   delq(&q1);
   delq(&q1);
   delq(&q1);
   delq(&q1);
}
void addq(que *qu1,int val)
{
    if(qu1->rear==MAX1-1)
{
	printf("q is full");
	return;
}
(qu1->rear)++;
qu1->arr[qu1->rear]=val;
if (qu1->front==-1)
	qu1->front=0;
}
void delq(que *qu1)
{
int data;
if(qu1->front==-1)
{
	printf("\nq is empty");
	return NULL;
}
data=qu1->arr[qu1->front];
qu1->arr[qu1->front]=0;
if(qu1->front==qu1->rear)
{
	qu1->front=qu1->rear=-1;
}
else
	(qu1->front)++;

printf("\nDeleted value:%d",data);
}

