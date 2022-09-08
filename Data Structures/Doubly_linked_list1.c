#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE;
NODE * create_dll(NODE *);
void display(NODE *);
NODE * merge_sort(NODE *);
NODE * find_mid(NODE *);
NODE * merge_dll(NODE *,NODE *);
int main()
{
    NODE *start=NULL;
    int opt;
    do
    {
        printf("\n************** MENU ***************");
        printf("\n1. Create Doubly Linked list");
        printf("\n2. Display Doubly Linked List");
        printf("\n3. Sort the List(Merge Sort)");
        printf("\n4. Exit");
        printf("\n***********************************");
        printf("\nSelect option:");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            start=create_dll(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            printf("Doubly Linked List Sorted !!\n");
            start=merge_sort(start);
            break;
        }
    }while(opt<4);
  return 0;
}
NODE * create_dll(NODE *start)
{
    NODE *head,*temp;
    char c;
    do
    {
        head=(NODE *)malloc(sizeof(NODE));
        printf("Enter Data: ");
        scanf("%d",&head->data);
        if(start==NULL)
        {
            head->prev=NULL;
            temp=start=head;
        }
        else
        {
            temp->next=head;
            head->prev=temp;
            temp=head;
        }
        printf("Do you want to continue...");
        scanf(" %c",&c);
    }while(c=='Y' || c=='y');
    temp->next=NULL;
  return start;
}
void display(NODE *start)
{
    printf("The Doubly Linked List:-\n");
    NODE *temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
}
NODE * merge_sort(NODE *start)
{
    if(start==NULL || start->next==NULL)
        return start;
    NODE *mid=find_mid(start);
    NODE *mid_next=mid->next;
    mid->next=NULL;
    mid_next->prev=NULL;

    NODE *first=merge_sort(start);
    NODE *second=merge_sort(mid_next);

    NODE *sorted_list=merge_dll(first,second);
    return sorted_list;
}
NODE * find_mid(NODE *start)
{
    NODE *slow,*fast;
    slow=start;
    fast=start->next;

    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }
  return slow;
}
NODE * merge_dll(NODE *first,NODE *second)
{
    NODE *temp1=first,*temp2=second,*result=NULL,*head,*temp;
    while(temp1!=NULL && temp2!=NULL)
    {
        if((temp1->data)<=(temp2->data))
        {
            head=temp1;
            temp1=temp1->next;
        }
        else
        {
            head=temp2;
            temp2=temp2->next;
        }
        if(result==NULL)
        {
            head->prev=NULL;
            temp=result=head;
        }
        else
        {
            temp->next=head;
            head->prev=temp;
            temp=head;
        }
    }
    while(temp1!=NULL)
    {
        head=temp1;
        temp->next=head;
        head->prev=temp;
        temp=head;
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        head=temp2;
        temp->next=head;
        head->prev=temp;
        temp=head;
        temp2=temp2->next;
    }
    temp->next=NULL;
    return result;
}

