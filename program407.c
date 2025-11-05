#include<stdio.h>

int Factorial(int iNo)
{
     static int Ans = 1;

    if(iNo > 1)
    {
        Ans = Ans * iNo;
        Factorial(iNo-1);//////
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