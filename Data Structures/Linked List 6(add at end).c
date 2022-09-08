#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
NODE *create(NODE *);
NODE *add(NODE *);
int main()
{
    NODE *first=NULL;
    first=create(first);
    first=add(first);
    disp(first);
  return 0;
}
NODE *create(NODE *start)
{
    NODE *head,*temp;
    char ch;
    do
    {
        head=(NODE *)malloc(sizeof(NODE));
        printf("enter data: ");
        scanf("%d",&head->data);
        if(start!=NULL)
        {
            temp->next=head;
            temp=head;
        }
        else
        {
            start=temp=head;
        }
        printf("do you want to con.....");
        scanf(" %c",&ch);//Atleast a single space should be left before %c so program works.
    }while(ch=='Y' || ch=='y');
    temp->next=NULL;
 return start;
}
NODE *add(NODE *start)
{
    NODE *temp;
    temp=start;
    NODE *new1=(NODE *)malloc(sizeof(NODE));
    printf("enter new data:");
    scanf("%d",&new1->data);
    while(temp->next!=NULL)
    {
        /*NODE *new1=(NODE *)malloc(sizeof(NODE));
        printf("enter new data:");
        scanf("%d",&new1->data);*/
        //printf("%3d",temp->data);
        temp=temp->next;
        if(temp==NULL)
        {

            temp->next=new1;
            new1->next=NULL;

        }
    }
  return start;
}
void disp(NODE *start)
{
    NODE *temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("%3d",temp->data);
        temp=temp->next;
    }
}
