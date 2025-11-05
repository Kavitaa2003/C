//MAtrix 
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef int * IPTR;
typedef int ** IPPTR;

void Accept(IPPTR Arr,int iRow,int iCol)
{
    int i= 0, j = 0;
    printf("Enter the Elements: \n");
    for(i = 0; i < iRow; i++)
    {
        for(j = 0; j < iCol; j++)
        {
            scanf("%d",&Arr[i][j]);
        }
    }
}

void Display(IPPTR Arr,int iRow,int iCol)
{
    int i = 0, j = 0;

    printf("Elemenst of Matrix : \n");
    for(i = 0; i < iRow; i++)
    {
        for(j = 0; j < iCol; j++)
        {
             printf("%d\t",Arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int Summation(IPPTR Arr,int iRow,int iCol)
{
    int i = 0, j = 0, iSum = 0;
    for(i = 0; i < iRow; i++)
    {
        for(j = 0; j < iCol; j++)
        {
            iSum = iSum + Arr[i][j];
        }
    }

    return iSum;
}

int Maximum(IPPTR Arr,int iRow,int iCol)
{
    int i = 0, j = 0, iMax = 0;

    iMax = INT_MIN;

    for(i = 0; i < iRow; i++)
    {
        for(j = 0; j < iCol; j++)
        {
            if(Arr[i][j] > iMax)
            {
                iMax = Arr[i][j];
            }
        }
    }

    return iMax;
}

int Minimum(IPPTR Arr,int iRow,int iCol)
{
    int i = 0, j = 0, iMin = 0;

    iMin = INT_MAX;

    for(i = 0; i < iRow; i++)
    {
        for(j = 0; j < iCol; j++)
        {
            if(Arr[i][j] < iMin)
            {
                iMin = Arr[i][j];
            }
        }
    }

    return iMin;
}

void MaxRow(IPPTR Arr,int iRow,int iCol)
{
    int i = 0, j = 0, iMax = 0;

    iMax = INT_MIN;

    for(i = 0; i < iRow; i++)
    {
        for(j = 0; j < iCol; j++)
        {
            if(Arr[i][j] > iMax)
            {
                iMax = Arr[i][j];
            }
        }
        printf("Maximum elementsb from row no %d is : %d\n",i,iMax);
        iMax = INT_MIN;
    }
}

void MaxMin(IPPTR Arr,int iRow,int iCol)
{
    int i = 0, j = 0, iMax = 0,iMin = 0;

    iMax = INT_MIN;
    iMin = INT_MAX;

    for(i = 0; i < iRow; i++)
    {
        for(j = 0; j < iCol; j++)
        {
            if(Arr[i][j] > iMax)
            {
                iMax = Arr[i][j];
            }

            if(Arr[i][j] < iMin)
            {
                iMin = Arr[i][j];
            }
        }
    }
    printf("Maximum element is : %d\n",iMax);
    printf("Minimum element is : %d\n",iMin);
}

int Summation_Border(IPPTR Arr,int iRow,int iCol)
{
    int i = 0, j = 0, iSum = 0;
    for(i = 0; i < iRow; i++)
    {
        for(j = 0; j < iCol; j++)
        {
            if(i == 0 || j == 0 || i == iRow-1 || j == iCol-1)
            {
                iSum = iSum + Arr[i][j];
            }
        }
    }

    return iSum;
}

int Summation_Even_Row(IPPTR Arr,int iRow,int iCol)
{
    int i = 0, j = 0, iSum = 0;
    for(i = 0; i < iRow; i++)
    {
        for(j = 0; j < iCol; j++)
        {
            if((i % 2) != 0)
            {
                iSum = iSum + Arr[i][j];
            }
        }
    }

    return iSum;
}

void Display_Neighbors(IPPTR Arr,int iRow,int iCol)
{
    int i = 0, j = 0;

    printf("Neighbors of Matrix : \n");
    for(i = 0; i < iRow; i++)
    {
        for(j = 0; j < iCol; j++)
        {
            if((j != 0) && (j != iCol-1))
            {
                if(Arr[i][j] == Arr[i][j-1] + Arr[i][j+1])
                {
                    printf("%d\t",Arr[i][j]);
                }
            }
        }
    }
    printf("\n");
}

void Reset_Neighbors(IPPTR Arr,int iRow,int iCol)
{
    int i = 0, j = 0;
    for(i = 0; i < iRow; i++)
    {
        for(j = 0; j < iCol; j++)
        {
            if((j != 0) && (j != iCol-1))
            {
                if(Arr[i][j] == Arr[i][j-1] + Arr[i][j+1])
                {
                    Arr[i][j] = 0;
                }
            }
        }
    }
    printf("\n");
}


int main()
{
    int iRow = 0, iCol = 0, i = 0, iRet = 0, iMax = 0, iMin =0;

    IPPTR Arr = NULL;

    printf("Enter number of rows : \n");
    scanf("%d",&iRow);

    printf("Enter number of columns : \n");
    scanf("%d",&iCol);

    Arr=(IPPTR)malloc(sizeof(IPTR) * iRow);

    for(i = 0; i < iRow; i++)
    {
        Arr[i] = (IPTR)malloc(sizeof(int) * iCol);
    }

    Accept(Arr,iRow,iCol);

    Display(Arr,iRow,iCol);

    Reset_Neighbors(Arr,iRow,iCol);

    printf(" Updated Neighbors of Matrix : \n");

    Display(Arr,iRow,iCol);

    //Deallocate memory of matrix
    for(i = 0; i < iRow; i++)
    {
        free(Arr[i]);
    }

    free(Arr);

    return 0;
}