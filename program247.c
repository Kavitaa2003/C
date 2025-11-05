#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

#define BUFFER_SIZE 1024

int main()
{
    int fd = 0;
    char Fname[20] = {'\0'};
    char Buffer[BUFFER_SIZE] = {'\0'};/////standard value 1024 
    int iRet = 0,iCnt = 0,iCapCount=0;

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

        while((iRet=read(fd,Buffer,BUFFER_SIZE)) != 0)
        { 
            for(iCnt = 0;iCnt < iRet ;iCnt++)
            {
                if(Buffer[iCnt>='A'] && Buffer[iCnt]<='Z')
                {
                    iCapCount++;
                }
                printf("%c\n",Buffer[iCnt]);
            }
            memset(Buffer,'\0',1024);
        }
        printf("Capital letters are  : %d\n",iCapCount);
    }
    return 0;
}
