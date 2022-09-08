#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *prev;
    struct node *next;
    int data;
}NODE;
void add_cdll(NODE **,int );
void disp(NODE *);
int main()
{
    NODE *first=NULL;
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
            add_cdll(&first,val);
            break;
        case 2:
            printf("The Linked List:-\n");
            disp(first);
            break;

        }
    }while(opt<3);
    return 0;
}
void add_cdll(NODE **first,int num)
{
    NODE *new_node,*temp;
    new_node=(NODE *)malloc(sizeof(NODE));
    new_node->data=num;
    if((*first)== NULL)
    {
        (*first)=new_node;
        new_node->next=*first;
        new_node->prev=*first;
    }
    else
    {
        temp=*first;
        while(temp->next!=*first)
          {
              temp = temp->next;
          }
        temp->next=new_node;
        new_node->prev=temp;
        (*first)->prev=new_node;
        new_node->next=*first;
    }
}
void disp(NODE *first)
{
    struct node *temp;
    temp=first;
    if(first==NULL)
    {
        printf("Empty Linked List");
    }
    else
    {
        while(temp->next!=first)
        {
            printf("%d ",temp-> data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}
