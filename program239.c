#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>//file control 

int main()
{
    int fd = 0;
    char Fname[20] = {'\0'};
    char Buffer[10] = {'\0'};
    int iRet = 0;

    printf("Enter the filename that you want to open: ");
    scanf("%s",&Fname);
    
    fd = open(Fname, O_RDONLY );
    if(fd == -1)
    {
        printf("unable to open file\n");
        return -1;
    }
    else
    {
        printf("file is successfully open with FD %d \n",fd);

        while((iRet=read(fd,Buffer,10)) != 0)
        {
            printf("%s",Buffer);
        }
    }
    
    return 0;
}