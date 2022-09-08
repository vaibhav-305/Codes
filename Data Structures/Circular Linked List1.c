#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

void disp(NODE *,NODE *);
void add_cll(NODE **,NODE **,int );

int main()
{
    NODE *first=NULL,*tail=NULL;
    int opt,val;
    do
    {
        printf("\n**********MENU**********");
        printf("\n1. Add element");
        printf("\n2. Display List");
        printf("\n3. Exit");
        printf("\n************************");
        printf("\nEnter Option: ");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            printf("Enter value to be added: ");
            scanf("%d",&val);
            add_cll(&first,&tail,val);
            break;
        case 2:
            printf("The Linked List:-\n");
            disp(first,tail);
            break;

        }
    }while(opt<3);
    return 0;
}
void add_cll(NODE **first,NODE **tail,int num)
{
    NODE *new1=(NODE *)malloc(sizeof(NODE));
    new1->data=num;
    if (*first==NULL)
    {
        *first=new1;
        *tail=new1;
    }
    else
    {
        (*tail)->next=new1;
        (*tail)=new1;
    }
    (*tail)->next=(*first);
}
void disp(NODE *first,NODE *tail)
{
    NODE *temp=first;
    if(temp==NULL)
    {
        printf("The Linked List is Empty.");
        return ;
    }
    while(temp!=tail)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}


