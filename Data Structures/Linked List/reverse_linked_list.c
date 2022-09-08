#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE * create_ll(NODE *);
void disp(NODE *);
NODE * reverse_ll(NODE *);

int main(){
    NODE *start1=NULL;
    printf("Enter Data for Linked List:-\n");
    start1=create_ll(start1);
    printf("\nThe original Linked List:-\n");
    disp(start1);

    start1=reverse_ll(start1);

    printf("\nThe Reversed Linked List:-\n");
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
NODE * reverse_ll(NODE *start)
{
    NODE *prev_node=NULL,*next_node,*temp;
    temp=start;
    while(temp!=NULL)
    {
        next_node=temp->next;
        temp->next=prev_node;
        prev_node=temp;
        temp=next_node;

    }
    return prev_node;
}
