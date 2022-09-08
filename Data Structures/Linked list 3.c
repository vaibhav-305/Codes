#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
void create(NODE **);
void disp(NODE **);
int main()
{
    NODE *first=NULL;
    create(&first);
    disp(&first);
  return 0;
}
void create(NODE **start)
{
    NODE *head,*temp;
    char ch;
    do
    {
        head=(NODE *)malloc(sizeof(NODE));
        printf("enter data: ");
        scanf("%d",&head->data);
        if(*start!=NULL)
        {
            temp->next=head;
            temp=head;
        }
        else
        {
            *start=temp=head;
        }
        printf("do you want to con.....");
        scanf(" %c",&ch);//Atleast a single space should be left before %c so program works.
    }while(ch=='Y' || ch=='y');
    temp->next=NULL;
 //return start;
}
void disp(NODE **start)
{
    NODE *temp;
    temp=*start;
    while(temp!=NULL)
    {
        printf("%3d",temp->data);
        temp=temp->next;
    }
}

