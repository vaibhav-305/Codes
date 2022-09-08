#include<stdio.h>
#include<stdlib.h>
int main()
{
  //here p is an array and q is simple variable
  //for array
  int *p,n,i;
  printf("Enter size:");
  scanf("%d",&n);
  p=(int *)malloc(sizeof(int)*n);
  printf("Enter values:\n");
  for(i=0;i<n;i++)
    scanf("%d",&p[i]);
  for(i=0;i<n;i++)
    printf("%3d",p[i]);
  free(p);
  //for simple variable
  float *q=(float *)malloc(sizeof(float));
  printf("\nEnter value of variable: ");
  scanf("%f",q);
  printf("value of Simple variable:%f",*q);
  free(q);
return 0;
}
