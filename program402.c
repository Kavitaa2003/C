#include<stdio.h>//iteration

int Factorial(int iNo)
{
    static int iCnt = 1;
    int Ans = 1;

    while(iCnt <= iNo)
    {
        Ans = Ans * iCnt;
        iCnt++;
    }
    
    return Ans;
}

int main()
{ 
    int iRet = 0,iValue = 6;

    iRet = Factorial(iValue);

    printf("Sum is: %d\n",iRet);

    return 0;
}