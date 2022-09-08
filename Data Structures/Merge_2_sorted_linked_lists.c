/** Merge 2 Sorted Linked Lists into one sorted Linked List */
//Concept used: Merge function from merge sort.
//O(n1 + n2) Time and O(n1 + n2) Extra Space where n1 and n2 are lengths of linked lists respectively.
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
NODE * create_ll(NODE *);
void disp(NODE *);
NODE * merge_ll(NODE *,NODE *);
int main()
{
    NODE *start1=NULL,*start2=NULL,*result;
    printf("Enter Data in sorted manner for 1st Linked List:-\n");
    start1=create_ll(start1);
    printf("\nEnter Data in sorted manner for 2nd Linked List:-\n");
    start2=create_ll(start2);
    printf("\nThe 1st Linked List:-\n");
    disp(start1);
    printf("\nThe 2nd Linked List:-\n");
    disp(start2);
    result=merge_ll(start1,start2);
    printf("\nThe Merged Sorted Linked List:-\n");
    disp(result);
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
NODE * merge_ll(NODE *start1,NODE *start2)
{
    NODE *temp1=start1,*temp2=start2,*result=NULL,*head,*temp;
    while(temp1!=NULL && temp2!=NULL)
    {
        head=(NODE *)malloc(sizeof(NODE));
        if((temp1->data)<=(temp2->data))
        {
            head->data=temp1->data;
            temp1=temp1->next;
        }
        else
        {
            head->data=temp2->data;
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
        head=(NODE *)malloc(sizeof(NODE));
        head->data=temp1->data;
        temp->next=head;
        temp=head;
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        head=(NODE *)malloc(sizeof(NODE));
        head->data=temp2->data;
        temp->next=head;
        temp=head;
        temp2=temp2->next;
    }
    temp->next=NULL;
  return result;
}
