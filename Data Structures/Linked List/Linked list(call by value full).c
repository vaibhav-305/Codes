#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *ptr;
}NODE;
NODE * create_ll(NODE *);
void display(NODE *);
NODE * add_at_beg(NODE *);
NODE * add_at_end(NODE *);
NODE * add_at_specificloc(NODE *);
NODE * delete_begn(NODE *);
NODE *sort_asc(NODE *);
int main()
{
    NODE *start=NULL;
    int opt;
    do
    {
        printf("\n************** MENU ***************");
        printf("\n1. Create Linked list");
        printf("\n2. Display Linked List");
        printf("\n3. Add a node at Beginning");
        printf("\n4. Add a node at end");
        printf("\n5. Add a node at specific Location");
        printf("\n6. Delete from Beginning");
        printf("\n7. Sort in ascending order(bubble sort)");
        printf("\n8. Exit");
        printf("\n***********************************");
        printf("\nSelect option:");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            start=create_ll(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            start=add_at_beg(start);
            break;
        case 4:
            start=add_at_end(start);
            break;
        case 5:
            start=add_at_specificloc(start);
            break;
        case 6:
            start=delete_begn(start);
            break;
        case 7:
            start=sort_asc(start);
            break;
        }
    }while(opt<8);
  return 0;
}
NODE * create_ll(NODE *start)
{
    NODE *head,*temp;
    char c;
    do
    {
        head=(NODE *)malloc(sizeof(NODE));
        printf("Enter Data:");
        scanf("%d",&head->data);
        if(start!=NULL)
        {
            temp->ptr=head;
            temp=head;
        }
        else
            temp=start=head;
        printf("Do you want to continue...");
        scanf(" %c",&c);

    }while(c=='Y' || c=='y');
    temp->ptr=NULL;
  return start;
}
void display(NODE *start)
{
    printf("The Linked List:-\n");
    NODE *temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->ptr;
    }
}
NODE * add_at_beg(NODE *start)
{
    NODE *new_node;
    char c;
    if(start==NULL)
        printf("Linked list is empty\n");
    new_node=(NODE *)malloc(sizeof(int));
    printf("Enter value to be added at begn:");
    scanf("%d",&new_node->data);
    new_node->ptr=start;
    start=new_node;
  return start;
}
NODE * add_at_end(NODE *start)
{
    NODE *new_node,*temp;
    temp=start;
    if(temp==NULL)
    {
        printf("Linked list is empty");
        return start;
    }
    else
    {
        new_node=(NODE *)malloc(sizeof(NODE));
        printf("Enter value to be added at end:");
        scanf("%d",&new_node->data);
        new_node->ptr=NULL;
        while(temp->ptr!=NULL)
            temp=temp->ptr;
        temp->ptr=new_node;
        return start;
    }
}
NODE * add_at_specificloc(NODE *start)
{
    NODE *temp,*pretemp,*new_node;
    int len=0,loc;
    printf("Enter loc for adding a node: ");
    scanf("%d",&loc);
    temp=start;
    while(temp!=NULL)
    {
        len+=1;
        temp=temp->ptr;
    }
    if(loc>len || loc<2)
    {
        printf("Index Out of bound");
        return start;
    }
    new_node=(NODE *)malloc(sizeof(NODE));
    printf("Enter value to be added at %d location:",loc);
    scanf("%d",&new_node->data);
    temp=start;
    for(int j=1;j<loc;j++)
    {
        pretemp=temp;
        temp=temp->ptr;
    }
    pretemp->ptr=new_node;
    new_node->ptr=temp;
  return start;
}
NODE * delete_begn(NODE *start)
{
    NODE *temp;
    temp=start;
    char c;
    if(start==NULL)
    {
        printf("No element present in Linked list");
        return start;
    }
    else
    {
        if(start->ptr==NULL)
        {
            printf("Only one element is present,do you want to delete it...");
            scanf(" %c",&c);
            if(c=='y' || c=='Y')
            {
                start=NULL;
            }
          return start;
        }
        else
            start=start->ptr;
    }
    free(temp);
    return start;
}
NODE *sort_asc(NODE *start)
{
    int s;
    NODE *temp1,*temp2;
    temp1=start;
    while(temp1->ptr!=NULL)
    {
        temp2=temp1->ptr;
        while(temp2!=NULL)
        {
            if(temp1->data>temp2->data)
            {
                s=temp1->data;
                temp1->data=temp2->data;
                temp2->data=s;
            }
            temp2=temp2->ptr;
        }
        temp1=temp1->ptr;
    }
  return start;
}

