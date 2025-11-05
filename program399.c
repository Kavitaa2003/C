#include<stdio.h>//iteration

int Addition()
{
    static int iCnt = 1;
    int Ans =0;

    while(iCnt <= 5)
    {
        Ans = Ans + iCnt;
        iCnt++;
    }
    
    return Ans;
}

int main()
{ 
    int iRet = 0;

    iRet = Addition();

    printf("Sum is: %d\n",iRet);

    return 0;
}