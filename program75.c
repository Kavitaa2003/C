//MAtrix 
#include<stdio.h>
#include<stdlib.h>

typedef int * IPTR;

int main()
{
    int iRow =0;
    IPTR Arr = NULL;

    printf("enter number of Elemnets\n");
    scanf("%d",&iRow);

    Arr = (IPTR)malloc(sizeof(int) * iRow);

    return 0;
}