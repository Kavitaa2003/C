#include<stdio.h>
///output stack overflow

void Display()
{
    int iCnt = 0;

    printf("Jay Ganesh..\n");

    Display();
}

int main()
{ 
    Display();
    return 0;
}