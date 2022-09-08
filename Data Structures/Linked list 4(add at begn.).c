#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
NODE *create(NODE *);
int main()
{
    NODE *first=NULL;
    first=create(first);
    first=insert_begn(start);
    disp(first);
  return 0;
}
NODE *insert_begn(NODE *first)
{
    NODE *new_node;
    new_node=(NODE *)malloc(sizeof(NODE));
}
