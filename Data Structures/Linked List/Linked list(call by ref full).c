#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *ptr;
}NODE;
void create_ll(NODE **);
void display_ll(NODE **);
void insert_begn(NODE **);
void add_end(NODE **);
void add_before(NODE **);
void add_after(NODE **);
void delete_begn(NODE **);
void delete_end(NODE **);
void delete_after(NODE **);
int main()
{
 NODE *first=NULL;
 int opt;
 do
 {
     printf("\n********MAIN MENU********");
     printf("\n 1: Create List");
     printf("\n 2: Display List");
     printf("\n 3: Add a node at beginning");
     printf("\n 4: Add a node at end");
     printf("\n 5: Add a node before");
     printf("\n 6: Add a node after");
     printf("\n 7: Delete from beginning");
     printf("\n 8: Delete from end");
     printf("\n 9: Delete after");
     printf("\n 10: Exit");
     printf("\n**************************");
     printf("\nEnter option: ");
     scanf("%d",&opt);
     switch(opt)
     {
     case 1:
        create_ll(&first);
        break;
     case 2:
        display_ll(&first);
        printf("\n");
        break;
     case 3:
        insert_begn(&first);
        printf("\n");
        break;
     case 4:
        add_end(&first);
        printf("\n");
        break;
     case 5:
        add_before(&first);
        printf("\n");
        break;
     case 6:
        add_after(&first);
        printf("\n");
        break;
     case 7:
        delete_begn(&first);
        printf("\n");
        break;
     case 8:
        delete_end(&first);
        printf("\n");
        break;
     case 9:
        delete_after(&first);
        printf("\n");
        break;
     }
 }while(opt !=10);
 return 0;
}
void create_ll(NODE **start)
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
            temp->ptr=head;
            temp=head;
        }
        else
        {
            *start=temp=head;
        }
        printf("do you want to con.....");
        scanf(" %c",&ch);//Atleast a single space should be left before %c so program works.
    }while(ch=='Y' || ch=='y');
    temp->ptr=NULL;
}
void display_ll(NODE **start)
{
    NODE *temp;
    temp=*start;
    while(temp!=NULL)
    {
        printf("%3d",temp->data);
        temp=temp->ptr;
    }
}
void insert_begn(NODE **start)
{
    NODE *new_node;
    int num;
    printf("\nEnter new value: ");
    scanf("%d",&num);
    new_node=(NODE *)malloc(sizeof(NODE));
    new_node->data=num;
    new_node->ptr=*start;
    (*start)=new_node;

}
void add_end(NODE **start)
{
    NODE *temp,*new_node;
    int num;
    printf("Enter new value: ");
    scanf("%d",&num);
    new_node=(NODE *)malloc(sizeof(NODE));
    new_node->data=num;
    new_node->ptr=NULL;
    temp=*start;
    while(temp->ptr!=NULL)
        temp=temp->ptr;
    temp->ptr=new_node;
}
void add_before(NODE **start)
{
    NODE *temp,*loc,*new_node;
    int num;
    printf("Enter new value: ");
    scanf("%d",&num);
    new_node=(NODE *)malloc(sizeof(NODE));
    new_node->data=num;
}
void add_after(NODE **start)
{
    NODE *temp,*loc,*new_node;
    int num;
    printf("Enter new value: ");
    scanf("%d",&num);
    new_node=(NODE *)malloc(sizeof(NODE));
    new_node->data=num;
}
void delete_begn(NODE **start)
{
    NODE *temp;
    temp=*start;
    if(*start==NULL)
    {
        printf("No linked list");
    }
    else
    {
        if((*start)->ptr==NULL)
           {
            *start = NULL;
            printf("There was only one element in linked list which is deleted");
           }
        else
            {
        *start = (*start)->ptr;
            }
    }
        free(temp);
}
void delete_end(NODE **start)
{
    NODE *temp,*pretemp;
    temp=*start;
    if((*start)==NULL)
    {
        printf("No linked list");
    }
    else
    {
        if((*start)->ptr==NULL)
           {
            *start = NULL;
            printf("There was only one element in linked list which is deleted");
           }
           else
           {
               while(temp->ptr!=NULL)
               {
                   pretemp=temp;
                   temp=temp->ptr;
               }
            pretemp->ptr=NULL;
            free(temp);
           }
    }
}
void delete_after(NODE **start)
{
    NODE *temp,*pretemp;
    int val;
    printf("Enter value of the node which is to be deleted: ");
    scanf("%d",&val);
    temp=*start;
    while(pretemp->data!=val)
        {
           pretemp=temp;
           temp=temp->ptr;

        }
    pretemp->ptr=temp->ptr;
    free(temp);
}
