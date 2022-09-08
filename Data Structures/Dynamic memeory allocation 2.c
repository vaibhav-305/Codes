#include<stdio.h>
#include<stdlib.h>
typedef struct Complex
{
float r,i;
}cmplx;
int main()
{
cmplx *n=(cmplx *)malloc(sizeof(cmplx));
printf("Enter no(in form x+jy): ");
scanf("%f+j%f",&(n->r),&(n->i));
printf("o/p= %f+j%f",n->r,n->i);
cmplx *p=(cmplx *)malloc(sizeof(cmplx));
printf("\nEnter no(in form x+jy): ");
scanf("%f+j%f",&((*p).r),&((*p).i));
printf("o/p= %f+j%f",(*p).r,(*p).i);
printf("\n----------Adresses---------\n");
printf("Adresses of n:\n%u\n%u",&(n->i),&(n->r));
printf("\nAdresses of n$:\n %u \n %u ",n->i,n->r);
printf("\n%u",n);
printf("\nAdresses of p:\n%u\n%u",&(p->i),&(p->r));
printf("\n%u",p);
printf("\n--------Values(again)--------\n");
printf("n= %f+j%f\n",n->r,n->i);
printf("p= %f+j%f",(*p).r,(*p).i);
free(p);
free(n);
return 0;
}
