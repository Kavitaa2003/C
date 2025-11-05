#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>//file control 

int main()
{
    int fd = 0;//file description 3 places are occupied already for 2 for monitors and 1 for keyboard
    char Fname[20]= {'\0'};
    char Buffer[] = "India is my Country";
    int iRet = 0;

    printf("Enter the filename that you want to open: ");
    scanf("%s",&Fname);
    
    fd = open(Fname,O_CREAT | O_WRONLY | O_APPEND);
    if(fd == -1)
    {
        printf("unable to open file\n");
        return -1;
    }
    else
    {
        printf("file is successfully open with FD %d \n",fd);
        iRet = write(fd,Buffer,strlen(Buffer));
        printf("%d bytes gets return successfully\n",iRet);
    }

    close(fd);
    
    return 0;
}