#include <stdio.h>
#include <stdlib.h>
int main()
{
    //malloc gives a adress to pointer variable so that is can store it.
    int *p=(int *)malloc(sizeof(int));
    printf("enter val: ");
    scanf("%d",p);
    printf("value: %d\nadress by malloc: %u\nadress of variable: %u",*p,p,&p);
    free(p);
  return 1;
}
