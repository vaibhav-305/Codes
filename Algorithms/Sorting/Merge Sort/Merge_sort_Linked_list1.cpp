// In O(N*log(N)) time and in O(1) space.
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
NODE * create_ll(NODE *);
void disp(NODE *);
NODE * merge_sort(NODE *);
NODE * find_mid(NODE *);
NODE * merge_ll(NODE *,NODE *);
int main()
{
    NODE *start1=NULL;
    printf("Enter Data for Linked List:-\n");
    start1=create_ll(start1);
    printf("\nThe original Linked List:-\n");
    disp(start1);

    start1=merge_sort(start1);

    printf("\nThe Sorted Linked List:-\n");
    disp(start1);
    return 0;
}
NODE * create_ll(NODE *start)
{
    NODE *temp,*head;
    char c;
    do
    {
        head=(NODE *)malloc(sizeof(NODE));
        printf("Enter data: ");
        scanf("%d",&head->data);
        if(start==NULL)
            temp=start=head;
        else
        {
            temp->next=head;
            temp=head;
        }
        printf("Do you want to continue...");
        scanf(" %c",&c);
    }while(c=='Y' || c=='y');
    temp->next=NULL;
  return start;
}
void disp(NODE *start)
{
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
    NODE *mid=find_mid(start); //to find mid of list
    NODE *mid_next=mid->next;
    mid->next=NULL;// This is breaking link between nodes

    NODE *first=merge_sort(start); //to split
    NODE *second=merge_sort(mid_next); //to split

    NODE *sorted_list=merge_ll(first,second); //to merge splited parts
  return sorted_list;
}
NODE * find_mid(NODE *start)
{
    NODE *slow,*fast;
    slow=start;
    fast=start->next;
    /* Advance 'fast' two nodes, and advance 'slow' one node */
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

NODE * merge_ll(NODE *first,NODE *second)
{
    NODE *temp1=first,*temp2=second,*result=NULL,*temp,*head;
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
            temp=result=head;
        else
        {
            temp->next=head;
            temp=head;
        }
    }
    while(temp1!=NULL)
    {
        head=temp1;
        temp->next=head;
        temp=head;
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        head=temp2;
        temp->next=head;
        temp=head;
        temp2=temp2->next;
    }
    temp->next=NULL;
  return result;
}

