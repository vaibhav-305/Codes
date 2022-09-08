#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
typedef struct node
{
int data;
struct node *ptr;
}NODE;
//program to make and take input in linked list
char ch;
NODE *first=NULL,*head,*temp;

do
{
head=(NODE *)malloc(sizeof(NODE));
printf("enter data");
scanf("%d",&head->data);
if(first!=NULL)
{
temp->ptr=head;
temp=head;
}
else
{
first=temp=head;
}
printf("do you want to con.....");
scanf(" %c",&ch);//Atleast a single space should be left before %c so program works.
}while(ch=='Y' || ch=='y');
temp->ptr=NULL;
//code to print linked list
temp=first;
while(temp!=NULL)
{
printf("%3d",temp->data);
temp=temp->ptr;
}

return 0;
}
