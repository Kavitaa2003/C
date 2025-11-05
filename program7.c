//MAtrix 
#include<stdio.h>
#include<stdlib.h>

typedef int * IPTR;
typedef int ** IPPTR;


int main()
{
    int iRow =0,iCol =0,i = 0;

    IPPTR Arr = NULL;

    printf("enter number of rows\n");
    scanf("%d",&iRow);

    printf("enter number of columns\n");
    scanf("%d",&iCol);

    Arr= (IPPTR)malloc(sizeof(IPTR) * iRow);

    for(i = 0; i < iRow; i++)
    {
        Arr[i] = (IPTR)malloc(sizeof(int) * iCol);
    }

    printf("Enter the Elements: \n");
    for(i = 0;i< iRow;i++)
    {
        for(int j= 0;i< iCol;j++)
        {
            scanf("%d",&Arr[i][i]);
        }
    }

    printf("Elemenst of Array : \n");
    for(i = 0;i< iRow;i++)
    {
        for(int j= 0;i< iCol;j++)
        {
             printf("%d\t",Arr[i][j]);
        }
    }

    return 0;
}