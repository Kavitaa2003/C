#include<stdio.h>
int Factorial(int iNo)
{
    static int iCnt = 1;
     static int Ans = 1;

    if(iCnt <= iNo)
    {
        Ans = Ans * iCnt;
        iCnt++;
        Factorial(iNo);
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