#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>//file control 

int main()
{
    int fd = 0;//file description
    char Fname[20]= {'\0'};

    printf("Enter the filename that you want to open: ");
    scanf("%s",&Fname);
    
    fd = open(Fname,O_RDWR);//O_RDONLY  O_WDONLY  O_RDWR

    if(fd==-1)
    {
        printf("unable to open file\n");
        return -1;
    }
    else
    {
        printf("file is successfully open with FD %d \n",fd);
    }

    close(fd);
    
    return 0;
}