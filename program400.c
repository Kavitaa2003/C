#include<stdio.h>//Recursion

int Addition()
{
    static int iCnt = 1;
    static int Ans = 0;

    if(iCnt <= 5) /////
    {
        Ans = Ans + iCnt;
        iCnt++;
        Addition();////
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