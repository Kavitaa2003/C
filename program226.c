#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd = 0;//file description
    char Fname[20]= {'\0'};

    printf("Enter the filename to create: ");
    scanf("%s",&Fname);
    fd = creat(Fname,0777);
    
    return 0;
}