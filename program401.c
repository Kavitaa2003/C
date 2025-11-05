#include<stdio.h>//Recursion

int Factorial()
{
    static int iCnt = 1;
    static int Ans = 1;

    if(iCnt <= 5)
    {
        Ans = Ans * iCnt;
        iCnt++;
        Factorial();
    }
    
    return Ans;
}

int main()
{ 
    int iRet = 0;

    iRet = Factorial();

    printf("Factorial  is: %d\n",iRet);

    return 0;
}