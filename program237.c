#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>//file control 

int main()
{
    int fd = 0;
    char Fname[20] = {'\0'};
    char Buffer[50] = {'\0'};
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
        
        iRet = read(fd,Buffer,11);
        
        printf("%d bytes gets reads successfully\n",iRet);
        
        printf("data from file is : %s\n",Buffer);

        iRet = read(fd,Buffer,20);//starting from 11th from above read 
        
        printf("%d bytes gets reads successfully\n",iRet);
        
        printf("data from file is : %s\n",Buffer);
    }

    close(fd);
    
    return 0;
}